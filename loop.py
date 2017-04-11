#!/usr/bin/env python

from ROOT import *
from optparse import OptionParser
import os.path
import sys
from muon import *
from jet import *
from prescale import *
from pileup import *
from crossSection import *

def skim(tree, eventSel):
  mylist = TEventList("mylist") 
  tree.Draw(">> mylist", eventSel)
  tree.SetEventList(mylist)
  print "total chain entries:", tree.GetEntries()
  mylist.Print()

def book(outFileName, variables, cuts):
  outFile = TFile(outFileName, "recreate")
  outFile.cd()
  histos={}
  for varname in variables.keys():
    histos[varname]={}
    for cutname in cuts.keys():
      hname = varname+"__"+cutname
      h = TH1F(hname, hname, variables[varname]['nbins'], variables[varname]['xmin'], variables[varname]['xmax'])
      h.Sumw2()
      histos[varname][cutname] = h

  return outFile, histos    
    
def passTrigger(event,trigIdx):
  bitIdx = trigIdx/32 ;
  return ( event.BitTrigger[bitIdx] & ( 1 << (trigIdx - bitIdx*32) ) )




#######################################
########   MAIN PROGRAM  ##############
#######################################

if __name__ == "__main__":
  usage="usage: %prog [opzioni] inputList outputFile"
    
  parser = OptionParser(usage=usage)
  parser.add_option("-t", action="store", help="tree name from BTagAnalyzer (default=btagana/ttree)", default="btagana/ttree", dest="tree")
  parser.add_option("-c", action="store", help="cuts file name (default cuts.py)", default="cuts.py", dest="cutsFile")
  parser.add_option("-v", action="store", help="variables file name (default variables.py)", default="variables.py", dest="variablesFile")
  parser.add_option("-d", action="store_true", help="if it is data apply trigger (default false (i.e. MC))", default=False, dest="isData")
  parser.add_option("-l", action="store", help="data luminosity in fb-1 (default=35.9)", default=35.9, dest="lumi")


  (opzioni, args) = parser.parse_args()
  if len(args) != 2:
    print parser.print_help() 
    sys.exit(1)

  # list of branches to activate
  # IMPORTANT remmeber to activate a branch before using it 
  # this variable is used also in variables.py and cuts.py
  activeBranches=[]

  activeBranches.extend([
  "PFMuon_isGlobal",
  "PFMuon_nMuHit",
  "PFMuon_nTkHit",
  "PFMuon_nPixHit",
  "PFMuon_nOutHit",
  "PFMuon_nMatched",
  "PFMuon_chi2",
  "PFMuon_chi2Tk",
  "PFMuon_IdxJet",
  'nPFMuon',
  'PFMuon_pt',
  'PFMuon_eta',
  'PFMuon_phi',
  'Jet_pt',
  'Jet_phi',
  'Jet_eta',
  'nBitTrigger',
  'BitTrigger',
  'Run',
  'LumiBlock',
  'Evt',
  'mcweight',
  'nPUtrue',
  'nPV']
  )

  cutsFile = opzioni.cutsFile
  passedFile=""

  if os.path.exists(cutsFile) :
    handle = open(cutsFile,'r')
    exec(handle)
    handle.close()
  else:
    print "!!! ERROR file ", cutsFile, " does not exist."
    sys.exit(1)

  variablesFile = opzioni.variablesFile  
  if os.path.exists(variablesFile) :
    handle = open(variablesFile,'r')
    exec(handle)
    handle.close()
  else:
    print "!!! ERROR file ", variablesFile, " does not exist."
    sys.exit(1)


  fileList=open(args[0])
  outputFile=args[1]
  print "creating chain..."
  # create a chain with all files in the list
  chain = TChain(opzioni.tree)
  for line in fileList:
    chain.Add(line.rstrip('\n'))
  print "...done"

  #skim the chain according to the gloval event selection
  #print "skimming..."
  #skim(chain, eventsel)
  #print "...done"

  # book histos
  print "booking histos..."
  outFile, histos = book(outputFile, variables, cuts)
  print "...done"

  # disable all branches, then reenable only the used ones
  chain.SetBranchStatus("*", 0)
  for branch in activeBranches:
    chain.SetBranchStatus(branch, 1)


  # prepare prescale tables
  if opzioni.isData:
    prescaleTables={}
    prescaleTables["30"] = Prescales("data/prescalesHLT_BTagMu_DiJet20_Mu5.txt")
    prescaleTables["31"] = Prescales("data/prescalesHLT_BTagMu_DiJet40_Mu5.txt")
    prescaleTables["32"] = Prescales("data/prescalesHLT_BTagMu_DiJet70_Mu5.txt")
    prescaleTables["33"] = Prescales("data/prescalesHLT_BTagMu_DiJet110_Mu5.txt")
    prescaleTables["34"] = Prescales("data/prescalesHLT_BTagMu_DiJet170_Mu5.txt")
    prescaleTables["35"] = Prescales("data/prescalesHLT_BTagMu_Jet300_Mu5.txt")

  else:
    pileup = Pileup(["data/PileupHistogram_Full2016_271036-278808_69p2mb_Rereco.root",
                     "data/PileupHistogram_Full2016_278820-284044_69p2mb_Rereco.root"],
                     [0.1, 0.9],
                     chain)
    crossSection = CrossSection("data/xsectionFilter.txt")                 
  i=0
  passed=0
  for event in chain:
    try:
      #if event.Evt != 615322131 and event.Evt != 637075692:
      #  continue
      # event weight
      
      weight=1.
      if (not opzioni.isData):
        mcweight = event.mcweight 
        weight = weight*mcweight
        npv = event.nPV
        npu = event.nPUtrue
        # PU weight
        weight = weight*pileup.getWeight(npu)
        # xsec weight
        weight = weight*crossSection.getWeight(chain, opzioni.lumi*1000.)

      i=i+1
      if (i%1000==0):
        sys.stdout.write("\rprocessing event %d" %i)
        sys.stdout.flush()

      # global event selection    
      if not (eventsel(event)): continue
      #print "passed global sel"
      # prepare lists with jets and leptons    
      nJet=event.nJet
      nPFMuon=event.nPFMuon
      jets=[]
      for IJ in range(nJet):
        jet=Jet(event,IJ)
        if (jet.fourMomentum.Pt()>20. and abs(jet.fourMomentum.Eta())<2.4):# and jet.Jet_Proba>0):
          jets.append(jet)
      #for jet in jets:
      #  print jet.index, jet.fourMomentum.Pt(),jet.fourMomentum.Eta(),jet.Jet_Proba
      muons=[]
      for IM in range(nPFMuon):
        muon=Muon(event,IM)
        if (muon.fourMomentum.Pt()>5. and abs(muon.fourMomentum.Eta()<2.4)):
          muons.append(muon)

      # the following is needed to decide how to 
      # assign pt bins to Triggers
      nJets=[0, 0, 0, 0, 0] 
      nMuJets=[0, 0, 0, 0, 0]
      atLeastOneMatchedMuon=False
      for jet in jets:
        matched=False
        for muon in muons:
          if muon.passMuId() and muon.match(jet):
            atLeastOneMatchedMuon = True
            matched = True
            break
            
        if (jet.fourMomentum.Pt()>20. and jet.fourMomentum.Pt()<50): nJets[0]=nJets[0]+1
        if (jet.fourMomentum.Pt()>50. and jet.fourMomentum.Pt()<80): nJets[1]=nJets[1]+1
        if (jet.fourMomentum.Pt()>80. and jet.fourMomentum.Pt()<120): nJets[2]=nJets[2]+1
        if (jet.fourMomentum.Pt()>120. and jet.fourMomentum.Pt()<320): nJets[3]=nJets[3]+1
        if (jet.fourMomentum.Pt()>320.) : nJets[4]=nJets[4]+1
        
        if (jet.fourMomentum.Pt()>20. and jet.fourMomentum.Pt()<50 and matched): nMuJets[0]=nMuJets[0]+1 
        if (jet.fourMomentum.Pt()>50. and jet.fourMomentum.Pt()<80 and matched): nMuJets[1]=nMuJets[1]+1
        if (jet.fourMomentum.Pt()>80. and jet.fourMomentum.Pt()<120 and matched): nMuJets[2]=nMuJets[2]+1
        if (jet.fourMomentum.Pt()>120. and jet.fourMomentum.Pt()<320 and matched): nMuJets[3]=nMuJets[3]+1
        if (jet.fourMomentum.Pt()>320. and matched) : nMuJets[4]=nMuJets[4]+1 
        
      if not atLeastOneMatchedMuon: continue
      #print "at east one matched muon"
      # trigger selection    
      triggers=[]
      for itrig in range(30, 36):
        if passTrigger(event, itrig) and itrig != 34: ##removed 170 for the moment as it was not available for the whole period
          triggers.append(itrig)
      if len(triggers) == 0: continue
      triggerPtBins=[]
      if ( nJets[0] >= 2 and nMuJets[0] >= 1 )  : triggerPtBins.append(30)
      if ( nJets[1] >= 2 and nMuJets[1] >= 1 )  : triggerPtBins.append(31)
      if ( nJets[2] >= 2 and nMuJets[2] >= 1 )  : triggerPtBins.append(32)
      if ( nJets[3] >= 2 and nMuJets[3] >= 1 )  : triggerPtBins.append(33)
      if ( nJets[4] > 0 and nMuJets[4] >= 1 )   : triggerPtBins.append(35)
      #print nJets
      #print nMuJets

      #find matches between triggers that actually fired and pt bins
      matches=set(triggers).intersection(triggerPtBins)
      matches=list(matches)
      #print triggers, triggerPtBins, matches
      if len(matches)==0: continue
      #print "triggered"
      #print puppapuppa
      if opzioni.isData:
        #get the prescale weight from the first trigger in the list
        #print ">>>>", matches
        matches.sort(reverse=True)
        #print "<<<<", matches
        weight = weight*prescaleTables[str(matches[0])].getPrescaleWeight(event.Run, event.LumiBlock)

      passed +=1
      passedFile += "%6d %6d %10d  %+2d  %+4.2f %+4.2f %+4.2f \n" % (event.Run, event.LumiBlock, event.Evt , event.nJet, jets[0].fourMomentum.Pt(), jets[0].fourMomentum.Eta(), jets[0].fourMomentum.Phi());
      # loop over jets, apply jet specific categorization and fill plots   
      for IJ in range(nJet):
        for cut in cuts.keys():
          if cutFunctions[cut](event, IJ):
            for variable in variables.keys():
              histos[variable][cut].Fill(variableFunctions[variable](event, IJ), weight)
    except KeyboardInterrupt:
      print "\nInterrupted"
      break
  print "\n"
  print "Total events processed", i, "; passed", passed
  outFile.Write()

  #print passedFile

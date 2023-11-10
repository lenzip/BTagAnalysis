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


import copy

def skim(tree, eventSel):
  mylist = TEventList("mylist") 
  tree.Draw(">> mylist", eventSel)
  tree.SetEventList(mylist)
  print("total chain entries:", tree.GetEntries())
  mylist.Print()

def bookamelo(outFileName, variables, cuts, systematics):
  outFile = TFile(outFileName, "recreate")
  outFile.cd()
  histos={}
  for varname in list(variables.keys()):
    histos[varname]={}
    for cutname in list(cuts.keys()):
      hname = varname+"__"+cutname
      h = TH1F(hname, hname, variables[varname]['nbins'], variables[varname]['xmin'], variables[varname]['xmax'])
      #print "booking", hname, " between",variables[varname]['xmin'],variables[varname]['xmax']
      h.Sumw2()
      histos[varname][cutname] = {}
      histos[varname][cutname]['central'] = h
      for systematic in systematics:
        hnameup = hname+"_"+systematic+"_up"
        hnamedo = hname+"_"+systematic+"_do"
        hup = TH1F(hnameup, hnameup, variables[varname]['nbins'], variables[varname]['xmin'], variables[varname]['xmax'])
        histos[varname][cutname][systematic+"_up"] = hup 
        hdo = TH1F(hnamedo, hnamedo, variables[varname]['nbins'], variables[varname]['xmin'], variables[varname]['xmax'])
        histos[varname][cutname][systematic+"_do"] = hdo 

  return outFile, histos    
    
def passTrigger(event,trigIdx):
  bitIdx = int(trigIdx/32) ;
  #return 1
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
  parser.add_option("-s", action="store", help="systematics file name (default systematics.py)", default="systematics.py", dest="systematicsFile")
  parser.add_option("-d", action="store_true", help="if it is data apply trigger (default false (i.e. MC))", default=False, dest="isData")
  parser.add_option("-l", action="store", help="data luminosity in fb-1 (default=4.235)", default=4.235, dest="lumi")
  parser.add_option("-p", action="store", help="what PU profile to use (defualt=PileupHistogram_Run2017D_69p2mb_Rereco.root)", default="PileupHistogram_Run2017D_69p2mb_Rereco.root", dest="pufile")


  (opzioni, args) = parser.parse_args()
  if len(args) != 2:
    print(parser.print_help()) 
    sys.exit(1)

  # list of branches to activate
  # IMPORTANT remmeber to activate a branch before using it 
  # this variable is used also in variables.py and cuts.py
  activeBranches=[]

  activeBranches.extend([
  #"PFMuon_isGlobal",
  #"PFMuon_nMuHit",
  #"PFMuon_nTkHit",
  #"PFMuon_nPixHit",
  #"PFMuon_nOutHit",
  #"PFMuon_nMatched",
  #"PFMuon_chi2",
  #"PFMuon_chi2Tk",
  "PFMuon_IdxJet",
  'nPFMuon',
  'PFMuon_pt',
  'PFMuon_eta',
  'PFMuon_phi',
  'PFMuon_GoodQuality',
  'Jet_pT',
  'Jet_phi',
  'Jet_eta',
  'nBitTrigger',
  'BitTrigger',
  'Run',
  'LumiBlock',
  'Evt',
  #'mcweight',
  'nPUtrue',
  'nPU']
  )

  if (not opzioni.isData):
    activeBranches.extend([
      'gluonSplittingWeightUp',
      'gluonSplittingWeightDo',
      'bFragmentationWeightUp',
      'bFragmentationWeightDo',
      'cdFragmentationWeightUp',
      'cdFragmentationWeightDo',
      'cFragmentationWeightUp',
      'cFragmentationWeightDo',
      'cSVmassWeightUp',
      'cSVmassWeightDo',
      'Evt_new',
      'v0WeightUp',
      'v0WeightDo',
      'Jet_pTJERUp',
      'Jet_pTJERDo',
      'Jet_pTJESUp',
      'Jet_pTJESDo',
          ])

  cutsFile = opzioni.cutsFile
  passedFile=""

  if os.path.exists(cutsFile) :
    handle = open(cutsFile,'r')
    exec(handle.read())
    handle.close()
  else:
    print("!!! ERROR file ", cutsFile, " does not exist.")
    sys.exit(1)

  variablesFile = opzioni.variablesFile  
  if os.path.exists(variablesFile) :
    handle = open(variablesFile,'r')
    exec(handle.read())
    handle.close()
  else:
    print("!!! ERROR file ", variablesFile, " does not exist.")
    sys.exit(1)

  weightSystematics = []
  shapeSystematics = []
  systematicsFile = opzioni.systematicsFile
  if os.path.exists(systematicsFile) :
    handle = open(systematicsFile,'r')
    exec(handle.read())
    handle.close()
  else:
    print("!!! ERROR file ", systematicsFile, " does not exist.")
    sys.exit(1)
  allSystematics = []
  allSystematics.extend(weightSystematics)
  allSystematics.extend(shapeSystematics)

  weightSystematicsFunctionsUp = {}
  weightSystematicsFunctionsDo = {}
  for syst in weightSystematics:
    weightSystematicsFunctionsUp[syst] = eval('lambda event, IJ: event.'+syst+"WeightUp[IJ]")
    weightSystematicsFunctionsDo[syst] = eval('lambda event, IJ: event.'+syst+"WeightDo[IJ]")
  
  cutsUp = {}
  cutFunctionsUp = {}
  cutsDo = {}
  cutFunctionsDo = {}
  variablesUp = {}
  variableFunctionsUp = {}
  variablesDo = {}
  variableFunctionsDo = {}

  for syst in shapeSystematics:
    cutsUp[syst] = copy.deepcopy(cuts)
    cutFunctionsUp[syst] = copy.deepcopy(cutFunctions)
    cutsDo[syst] = copy.deepcopy(cuts)
    cutFunctionsDo[syst] = copy.deepcopy(cutFunctions)
    for cut in cuts:
      cutsUp[syst][cut] = cutsUp[syst][cut].replace('Jet_pT', 'Jet_pT'+syst+"Up")
      cutFunctionsUp[syst][cut]=eval("lambda event,IJ:"+cutsUp[syst][cut])
      cutsDo[syst][cut] = cutsDo[syst][cut].replace('Jet_pT', 'Jet_pT'+syst+"Do")
      cutFunctionsDo[syst][cut]=eval("lambda event,IJ:"+cutsDo[syst][cut])
    variablesUp[syst] = copy.deepcopy(variables)  
    variableFunctionsUp[syst] = copy.deepcopy(variableFunctions)
    variablesDo[syst] = copy.deepcopy(variables)
    variableFunctionsDo[syst] = copy.deepcopy(variableFunctions)
    for variable in variables:
      variablesUp[syst][variable]['expression'] = variablesUp[syst][variable]['expression'].replace('Jet_pT', 'Jet_pT'+syst+"Up")
      variableFunctionsUp[syst][variable]=eval("lambda event,IJ:"+variablesUp[syst][variable]['expression'])
      variablesDo[syst][variable]['expression'] = variablesDo[syst][variable]['expression'].replace('Jet_pT', 'Jet_pT'+syst+"Do")
      variableFunctionsDo[syst][variable]=eval("lambda event,IJ:"+variablesDo[syst][variable]['expression'])

  fileList=open(args[0])
  outputFile=args[1]
  print("creating chain...")
  # create a chain with all files in the list
  chain = TChain(opzioni.tree)
  for line in fileList:
    chain.Add(line.rstrip('\n'))
  print("...done")
  fileList.seek(0)

  print(bookamelo)
  if not opzioni.isData:
    print("this is MC, adding systematic variations to the tree...")
    cmssw_base = os.getenv('CMSSW_BASE')
    gSystem.AddIncludePath("-I"+cmssw_base+"/interface/");
    gSystem.Load("libFWCoreFWLite.so");
    try:
      gROOT.LoadMacro('BTagAnalyzerSelector.C+g')
    except RuntimeError:
      gROOT.LoadMacro('BTagAnalyzerSelector.C+g')
    print("Starting pre-processing")   
    ihelper = 0
    helperChain = TChain("helper")
    helperFiles = []
    for filename in fileList:
      helpername = "helper"+str(ihelper)+".root"
      helperFile = TFile(helpername, "recreate")
      helperFile.cd()
      systHelper = BTagAnalyzerSelector()
      print("processing tree", filename)
      thisFile = TFile.Open(filename.rstrip('\n'))
      thisTree = thisFile.Get(opzioni.tree)
      systHelper.Init(thisTree)
      for iEvent in range(thisTree.GetEntries()):
        systHelper.Process(iEvent)
      helperFile.cd()
      systHelper.getHelperTree().Write()
      helperFile.Close()
      helperFiles.append(helpername)
      ihelper += 1 
    for helper in helperFiles:  
      helperChain.Add(helper)
    '''
    systHelper.Init(chain)
    ipre=0
    for iEvent in range(chain.GetEntries()):
      #print iEvent, systHelper.GetEntry(iEvent)
      #print iEvent
      if (ipre%1000==0):
        sys.stdout.write("\rpre-processing event %d/%d" %(ipre, chain.GetEntries()))
        sys.stdout.flush()
      ipre = ipre+1  
      systHelper.Process(iEvent)
    '''
    print(chain.GetEntries(), helperChain.GetEntries())
    chain.AddFriend(helperChain)
    print("...done")

  print(bookamelo)
  # book histos
  print("booking histos...")
  outFile, histos = bookamelo(outputFile, variables, cuts, allSystematics)
  print("...done")

  #skim the chain according to the gloval event selection
  #print "skimming..."
  #skim(chain, eventsel)
  #print "...done"

  # disable all branches, then reenable only the used ones
  chain.SetBranchStatus("*", 0)
  for branch in activeBranches:
    chain.SetBranchStatus(branch, 1)


  # prepare prescale tables
  if opzioni.isData:
    prescaleTables={}
    prescaleTables["32"] = Prescales("data/prescalesRun2022FG_HLT_BTagMu_AK4DiJet20_Mu5.txt")
    prescaleTables["33"] = Prescales("data/prescalesRun2022FG_HLT_BTagMu_AK4DiJet40_Mu5.txt")
    prescaleTables["34"] = Prescales("data/prescalesRun2022FG_HLT_BTagMu_AK4DiJet70_Mu5.txt")
    prescaleTables["35"] = Prescales("data/prescalesRun2022FG_HLT_BTagMu_AK4DiJet110_Mu5.txt")
    prescaleTables["36"] = Prescales("data/prescalesRun2022FG_HLT_BTagMu_AK4DiJet170_Mu5.txt")
    prescaleTables["37"] = Prescales("data/prescalesRun2022FG_HLT_BTagMu_AK4Jet300_Mu5.txt")

  else:
    pileup = Pileup(["data/"+opzioni.pufile],
                     [1.],
                     chain)
    crossSection = CrossSection("data/xsectionFilter.txt")                 
  i=0
  passed=0
  for ievent,event in enumerate(chain):
    try:
      #print("**",ievent)
      #if event.Evt != 1614523636 :
      #  continue
      # event weight
     
      weight=1.
      if (not opzioni.isData):
        mcweight = 1.#event.mcweight 
        weight = weight*mcweight
        npv = event.nPU
        npu = event.nPUtrue
        # PU weight
        weight = weight*pileup.getWeight(npu)
        #print ("puweight", pileup.getWeight(npu))
        #print ("xsweight", crossSection.getWeight(chain, float(opzioni.lumi)*1000.))
        # xsec weight
        weight = weight*crossSection.getWeight(chain, float(opzioni.lumi)*1000.)

        #just to be sure, check the main tree and the helper one are in sync
        #if event.Evt != event.Evt_new:  
        #  print("main tree and helper tree are out of sync. Big Problem. Ending now.",event.Evt,event.Evt_new)
        #  sys.exit(1)

      i=i+1
      if (i%1000==0):
        sys.stdout.write("\rprocessing event %d/%d" %(i, chain.GetEntries()))
        sys.stdout.flush()

      # global event selection    
      if not (eventsel(event)): continue
      #print "passed global sel"
      # prepare lists with jets and leptons    
      nJet=event.nJet
      nPFMuon=event.nPFMuon
      jets=[]
      event.associatedMuonIds = []
      #print("This event has", nJet, "jets", event.Evt)#, event.Evt_new
      for IJ in range(nJet):
        event.associatedMuonIds.append(-1)
        #print "gluonSplitting  (Up,Do)", event.gluonSplittingWeightUp[IJ], event.gluonSplittingWeightDo[IJ]  
        #print "bFragmentation  (Up,Do)", event.bFragmentationWeightUp[IJ], event.bFragmentationWeightDo[IJ]  
        #print "cdFragmentation (Up,Do)", event.cdFragmentationWeightUp[IJ], event.cdFragmentationWeightDo[IJ] 
        #print "cFragmentation  (Up,Do)", event.cFragmentationWeightUp[IJ], event.cFragmentationWeightDo[IJ]    
        #print "v0              (Up,Do)", event.v0WeightUp[IJ], event.v0WeightDo[IJ] 
        #print("pt                     ", event.Jet_pT[IJ])
        #print "pt JER          (Up,Do)", event.Jet_pTJERUp[IJ], event.Jet_pTJERDo[IJ]
        #print "pt JES          (Up,Do)", event.Jet_pTJESUp[IJ], event.Jet_pTJESDo[IJ]
        jet=Jet(event,IJ)
        event.associatedMuonIds.append(-1)
        if (jet.fourMomentum.Pt()>20. and abs(jet.fourMomentum.Eta())<2.4):# and jet.Jet_Proba > 0.):
          jets.append(jet)
      #for jet in jets:
      # print(jet.index, jet.fourMomentum.Pt(),jet.fourMomentum.Eta(),jet.Jet_Proba)
      muons=[]
      #print(nPFMuon)
      for IM in range(nPFMuon):
        #print("  ",IM)
        muon=Muon(event,IM)
        if (muon.fourMomentum.Pt()>5. and abs(muon.fourMomentum.Eta()<2.4)):
          muons.append(muon)

      # the following is needed to decide how to 
      # assign pt bins to Triggers
      nJets=[0, 0, 0, 0, 0, 0] 
      nMuJets=[0, 0, 0, 0, 0, 0]
      atLeastOneMatchedMuon=False
      jetsWithMatchedMuons=[]
      for jet in jets:
        #jet.printMe()
        matched=False
        for muon in muons:
          if muon.passMuId() and muon.match(jet):
            #muon.printMe()
            #print "matched"
            jet.associateMuon(muon.index)
            event.associatedMuonIds
            atLeastOneMatchedMuon = True
            matched = True
            event.associatedMuonIds[jet.index] = muon.index
            jetsWithMatchedMuons.append(jet)
            break
            
        if (jet.fourMomentum.Pt()>20. and jet.fourMomentum.Pt()<50): nJets[0]=nJets[0]+1
        if (jet.fourMomentum.Pt()>50. and jet.fourMomentum.Pt()<80): nJets[1]=nJets[1]+1
        if (jet.fourMomentum.Pt()>80. and jet.fourMomentum.Pt()<120): nJets[2]=nJets[2]+1
        if (jet.fourMomentum.Pt()>120. and jet.fourMomentum.Pt()<180): nJets[3]=nJets[3]+1
        if (jet.fourMomentum.Pt()>180. and jet.fourMomentum.Pt()<320): nJets[4]=nJets[4]+1
        if (jet.fourMomentum.Pt()>320.) : nJets[5]=nJets[5]+1
        
        if (jet.fourMomentum.Pt()>20. and jet.fourMomentum.Pt()<50 and matched): nMuJets[0]=nMuJets[0]+1 
        if (jet.fourMomentum.Pt()>50. and jet.fourMomentum.Pt()<80 and matched): nMuJets[1]=nMuJets[1]+1
        if (jet.fourMomentum.Pt()>80. and jet.fourMomentum.Pt()<120 and matched): nMuJets[2]=nMuJets[2]+1
        if (jet.fourMomentum.Pt()>120. and jet.fourMomentum.Pt()<180 and matched): nMuJets[3]=nMuJets[3]+1
        if (jet.fourMomentum.Pt()>180. and jet.fourMomentum.Pt()<320 and matched): nMuJets[4]=nMuJets[4]+1
        if (jet.fourMomentum.Pt()>320. and matched) : nMuJets[5]=nMuJets[5]+1 
        
      if not atLeastOneMatchedMuon: continue
      #for jet in jetsWithMatchedMuons:
      #  print jet.index, jet.fourMomentum.Pt(),jet.fourMomentum.Eta(),jet.Jet_Proba,event.Jet_flavour[jet.index]

      #print "at east one matched muon"
      # trigger selection    
      triggers=[]
      for itrig in range(32, 38):
        if passTrigger(event, itrig) : #and itrig != 34: ##removed 170 for the moment as it was not available for the whole period
          triggers.append(itrig)
      if len(triggers) == 0: continue
      triggerPtBins=[]
      if ( nJets[0] >= 2 and nMuJets[0] >= 1 )  : triggerPtBins.append(32)
      if ( nJets[1] >= 2 and nMuJets[1] >= 1 )  : triggerPtBins.append(33)
      if ( nJets[2] >= 2 and nMuJets[2] >= 1 )  : triggerPtBins.append(34)
      if ( nJets[3] >= 2 and nMuJets[3] >= 1 )  : triggerPtBins.append(35)
      if ( nJets[4] >= 2 and nMuJets[4] >= 1 )  : triggerPtBins.append(36)
      if ( nJets[5] > 0  and nMuJets[5] >= 1 )  : triggerPtBins.append(37)
      #print nJets
      #print nMuJets

      #find matches between triggers that actually fired and pt bins
      matches=set(triggers).intersection(triggerPtBins)
      matches=list(matches)
      #print (triggers, triggerPtBins, matches)
      if len(matches)==0: continue
      #print "triggered"
      if opzioni.isData:
        #get the prescale weight from the first trigger in the list
        #print (">>>>", matches)
        matches.sort(reverse=True)
        #print ("<<<<", matches, event.Run, event.LumiBlock, prescaleTables[str(matches[0])].getPrescaleWeight(event.Run, event.LumiBlock))
        weight = weight*prescaleTables[str(matches[0])].getPrescaleWeight(event.Run, event.LumiBlock)

      passed +=1
      #passedFile += "%6d %6d %10d  %+2d  %+4.2f %+4.2f %+4.2f \n" % (event.Run, event.LumiBlock, event.Evt , event.nJet, jets[0].fourMomentum.Pt(), jets[0].fourMomentum.Eta(), jets[0].fourMomentum.Phi());
      # loop over jets, apply jet specific categorization and fill plots   
      for jet in jetsWithMatchedMuons:
        for cut in list(cuts.keys()):
          if cutFunctions[cut](event, jet.index):
            #if cut == "ptbin_20.0-30.0_l_CombIVFM":
            #  print cuts[cut]
            #  passedFile += "%6d %6d %10d  %+2d  %+4.2f %+4.2f %+4.2f \n" % (event.Run, event.LumiBlock, event.Evt , event.nJet, jet.fourMomentum.Pt(), jet.fourMomentum.Eta(), jet.fourMomentum.Phi())
            for variable in list(variables.keys()): 
              histos[variable][cut]['central'].Fill(variableFunctions[variable](event, jet.index), weight)
              if not opzioni.isData:
                for syst in weightSystematics:
                  weightup = weightSystematicsFunctionsUp[syst](event, jet.index)
                  weightdo = weightSystematicsFunctionsDo[syst](event, jet.index)
                  histos[variable][cut][syst+'_up'].Fill(variableFunctions[variable](event, jet.index), weight*weightup)
                  histos[variable][cut][syst+'_do'].Fill(variableFunctions[variable](event, jet.index), weight*weightdo)
          if not opzioni.isData:      
            for syst in shapeSystematics:
              if cutFunctionsUp[syst][cut](event, jet.index):
                for variable in list(variables.keys()):
                  histos[variable][cut][syst+'_up'].Fill(variableFunctionsUp[syst][variable](event, jet.index), weight)
              if cutFunctionsDo[syst][cut](event, jet.index):  
                for variable in list(variables.keys()):
                  histos[variable][cut][syst+'_do'].Fill(variableFunctionsDo[syst][variable](event, jet.index), weight)
    except KeyboardInterrupt:
      print("\nInterrupted")
      break
  print("\n")
  print("Total events processed", i, "; passed", passed)
  outFile.Write()

  print(passedFile)

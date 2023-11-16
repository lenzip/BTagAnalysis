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

ROOT.DisableImplicitMT()

import copy




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
  
  fileList=open(args[0])
  outputFile=args[1]
  print("creating chain...")
  # create a chain with all files in the list
  chain = TChain(opzioni.tree)
  for line in fileList:
    chain.Add(line.rstrip('\n'))
  print("...done")
  fileList.seek(0)

  helperChain = TChain("helper")
  if not opzioni.isData:  
    i=0
    for filename in fileList:  
      helperChain.Add("helper"+str(i)+".root")
      i+=1
    print(chain.GetEntries(), helperChain.GetEntries())
    chain.AddFriend(helperChain)
    print("...done")
  

  #skim the chain according to the gloval event selection
  #print "skimming..."
  #skim(chain, eventsel)
  #print "...done"

  # disable all branches, then reenable only the used ones
  chain.SetBranchStatus("*", 0)
  for branch in activeBranches:
    chain.SetBranchStatus(branch, 1)

  
  i=0
  gInterpreter.Declare('#include "library_rdf.h"')
  df = ROOT.RDataFrame(chain)
  #ROOT.RDF.Experimental.AddProgressBar(df)
  pileup_rdf = None
  if (not opzioni.isData):
    filepu = TFile("data/"+opzioni.pufile)
    dataHistopu = filepu.Get("pileup")
    mcpu = TH1F("mcpu", "mcpu", dataHistopu.GetXaxis().GetNbins(), dataHistopu.GetXaxis().GetXmin(), dataHistopu.GetXaxis().GetXmax())
    chain.Draw("nPUtrue >> mcPU", "", "goff")
    pileup_rdf = RDFHelper.Pileup(dataHistopu, mcpu)
    df = df.Define("my_puweight", pileup_rdf, ["nPUtrue"])
    df = df.DefinePerSample("my_xsecweight", "RDFHelper::getXsectionWeight(rdfslot_, rdfsampleinfo_)")
    df = df.Define("myweight", f"my_puweight*my_xsecweight*{float(opzioni.lumi)}*1000.")
    

  df = df.Filter(eventsel) 

  print (weightSystematics)
  
  for syst in shapeSystematics:
    df = df.Vary("Jet_pT", 'ROOT::RVec<ROOT::RVecF>{Jet_pT'+syst+'Up, Jet_pT'+syst+'Do}', [f'{syst}Up', f'{syst}Do'])

  df = df.Define("good_muon_idx", "RDFHelper::FindGoodMuons(PFMuon_pt, PFMuon_eta)")\
         .Define("good_jet_idx", "RDFHelper::FindGoodJets(Jet_pT, Jet_eta)")\
         .Define("good_matched_jet_idx", "RDFHelper::FindMatchedJets(Take(Jet_eta, good_jet_idx), Take(Jet_phi, good_jet_idx), Take(PFMuon_eta, good_muon_idx), Take(PFMuon_phi, good_muon_idx))")\
         .Filter("ROOT::VecOps::Sum(good_jet_idx)>0 && Sum(good_muon_idx)>0") 

  df = df.Define("nJet20", "Sum(Take(Jet_pT, good_jet_idx)>20 && Take(Jet_pT, good_jet_idx)<50)")\
         .Define("nJet50", "Sum(Take(Jet_pT, good_jet_idx)>50 && Take(Jet_pT, good_jet_idx)<80)")\
         .Define("nJet80", "Sum(Take(Jet_pT, good_jet_idx)>80 && Take(Jet_pT, good_jet_idx)<120)")\
         .Define("nJet120", "Sum(Take(Jet_pT, good_jet_idx)>120 && Take(Jet_pT, good_jet_idx)<180)")\
         .Define("nJet180", "Sum(Take(Jet_pT, good_jet_idx)>180 && Take(Jet_pT, good_jet_idx)<320)")\
         .Define("nJet320", "Sum(Take(Jet_pT, good_jet_idx)>320)")\
         .Define("nMuJet20", "Sum(Take(Jet_pT, good_matched_jet_idx)>20 && Take(Jet_pT, good_matched_jet_idx)<50)")\
         .Define("nMuJet50", "Sum(Take(Jet_pT, good_matched_jet_idx)>50 && Take(Jet_pT, good_matched_jet_idx)<80)")\
         .Define("nMuJet80", "Sum(Take(Jet_pT, good_matched_jet_idx)>80 && Take(Jet_pT, good_matched_jet_idx)<120)")\
         .Define("nMuJet120", "Sum(Take(Jet_pT, good_matched_jet_idx)>120 && Take(Jet_pT, good_matched_jet_idx)<180)")\
         .Define("nMuJet180", "Sum(Take(Jet_pT, good_matched_jet_idx)>180 && Take(Jet_pT, good_matched_jet_idx)<320)")\
         .Define("nMuJet320", "Sum(Take(Jet_pT, good_matched_jet_idx)>320)")
        

  df_final = df.Define("triggers", "RDFHelper::GetTriggersFires(BitTrigger)")\
         .Define("triggerPtBins", "RDFHelper::GetTriggerPtBins(nJet20, nJet50, nJet80, nJet120, nJet180, nJet320, nMuJet20, nMuJet50, nMuJet80, nMuJet120, nMuJet180, nMuJet320)")\
         .Define("triggerMatches", "Reverse(Sort(Intersect(triggers, triggerPtBins)))").Filter("triggerMatches.size()>0")
  


  if (opzioni.isData):
    prescales = RDFHelper.Prescale()
    prescales.load(32, "data/prescalesRun2022FG_HLT_BTagMu_AK4DiJet20_Mu5.txt")
    prescales.load(33, "data/prescalesRun2022FG_HLT_BTagMu_AK4DiJet40_Mu5.txt")
    prescales.load(34, "data/prescalesRun2022FG_HLT_BTagMu_AK4DiJet70_Mu5.txt")
    prescales.load(35, "data/prescalesRun2022FG_HLT_BTagMu_AK4DiJet110_Mu5.txt")
    prescales.load(36, "data/prescalesRun2022FG_HLT_BTagMu_AK4DiJet170_Mu5.txt")
    prescales.load(37, "data/prescalesRun2022FG_HLT_BTagMu_AK4Jet300_Mu5.txt")
    df_final = df.Define("myweight", prescales, ['triggerMatches', 'Run', 'LumiBlock'])
  
  for branch in set(activeBranches):
    if "Jet_" in branch or "TagVarCSV" in branch:
      df_final = df_final.Define("Good"+branch, f"Take({branch},good_matched_jet_idx)")
  df_final = df_final.Define("myweight_vector", 'ROOT::RVecF(good_matched_jet_idx.size(), myweight)')
  for syst in weightSystematics:
    df_final = df_final.Vary("myweight_vector", 'ROOT::RVec<ROOT::RVecF>{myweight_vector*Take('+syst+'WeightUp, good_matched_jet_idx), myweight_vector*Take('+syst+'WeightDo, good_matched_jet_idx)}', [f'{syst}Up', f'{syst}Do'])
    
  

  outFile = TFile(outputFile, "RECREATE")
  outFile.cd()
  #histosvars = []
  
  histos = []
  histosWithVariations = []
  for cut in list(cuts.keys()):
      maskname = f"{cut}_mask"
      #df_final = df_final.Define(f"{cut}_mask", cuts[cut])
      #df_final = df_final.Define('myweight_vector_'+cut, f"myweight_vector[{maskname}]")
      for variable in list(variables.keys()):
        name_column_for_fill = f"{variable}__{cut}" 
        h = df_final.Define(f"{cut}_mask", cuts[cut]).\
                     Define(name_column_for_fill, variables[variable]['expression'].replace('mask', maskname)).\
                     Define('myweight_vector_'+cut, f"myweight_vector[{maskname}]").\
                     Histo1D((name_column_for_fill, name_column_for_fill, 
                        variables[variable]['nbins'], variables[variable]['xmin'], variables[variable]['xmax']), 
                        name_column_for_fill, 'myweight_vector_'+cut)
        histosWithVariations.append(h)
  for h in histosWithVariations:  
    hvar = ROOT.RDF.Experimental.VariationsFor(h)
    for label in hvar.GetKeys():
      if "nominal" in str(label):
        newname = hvar[label].GetName()
      else:   
        newname = hvar[label].GetName()+str(label).replace(":", "")
      hvar[label].SetNameTitle(newname, newname)
      hvar[label].Write()        
  ROOT.RDF.SaveGraph(ROOT.RDF.AsRNode(df_final), "./mydot.dot")
  
  outFile.Close()                                 
  
  

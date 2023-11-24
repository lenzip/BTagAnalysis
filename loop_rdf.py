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
  parser.add_option("-b", action="store_true", help="batch mode (default=False)", default=False, dest="batch")
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

  """
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
  """  
  i=0
  gInterpreter.Declare('#include "library_rdf.h"')
  df = ROOT.RDataFrame(chain)
  #ROOT.RDF.Experimental.AddProgressBar(df)
  pileup_rdf = None
  if (not opzioni.isData):
    filepu = TFile("data/"+opzioni.pufile)
    dataHistopu = filepu.Get("pileup")
    mcpu = TH1F("mcpu", "mcpu", dataHistopu.GetXaxis().GetNbins(), dataHistopu.GetXaxis().GetXmin(), dataHistopu.GetXaxis().GetXmax())
    chain.Draw("nPUtrue >> mcpu", "", "goff")
    pileup_rdf = RDFHelper.Pileup(dataHistopu, mcpu)
    df = df.Define("my_puweight", pileup_rdf, ["nPUtrue"]).\
             DefinePerSample("my_xsecweight", "RDFHelper::getXsectionWeight(rdfslot_, rdfsampleinfo_)").\
             Define("myweight", f"my_puweight*my_xsecweight*{float(opzioni.lumi)}*1000.")
    

  df = df.Filter(eventsel) 

  print (weightSystematics)
  if (not opzioni.isData):
    for syst in shapeSystematics:
      df = df.Vary("Jet_pT", 'ROOT::RVec<ROOT::RVecF>{Jet_pT'+syst+'Up, Jet_pT'+syst+'Do}', [f'{syst}_up', f'{syst}_do'])

  df = df.Define("good_muon_idx", "RDFHelper::FindGoodMuons(PFMuon_pt, PFMuon_eta)")\
         .Define("good_jet_idx", "RDFHelper::FindGoodJets(Jet_pT, Jet_eta)")\
         .Define("good_matched_jet_idx", "RDFHelper::FindMatchedJets(Take(Jet_eta, good_jet_idx), Take(Jet_phi, good_jet_idx), Take(PFMuon_eta, good_muon_idx), Take(PFMuon_phi, good_muon_idx))")\
         .Filter("ROOT::VecOps::Sum(good_jet_idx)>0 && Sum(good_muon_idx)>0")\
         .Define("nJet20", "Sum(Take(Jet_pT, good_jet_idx)>20 && Take(Jet_pT, good_jet_idx)<50)")\
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
         .Define("nMuJet320", "Sum(Take(Jet_pT, good_matched_jet_idx)>320)")\
         .Define("triggers", "RDFHelper::GetTriggersFires(BitTrigger)")\
         .Define("triggerPtBins", "RDFHelper::GetTriggerPtBins(nJet20, nJet50, nJet80, nJet120, nJet180, nJet320, nMuJet20, nMuJet50, nMuJet80, nMuJet120, nMuJet180, nMuJet320)")\
         .Define("triggerMatches", "Reverse(Sort(Intersect(triggers, triggerPtBins)))")
  
  df = df.Filter("triggerMatches.size()>0")
  
  #df.Display(["triggers", "triggerPtBins", "triggerMatches"]).Print()

  if (opzioni.isData):
    prescales = RDFHelper.Prescale()
    prescales.load(32, "data/prescalesRun2022FG_HLT_BTagMu_AK4DiJet20_Mu5.txt")
    prescales.load(33, "data/prescalesRun2022FG_HLT_BTagMu_AK4DiJet40_Mu5.txt")
    prescales.load(34, "data/prescalesRun2022FG_HLT_BTagMu_AK4DiJet70_Mu5.txt")
    prescales.load(35, "data/prescalesRun2022FG_HLT_BTagMu_AK4DiJet110_Mu5.txt")
    prescales.load(36, "data/prescalesRun2022FG_HLT_BTagMu_AK4DiJet170_Mu5.txt")
    prescales.load(37, "data/prescalesRun2022FG_HLT_BTagMu_AK4Jet300_Mu5.txt")
    df = df.Define("myweight", prescales, ['triggerMatches', 'Run', 'LumiBlock'])
    df.Display(["triggerMatches", "Run", "LumiBlock", "myweight"]).Print()
  for branch in set(activeBranches):
    if "Jet_" in branch or "TagVarCSV" in branch:
      if "Jet_flavour" in branch and opzioni.isData:
        continue
      df = df.Define("Good"+branch, f"Take({branch},good_matched_jet_idx)")
  df = df.Define("myweight_vector", 'ROOT::RVecF(good_matched_jet_idx.size(), myweight)')
  if not opzioni.isData:
    for syst in weightSystematics:
      df = df.Vary("myweight_vector", 'ROOT::RVec<ROOT::RVecF>{myweight_vector*Take('+syst+'WeightUp, good_matched_jet_idx), myweight_vector*Take('+syst+'WeightDo, good_matched_jet_idx)}', [f'{syst}_up', f'{syst}_do'])

  outFile = TFile(outputFile, "RECREATE")
  outFile.cd()
  #histosvars = []
  #df.Display(["my_puweight", "my_xsecweight", "myweight", "myweight_vector"]).Print()
  histos = []
  histosWithVariations = []
  #ROOT.RDF.Experimental.AddProgressBar(ROOT.RDF.AsRNode(df))
  for cut in list(cuts.keys()):
      maskname = f"{cut}_mask"
      dfi = df.Define(f"{cut}_mask", cuts[cut])
      dfi = dfi.Define('myweight_vector_'+cut, f"myweight_vector[{maskname}]")
      for variable in list(variables.keys()):
        name_column_for_fill = f"{variable}__{cut}" 
        h = dfi.Define(name_column_for_fill, variables[variable]['expression'].replace('mask', maskname)).\
               Histo1D((name_column_for_fill, name_column_for_fill, 
                        variables[variable]['nbins'], variables[variable]['xmin'], variables[variable]['xmax']), 
                        name_column_for_fill, 'myweight_vector_'+cut)
        histosWithVariations.append(h)
  gInterpreter.Declare("""
    const UInt_t barWidth = 60;
    ULong64_t processed = 0, totalEvents = 0;
    std::string progressBar;
    std::mutex barMutex;
    auto registerEvents = [](ULong64_t nIncrement) {totalEvents += nIncrement;};

    ROOT::RDF::RResultPtr<ULong64_t> AddProgressBar(ROOT::RDF::RNode df, int everyN=10000, int totalN=100000) {
        registerEvents(totalN);
        auto c = df.Count();
        c.OnPartialResultSlot(everyN, [everyN] (unsigned int slot, ULong64_t &cnt){
            std::lock_guard<std::mutex> l(barMutex);
            processed += everyN; //everyN captured by value for this lambda
            progressBar = "[";
            for(UInt_t i = 0; i < static_cast<UInt_t>(static_cast<Float_t>(processed)/totalEvents*barWidth); ++i){
                progressBar.push_back('|');
            }
            // escape the '\' when defined in python string
            std::cout << "\\r" << std::left << std::setw(barWidth) << progressBar << "] " << processed << "/" << totalEvents << std::flush;
        });
        return c;
    }
  """)
  if (not opzioni.batch):
    counts_1 = AddProgressBar(ROOT.RDF.AsRNode(df), max(100, int(chain.GetEntries()/5000)), int(chain.GetEntries()))
  #ROOT.RDF.Experimental.AddProgressBar(ROOT.RDF.AsRNode(df))
  hvars = [ROOT.RDF.Experimental.VariationsFor(h) for h in histosWithVariations]
  for hvar in hvars:
    for label in hvar.GetKeys():
      if "nominal" in str(label):
        newname = hvar[label].GetName()
      else:   
        newname = hvar[label].GetName()+"_"+str(label).split(':')[-1]
        hvar[label].SetNameTitle(newname, newname)
      hvar[label].Write()                
  ROOT.RDF.SaveGraph(ROOT.RDF.AsRNode(df), "./mydot.dot")
  '''
  for h in histos:
    h.Write()
  for h in histosWithVariations:  
    hvar = ROOT.RDF.Experimental.VariationsFor(h)
    for label in hvar.GetKeys():
      if "nominal" in str(label):
        newname = hvar[label].GetName()
      else:   
        newname = hvar[label].GetName()+str(label).replace(":", "")
      hvar[label].SetNameTitle(newname, newname)
      hvar[label].Write()
  #ROOT.RDF.SaveGraph(df, "./mydot.dot");
  '''
  """  
  ROOT.RDF.SaveGraph(df, "./mydot.dot");
  for histo in histos:
    hvar = ROOT.RDF.Experimental.VariationsFor(histo)
    #print (histo.GetKeys())
    for h in hvar.GetKeys():
      hvar[h].Write()

  """    
  outFile.Close()                                 
  """
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
  """

  

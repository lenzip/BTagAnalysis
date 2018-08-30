#!/bin/bash

#30-inf 
#python plotStack2.py plots_ptgt30/QCD_MuEnriched.root plots_ptgt30/Run2017D.root MuPt "ptbin_30.0-1000.0" "" 1
#python plotStack2.py plots_ptgt30/QCD_MuEnriched.root plots_ptgt30/Run2017D.root nPV  "ptbin_30.0-1000.0" "" 1
#python plotStack2.py plots_ptgt30/QCD_MuEnriched.root plots_ptgt30/Run2017D.root PT   "ptbin_30.0-1000.0" "" 1
#python plotStack2.py plots_ptgt30/QCD_MuEnriched.root plots_ptgt30/Run2017D.root ETA  "ptbin_30.0-1000.0" "" 1
#python plotStack2.py plots_ptgt30/QCD_MuEnriched.root plots_ptgt30/Run2017D.root JP   "ptbin_30.0-1000.0" "" 1
#
#python plotStack2.py plots_ptgt30/QCD_MuEnriched.root plots_ptgt30/Run2017D.root MuPt "ptbin_30.0-1000.0" "_DeepCSVBDiscL" 1
#python plotStack2.py plots_ptgt30/QCD_MuEnriched.root plots_ptgt30/Run2017D.root nPV  "ptbin_30.0-1000.0" "_DeepCSVBDiscL" 1
#python plotStack2.py plots_ptgt30/QCD_MuEnriched.root plots_ptgt30/Run2017D.root PT   "ptbin_30.0-1000.0" "_DeepCSVBDiscL" 1
#python plotStack2.py plots_ptgt30/QCD_MuEnriched.root plots_ptgt30/Run2017D.root ETA  "ptbin_30.0-1000.0" "_DeepCSVBDiscL" 1
#python plotStack2.py plots_ptgt30/QCD_MuEnriched.root plots_ptgt30/Run2017D.root JP   "ptbin_30.0-1000.0" "_DeepCSVBDiscL" 1
#
##20-inf
#python plotStack2.py plots_mc_runBCDEF_test/QCD_MuEnriched.root plots_data_test/Run2017.root plots_data_test/Run2017.root SVmass "ptbin_20.0-1000.0" "" 1
#python plotStack2.py plots_mc_runBCDEF_test/QCD_MuEnriched.root plots_data_test/Run2017.root plots_data_test/Run2017.root SVmass "ptbin_20.0-1000.0" "_DeepCSVBDiscL" 1
#python plotStack2.py plots_mc_runBCDEF_test/QCD_MuEnriched.root plots_data_test/Run2017.root plots_data_test/Run2017.root SVmass "ptbin_20.0-1000.0" "_DeepCSVBDiscM" 1
#python plotStack2.py plots_mc_runBCDEF_test/QCD_MuEnriched.root plots_data_test/Run2017.root plots_data_test/Run2017.root SVmass "ptbin_20.0-1000.0" "_DeepCSVBDiscT" 1
#python plotStack2.py plots_ptgt20/QCD_MuEnriched.root plots_ptgt20/Run2017D.root nPV  "ptbin_20.0-1000.0" "" 1
#python plotStack2.py plots_ptgt20/QCD_MuEnriched.root plots_ptgt20/Run2017D.root PT   "ptbin_20.0-1000.0" "" 1
#python plotStack2.py plots_ptgt20/QCD_MuEnriched.root plots_ptgt20/Run2017D.root ETA  "ptbin_20.0-1000.0" "" 1
#python plotStack2.py plots_ptgt20/QCD_MuEnriched.root plots_ptgt20/Run2017D.root JP   "ptbin_20.0-1000.0" "" 1
#
#python plotStack2.py plots_ptgt20/QCD_MuEnriched.root plots_ptgt20/Run2017D.root MuPt "ptbin_20.0-1000.0" "_DeepCSVBDiscL" 1
#python plotStack2.py plots_ptgt20/QCD_MuEnriched.root plots_ptgt20/Run2017D.root nPV  "ptbin_20.0-1000.0" "_DeepCSVBDiscL" 1
#python plotStack2.py plots_ptgt20/QCD_MuEnriched.root plots_ptgt20/Run2017D.root PT   "ptbin_20.0-1000.0" "_DeepCSVBDiscL" 1
#python plotStack2.py plots_ptgt20/QCD_MuEnriched.root plots_ptgt20/Run2017D.root ETA  "ptbin_20.0-1000.0" "_DeepCSVBDiscL" 1
#python plotStack2.py plots_ptgt20/QCD_MuEnriched.root plots_ptgt20/Run2017D.root JP   "ptbin_20.0-1000.0" "_DeepCSVBDiscL" 1

#20-30
python plotStack2.py plots_mc_runBCDEF_test2/QCD_MuEnriched.root plots_data_test2/Run2017.root plots_data_test2/Run2017.root MuPtOverJetPt "ptbin_20.0-30.0" "" 1
python plotStack2.py plots_mc_runBCDEF_test2/QCD_MuEnriched.root plots_data_test2/Run2017.root plots_data_test2/Run2017.root SVmass "ptbin_20.0-30.0" "" 1
#python plotStack2.py plots_mc_runBCDEF_test2/QCD_MuEnriched.root plots_data_test2/Run2017.root plots_data_test2/Run2017.root nPV  "ptbin_20.0-30.0" "" 1
#python plotStack2.py plots_mc_runBCDEF_test2/QCD_MuEnriched.root plots_data_test2/Run2017.root plots_data_test2/Run2017.root PT   "ptbin_20.0-30.0" "" 1
#python plotStack2.py plots_mc_runBCDEF_test2/QCD_MuEnriched.root plots_data_test2/Run2017.root plots_data_test2/Run2017.root ETA  "ptbin_20.0-30.0" "" 1
#python plotStack2.py plots_mc_runBCDEF_test2/QCD_MuEnriched.root plots_data_test2/Run2017.root plots_data_test2/Run2017.root JP   "ptbin_20.0-30.0" "" 1
#
python plotStack2.py plots_mc_runBCDEF_test2/QCD_MuEnriched.root plots_data_test2/Run2017.root plots_data_test2/Run2017.root MuPtOverJetPt "ptbin_20.0-30.0" "_DeepCSVBDiscL" 1
python plotStack2.py plots_mc_runBCDEF_test2/QCD_MuEnriched.root plots_data_test2/Run2017.root plots_data_test2/Run2017.root SVmass "ptbin_20.0-30.0" "_DeepCSVBDiscL" 1
#python plotStack2.py plots_mc_runBCDEF_test2/QCD_MuEnriched.root plots_data_test2/Run2017.root plots_data_test2/Run2017.root nPV  "ptbin_20.0-30.0" "_DeepCSVBDiscL" 1
#python plotStack2.py plots_mc_runBCDEF_test2/QCD_MuEnriched.root plots_data_test2/Run2017.root plots_data_test2/Run2017.root PT   "ptbin_20.0-30.0" "_DeepCSVBDiscL" 1
#python plotStack2.py plots_mc_runBCDEF_test2/QCD_MuEnriched.root plots_data_test2/Run2017.root plots_data_test2/Run2017.root ETA  "ptbin_20.0-30.0" "_DeepCSVBDiscL" 1
#python plotStack2.py plots_mc_runBCDEF_test2/QCD_MuEnriched.root plots_data_test2/Run2017.root plots_data_test2/Run2017.root JP   "ptbin_20.0-30.0" "_DeepCSVBDiscL" 1
#
##30-50
python plotStack2.py plots_mc_runBCDEF_test2/QCD_MuEnriched.root plots_data_test2/Run2017.root plots_data_test2/Run2017.root MuPtOverJetPt "ptbin_30.0-50.0" "" 1 
python plotStack2.py plots_mc_runBCDEF_test2/QCD_MuEnriched.root plots_data_test2/Run2017.root plots_data_test2/Run2017.root SVmass "ptbin_30.0-50.0" "" 1 
#python plotStack2.py plots_mc_runBCDEF_test2/QCD_MuEnriched.root plots_data_test2/Run2017.root plots_data_test2/Run2017.root nPV  "ptbin_30.0-50.0" "" 1 
#python plotStack2.py plots_mc_runBCDEF_test2/QCD_MuEnriched.root plots_data_test2/Run2017.root plots_data_test2/Run2017.root PT   "ptbin_30.0-50.0" "" 1 
#python plotStack2.py plots_mc_runBCDEF_test2/QCD_MuEnriched.root plots_data_test2/Run2017.root plots_data_test2/Run2017.root ETA  "ptbin_30.0-50.0" "" 1 
#python plotStack2.py plots_mc_runBCDEF_test2/QCD_MuEnriched.root plots_data_test2/Run2017.root plots_data_test2/Run2017.root JP   "ptbin_30.0-50.0" "" 1 
#
python plotStack2.py plots_mc_runBCDEF_test2/QCD_MuEnriched.root plots_data_test2/Run2017.root plots_data_test2/Run2017.root MuPtOverJetPt "ptbin_30.0-50.0" "_DeepCSVBDiscL" 1 
python plotStack2.py plots_mc_runBCDEF_test2/QCD_MuEnriched.root plots_data_test2/Run2017.root plots_data_test2/Run2017.root SVmass "ptbin_30.0-50.0" "_DeepCSVBDiscL" 1 
#python plotStack2.py plots_mc_runBCDEF_test2/QCD_MuEnriched.root plots_data_test2/Run2017.root plots_data_test2/Run2017.root nPV  "ptbin_30.0-50.0" "_DeepCSVBDiscL" 1 
#python plotStack2.py plots_mc_runBCDEF_test2/QCD_MuEnriched.root plots_data_test2/Run2017.root plots_data_test2/Run2017.root PT   "ptbin_30.0-50.0" "_DeepCSVBDiscL" 1 
#python plotStack2.py plots_mc_runBCDEF_test2/QCD_MuEnriched.root plots_data_test2/Run2017.root plots_data_test2/Run2017.root ETA  "ptbin_30.0-50.0" "_DeepCSVBDiscL" 1 
#python plotStack2.py plots_mc_runBCDEF_test2/QCD_MuEnriched.root plots_data_test2/Run2017.root plots_data_test2/Run2017.root JP   "ptbin_30.0-50.0" "_DeepCSVBDiscL" 1
#
##50-70
python plotStack2.py plots_mc_runBCDEF_test2/QCD_MuEnriched.root plots_data_test2/Run2017.root plots_data_test2/Run2017.root MuPtOverJetPt "ptbin_50.0-70.0" "" 1
python plotStack2.py plots_mc_runBCDEF_test2/QCD_MuEnriched.root plots_data_test2/Run2017.root plots_data_test2/Run2017.root SVmass "ptbin_50.0-70.0" "" 1
#python plotStack2.py plots_mc_runBCDEF_test2/QCD_MuEnriched.root plots_data_test2/Run2017.root plots_data_test2/Run2017.root nPV  "ptbin_50.0-70.0" "" 1
#python plotStack2.py plots_mc_runBCDEF_test2/QCD_MuEnriched.root plots_data_test2/Run2017.root plots_data_test2/Run2017.root PT   "ptbin_50.0-70.0" "" 1
#python plotStack2.py plots_mc_runBCDEF_test2/QCD_MuEnriched.root plots_data_test2/Run2017.root plots_data_test2/Run2017.root ETA  "ptbin_50.0-70.0" "" 1
#python plotStack2.py plots_mc_runBCDEF_test2/QCD_MuEnriched.root plots_data_test2/Run2017.root plots_data_test2/Run2017.root JP   "ptbin_50.0-70.0" "" 1
#
python plotStack2.py plots_mc_runBCDEF_test2/QCD_MuEnriched.root plots_data_test2/Run2017.root plots_data_test2/Run2017.root MuPtOverJetPt "ptbin_50.0-70.0" "_DeepCSVBDiscL" 1
python plotStack2.py plots_mc_runBCDEF_test2/QCD_MuEnriched.root plots_data_test2/Run2017.root plots_data_test2/Run2017.root SVmass "ptbin_50.0-70.0" "_DeepCSVBDiscL" 1
#python plotStack2.py plots_mc_runBCDEF_test2/QCD_MuEnriched.root plots_data_test2/Run2017.root plots_data_test2/Run2017.root nPV  "ptbin_50.0-70.0" "_DeepCSVBDiscL" 1
#python plotStack2.py plots_mc_runBCDEF_test2/QCD_MuEnriched.root plots_data_test2/Run2017.root plots_data_test2/Run2017.root PT   "ptbin_50.0-70.0" "_DeepCSVBDiscL" 1
#python plotStack2.py plots_mc_runBCDEF_test2/QCD_MuEnriched.root plots_data_test2/Run2017.root plots_data_test2/Run2017.root ETA  "ptbin_50.0-70.0" "_DeepCSVBDiscL" 1
#python plotStack2.py plots_mc_runBCDEF_test2/QCD_MuEnriched.root plots_data_test2/Run2017.root plots_data_test2/Run2017.root JP   "ptbin_50.0-70.0" "_DeepCSVBDiscL" 1
#
##70-100
python plotStack2.py plots_mc_runBCDEF_test2/QCD_MuEnriched.root plots_data_test2/Run2017.root plots_data_test2/Run2017.root MuPtOverJetPt "ptbin_70.0-100.0" "" 1
python plotStack2.py plots_mc_runBCDEF_test2/QCD_MuEnriched.root plots_data_test2/Run2017.root plots_data_test2/Run2017.root SVmass "ptbin_70.0-100.0" "" 1
#python plotStack2.py plots_mc_runBCDEF_test2/QCD_MuEnriched.root plots_data_test2/Run2017.root plots_data_test2/Run2017.root nPV  "ptbin_70.0-100.0" "" 1
#python plotStack2.py plots_mc_runBCDEF_test2/QCD_MuEnriched.root plots_data_test2/Run2017.root plots_data_test2/Run2017.root PT   "ptbin_70.0-100.0" "" 1
#python plotStack2.py plots_mc_runBCDEF_test2/QCD_MuEnriched.root plots_data_test2/Run2017.root plots_data_test2/Run2017.root ETA  "ptbin_70.0-100.0" "" 1
#python plotStack2.py plots_mc_runBCDEF_test2/QCD_MuEnriched.root plots_data_test2/Run2017.root plots_data_test2/Run2017.root JP   "ptbin_70.0-100.0" "" 1
#
python plotStack2.py plots_mc_runBCDEF_test2/QCD_MuEnriched.root plots_data_test2/Run2017.root plots_data_test2/Run2017.root MuPtOverJetPt "ptbin_70.0-100.0" "_DeepCSVBDiscL" 1
python plotStack2.py plots_mc_runBCDEF_test2/QCD_MuEnriched.root plots_data_test2/Run2017.root plots_data_test2/Run2017.root SVmass "ptbin_70.0-100.0" "_DeepCSVBDiscL" 1
#python plotStack2.py plots_mc_runBCDEF_test2/QCD_MuEnriched.root plots_data_test2/Run2017.root plots_data_test2/Run2017.root nPV  "ptbin_70.0-100.0" "_DeepCSVBDiscL" 1
#python plotStack2.py plots_mc_runBCDEF_test2/QCD_MuEnriched.root plots_data_test2/Run2017.root plots_data_test2/Run2017.root PT   "ptbin_70.0-100.0" "_DeepCSVBDiscL" 1
#python plotStack2.py plots_mc_runBCDEF_test2/QCD_MuEnriched.root plots_data_test2/Run2017.root plots_data_test2/Run2017.root ETA  "ptbin_70.0-100.0" "_DeepCSVBDiscL" 1
#python plotStack2.py plots_mc_runBCDEF_test2/QCD_MuEnriched.root plots_data_test2/Run2017.root plots_data_test2/Run2017.root JP   "ptbin_70.0-100.0" "_DeepCSVBDiscL" 1
#
##100-140
python plotStack2.py plots_mc_runBCDEF_test2/QCD_MuEnriched.root plots_data_test2/Run2017.root plots_data_test2/Run2017.root MuPtOverJetPt "ptbin_100.0-140.0" "" 1
python plotStack2.py plots_mc_runBCDEF_test2/QCD_MuEnriched.root plots_data_test2/Run2017.root plots_data_test2/Run2017.root SVmass "ptbin_100.0-140.0" "" 1
#python plotStack2.py plots_mc_runBCDEF_test2/QCD_MuEnriched.root plots_data_test2/Run2017.root plots_data_test2/Run2017.root nPV  "ptbin_100.0-140.0" "" 1
#python plotStack2.py plots_mc_runBCDEF_test2/QCD_MuEnriched.root plots_data_test2/Run2017.root plots_data_test2/Run2017.root PT   "ptbin_100.0-140.0" "" 1
#python plotStack2.py plots_mc_runBCDEF_test2/QCD_MuEnriched.root plots_data_test2/Run2017.root plots_data_test2/Run2017.root ETA  "ptbin_100.0-140.0" "" 1
#python plotStack2.py plots_mc_runBCDEF_test2/QCD_MuEnriched.root plots_data_test2/Run2017.root plots_data_test2/Run2017.root JP   "ptbin_100.0-140.0" "" 1
#
python plotStack2.py plots_mc_runBCDEF_test2/QCD_MuEnriched.root plots_data_test2/Run2017.root plots_data_test2/Run2017.root MuPtOverJetPt "ptbin_100.0-140.0" "_DeepCSVBDiscL" 1
python plotStack2.py plots_mc_runBCDEF_test2/QCD_MuEnriched.root plots_data_test2/Run2017.root plots_data_test2/Run2017.root SVmass "ptbin_100.0-140.0" "_DeepCSVBDiscL" 1
#python plotStack2.py plots_mc_runBCDEF_test2/QCD_MuEnriched.root plots_data_test2/Run2017.root plots_data_test2/Run2017.root nPV  "ptbin_100.0-140.0" "_DeepCSVBDiscL" 1
#python plotStack2.py plots_mc_runBCDEF_test2/QCD_MuEnriched.root plots_data_test2/Run2017.root plots_data_test2/Run2017.root PT   "ptbin_100.0-140.0" "_DeepCSVBDiscL" 1
#python plotStack2.py plots_mc_runBCDEF_test2/QCD_MuEnriched.root plots_data_test2/Run2017.root plots_data_test2/Run2017.root ETA  "ptbin_100.0-140.0" "_DeepCSVBDiscL" 1
#python plotStack2.py plots_mc_runBCDEF_test2/QCD_MuEnriched.root plots_data_test2/Run2017.root plots_data_test2/Run2017.root JP   "ptbin_100.0-140.0" "_DeepCSVBDiscL" 1
#
##140-200
python plotStack2.py plots_mc_runBCDEF_test2/QCD_MuEnriched.root plots_data_test2/Run2017.root plots_data_test2/Run2017.root MuPtOverJetPt "ptbin_140.0-200.0" "" 1
python plotStack2.py plots_mc_runBCDEF_test2/QCD_MuEnriched.root plots_data_test2/Run2017.root plots_data_test2/Run2017.root SVmass "ptbin_140.0-200.0" "" 1
#python plotStack2.py plots_mc_runBCDEF_test2/QCD_MuEnriched.root plots_data_test2/Run2017.root plots_data_test2/Run2017.root nPV  "ptbin_140.0-200.0" "" 1
#python plotStack2.py plots_mc_runBCDEF_test2/QCD_MuEnriched.root plots_data_test2/Run2017.root plots_data_test2/Run2017.root PT   "ptbin_140.0-200.0" "" 1
#python plotStack2.py plots_mc_runBCDEF_test2/QCD_MuEnriched.root plots_data_test2/Run2017.root plots_data_test2/Run2017.root ETA  "ptbin_140.0-200.0" "" 1
#python plotStack2.py plots_mc_runBCDEF_test2/QCD_MuEnriched.root plots_data_test2/Run2017.root plots_data_test2/Run2017.root JP   "ptbin_140.0-200.0" "" 1
#
python plotStack2.py plots_mc_runBCDEF_test2/QCD_MuEnriched.root plots_data_test2/Run2017.root plots_data_test2/Run2017.root MuPtOverJetPt "ptbin_140.0-200.0" "_DeepCSVBDiscL" 1
python plotStack2.py plots_mc_runBCDEF_test2/QCD_MuEnriched.root plots_data_test2/Run2017.root plots_data_test2/Run2017.root SVmass "ptbin_140.0-200.0" "_DeepCSVBDiscL" 1
#python plotStack2.py plots_mc_runBCDEF_test2/QCD_MuEnriched.root plots_data_test2/Run2017.root plots_data_test2/Run2017.root nPV  "ptbin_140.0-200.0" "_DeepCSVBDiscL" 1
#python plotStack2.py plots_mc_runBCDEF_test2/QCD_MuEnriched.root plots_data_test2/Run2017.root plots_data_test2/Run2017.root PT   "ptbin_140.0-200.0" "_DeepCSVBDiscL" 1
#python plotStack2.py plots_mc_runBCDEF_test2/QCD_MuEnriched.root plots_data_test2/Run2017.root plots_data_test2/Run2017.root ETA  "ptbin_140.0-200.0" "_DeepCSVBDiscL" 1
#python plotStack2.py plots_mc_runBCDEF_test2/QCD_MuEnriched.root plots_data_test2/Run2017.root plots_data_test2/Run2017.root JP   "ptbin_140.0-200.0" "_DeepCSVBDiscL" 1
#
##200-300
python plotStack2.py plots_mc_runBCDEF_test2/QCD_MuEnriched.root plots_data_test2/Run2017.root plots_data_test2/Run2017.root MuPtOverJetPt "ptbin_200.0-300.0" "" 1
python plotStack2.py plots_mc_runBCDEF_test2/QCD_MuEnriched.root plots_data_test2/Run2017.root plots_data_test2/Run2017.root SVmass "ptbin_200.0-300.0" "" 1
#python plotStack2.py plots_mc_runBCDEF_test2/QCD_MuEnriched.root plots_data_test2/Run2017.root plots_data_test2/Run2017.root nPV  "ptbin_200.0-300.0" "" 1
#python plotStack2.py plots_mc_runBCDEF_test2/QCD_MuEnriched.root plots_data_test2/Run2017.root plots_data_test2/Run2017.root PT   "ptbin_200.0-300.0" "" 1
#python plotStack2.py plots_mc_runBCDEF_test2/QCD_MuEnriched.root plots_data_test2/Run2017.root plots_data_test2/Run2017.root ETA  "ptbin_200.0-300.0" "" 1
#python plotStack2.py plots_mc_runBCDEF_test2/QCD_MuEnriched.root plots_data_test2/Run2017.root plots_data_test2/Run2017.root JP   "ptbin_200.0-300.0" "" 1
#
python plotStack2.py plots_mc_runBCDEF_test2/QCD_MuEnriched.root plots_data_test2/Run2017.root plots_data_test2/Run2017.root MuPtOverJetPt "ptbin_200.0-300.0" "_DeepCSVBDiscL" 1
python plotStack2.py plots_mc_runBCDEF_test2/QCD_MuEnriched.root plots_data_test2/Run2017.root plots_data_test2/Run2017.root SVmass "ptbin_200.0-300.0" "_DeepCSVBDiscL" 1
#python plotStack2.py plots_mc_runBCDEF_test2/QCD_MuEnriched.root plots_data_test2/Run2017.root plots_data_test2/Run2017.root nPV  "ptbin_200.0-300.0" "_DeepCSVBDiscL" 1
#python plotStack2.py plots_mc_runBCDEF_test2/QCD_MuEnriched.root plots_data_test2/Run2017.root plots_data_test2/Run2017.root PT   "ptbin_200.0-300.0" "_DeepCSVBDiscL" 1
#python plotStack2.py plots_mc_runBCDEF_test2/QCD_MuEnriched.root plots_data_test2/Run2017.root plots_data_test2/Run2017.root ETA  "ptbin_200.0-300.0" "_DeepCSVBDiscL" 1
#python plotStack2.py plots_mc_runBCDEF_test2/QCD_MuEnriched.root plots_data_test2/Run2017.root plots_data_test2/Run2017.root JP   "ptbin_200.0-300.0" "_DeepCSVBDiscL" 1
#
##300-670
python plotStack2.py plots_mc_runBCDEF_test2/QCD_MuEnriched.root plots_data_test2/Run2017.root plots_data_test2/Run2017.root MuPtOverJetPt "ptbin_300.0-670.0" "" 1
python plotStack2.py plots_mc_runBCDEF_test2/QCD_MuEnriched.root plots_data_test2/Run2017.root plots_data_test2/Run2017.root SVmass "ptbin_300.0-670.0" "" 1
#python plotStack2.py plots_mc_runBCDEF_test2/QCD_MuEnriched.root plots_data_test2/Run2017.root plots_data_test2/Run2017.root nPV  "ptbin_300.0-670.0" "" 1
#python plotStack2.py plots_mc_runBCDEF_test2/QCD_MuEnriched.root plots_data_test2/Run2017.root plots_data_test2/Run2017.root PT   "ptbin_300.0-670.0" "" 1
#python plotStack2.py plots_mc_runBCDEF_test2/QCD_MuEnriched.root plots_data_test2/Run2017.root plots_data_test2/Run2017.root ETA  "ptbin_300.0-670.0" "" 1
#python plotStack2.py plots_mc_runBCDEF_test2/QCD_MuEnriched.root plots_data_test2/Run2017.root plots_data_test2/Run2017.root JP   "ptbin_300.0-670.0" "" 1
#
python plotStack2.py plots_mc_runBCDEF_test2/QCD_MuEnriched.root plots_data_test2/Run2017.root plots_data_test2/Run2017.root MuPtOverJetPt "ptbin_300.0-670.0" "_DeepCSVBDiscL" 1
python plotStack2.py plots_mc_runBCDEF_test2/QCD_MuEnriched.root plots_data_test2/Run2017.root plots_data_test2/Run2017.root SVmass "ptbin_300.0-670.0" "_DeepCSVBDiscL" 1
#python plotStack2.py plots_mc_runBCDEF_test2/QCD_MuEnriched.root plots_data_test2/Run2017.root plots_data_test2/Run2017.root nPV  "ptbin_300.0-670.0" "_DeepCSVBDiscL" 1
#python plotStack2.py plots_mc_runBCDEF_test2/QCD_MuEnriched.root plots_data_test2/Run2017.root plots_data_test2/Run2017.root PT   "ptbin_300.0-670.0" "_DeepCSVBDiscL" 1
#python plotStack2.py plots_mc_runBCDEF_test2/QCD_MuEnriched.root plots_data_test2/Run2017.root plots_data_test2/Run2017.root ETA  "ptbin_300.0-670.0" "_DeepCSVBDiscL" 1
#python plotStack2.py plots_mc_runBCDEF_test2/QCD_MuEnriched.root plots_data_test2/Run2017.root plots_data_test2/Run2017.root JP   "ptbin_300.0-670.0" "_DeepCSVBDiscL" 1
#
##670-1000
python plotStack2.py plots_mc_runBCDEF_test2/QCD_MuEnriched.root plots_data_test2/Run2017.root plots_data_test2/Run2017.root MuPtOverJetPt "ptbin_670.0-1000.0" "" 1
python plotStack2.py plots_mc_runBCDEF_test2/QCD_MuEnriched.root plots_data_test2/Run2017.root plots_data_test2/Run2017.root SVmass "ptbin_670.0-1000.0" "" 1
#python plotStack2.py plots_mc_runBCDEF_test2/QCD_MuEnriched.root plots_data_test2/Run2017.root plots_data_test2/Run2017.root nPV  "ptbin_670.0-1000.0" "" 1
#python plotStack2.py plots_mc_runBCDEF_test2/QCD_MuEnriched.root plots_data_test2/Run2017.root plots_data_test2/Run2017.root PT   "ptbin_670.0-1000.0" "" 1
#python plotStack2.py plots_mc_runBCDEF_test2/QCD_MuEnriched.root plots_data_test2/Run2017.root plots_data_test2/Run2017.root ETA  "ptbin_670.0-1000.0" "" 1
#python plotStack2.py plots_mc_runBCDEF_test2/QCD_MuEnriched.root plots_data_test2/Run2017.root plots_data_test2/Run2017.root JP   "ptbin_670.0-1000.0" "" 1
#
python plotStack2.py plots_mc_runBCDEF_test2/QCD_MuEnriched.root plots_data_test2/Run2017.root plots_data_test2/Run2017.root MuPtOverJetPt "ptbin_670.0-1000.0" "_DeepCSVBDiscL" 1
python plotStack2.py plots_mc_runBCDEF_test2/QCD_MuEnriched.root plots_data_test2/Run2017.root plots_data_test2/Run2017.root SVmass "ptbin_670.0-1000.0" "_DeepCSVBDiscL" 1
#python plotStack2.py plots_mc_runBCDEF_test2/QCD_MuEnriched.root plots_data_test2/Run2017.root plots_data_test2/Run2017.root nPV  "ptbin_670.0-1000.0" "_DeepCSVBDiscL" 1
#python plotStack2.py plots_mc_runBCDEF_test2/QCD_MuEnriched.root plots_data_test2/Run2017.root plots_data_test2/Run2017.root PT   "ptbin_670.0-1000.0" "_DeepCSVBDiscL" 1
#python plotStack2.py plots_mc_runBCDEF_test2/QCD_MuEnriched.root plots_data_test2/Run2017.root plots_data_test2/Run2017.root ETA  "ptbin_670.0-1000.0" "_DeepCSVBDiscL" 1
#python plotStack2.py plots_mc_runBCDEF_test2/QCD_MuEnriched.root plots_data_test2/Run2017.root plots_data_test2/Run2017.root JP   "ptbin_670.0-1000.0" "_DeepCSVBDiscL" 1



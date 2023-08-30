#!/bin/bash
wps=(L M T XT XXT)
#20-inf 
python plotStack2.py mc/QCD_MuEnriched.root Data/BTagMu_Run2022.root Data/BTagMu_Run2022.root MuPt "ptbin_20.0-1000.0" "" 1 "#mu p_T [GeV]"
python plotStack2.py mc/QCD_MuEnriched.root Data/BTagMu_Run2022.root Data/BTagMu_Run2022.root MuPtOverJetPt "ptbin_20.0-1000.0" "" 1 "p_T_{#mu}/p_T_{jet}"
python plotStack2.py mc/QCD_MuEnriched.root Data/BTagMu_Run2022.root Data/BTagMu_Run2022.root ETA "ptbin_20.0-1000.0" "" 1 "#eta_{jet}"
python plotStack2.py mc/QCD_MuEnriched.root Data/BTagMu_Run2022.root Data/BTagMu_Run2022.root PT "ptbin_20.0-1000.0" "" 1 "jet p_T [GeV]"
python plotStack2.py mc/QCD_MuEnriched.root Data/BTagMu_Run2022.root Data/BTagMu_Run2022.root JP "ptbin_20.0-1000.0" "" 1 "jet JP"
python plotStack2.py mc/QCD_MuEnriched.root Data/BTagMu_Run2022.root Data/BTagMu_Run2022.root SVmass "ptbin_20.0-1000.0" "" 1 "SV mass [GeV]"

# DeepFlavourBDiscL
for wp in ${wps[@]}; do
  python plotStack2.py mc/QCD_MuEnriched.root Data/BTagMu_Run2022.root Data/BTagMu_Run2022.root MuPt "ptbin_20.0-1000.0" "_DeepFlavourBDisc$wp" 1 "#mu p_T [GeV]"
  python plotStack2.py mc/QCD_MuEnriched.root Data/BTagMu_Run2022.root Data/BTagMu_Run2022.root MuPtOverJetPt "ptbin_20.0-1000.0" "_DeepFlavourBDisc$wp" 1 "p_T_{#mu}/p_T_{jet}"
  python plotStack2.py mc/QCD_MuEnriched.root Data/BTagMu_Run2022.root Data/BTagMu_Run2022.root ETA "ptbin_20.0-1000.0" "_DeepFlavourBDisc$wp" 1 "#eta_{jet}"
  python plotStack2.py mc/QCD_MuEnriched.root Data/BTagMu_Run2022.root Data/BTagMu_Run2022.root PT "ptbin_20.0-1000.0" "_DeepFlavourBDisc$wp" 1 "jet p_T [GeV]"
  python plotStack2.py mc/QCD_MuEnriched.root Data/BTagMu_Run2022.root Data/BTagMu_Run2022.root JP "ptbin_20.0-1000.0" "_DeepFlavourBDisc$wp" 1 "jet JP"
  python plotStack2.py mc/QCD_MuEnriched.root Data/BTagMu_Run2022.root Data/BTagMu_Run2022.root SVmass "ptbin_20.0-1000.0" "_DeepFlavourBDisc$wp" 1 "SV mass [GeV]"
done  


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
#python plotStack2.py plots_mc_runBCDEF_test2/QCD_MuEnriched.root plots_data_test2/Run2017.root plots_data_test2/Run2017.root MuPtOverJetPt "ptbin_20.0-30.0" "" 1
#python plotStack2.py plots_mc_runBCDEF_test2/QCD_MuEnriched.root plots_data_test2/Run2017.root plots_data_test2/Run2017.root SVmass "ptbin_20.0-30.0" "" 1
#python plotStack2.py plots_mc_runBCDEF_test2/QCD_MuEnriched.root plots_data_test2/Run2017.root plots_data_test2/Run2017.root nPV  "ptbin_20.0-30.0" "" 1
#python plotStack2.py plots_mc_runBCDEF_test2/QCD_MuEnriched.root plots_data_test2/Run2017.root plots_data_test2/Run2017.root PT   "ptbin_20.0-30.0" "" 1
#python plotStack2.py plots_mc_runBCDEF_test2/QCD_MuEnriched.root plots_data_test2/Run2017.root plots_data_test2/Run2017.root ETA  "ptbin_20.0-30.0" "" 1
#python plotStack2.py plots_mc_runBCDEF_test2/QCD_MuEnriched.root plots_data_test2/Run2017.root plots_data_test2/Run2017.root JP   "ptbin_20.0-30.0" "" 1
#
#python plotStack2.py plots_mc_runBCDEF_test2/QCD_MuEnriched.root plots_data_test2/Run2017.root plots_data_test2/Run2017.root MuPtOverJetPt "ptbin_20.0-30.0" "_DeepCSVBDiscL" 1
#python plotStack2.py plots_mc_runBCDEF_test2/QCD_MuEnriched.root plots_data_test2/Run2017.root plots_data_test2/Run2017.root SVmass "ptbin_20.0-30.0" "_DeepCSVBDiscL" 1
#python plotStack2.py plots_mc_runBCDEF_test2/QCD_MuEnriched.root plots_data_test2/Run2017.root plots_data_test2/Run2017.root nPV  "ptbin_20.0-30.0" "_DeepCSVBDiscL" 1
#python plotStack2.py plots_mc_runBCDEF_test2/QCD_MuEnriched.root plots_data_test2/Run2017.root plots_data_test2/Run2017.root PT   "ptbin_20.0-30.0" "_DeepCSVBDiscL" 1
#python plotStack2.py plots_mc_runBCDEF_test2/QCD_MuEnriched.root plots_data_test2/Run2017.root plots_data_test2/Run2017.root ETA  "ptbin_20.0-30.0" "_DeepCSVBDiscL" 1
#python plotStack2.py plots_mc_runBCDEF_test2/QCD_MuEnriched.root plots_data_test2/Run2017.root plots_data_test2/Run2017.root JP   "ptbin_20.0-30.0" "_DeepCSVBDiscL" 1
#
##30-50
#python plotStack2.py plots_mc_runBCDEF_test2/QCD_MuEnriched.root plots_data_test2/Run2017.root plots_data_test2/Run2017.root MuPtOverJetPt "ptbin_30.0-50.0" "" 1 
#python plotStack2.py plots_mc_runBCDEF_test2/QCD_MuEnriched.root plots_data_test2/Run2017.root plots_data_test2/Run2017.root SVmass "ptbin_30.0-50.0" "" 1 
#python plotStack2.py plots_mc_runBCDEF_test2/QCD_MuEnriched.root plots_data_test2/Run2017.root plots_data_test2/Run2017.root nPV  "ptbin_30.0-50.0" "" 1 
#python plotStack2.py plots_mc_runBCDEF_test2/QCD_MuEnriched.root plots_data_test2/Run2017.root plots_data_test2/Run2017.root PT   "ptbin_30.0-50.0" "" 1 
#python plotStack2.py plots_mc_runBCDEF_test2/QCD_MuEnriched.root plots_data_test2/Run2017.root plots_data_test2/Run2017.root ETA  "ptbin_30.0-50.0" "" 1 
#python plotStack2.py plots_mc_runBCDEF_test2/QCD_MuEnriched.root plots_data_test2/Run2017.root plots_data_test2/Run2017.root JP   "ptbin_30.0-50.0" "" 1 
#
#python plotStack2.py plots_mc_runBCDEF_test2/QCD_MuEnriched.root plots_data_test2/Run2017.root plots_data_test2/Run2017.root MuPtOverJetPt "ptbin_30.0-50.0" "_DeepCSVBDiscL" 1 
#python plotStack2.py plots_mc_runBCDEF_test2/QCD_MuEnriched.root plots_data_test2/Run2017.root plots_data_test2/Run2017.root SVmass "ptbin_30.0-50.0" "_DeepCSVBDiscL" 1 
#python plotStack2.py plots_mc_runBCDEF_test2/QCD_MuEnriched.root plots_data_test2/Run2017.root plots_data_test2/Run2017.root nPV  "ptbin_30.0-50.0" "_DeepCSVBDiscL" 1 
#python plotStack2.py plots_mc_runBCDEF_test2/QCD_MuEnriched.root plots_data_test2/Run2017.root plots_data_test2/Run2017.root PT   "ptbin_30.0-50.0" "_DeepCSVBDiscL" 1 
#python plotStack2.py plots_mc_runBCDEF_test2/QCD_MuEnriched.root plots_data_test2/Run2017.root plots_data_test2/Run2017.root ETA  "ptbin_30.0-50.0" "_DeepCSVBDiscL" 1 
#python plotStack2.py plots_mc_runBCDEF_test2/QCD_MuEnriched.root plots_data_test2/Run2017.root plots_data_test2/Run2017.root JP   "ptbin_30.0-50.0" "_DeepCSVBDiscL" 1
#
##50-70
#python plotStack2.py plots_mc_runBCDEF_test2/QCD_MuEnriched.root plots_data_test2/Run2017.root plots_data_test2/Run2017.root MuPtOverJetPt "ptbin_50.0-70.0" "" 1
#python plotStack2.py plots_mc_runBCDEF_test2/QCD_MuEnriched.root plots_data_test2/Run2017.root plots_data_test2/Run2017.root SVmass "ptbin_50.0-70.0" "" 1
#python plotStack2.py plots_mc_runBCDEF_test2/QCD_MuEnriched.root plots_data_test2/Run2017.root plots_data_test2/Run2017.root nPV  "ptbin_50.0-70.0" "" 1
#python plotStack2.py plots_mc_runBCDEF_test2/QCD_MuEnriched.root plots_data_test2/Run2017.root plots_data_test2/Run2017.root PT   "ptbin_50.0-70.0" "" 1
#python plotStack2.py plots_mc_runBCDEF_test2/QCD_MuEnriched.root plots_data_test2/Run2017.root plots_data_test2/Run2017.root ETA  "ptbin_50.0-70.0" "" 1
#python plotStack2.py plots_mc_runBCDEF_test2/QCD_MuEnriched.root plots_data_test2/Run2017.root plots_data_test2/Run2017.root JP   "ptbin_50.0-70.0" "" 1
#
#python plotStack2.py plots_mc_runBCDEF_test2/QCD_MuEnriched.root plots_data_test2/Run2017.root plots_data_test2/Run2017.root MuPtOverJetPt "ptbin_50.0-70.0" "_DeepCSVBDiscL" 1
#python plotStack2.py plots_mc_runBCDEF_test2/QCD_MuEnriched.root plots_data_test2/Run2017.root plots_data_test2/Run2017.root SVmass "ptbin_50.0-70.0" "_DeepCSVBDiscL" 1
#python plotStack2.py plots_mc_runBCDEF_test2/QCD_MuEnriched.root plots_data_test2/Run2017.root plots_data_test2/Run2017.root nPV  "ptbin_50.0-70.0" "_DeepCSVBDiscL" 1
#python plotStack2.py plots_mc_runBCDEF_test2/QCD_MuEnriched.root plots_data_test2/Run2017.root plots_data_test2/Run2017.root PT   "ptbin_50.0-70.0" "_DeepCSVBDiscL" 1
#python plotStack2.py plots_mc_runBCDEF_test2/QCD_MuEnriched.root plots_data_test2/Run2017.root plots_data_test2/Run2017.root ETA  "ptbin_50.0-70.0" "_DeepCSVBDiscL" 1
#python plotStack2.py plots_mc_runBCDEF_test2/QCD_MuEnriched.root plots_data_test2/Run2017.root plots_data_test2/Run2017.root JP   "ptbin_50.0-70.0" "_DeepCSVBDiscL" 1
#
##70-100
#python plotStack2.py plots_mc_runBCDEF_test2/QCD_MuEnriched.root plots_data_test2/Run2017.root plots_data_test2/Run2017.root MuPtOverJetPt "ptbin_70.0-100.0" "" 1
#python plotStack2.py plots_mc_runBCDEF_test2/QCD_MuEnriched.root plots_data_test2/Run2017.root plots_data_test2/Run2017.root SVmass "ptbin_70.0-100.0" "" 1
#python plotStack2.py plots_mc_runBCDEF_test2/QCD_MuEnriched.root plots_data_test2/Run2017.root plots_data_test2/Run2017.root nPV  "ptbin_70.0-100.0" "" 1
#python plotStack2.py plots_mc_runBCDEF_test2/QCD_MuEnriched.root plots_data_test2/Run2017.root plots_data_test2/Run2017.root PT   "ptbin_70.0-100.0" "" 1
#python plotStack2.py plots_mc_runBCDEF_test2/QCD_MuEnriched.root plots_data_test2/Run2017.root plots_data_test2/Run2017.root ETA  "ptbin_70.0-100.0" "" 1
#python plotStack2.py plots_mc_runBCDEF_test2/QCD_MuEnriched.root plots_data_test2/Run2017.root plots_data_test2/Run2017.root JP   "ptbin_70.0-100.0" "" 1
#
#python plotStack2.py plots_mc_runBCDEF_test2/QCD_MuEnriched.root plots_data_test2/Run2017.root plots_data_test2/Run2017.root MuPtOverJetPt "ptbin_70.0-100.0" "_DeepCSVBDiscL" 1
#python plotStack2.py plots_mc_runBCDEF_test2/QCD_MuEnriched.root plots_data_test2/Run2017.root plots_data_test2/Run2017.root SVmass "ptbin_70.0-100.0" "_DeepCSVBDiscL" 1
#python plotStack2.py plots_mc_runBCDEF_test2/QCD_MuEnriched.root plots_data_test2/Run2017.root plots_data_test2/Run2017.root nPV  "ptbin_70.0-100.0" "_DeepCSVBDiscL" 1
#python plotStack2.py plots_mc_runBCDEF_test2/QCD_MuEnriched.root plots_data_test2/Run2017.root plots_data_test2/Run2017.root PT   "ptbin_70.0-100.0" "_DeepCSVBDiscL" 1
#python plotStack2.py plots_mc_runBCDEF_test2/QCD_MuEnriched.root plots_data_test2/Run2017.root plots_data_test2/Run2017.root ETA  "ptbin_70.0-100.0" "_DeepCSVBDiscL" 1
#python plotStack2.py plots_mc_runBCDEF_test2/QCD_MuEnriched.root plots_data_test2/Run2017.root plots_data_test2/Run2017.root JP   "ptbin_70.0-100.0" "_DeepCSVBDiscL" 1
#
##100-140
#python plotStack2.py plots_mc_runBCDEF_test2/QCD_MuEnriched.root plots_data_test2/Run2017.root plots_data_test2/Run2017.root MuPtOverJetPt "ptbin_100.0-140.0" "" 1
#python plotStack2.py plots_mc_runBCDEF_test2/QCD_MuEnriched.root plots_data_test2/Run2017.root plots_data_test2/Run2017.root SVmass "ptbin_100.0-140.0" "" 1
#python plotStack2.py plots_mc_runBCDEF_test2/QCD_MuEnriched.root plots_data_test2/Run2017.root plots_data_test2/Run2017.root nPV  "ptbin_100.0-140.0" "" 1
#python plotStack2.py plots_mc_runBCDEF_test2/QCD_MuEnriched.root plots_data_test2/Run2017.root plots_data_test2/Run2017.root PT   "ptbin_100.0-140.0" "" 1
#python plotStack2.py plots_mc_runBCDEF_test2/QCD_MuEnriched.root plots_data_test2/Run2017.root plots_data_test2/Run2017.root ETA  "ptbin_100.0-140.0" "" 1
#python plotStack2.py plots_mc_runBCDEF_test2/QCD_MuEnriched.root plots_data_test2/Run2017.root plots_data_test2/Run2017.root JP   "ptbin_100.0-140.0" "" 1
#
#python plotStack2.py plots_mc_runBCDEF_test2/QCD_MuEnriched.root plots_data_test2/Run2017.root plots_data_test2/Run2017.root MuPtOverJetPt "ptbin_100.0-140.0" "_DeepCSVBDiscL" 1
#python plotStack2.py plots_mc_runBCDEF_test2/QCD_MuEnriched.root plots_data_test2/Run2017.root plots_data_test2/Run2017.root SVmass "ptbin_100.0-140.0" "_DeepCSVBDiscL" 1
#python plotStack2.py plots_mc_runBCDEF_test2/QCD_MuEnriched.root plots_data_test2/Run2017.root plots_data_test2/Run2017.root nPV  "ptbin_100.0-140.0" "_DeepCSVBDiscL" 1
#python plotStack2.py plots_mc_runBCDEF_test2/QCD_MuEnriched.root plots_data_test2/Run2017.root plots_data_test2/Run2017.root PT   "ptbin_100.0-140.0" "_DeepCSVBDiscL" 1
#python plotStack2.py plots_mc_runBCDEF_test2/QCD_MuEnriched.root plots_data_test2/Run2017.root plots_data_test2/Run2017.root ETA  "ptbin_100.0-140.0" "_DeepCSVBDiscL" 1
#python plotStack2.py plots_mc_runBCDEF_test2/QCD_MuEnriched.root plots_data_test2/Run2017.root plots_data_test2/Run2017.root JP   "ptbin_100.0-140.0" "_DeepCSVBDiscL" 1
#
##140-200
#python plotStack2.py plots_mc_runBCDEF_test2/QCD_MuEnriched.root plots_data_test2/Run2017.root plots_data_test2/Run2017.root MuPtOverJetPt "ptbin_140.0-200.0" "" 1
#python plotStack2.py plots_mc_runBCDEF_test2/QCD_MuEnriched.root plots_data_test2/Run2017.root plots_data_test2/Run2017.root SVmass "ptbin_140.0-200.0" "" 1
#python plotStack2.py plots_mc_runBCDEF_test2/QCD_MuEnriched.root plots_data_test2/Run2017.root plots_data_test2/Run2017.root nPV  "ptbin_140.0-200.0" "" 1
#python plotStack2.py plots_mc_runBCDEF_test2/QCD_MuEnriched.root plots_data_test2/Run2017.root plots_data_test2/Run2017.root PT   "ptbin_140.0-200.0" "" 1
#python plotStack2.py plots_mc_runBCDEF_test2/QCD_MuEnriched.root plots_data_test2/Run2017.root plots_data_test2/Run2017.root ETA  "ptbin_140.0-200.0" "" 1
#python plotStack2.py plots_mc_runBCDEF_test2/QCD_MuEnriched.root plots_data_test2/Run2017.root plots_data_test2/Run2017.root JP   "ptbin_140.0-200.0" "" 1
#
#python plotStack2.py plots_mc_runBCDEF_test2/QCD_MuEnriched.root plots_data_test2/Run2017.root plots_data_test2/Run2017.root MuPtOverJetPt "ptbin_140.0-200.0" "_DeepCSVBDiscL" 1
#python plotStack2.py plots_mc_runBCDEF_test2/QCD_MuEnriched.root plots_data_test2/Run2017.root plots_data_test2/Run2017.root SVmass "ptbin_140.0-200.0" "_DeepCSVBDiscL" 1
#python plotStack2.py plots_mc_runBCDEF_test2/QCD_MuEnriched.root plots_data_test2/Run2017.root plots_data_test2/Run2017.root nPV  "ptbin_140.0-200.0" "_DeepCSVBDiscL" 1
#python plotStack2.py plots_mc_runBCDEF_test2/QCD_MuEnriched.root plots_data_test2/Run2017.root plots_data_test2/Run2017.root PT   "ptbin_140.0-200.0" "_DeepCSVBDiscL" 1
#python plotStack2.py plots_mc_runBCDEF_test2/QCD_MuEnriched.root plots_data_test2/Run2017.root plots_data_test2/Run2017.root ETA  "ptbin_140.0-200.0" "_DeepCSVBDiscL" 1
#python plotStack2.py plots_mc_runBCDEF_test2/QCD_MuEnriched.root plots_data_test2/Run2017.root plots_data_test2/Run2017.root JP   "ptbin_140.0-200.0" "_DeepCSVBDiscL" 1
#
##200-300
#python plotStack2.py plots_mc_runBCDEF_test2/QCD_MuEnriched.root plots_data_test2/Run2017.root plots_data_test2/Run2017.root MuPtOverJetPt "ptbin_200.0-300.0" "" 1
#python plotStack2.py plots_mc_runBCDEF_test2/QCD_MuEnriched.root plots_data_test2/Run2017.root plots_data_test2/Run2017.root SVmass "ptbin_200.0-300.0" "" 1
#python plotStack2.py plots_mc_runBCDEF_test2/QCD_MuEnriched.root plots_data_test2/Run2017.root plots_data_test2/Run2017.root nPV  "ptbin_200.0-300.0" "" 1
#python plotStack2.py plots_mc_runBCDEF_test2/QCD_MuEnriched.root plots_data_test2/Run2017.root plots_data_test2/Run2017.root PT   "ptbin_200.0-300.0" "" 1
#python plotStack2.py plots_mc_runBCDEF_test2/QCD_MuEnriched.root plots_data_test2/Run2017.root plots_data_test2/Run2017.root ETA  "ptbin_200.0-300.0" "" 1
#python plotStack2.py plots_mc_runBCDEF_test2/QCD_MuEnriched.root plots_data_test2/Run2017.root plots_data_test2/Run2017.root JP   "ptbin_200.0-300.0" "" 1
#
#python plotStack2.py plots_mc_runBCDEF_test2/QCD_MuEnriched.root plots_data_test2/Run2017.root plots_data_test2/Run2017.root MuPtOverJetPt "ptbin_200.0-300.0" "_DeepCSVBDiscL" 1
#python plotStack2.py plots_mc_runBCDEF_test2/QCD_MuEnriched.root plots_data_test2/Run2017.root plots_data_test2/Run2017.root SVmass "ptbin_200.0-300.0" "_DeepCSVBDiscL" 1
#python plotStack2.py plots_mc_runBCDEF_test2/QCD_MuEnriched.root plots_data_test2/Run2017.root plots_data_test2/Run2017.root nPV  "ptbin_200.0-300.0" "_DeepCSVBDiscL" 1
#python plotStack2.py plots_mc_runBCDEF_test2/QCD_MuEnriched.root plots_data_test2/Run2017.root plots_data_test2/Run2017.root PT   "ptbin_200.0-300.0" "_DeepCSVBDiscL" 1
#python plotStack2.py plots_mc_runBCDEF_test2/QCD_MuEnriched.root plots_data_test2/Run2017.root plots_data_test2/Run2017.root ETA  "ptbin_200.0-300.0" "_DeepCSVBDiscL" 1
#python plotStack2.py plots_mc_runBCDEF_test2/QCD_MuEnriched.root plots_data_test2/Run2017.root plots_data_test2/Run2017.root JP   "ptbin_200.0-300.0" "_DeepCSVBDiscL" 1
#
##300-670
#python plotStack2.py plots_mc_runBCDEF_test2/QCD_MuEnriched.root plots_data_test2/Run2017.root plots_data_test2/Run2017.root MuPtOverJetPt "ptbin_300.0-670.0" "" 1
#python plotStack2.py plots_mc_runBCDEF_test2/QCD_MuEnriched.root plots_data_test2/Run2017.root plots_data_test2/Run2017.root SVmass "ptbin_300.0-670.0" "" 1
#python plotStack2.py plots_mc_runBCDEF_test2/QCD_MuEnriched.root plots_data_test2/Run2017.root plots_data_test2/Run2017.root nPV  "ptbin_300.0-670.0" "" 1
#python plotStack2.py plots_mc_runBCDEF_test2/QCD_MuEnriched.root plots_data_test2/Run2017.root plots_data_test2/Run2017.root PT   "ptbin_300.0-670.0" "" 1
#python plotStack2.py plots_mc_runBCDEF_test2/QCD_MuEnriched.root plots_data_test2/Run2017.root plots_data_test2/Run2017.root ETA  "ptbin_300.0-670.0" "" 1
#python plotStack2.py plots_mc_runBCDEF_test2/QCD_MuEnriched.root plots_data_test2/Run2017.root plots_data_test2/Run2017.root JP   "ptbin_300.0-670.0" "" 1
#
#python plotStack2.py plots_mc_runBCDEF_test2/QCD_MuEnriched.root plots_data_test2/Run2017.root plots_data_test2/Run2017.root MuPtOverJetPt "ptbin_300.0-670.0" "_DeepCSVBDiscL" 1
#python plotStack2.py plots_mc_runBCDEF_test2/QCD_MuEnriched.root plots_data_test2/Run2017.root plots_data_test2/Run2017.root SVmass "ptbin_300.0-670.0" "_DeepCSVBDiscL" 1
#python plotStack2.py plots_mc_runBCDEF_test2/QCD_MuEnriched.root plots_data_test2/Run2017.root plots_data_test2/Run2017.root nPV  "ptbin_300.0-670.0" "_DeepCSVBDiscL" 1
#python plotStack2.py plots_mc_runBCDEF_test2/QCD_MuEnriched.root plots_data_test2/Run2017.root plots_data_test2/Run2017.root PT   "ptbin_300.0-670.0" "_DeepCSVBDiscL" 1
#python plotStack2.py plots_mc_runBCDEF_test2/QCD_MuEnriched.root plots_data_test2/Run2017.root plots_data_test2/Run2017.root ETA  "ptbin_300.0-670.0" "_DeepCSVBDiscL" 1
#python plotStack2.py plots_mc_runBCDEF_test2/QCD_MuEnriched.root plots_data_test2/Run2017.root plots_data_test2/Run2017.root JP   "ptbin_300.0-670.0" "_DeepCSVBDiscL" 1
#
##670-1000
#python plotStack2.py plots_mc_runBCDEF_test2/QCD_MuEnriched.root plots_data_test2/Run2017.root plots_data_test2/Run2017.root MuPtOverJetPt "ptbin_670.0-1000.0" "" 1
#python plotStack2.py plots_mc_runBCDEF_test2/QCD_MuEnriched.root plots_data_test2/Run2017.root plots_data_test2/Run2017.root SVmass "ptbin_670.0-1000.0" "" 1
#python plotStack2.py plots_mc_runBCDEF_test2/QCD_MuEnriched.root plots_data_test2/Run2017.root plots_data_test2/Run2017.root nPV  "ptbin_670.0-1000.0" "" 1
#python plotStack2.py plots_mc_runBCDEF_test2/QCD_MuEnriched.root plots_data_test2/Run2017.root plots_data_test2/Run2017.root PT   "ptbin_670.0-1000.0" "" 1
#python plotStack2.py plots_mc_runBCDEF_test2/QCD_MuEnriched.root plots_data_test2/Run2017.root plots_data_test2/Run2017.root ETA  "ptbin_670.0-1000.0" "" 1
#python plotStack2.py plots_mc_runBCDEF_test2/QCD_MuEnriched.root plots_data_test2/Run2017.root plots_data_test2/Run2017.root JP   "ptbin_670.0-1000.0" "" 1
#
#python plotStack2.py plots_mc_runBCDEF_test2/QCD_MuEnriched.root plots_data_test2/Run2017.root plots_data_test2/Run2017.root MuPtOverJetPt "ptbin_670.0-1000.0" "_DeepCSVBDiscL" 1
#python plotStack2.py plots_mc_runBCDEF_test2/QCD_MuEnriched.root plots_data_test2/Run2017.root plots_data_test2/Run2017.root SVmass "ptbin_670.0-1000.0" "_DeepCSVBDiscL" 1
#python plotStack2.py plots_mc_runBCDEF_test2/QCD_MuEnriched.root plots_data_test2/Run2017.root plots_data_test2/Run2017.root nPV  "ptbin_670.0-1000.0" "_DeepCSVBDiscL" 1
#python plotStack2.py plots_mc_runBCDEF_test2/QCD_MuEnriched.root plots_data_test2/Run2017.root plots_data_test2/Run2017.root PT   "ptbin_670.0-1000.0" "_DeepCSVBDiscL" 1
#python plotStack2.py plots_mc_runBCDEF_test2/QCD_MuEnriched.root plots_data_test2/Run2017.root plots_data_test2/Run2017.root ETA  "ptbin_670.0-1000.0" "_DeepCSVBDiscL" 1
#python plotStack2.py plots_mc_runBCDEF_test2/QCD_MuEnriched.root plots_data_test2/Run2017.root plots_data_test2/Run2017.root JP   "ptbin_670.0-1000.0" "_DeepCSVBDiscL" 1



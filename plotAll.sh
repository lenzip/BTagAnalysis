#!/bin/bash
wps=(L M T XT XXT)
#20-inf 
python3 plotStack2.py mc/QCD_MuEnriched_rdf_inclusive.root Data/BTagMu_Run2022EE_rdf_inclusive.root Data_inverted/BTagMu_Run2022EE_rdf_inclusive.root ETA "ptbin_20_1000" "" 1 "#eta_{jet}"
python3 plotStack2.py mc/QCD_MuEnriched_rdf_inclusive.root Data/BTagMu_Run2022EE_rdf_inclusive.root Data_inverted/BTagMu_Run2022EE_rdf_inclusive.root PT "ptbin_20_1000" "" 1 "jet p_T [GeV]"
python3 plotStack2.py mc/QCD_MuEnriched_rdf_inclusive.root Data/BTagMu_Run2022EE_rdf_inclusive.root Data_inverted/BTagMu_Run2022EE_rdf_inclusive.root JP "ptbin_20_1000" "" 1 "jet JP"
python3 plotStack2.py mc/QCD_MuEnriched_rdf_inclusive.root Data/BTagMu_Run2022EE_rdf_inclusive.root Data_inverted/BTagMu_Run2022EE_rdf_inclusive.root SVmass "ptbin_20_1000" "" 1 "SV mass [GeV]"

## DeepFlavourBDiscL
#for wp in ${wps[@]}; do
#  python3 plotStack2.py mc/QCD_MuEnriched_rdf_inclusive.root Data/BTagMu_Run2022EE_rdf_inclusive.root Data_inverted/BTagMu_Run2022EE_rdf_inclusive.root ETA "ptbin_20_1000" "_DeepFlavourBDisc$wp" 0 "#eta_{jet}"
#  python3 plotStack2.py mc/QCD_MuEnriched_rdf_inclusive.root Data/BTagMu_Run2022EE_rdf_inclusive.root Data_inverted/BTagMu_Run2022EE_rdf_inclusive.root PT "ptbin_20_1000" "_DeepFlavourBDisc$wp" 0 "jet p_T [GeV]"
#  python3 plotStack2.py mc/QCD_MuEnriched_rdf_inclusive.root Data/BTagMu_Run2022EE_rdf_inclusive.root Data_inverted/BTagMu_Run2022EE_rdf_inclusive.root JP "ptbin_20_1000" "_DeepFlavourBDisc$wp" 0 "jet JP"
#  python3 plotStack2.py mc/QCD_MuEnriched_rdf_inclusive.root Data/BTagMu_Run2022EE_rdf_inclusive.root Data_inverted/BTagMu_Run2022EE_rdf_inclusive.root SVmass "ptbin_20_1000" "_DeepFlavourBDisc$wp" 0 "SV mass [GeV]"
#done  
##
#ptbins=(20_30 30_50 50_70 70_100 100_140 140_200 200_300 300_600 600_1000)
##discriminators=(DeepFlavourBDisc ParTBDisc PNetBDisc)
#discriminators=(DeepFlavourBDisc)
#for ptbin in ${ptbins[@]}; do  
#  for disc in ${discriminators[@]}; do
#    python3 plotStack2.py mc/QCD_MuEnriched_rdf_DeepFlavourBDisc.root Data/BTagMu_Run2022EE_rdf_DeepFlavourBDisc.root Data_inverted/BTagMu_Run2022EE_rdf_DeepFlavourBDisc.root ETA "ptbin_${ptbin}" "" 0 "#eta_{jet}"
#    python3 plotStack2.py mc/QCD_MuEnriched_rdf_DeepFlavourBDisc.root Data/BTagMu_Run2022EE_rdf_DeepFlavourBDisc.root Data_inverted/BTagMu_Run2022EE_rdf_DeepFlavourBDisc.root PT "ptbin_${ptbin}" "" 0 "jet p_T [GeV]"
#    python3 plotStack2.py mc/QCD_MuEnriched_rdf_DeepFlavourBDisc.root Data/BTagMu_Run2022EE_rdf_DeepFlavourBDisc.root Data_inverted/BTagMu_Run2022EE_rdf_DeepFlavourBDisc.root JP "ptbin_${ptbin}" "" 0 "jet JP"
#    python3 plotStack2.py mc/QCD_MuEnriched_rdf_DeepFlavourBDisc.root Data/BTagMu_Run2022EE_rdf_DeepFlavourBDisc.root Data_inverted/BTagMu_Run2022EE_rdf_DeepFlavourBDisc.root SVmass "ptbin_${ptbin}" "_${disc}$wp" 0 "SV mass [GeV]"
#    for wp in ${wps[@]}; do
#      python3 plotStack2.py mc/QCD_MuEnriched_rdf_DeepFlavourBDisc.root Data/BTagMu_Run2022EE_rdf_DeepFlavourBDisc.root Data_inverted/BTagMu_Run2022EE_rdf_DeepFlavourBDisc.root ETA "ptbin_${ptbin}" "_${disc}$wp" 0 "#eta_{jet}"
#      python3 plotStack2.py mc/QCD_MuEnriched_rdf_DeepFlavourBDisc.root Data/BTagMu_Run2022EE_rdf_DeepFlavourBDisc.root Data_inverted/BTagMu_Run2022EE_rdf_DeepFlavourBDisc.root PT "ptbin_${ptbin}" "_${disc}$wp" 0 "jet p_T [GeV]"
#      python3 plotStack2.py mc/QCD_MuEnriched_rdf_DeepFlavourBDisc.root Data/BTagMu_Run2022EE_rdf_DeepFlavourBDisc.root Data_inverted/BTagMu_Run2022EE_rdf_DeepFlavourBDisc.root JP "ptbin_${ptbin}" "_${disc}$wp" 0 "jet JP"
#      python3 plotStack2.py mc/QCD_MuEnriched_rdf_DeepFlavourBDisc.root Data/BTagMu_Run2022EE_rdf_DeepFlavourBDisc.root Data_inverted/BTagMu_Run2022EE_rdf_DeepFlavourBDisc.root SVmass "ptbin_${ptbin}" "_${disc}$wp" 0 "SV mass [GeV]"
#    done
#  done
#done

#python3 plotStack2.py plots_ptgt30/QCD_MuEnriched_rdf_inclusive.root plots_ptgt30/Run2017D.root MuPt "ptbin_30.0-1000.0" "" 1
#python3 plotStack2.py plots_ptgt30/QCD_MuEnriched_rdf_inclusive.root plots_ptgt30/Run2017D.root nPV  "ptbin_30.0-1000.0" "" 1
#python3 plotStack2.py plots_ptgt30/QCD_MuEnriched_rdf_inclusive.root plots_ptgt30/Run2017D.root PT   "ptbin_30.0-1000.0" "" 1
#python3 plotStack2.py plots_ptgt30/QCD_MuEnriched_rdf_inclusive.root plots_ptgt30/Run2017D.root ETA  "ptbin_30.0-1000.0" "" 1
#python3 plotStack2.py plots_ptgt30/QCD_MuEnriched_rdf_inclusive.root plots_ptgt30/Run2017D.root JP   "ptbin_30.0-1000.0" "" 1
#
#python3 plotStack2.py plots_ptgt30/QCD_MuEnriched_rdf_inclusive.root plots_ptgt30/Run2017D.root MuPt "ptbin_30.0-1000.0" "_DeepCSVBDiscL" 1
#python3 plotStack2.py plots_ptgt30/QCD_MuEnriched_rdf_inclusive.root plots_ptgt30/Run2017D.root nPV  "ptbin_30.0-1000.0" "_DeepCSVBDiscL" 1
#python3 plotStack2.py plots_ptgt30/QCD_MuEnriched_rdf_inclusive.root plots_ptgt30/Run2017D.root PT   "ptbin_30.0-1000.0" "_DeepCSVBDiscL" 1
#python3 plotStack2.py plots_ptgt30/QCD_MuEnriched_rdf_inclusive.root plots_ptgt30/Run2017D.root ETA  "ptbin_30.0-1000.0" "_DeepCSVBDiscL" 1
#python3 plotStack2.py plots_ptgt30/QCD_MuEnriched_rdf_inclusive.root plots_ptgt30/Run2017D.root JP   "ptbin_30.0-1000.0" "_DeepCSVBDiscL" 1
#
##20-inf
#python3 plotStack2.py plots_mc_runBCDEF_test/QCD_MuEnriched_rdf_inclusive.root plots_data_test/Run2017.root plots_data_test/Run2017.root SVmass "ptbin_20_1000" "" 1
#python3 plotStack2.py plots_mc_runBCDEF_test/QCD_MuEnriched_rdf_inclusive.root plots_data_test/Run2017.root plots_data_test/Run2017.root SVmass "ptbin_20_1000" "_DeepCSVBDiscL" 1
#python3 plotStack2.py plots_mc_runBCDEF_test/QCD_MuEnriched_rdf_inclusive.root plots_data_test/Run2017.root plots_data_test/Run2017.root SVmass "ptbin_20_1000" "_DeepCSVBDiscM" 1
#python3 plotStack2.py plots_mc_runBCDEF_test/QCD_MuEnriched_rdf_inclusive.root plots_data_test/Run2017.root plots_data_test/Run2017.root SVmass "ptbin_20_1000" "_DeepCSVBDiscT" 1
#python3 plotStack2.py plots_ptgt20/QCD_MuEnriched_rdf_inclusive.root plots_ptgt20/Run2017D.root nPV  "ptbin_20_1000" "" 1
#python3 plotStack2.py plots_ptgt20/QCD_MuEnriched_rdf_inclusive.root plots_ptgt20/Run2017D.root PT   "ptbin_20_1000" "" 1
#python3 plotStack2.py plots_ptgt20/QCD_MuEnriched_rdf_inclusive.root plots_ptgt20/Run2017D.root ETA  "ptbin_20_1000" "" 1
#python3 plotStack2.py plots_ptgt20/QCD_MuEnriched_rdf_inclusive.root plots_ptgt20/Run2017D.root JP   "ptbin_20_1000" "" 1
#
#python3 plotStack2.py plots_ptgt20/QCD_MuEnriched_rdf_inclusive.root plots_ptgt20/Run2017D.root MuPt "ptbin_20_1000" "_DeepCSVBDiscL" 1
#python3 plotStack2.py plots_ptgt20/QCD_MuEnriched_rdf_inclusive.root plots_ptgt20/Run2017D.root nPV  "ptbin_20_1000" "_DeepCSVBDiscL" 1
#python3 plotStack2.py plots_ptgt20/QCD_MuEnriched_rdf_inclusive.root plots_ptgt20/Run2017D.root PT   "ptbin_20_1000" "_DeepCSVBDiscL" 1
#python3 plotStack2.py plots_ptgt20/QCD_MuEnriched_rdf_inclusive.root plots_ptgt20/Run2017D.root ETA  "ptbin_20_1000" "_DeepCSVBDiscL" 1
#python3 plotStack2.py plots_ptgt20/QCD_MuEnriched_rdf_inclusive.root plots_ptgt20/Run2017D.root JP   "ptbin_20_1000" "_DeepCSVBDiscL" 1

#20-30
#python3 plotStack2.py plots_mc_runBCDEF_test2/QCD_MuEnriched_rdf_inclusive.root plots_data_test2/Run2017.root plots_data_test2/Run2017.root MuPtOverJetPt "ptbin_20.0-30.0" "" 1
#python3 plotStack2.py plots_mc_runBCDEF_test2/QCD_MuEnriched_rdf_inclusive.root plots_data_test2/Run2017.root plots_data_test2/Run2017.root SVmass "ptbin_20.0-30.0" "" 1
#python3 plotStack2.py plots_mc_runBCDEF_test2/QCD_MuEnriched_rdf_inclusive.root plots_data_test2/Run2017.root plots_data_test2/Run2017.root nPV  "ptbin_20.0-30.0" "" 1
#python3 plotStack2.py plots_mc_runBCDEF_test2/QCD_MuEnriched_rdf_inclusive.root plots_data_test2/Run2017.root plots_data_test2/Run2017.root PT   "ptbin_20.0-30.0" "" 1
#python3 plotStack2.py plots_mc_runBCDEF_test2/QCD_MuEnriched_rdf_inclusive.root plots_data_test2/Run2017.root plots_data_test2/Run2017.root ETA  "ptbin_20.0-30.0" "" 1
#python3 plotStack2.py plots_mc_runBCDEF_test2/QCD_MuEnriched_rdf_inclusive.root plots_data_test2/Run2017.root plots_data_test2/Run2017.root JP   "ptbin_20.0-30.0" "" 1
#
#python3 plotStack2.py plots_mc_runBCDEF_test2/QCD_MuEnriched_rdf_inclusive.root plots_data_test2/Run2017.root plots_data_test2/Run2017.root MuPtOverJetPt "ptbin_20.0-30.0" "_DeepCSVBDiscL" 1
#python3 plotStack2.py plots_mc_runBCDEF_test2/QCD_MuEnriched_rdf_inclusive.root plots_data_test2/Run2017.root plots_data_test2/Run2017.root SVmass "ptbin_20.0-30.0" "_DeepCSVBDiscL" 1
#python3 plotStack2.py plots_mc_runBCDEF_test2/QCD_MuEnriched_rdf_inclusive.root plots_data_test2/Run2017.root plots_data_test2/Run2017.root nPV  "ptbin_20.0-30.0" "_DeepCSVBDiscL" 1
#python3 plotStack2.py plots_mc_runBCDEF_test2/QCD_MuEnriched_rdf_inclusive.root plots_data_test2/Run2017.root plots_data_test2/Run2017.root PT   "ptbin_20.0-30.0" "_DeepCSVBDiscL" 1
#python3 plotStack2.py plots_mc_runBCDEF_test2/QCD_MuEnriched_rdf_inclusive.root plots_data_test2/Run2017.root plots_data_test2/Run2017.root ETA  "ptbin_20.0-30.0" "_DeepCSVBDiscL" 1
#python3 plotStack2.py plots_mc_runBCDEF_test2/QCD_MuEnriched_rdf_inclusive.root plots_data_test2/Run2017.root plots_data_test2/Run2017.root JP   "ptbin_20.0-30.0" "_DeepCSVBDiscL" 1
#
##30-50
#python3 plotStack2.py plots_mc_runBCDEF_test2/QCD_MuEnriched_rdf_inclusive.root plots_data_test2/Run2017.root plots_data_test2/Run2017.root MuPtOverJetPt "ptbin_30.0-50.0" "" 1 
#python3 plotStack2.py plots_mc_runBCDEF_test2/QCD_MuEnriched_rdf_inclusive.root plots_data_test2/Run2017.root plots_data_test2/Run2017.root SVmass "ptbin_30.0-50.0" "" 1 
#python3 plotStack2.py plots_mc_runBCDEF_test2/QCD_MuEnriched_rdf_inclusive.root plots_data_test2/Run2017.root plots_data_test2/Run2017.root nPV  "ptbin_30.0-50.0" "" 1 
#python3 plotStack2.py plots_mc_runBCDEF_test2/QCD_MuEnriched_rdf_inclusive.root plots_data_test2/Run2017.root plots_data_test2/Run2017.root PT   "ptbin_30.0-50.0" "" 1 
#python3 plotStack2.py plots_mc_runBCDEF_test2/QCD_MuEnriched_rdf_inclusive.root plots_data_test2/Run2017.root plots_data_test2/Run2017.root ETA  "ptbin_30.0-50.0" "" 1 
#python3 plotStack2.py plots_mc_runBCDEF_test2/QCD_MuEnriched_rdf_inclusive.root plots_data_test2/Run2017.root plots_data_test2/Run2017.root JP   "ptbin_30.0-50.0" "" 1 
#
#python3 plotStack2.py plots_mc_runBCDEF_test2/QCD_MuEnriched_rdf_inclusive.root plots_data_test2/Run2017.root plots_data_test2/Run2017.root MuPtOverJetPt "ptbin_30.0-50.0" "_DeepCSVBDiscL" 1 
#python3 plotStack2.py plots_mc_runBCDEF_test2/QCD_MuEnriched_rdf_inclusive.root plots_data_test2/Run2017.root plots_data_test2/Run2017.root SVmass "ptbin_30.0-50.0" "_DeepCSVBDiscL" 1 
#python3 plotStack2.py plots_mc_runBCDEF_test2/QCD_MuEnriched_rdf_inclusive.root plots_data_test2/Run2017.root plots_data_test2/Run2017.root nPV  "ptbin_30.0-50.0" "_DeepCSVBDiscL" 1 
#python3 plotStack2.py plots_mc_runBCDEF_test2/QCD_MuEnriched_rdf_inclusive.root plots_data_test2/Run2017.root plots_data_test2/Run2017.root PT   "ptbin_30.0-50.0" "_DeepCSVBDiscL" 1 
#python3 plotStack2.py plots_mc_runBCDEF_test2/QCD_MuEnriched_rdf_inclusive.root plots_data_test2/Run2017.root plots_data_test2/Run2017.root ETA  "ptbin_30.0-50.0" "_DeepCSVBDiscL" 1 
#python3 plotStack2.py plots_mc_runBCDEF_test2/QCD_MuEnriched_rdf_inclusive.root plots_data_test2/Run2017.root plots_data_test2/Run2017.root JP   "ptbin_30.0-50.0" "_DeepCSVBDiscL" 1
#
##50-70
#python3 plotStack2.py plots_mc_runBCDEF_test2/QCD_MuEnriched_rdf_inclusive.root plots_data_test2/Run2017.root plots_data_test2/Run2017.root MuPtOverJetPt "ptbin_50.0-70.0" "" 1
#python3 plotStack2.py plots_mc_runBCDEF_test2/QCD_MuEnriched_rdf_inclusive.root plots_data_test2/Run2017.root plots_data_test2/Run2017.root SVmass "ptbin_50.0-70.0" "" 1
#python3 plotStack2.py plots_mc_runBCDEF_test2/QCD_MuEnriched_rdf_inclusive.root plots_data_test2/Run2017.root plots_data_test2/Run2017.root nPV  "ptbin_50.0-70.0" "" 1
#python3 plotStack2.py plots_mc_runBCDEF_test2/QCD_MuEnriched_rdf_inclusive.root plots_data_test2/Run2017.root plots_data_test2/Run2017.root PT   "ptbin_50.0-70.0" "" 1
#python3 plotStack2.py plots_mc_runBCDEF_test2/QCD_MuEnriched_rdf_inclusive.root plots_data_test2/Run2017.root plots_data_test2/Run2017.root ETA  "ptbin_50.0-70.0" "" 1
#python3 plotStack2.py plots_mc_runBCDEF_test2/QCD_MuEnriched_rdf_inclusive.root plots_data_test2/Run2017.root plots_data_test2/Run2017.root JP   "ptbin_50.0-70.0" "" 1
#
#python3 plotStack2.py plots_mc_runBCDEF_test2/QCD_MuEnriched_rdf_inclusive.root plots_data_test2/Run2017.root plots_data_test2/Run2017.root MuPtOverJetPt "ptbin_50.0-70.0" "_DeepCSVBDiscL" 1
#python3 plotStack2.py plots_mc_runBCDEF_test2/QCD_MuEnriched_rdf_inclusive.root plots_data_test2/Run2017.root plots_data_test2/Run2017.root SVmass "ptbin_50.0-70.0" "_DeepCSVBDiscL" 1
#python3 plotStack2.py plots_mc_runBCDEF_test2/QCD_MuEnriched_rdf_inclusive.root plots_data_test2/Run2017.root plots_data_test2/Run2017.root nPV  "ptbin_50.0-70.0" "_DeepCSVBDiscL" 1
#python3 plotStack2.py plots_mc_runBCDEF_test2/QCD_MuEnriched_rdf_inclusive.root plots_data_test2/Run2017.root plots_data_test2/Run2017.root PT   "ptbin_50.0-70.0" "_DeepCSVBDiscL" 1
#python3 plotStack2.py plots_mc_runBCDEF_test2/QCD_MuEnriched_rdf_inclusive.root plots_data_test2/Run2017.root plots_data_test2/Run2017.root ETA  "ptbin_50.0-70.0" "_DeepCSVBDiscL" 1
#python3 plotStack2.py plots_mc_runBCDEF_test2/QCD_MuEnriched_rdf_inclusive.root plots_data_test2/Run2017.root plots_data_test2/Run2017.root JP   "ptbin_50.0-70.0" "_DeepCSVBDiscL" 1
#
##70-100
#python3 plotStack2.py plots_mc_runBCDEF_test2/QCD_MuEnriched_rdf_inclusive.root plots_data_test2/Run2017.root plots_data_test2/Run2017.root MuPtOverJetPt "ptbin_70.0-100.0" "" 1
#python3 plotStack2.py plots_mc_runBCDEF_test2/QCD_MuEnriched_rdf_inclusive.root plots_data_test2/Run2017.root plots_data_test2/Run2017.root SVmass "ptbin_70.0-100.0" "" 1
#python3 plotStack2.py plots_mc_runBCDEF_test2/QCD_MuEnriched_rdf_inclusive.root plots_data_test2/Run2017.root plots_data_test2/Run2017.root nPV  "ptbin_70.0-100.0" "" 1
#python3 plotStack2.py plots_mc_runBCDEF_test2/QCD_MuEnriched_rdf_inclusive.root plots_data_test2/Run2017.root plots_data_test2/Run2017.root PT   "ptbin_70.0-100.0" "" 1
#python3 plotStack2.py plots_mc_runBCDEF_test2/QCD_MuEnriched_rdf_inclusive.root plots_data_test2/Run2017.root plots_data_test2/Run2017.root ETA  "ptbin_70.0-100.0" "" 1
#python3 plotStack2.py plots_mc_runBCDEF_test2/QCD_MuEnriched_rdf_inclusive.root plots_data_test2/Run2017.root plots_data_test2/Run2017.root JP   "ptbin_70.0-100.0" "" 1
#
#python3 plotStack2.py plots_mc_runBCDEF_test2/QCD_MuEnriched_rdf_inclusive.root plots_data_test2/Run2017.root plots_data_test2/Run2017.root MuPtOverJetPt "ptbin_70.0-100.0" "_DeepCSVBDiscL" 1
#python3 plotStack2.py plots_mc_runBCDEF_test2/QCD_MuEnriched_rdf_inclusive.root plots_data_test2/Run2017.root plots_data_test2/Run2017.root SVmass "ptbin_70.0-100.0" "_DeepCSVBDiscL" 1
#python3 plotStack2.py plots_mc_runBCDEF_test2/QCD_MuEnriched_rdf_inclusive.root plots_data_test2/Run2017.root plots_data_test2/Run2017.root nPV  "ptbin_70.0-100.0" "_DeepCSVBDiscL" 1
#python3 plotStack2.py plots_mc_runBCDEF_test2/QCD_MuEnriched_rdf_inclusive.root plots_data_test2/Run2017.root plots_data_test2/Run2017.root PT   "ptbin_70.0-100.0" "_DeepCSVBDiscL" 1
#python3 plotStack2.py plots_mc_runBCDEF_test2/QCD_MuEnriched_rdf_inclusive.root plots_data_test2/Run2017.root plots_data_test2/Run2017.root ETA  "ptbin_70.0-100.0" "_DeepCSVBDiscL" 1
#python3 plotStack2.py plots_mc_runBCDEF_test2/QCD_MuEnriched_rdf_inclusive.root plots_data_test2/Run2017.root plots_data_test2/Run2017.root JP   "ptbin_70.0-100.0" "_DeepCSVBDiscL" 1
#
##100-140
#python3 plotStack2.py plots_mc_runBCDEF_test2/QCD_MuEnriched_rdf_inclusive.root plots_data_test2/Run2017.root plots_data_test2/Run2017.root MuPtOverJetPt "ptbin_100.0-140.0" "" 1
#python3 plotStack2.py plots_mc_runBCDEF_test2/QCD_MuEnriched_rdf_inclusive.root plots_data_test2/Run2017.root plots_data_test2/Run2017.root SVmass "ptbin_100.0-140.0" "" 1
#python3 plotStack2.py plots_mc_runBCDEF_test2/QCD_MuEnriched_rdf_inclusive.root plots_data_test2/Run2017.root plots_data_test2/Run2017.root nPV  "ptbin_100.0-140.0" "" 1
#python3 plotStack2.py plots_mc_runBCDEF_test2/QCD_MuEnriched_rdf_inclusive.root plots_data_test2/Run2017.root plots_data_test2/Run2017.root PT   "ptbin_100.0-140.0" "" 1
#python3 plotStack2.py plots_mc_runBCDEF_test2/QCD_MuEnriched_rdf_inclusive.root plots_data_test2/Run2017.root plots_data_test2/Run2017.root ETA  "ptbin_100.0-140.0" "" 1
#python3 plotStack2.py plots_mc_runBCDEF_test2/QCD_MuEnriched_rdf_inclusive.root plots_data_test2/Run2017.root plots_data_test2/Run2017.root JP   "ptbin_100.0-140.0" "" 1
#
#python3 plotStack2.py plots_mc_runBCDEF_test2/QCD_MuEnriched_rdf_inclusive.root plots_data_test2/Run2017.root plots_data_test2/Run2017.root MuPtOverJetPt "ptbin_100.0-140.0" "_DeepCSVBDiscL" 1
#python3 plotStack2.py plots_mc_runBCDEF_test2/QCD_MuEnriched_rdf_inclusive.root plots_data_test2/Run2017.root plots_data_test2/Run2017.root SVmass "ptbin_100.0-140.0" "_DeepCSVBDiscL" 1
#python3 plotStack2.py plots_mc_runBCDEF_test2/QCD_MuEnriched_rdf_inclusive.root plots_data_test2/Run2017.root plots_data_test2/Run2017.root nPV  "ptbin_100.0-140.0" "_DeepCSVBDiscL" 1
#python3 plotStack2.py plots_mc_runBCDEF_test2/QCD_MuEnriched_rdf_inclusive.root plots_data_test2/Run2017.root plots_data_test2/Run2017.root PT   "ptbin_100.0-140.0" "_DeepCSVBDiscL" 1
#python3 plotStack2.py plots_mc_runBCDEF_test2/QCD_MuEnriched_rdf_inclusive.root plots_data_test2/Run2017.root plots_data_test2/Run2017.root ETA  "ptbin_100.0-140.0" "_DeepCSVBDiscL" 1
#python3 plotStack2.py plots_mc_runBCDEF_test2/QCD_MuEnriched_rdf_inclusive.root plots_data_test2/Run2017.root plots_data_test2/Run2017.root JP   "ptbin_100.0-140.0" "_DeepCSVBDiscL" 1
#
##140-200
#python3 plotStack2.py plots_mc_runBCDEF_test2/QCD_MuEnriched_rdf_inclusive.root plots_data_test2/Run2017.root plots_data_test2/Run2017.root MuPtOverJetPt "ptbin_140.0-200.0" "" 1
#python3 plotStack2.py plots_mc_runBCDEF_test2/QCD_MuEnriched_rdf_inclusive.root plots_data_test2/Run2017.root plots_data_test2/Run2017.root SVmass "ptbin_140.0-200.0" "" 1
#python3 plotStack2.py plots_mc_runBCDEF_test2/QCD_MuEnriched_rdf_inclusive.root plots_data_test2/Run2017.root plots_data_test2/Run2017.root nPV  "ptbin_140.0-200.0" "" 1
#python3 plotStack2.py plots_mc_runBCDEF_test2/QCD_MuEnriched_rdf_inclusive.root plots_data_test2/Run2017.root plots_data_test2/Run2017.root PT   "ptbin_140.0-200.0" "" 1
#python3 plotStack2.py plots_mc_runBCDEF_test2/QCD_MuEnriched_rdf_inclusive.root plots_data_test2/Run2017.root plots_data_test2/Run2017.root ETA  "ptbin_140.0-200.0" "" 1
#python3 plotStack2.py plots_mc_runBCDEF_test2/QCD_MuEnriched_rdf_inclusive.root plots_data_test2/Run2017.root plots_data_test2/Run2017.root JP   "ptbin_140.0-200.0" "" 1
#
#python3 plotStack2.py plots_mc_runBCDEF_test2/QCD_MuEnriched_rdf_inclusive.root plots_data_test2/Run2017.root plots_data_test2/Run2017.root MuPtOverJetPt "ptbin_140.0-200.0" "_DeepCSVBDiscL" 1
#python3 plotStack2.py plots_mc_runBCDEF_test2/QCD_MuEnriched_rdf_inclusive.root plots_data_test2/Run2017.root plots_data_test2/Run2017.root SVmass "ptbin_140.0-200.0" "_DeepCSVBDiscL" 1
#python3 plotStack2.py plots_mc_runBCDEF_test2/QCD_MuEnriched_rdf_inclusive.root plots_data_test2/Run2017.root plots_data_test2/Run2017.root nPV  "ptbin_140.0-200.0" "_DeepCSVBDiscL" 1
#python3 plotStack2.py plots_mc_runBCDEF_test2/QCD_MuEnriched_rdf_inclusive.root plots_data_test2/Run2017.root plots_data_test2/Run2017.root PT   "ptbin_140.0-200.0" "_DeepCSVBDiscL" 1
#python3 plotStack2.py plots_mc_runBCDEF_test2/QCD_MuEnriched_rdf_inclusive.root plots_data_test2/Run2017.root plots_data_test2/Run2017.root ETA  "ptbin_140.0-200.0" "_DeepCSVBDiscL" 1
#python3 plotStack2.py plots_mc_runBCDEF_test2/QCD_MuEnriched_rdf_inclusive.root plots_data_test2/Run2017.root plots_data_test2/Run2017.root JP   "ptbin_140.0-200.0" "_DeepCSVBDiscL" 1
#
##200-300
#python3 plotStack2.py plots_mc_runBCDEF_test2/QCD_MuEnriched_rdf_inclusive.root plots_data_test2/Run2017.root plots_data_test2/Run2017.root MuPtOverJetPt "ptbin_200.0-300.0" "" 1
#python3 plotStack2.py plots_mc_runBCDEF_test2/QCD_MuEnriched_rdf_inclusive.root plots_data_test2/Run2017.root plots_data_test2/Run2017.root SVmass "ptbin_200.0-300.0" "" 1
#python3 plotStack2.py plots_mc_runBCDEF_test2/QCD_MuEnriched_rdf_inclusive.root plots_data_test2/Run2017.root plots_data_test2/Run2017.root nPV  "ptbin_200.0-300.0" "" 1
#python3 plotStack2.py plots_mc_runBCDEF_test2/QCD_MuEnriched_rdf_inclusive.root plots_data_test2/Run2017.root plots_data_test2/Run2017.root PT   "ptbin_200.0-300.0" "" 1
#python3 plotStack2.py plots_mc_runBCDEF_test2/QCD_MuEnriched_rdf_inclusive.root plots_data_test2/Run2017.root plots_data_test2/Run2017.root ETA  "ptbin_200.0-300.0" "" 1
#python3 plotStack2.py plots_mc_runBCDEF_test2/QCD_MuEnriched_rdf_inclusive.root plots_data_test2/Run2017.root plots_data_test2/Run2017.root JP   "ptbin_200.0-300.0" "" 1
#
#python3 plotStack2.py plots_mc_runBCDEF_test2/QCD_MuEnriched_rdf_inclusive.root plots_data_test2/Run2017.root plots_data_test2/Run2017.root MuPtOverJetPt "ptbin_200.0-300.0" "_DeepCSVBDiscL" 1
#python3 plotStack2.py plots_mc_runBCDEF_test2/QCD_MuEnriched_rdf_inclusive.root plots_data_test2/Run2017.root plots_data_test2/Run2017.root SVmass "ptbin_200.0-300.0" "_DeepCSVBDiscL" 1
#python3 plotStack2.py plots_mc_runBCDEF_test2/QCD_MuEnriched_rdf_inclusive.root plots_data_test2/Run2017.root plots_data_test2/Run2017.root nPV  "ptbin_200.0-300.0" "_DeepCSVBDiscL" 1
#python3 plotStack2.py plots_mc_runBCDEF_test2/QCD_MuEnriched_rdf_inclusive.root plots_data_test2/Run2017.root plots_data_test2/Run2017.root PT   "ptbin_200.0-300.0" "_DeepCSVBDiscL" 1
#python3 plotStack2.py plots_mc_runBCDEF_test2/QCD_MuEnriched_rdf_inclusive.root plots_data_test2/Run2017.root plots_data_test2/Run2017.root ETA  "ptbin_200.0-300.0" "_DeepCSVBDiscL" 1
#python3 plotStack2.py plots_mc_runBCDEF_test2/QCD_MuEnriched_rdf_inclusive.root plots_data_test2/Run2017.root plots_data_test2/Run2017.root JP   "ptbin_200.0-300.0" "_DeepCSVBDiscL" 1
#
##300-670
#python3 plotStack2.py plots_mc_runBCDEF_test2/QCD_MuEnriched_rdf_inclusive.root plots_data_test2/Run2017.root plots_data_test2/Run2017.root MuPtOverJetPt "ptbin_300.0-670.0" "" 1
#python3 plotStack2.py plots_mc_runBCDEF_test2/QCD_MuEnriched_rdf_inclusive.root plots_data_test2/Run2017.root plots_data_test2/Run2017.root SVmass "ptbin_300.0-670.0" "" 1
#python3 plotStack2.py plots_mc_runBCDEF_test2/QCD_MuEnriched_rdf_inclusive.root plots_data_test2/Run2017.root plots_data_test2/Run2017.root nPV  "ptbin_300.0-670.0" "" 1
#python3 plotStack2.py plots_mc_runBCDEF_test2/QCD_MuEnriched_rdf_inclusive.root plots_data_test2/Run2017.root plots_data_test2/Run2017.root PT   "ptbin_300.0-670.0" "" 1
#python3 plotStack2.py plots_mc_runBCDEF_test2/QCD_MuEnriched_rdf_inclusive.root plots_data_test2/Run2017.root plots_data_test2/Run2017.root ETA  "ptbin_300.0-670.0" "" 1
#python3 plotStack2.py plots_mc_runBCDEF_test2/QCD_MuEnriched_rdf_inclusive.root plots_data_test2/Run2017.root plots_data_test2/Run2017.root JP   "ptbin_300.0-670.0" "" 1
#
#python3 plotStack2.py plots_mc_runBCDEF_test2/QCD_MuEnriched_rdf_inclusive.root plots_data_test2/Run2017.root plots_data_test2/Run2017.root MuPtOverJetPt "ptbin_300.0-670.0" "_DeepCSVBDiscL" 1
#python3 plotStack2.py plots_mc_runBCDEF_test2/QCD_MuEnriched_rdf_inclusive.root plots_data_test2/Run2017.root plots_data_test2/Run2017.root SVmass "ptbin_300.0-670.0" "_DeepCSVBDiscL" 1
#python3 plotStack2.py plots_mc_runBCDEF_test2/QCD_MuEnriched_rdf_inclusive.root plots_data_test2/Run2017.root plots_data_test2/Run2017.root nPV  "ptbin_300.0-670.0" "_DeepCSVBDiscL" 1
#python3 plotStack2.py plots_mc_runBCDEF_test2/QCD_MuEnriched_rdf_inclusive.root plots_data_test2/Run2017.root plots_data_test2/Run2017.root PT   "ptbin_300.0-670.0" "_DeepCSVBDiscL" 1
#python3 plotStack2.py plots_mc_runBCDEF_test2/QCD_MuEnriched_rdf_inclusive.root plots_data_test2/Run2017.root plots_data_test2/Run2017.root ETA  "ptbin_300.0-670.0" "_DeepCSVBDiscL" 1
#python3 plotStack2.py plots_mc_runBCDEF_test2/QCD_MuEnriched_rdf_inclusive.root plots_data_test2/Run2017.root plots_data_test2/Run2017.root JP   "ptbin_300.0-670.0" "_DeepCSVBDiscL" 1
#
##670-1000
#python3 plotStack2.py plots_mc_runBCDEF_test2/QCD_MuEnriched_rdf_inclusive.root plots_data_test2/Run2017.root plots_data_test2/Run2017.root MuPtOverJetPt "ptbin_670.0-1000.0" "" 1
#python3 plotStack2.py plots_mc_runBCDEF_test2/QCD_MuEnriched_rdf_inclusive.root plots_data_test2/Run2017.root plots_data_test2/Run2017.root SVmass "ptbin_670.0-1000.0" "" 1
#python3 plotStack2.py plots_mc_runBCDEF_test2/QCD_MuEnriched_rdf_inclusive.root plots_data_test2/Run2017.root plots_data_test2/Run2017.root nPV  "ptbin_670.0-1000.0" "" 1
#python3 plotStack2.py plots_mc_runBCDEF_test2/QCD_MuEnriched_rdf_inclusive.root plots_data_test2/Run2017.root plots_data_test2/Run2017.root PT   "ptbin_670.0-1000.0" "" 1
#python3 plotStack2.py plots_mc_runBCDEF_test2/QCD_MuEnriched_rdf_inclusive.root plots_data_test2/Run2017.root plots_data_test2/Run2017.root ETA  "ptbin_670.0-1000.0" "" 1
#python3 plotStack2.py plots_mc_runBCDEF_test2/QCD_MuEnriched_rdf_inclusive.root plots_data_test2/Run2017.root plots_data_test2/Run2017.root JP   "ptbin_670.0-1000.0" "" 1
#
#python3 plotStack2.py plots_mc_runBCDEF_test2/QCD_MuEnriched_rdf_inclusive.root plots_data_test2/Run2017.root plots_data_test2/Run2017.root MuPtOverJetPt "ptbin_670.0-1000.0" "_DeepCSVBDiscL" 1
#python3 plotStack2.py plots_mc_runBCDEF_test2/QCD_MuEnriched_rdf_inclusive.root plots_data_test2/Run2017.root plots_data_test2/Run2017.root SVmass "ptbin_670.0-1000.0" "_DeepCSVBDiscL" 1
#python3 plotStack2.py plots_mc_runBCDEF_test2/QCD_MuEnriched_rdf_inclusive.root plots_data_test2/Run2017.root plots_data_test2/Run2017.root nPV  "ptbin_670.0-1000.0" "_DeepCSVBDiscL" 1
#python3 plotStack2.py plots_mc_runBCDEF_test2/QCD_MuEnriched_rdf_inclusive.root plots_data_test2/Run2017.root plots_data_test2/Run2017.root PT   "ptbin_670.0-1000.0" "_DeepCSVBDiscL" 1
#python3 plotStack2.py plots_mc_runBCDEF_test2/QCD_MuEnriched_rdf_inclusive.root plots_data_test2/Run2017.root plots_data_test2/Run2017.root ETA  "ptbin_670.0-1000.0" "_DeepCSVBDiscL" 1
#python3 plotStack2.py plots_mc_runBCDEF_test2/QCD_MuEnriched_rdf_inclusive.root plots_data_test2/Run2017.root plots_data_test2/Run2017.root JP   "ptbin_670.0-1000.0" "_DeepCSVBDiscL" 1



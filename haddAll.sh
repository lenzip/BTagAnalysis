#!/bin/bash

cd plots_data_SVmass_CSVv2_v3
hadd -f Run2017B.root  Run2017B_ID*.root
hadd -f Run2017C.root  Run2017C_ID*.root
hadd -f Run2017D.root  Run2017D_ID*.root
hadd -f Run2017Elo.root  Run2017Elo_ID*.root
hadd -f Run2017Ehi.root  Run2017Ehi_ID*.root
hadd -f Run2017F.root  Run2017F_ID*.root

hadd -f Run2017.root Run2017B.root Run2017C.root Run2017D.root Run2017Elo.root Run2017Ehi.root Run2017F.root 
hadd -f Run2017CDElo.root Run2017C.root Run2017D.root Run2017Elo.root
hadd -f Run2017EhiF.root Run2017Ehi.root Run2017F.root
cd ..


cd plots_data_inverted_SVmass_CSVv2_v3
hadd -f Run2017B_MCJP.root  Run2017B_MCJP_ID*.root
hadd -f Run2017C_MCJP.root  Run2017C_MCJP_ID*.root
hadd -f Run2017D_MCJP.root  Run2017D_MCJP_ID*.root
hadd -f Run2017Elo_MCJP.root  Run2017Elo_MCJP_ID*.root
hadd -f Run2017Ehi_MCJP.root  Run2017Ehi_MCJP_ID*.root
hadd -f Run2017F_MCJP.root  Run2017F_MCJP_ID*.root

hadd -f Run2017_MCJP.root Run2017B_MCJP.root Run2017C_MCJP.root Run2017D_MCJP.root Run2017Elo_MCJP.root Run2017Ehi_MCJP.root Run2017F_MCJP.root
hadd -f Run2017CDElo_MCJP.root Run2017C_MCJP.root Run2017D_MCJP.root Run2017Elo_MCJP.root
hadd -f Run2017EhiF_MCJP.root Run2017Ehi_MCJP.root Run2017F_MCJP.root
cd ..

cd plots_mc_runBCDEF_SVmass_CSVv2_v3
hadd -f QCD_MuEnriched.root QCD_Pt*.root
cd ..

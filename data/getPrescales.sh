#!/bin/bash
source /cvmfs/cms-bril.cern.ch/cms-lumi-pog/brilws-docker/brilws-env
triggers=(HLT_BTagMu_AK4DiJet20_Mu5 HLT_BTagMu_AK4DiJet40_Mu5 HLT_BTagMu_AK4DiJet70_Mu5 HLT_BTagMu_AK4DiJet110_Mu5 HLT_BTagMu_AK4DiJet170_Mu5 HLT_BTagMu_AK4Jet300_Mu5)
#triggers=(HLT_BTagMu_AK4Jet300_Mu5)
#triggers=(HLT_BTagMu_AK4DiJet170_Mu5)

for i in ${triggers[@]}; do
  echo $i;
  for run in `cat runNumbers2023C.txt`; do
    echo " $run"
    echo "brilcalc trg --prescale --hltpath ${i}_v* -r $run --output-style=csv >> prescalesRun2023C_${i}.txt"
    brilcalc trg --prescale --hltpath ${i}_v* -r $run --output-style=csv >> prescalesRun2023C_${i}.txt
  done  
done


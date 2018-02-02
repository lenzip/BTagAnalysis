#!/bin/bash


#echo "Submitting DATA B...."
#for i in `ls listsFromKirill | grep Run2017B`; do
#  bsub -q cmscaf1nd -o $PWD/logs_data/$i "submitKirill.sh $i 4.8  PileupHistogram_Run2017B_69p2mb_Rereco.root plots_data -d"
#done 
#echo "Submitting DATA C...."
#for i in `ls listsFromKirill | grep Run2017C`; do
#  bsub -q cmscaf1nd -o $PWD/logs_data/$i "submitKirill.sh $i 9.63 PileupHistogram_Run2017C_69p2mb_Rereco.root plots_data -d"
#done
#echo "Submitting DATA B inverted...."
#for i in `ls listsFromKirill_inverted | grep Run2017B`; do
#  bsub -q cmscaf1nd -o $PWD/logs_data_inverted/$i "submitKirill.sh $i 4.8  PileupHistogram_Run2017B_69p2mb_Rereco.root plots_data_inverted -d"
#done
#echo "Submitting DATA C inverted...."
#for i in `ls listsFromKirill_inverted | grep Run2017C`; do
#  bsub -q cmscaf1nd -o $PWD/logs_data_inverted/$i "submitKirill.sh $i 9.63 PileupHistogram_Run2017C_69p2mb_Rereco.root plots_data_inverted -d"
#done

echo "Submitting DATA ...."
for i in `ls listsFromKirill | grep Run2017`; do
  bsub -q cmscaf1nd -o $PWD/logs_data/$i "submitKirill.sh $i 41.213  PileupHistogram_Run2017BCDEF_69p2mb_Rereco.root plots_data -d"
done 
echo "Submitting DATA inverted ...."
for i in `ls listsFromKirill_inverted | grep Run2017`; do
  bsub -q cmscaf1nd -o $PWD/logs_data_inverted/$i "submitKirill_inverted.sh $i 41.213  PileupHistogram_Run2017BCDEF_69p2mb_Rereco.root plots_data -d"
done

echo "Submitting MC runBCDEF...."
for i in `ls listsFromKirill | grep MuEnriched`; do
  bsub -q cmscaf1nd -o $PWD/logs_mc_runbcdef/$i "submitKirill.sh $i 41.213 PileupHistogram_Run2017BCDEF_69p2mb_Rereco.root plots_mc_runBCDEF"
done


#echo "Submitting MC runB...."
#for i in `ls listsFromKirill | grep MuEnriched`; do
#  bsub -q cmscaf1nd -o $PWD/logs_mc_runb/$i "submitKirill.sh $i 4.8 PileupHistogram_Run2017B_69p2mb_Rereco.root plots_mc_runB"
#done
#echo "Submitting MC runC...."
#for i in `ls listsFromKirill | grep MuEnriched`; do
#  bsub -q cmscaf1nd -o $PWD/logs_mc_runc/$i "submitKirill.sh $i 9.63 PileupHistogram_Run2017C_69p2mb_Rereco.root plots_mc_runC"
#done
#echo "Submitting MC run B and C...."
#for i in `ls listsFromKirill | grep MuEnriched`; do
#  bsub -q cmscaf1nd -o $PWD/logs_mc_runbc/$i "submitKirill.sh $i 14.43 PileupHistogram_Run2017BC_69p2mb_Rereco.root plots_mc_runBC"
#done



#!/bin/bash


#echo "Submitting DATA...."
#for i in `ls listsFromKirill | grep BTagMu`; do
#  bsub -q cmscaf1nd -o $PWD/logs/$i "submitKirill.sh $i -d"
#done  
echo "Submitting MC...."
for i in `ls listsFromKirill | grep MuEnriched`; do
  bsub -q cmscaf1nd -o $PWD/logs/$i "submitKirill.sh $i"
done


#!/bin/bash


echo "Submitting DATA...."
for i in `ls lists | grep BTagMu`; do
  bsub -q cmscaf1nd -o $PWD/logs/$i "submit.sh $i -d"
done  
#echo "Submitting MC...."
#for i in `ls lists | grep MuEnriched`; do
#  bsub -q cmscaf1nd -o $PWD/logs/$i "submit.sh $i"
#done


#!/bin/bash
for dataset in `cat datasets.txt`; do
  echo $dataset;
  primaryDataset=`echo $dataset | cut -d"/" -f2`
  echo $primaryDataset
  onefile=`dasgoclient --query "file dataset=$dataset" --limit 1`
  cmsRun ana.py inputFiles=$onefile maxEvents=-1 | grep "After filter: final cross section" 
  python3 getN.py $primaryDataset
done  

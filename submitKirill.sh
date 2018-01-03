#!/bin/bash

export X509_USER_PROXY=/afs/cern.ch/user/l/lenzip/proxy.proxy

base=/afs/cern.ch/user/l/lenzip/work/BTag2017/CMSSW_9_4_1/work/BTagAnalysis

cd $base

eval `scram runtime -sh`
cd -

mkdir $base/plots

outputFile=`basename $1 ".txt"`.root

cp $base/*.py .
cp $base/*.C .
cp $base/*.h .
cp -r $base/data .
cp $base/copy.sh .
./copy.sh $base/listsFromKirill/$1 ./

#echo $outputFile
python loop.py listlocal.txt $base/plots/$outputFile $2 



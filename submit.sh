#!/bin/bash

export X509_USER_PROXY=/afs/cern.ch/user/l/lenzip/proxy.proxy

base=/afs/cern.ch/user/l/lenzip/work/BTag2017/CMSSW_8_0_23/work/

cd $base

eval `scram runtime -sh`
cd -

mkdir $base/plots

outputFile=`basename $1 ".txt"`.root

cp $base/*.py .
cp $base/*.C .
cp $base/*.h .
cp -r $base/data .
#echo $outputFile

python loop.py $base/lists/$1 $base/plots/$outputFile $2 



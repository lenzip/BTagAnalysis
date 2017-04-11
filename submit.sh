#!/bin/bash

export X509_USER_PROXY=/afs/cern.ch/user/l/lenzip/proxy.proxy

base=/afs/cern.ch/user/l/lenzip/work/BTag2017/CMSSW_8_0_23/work/

cd $base

#eval `scram runtime -sh`

mkdir plots

outputFile=`basename $1 ".txt"`.root
#echo $outputFile

python loop.py lists/$1 plots/$outputFile $2 

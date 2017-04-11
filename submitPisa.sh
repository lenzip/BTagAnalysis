#!/bin/bash


base=/home/users/lenzip/BTag/CMSSW_8_0_23/work/BTagAnalysis/

cd $base

eval `scram runtime -sh`

mkdir plots

outputFile=`basename $1 ".txt"`.root
#echo $outputFile

python loop.py lists/$1 plots/$outputFile $2 

#!/bin/bash

export X509_USER_PROXY=/afs/cern.ch/user/l/lenzip/proxy.proxy


i=0
rm listlocal.txt

for filename in `cat $1`; do
  outputFile=`basename $1 ".txt"`_${i}.root
  gfal-copy $filename $2/$outputFile
  echo $outputFile >> listlocal.txt
  i=$(($i+1))
done  


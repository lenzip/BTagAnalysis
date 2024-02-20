#!/bin/bash
export X509_USER_PROXY=/afs/cern.ch/user/l/lenzip/proxy.proxy

source /cvmfs/cms.cern.ch/cmsset_default.sh
base=/afs/cern.ch/work/l/lenzip/BTag2023/2022Prompt/BTagAnalysis_RDF

cd $base/CMSSW_13_1_3

eval `scram runtime -sh`
cd -
pip install --user gfal2-python

list=$1
lumi=$2
puprofile=$3
outdir=$4
isdata=$5

mkdir $base/$outdir

outputFile=`basename $1 ".txt"`.root

cp $base/*.py .
cp $base/*.C .
cp $base/*.h .
cp -r $base/data .
#cp $base/copy.sh .
#./copy.sh $base/listsFromKirill/$1 ./
cp $base/listsFromKirillInverted/$1 ./listlocal.txt

#echo $outputFile
python3 loop_rdf.py -b listlocal.txt $outputFile -l $lumi -p $puprofile $isdata 
cp $outputFile $base/$outdir/$outputFile


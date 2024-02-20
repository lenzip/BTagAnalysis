#!/bin/bash

cp haddfast mc/
cd mc

samplesmc=(QCD_PT-15to20_MuEnrichedPt5 QCD_PT-20to30_MuEnrichedPt5 QCD_PT-30to50_MuEnrichedPt5 QCD_PT-50to80_MuEnrichedPt5 QCD_PT-80to120_MuEnrichedPt5 QCD_PT-120to170_MuEnrichedPt5 QCD_PT-170to300_MuEnrichedPt5 QCD_PT-300to470_MuEnrichedPt5 QCD_PT-470to600_MuEnrichedPt5 QCD_PT-600to800_MuEnrichedPt5 QCD_PT-800to1000_MuEnrichedPt5 QCD_PT-1000_MuEnrichedPt5)
#samplesmc=(QCD_PT-30to50_MuEnrichedPt5 QCD_PT-50to80_MuEnrichedPt5 QCD_PT-80to120_MuEnrichedPt5 QCD_PT-120to170_MuEnrichedPt5 QCD_PT-170to300_MuEnrichedPt5 QCD_PT-300to470_MuEnrichedPt5 QCD_PT-470to600_MuEnrichedPt5 QCD_PT-600to800_MuEnrichedPt5 QCD_PT-800to1000_MuEnrichedPt5 QCD_PT-1000_MuEnrichedPt5)
#samplesmc=(QCD_PT-170to300_MuEnrichedPt5)
#samplesmc=(QCD_PT-800to1000_MuEnrichedPt5 QCD_PT-1000_MuEnrichedPt5)
#samplesmc=(QCD_PT-800to1000_MuEnrichedPt5 QCD_PT-1000_MuEnrichedPt5)
rm tmplist*
for sample in ${samplesmc[@]}; do
  ls ${sample}_TuneCP5_13p6TeV_pythia8_ID* > tmplist
  split -a 3 -l 50 -d tmplist tmplist_
  for ichunk in `ls tmplist_*`; do 
    echo "hadd -j 15 -k -f ${sample}_TuneCP5_13p6TeV_pythia8_${ichunk}.root `cat $ichunk | tr "\n" " "`;"
    hadd -k -j 8 -f ${sample}_TuneCP5_13p6TeV_pythia8_${ichunk}.root `cat $ichunk | tr "\n" " "`;
    cd -
    cd -
  done
  list=""
  for ichunk in `ls tmplist_*`; do
    list="$list ${sample}_TuneCP5_13p6TeV_pythia8_${ichunk}.root"
  done
  echo "hadd -j 5 -k -f ${sample}_TuneCP5_13p6TeV_pythia8.root $list"
  hadd -k -j 5 -f ${sample}_TuneCP5_13p6TeV_pythia8.root $list
  rm tmplist*
done  

list=""
for sample in ${samplesmc[@]}; do
  list="$list ${sample}_TuneCP5_13p6TeV_pythia8.root"
done

hadd -k -f QCD_MuEnriched_rdf_PNetBDisc.root $list
#hadd -k -f QCD_MuEnriched_rdf_inclusive.root $list

cd ..

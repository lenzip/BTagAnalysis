#!/bin/bash

dataDir="/eos/cms/store/group/phys_btag/milee/BTA_addPFMuons_NanoV12_fixPuppi/Summer22EE/"
#dataDirOut="root://xrootd-cms.infn.it///store/user/kskovpen/BTV/MORIOND17JPDEF/BTagMu/"
dataDirOut="/eos/cms/store/group/phys_btag/milee/BTA_addPFMuons_NanoV12_fixPuppi/Summer22EE/"
mcDir="/eos/cms/store/group/phys_btag/milee/BTA_addPFMuons_NanoV12_fixPuppi/Summer22EE/"
#mcDirOut="root://xrootd-cms.infn.it///store/user/kskovpen/BTV/MORIOND17JPDEF/"
mcDirOut="/eos/cms/store/group/phys_btag/milee/BTA_addPFMuons_NanoV12_fixPuppi/Summer22EE/"
dataSubdir1=$(ls $dataDir | grep BTagMu)
mcSubdir1=$(ls $mcDir | grep MuEnrichedPt5)
nFilesDATA=15
nFilesMC=15
outDir="listsFromKirill"

mkdir $outDir

rm /tmp/tempDATA.txt

for dir1 in $dataSubdir1; do
  echo $dir1
  files=$(ls $dataDir/$dir1)
  for file in $files; do
    echo "$dataDirOut/$dir1/$file" >> /tmp/tempDATA.txt  
  done  
  split -a 5 -l ${nFilesDATA} -d /tmp/tempDATA.txt /tmp/${dir1}_
  lsfi=$(ls /tmp/${dir1}_*)
  jid=0
  for fil in $lsfi; do
    sampStrip=$(echo $dir1 | sed -e "s#crab_##g")
    mv ${fil} ${outDir}/${sampStrip}_ID${jid}.txt
    jid=$(( $jid+1 ))
    echo $jid
  done
  rm -f /tmp/tempDATA.txt
done  


#for dir1 in $mcSubdir1; do
#  echo "1",$dir1
#  files=$(ls $mcDir/$dir1)
#  for file in $files; do
#      echo "$mcDirOut/$dir1/$file" >> /tmp/tempMC.txt
#  done
#  split -a 5 -l ${nFilesMC} -d /tmp/tempMC.txt /tmp//${dir1}_
#  lsfi=$(ls /tmp/${dir1}_*)
#  jid=0
#  for fil in $lsfi; do
#    sampStrip=$dir1
#    mv ${fil} ${outDir}/${dir1}_ID${jid}.txt
#    jid=$(( $jid+1 ))
#    echo $jid
#  done
#  rm -f /tmp/tempMC.txt
#done

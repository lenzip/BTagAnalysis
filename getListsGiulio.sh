#!/bin/bash

dataDir="srm://stormfe1.pi.infn.it:8444/srm/managerv2?SFN=/cms/store/user/lenzip/BTag/14Mar/BTagMu/"
dataDirOut="root://xrootd-cms.infn.it///store/user/lenzip/BTag/14Mar/BTagMu/"
mcDir="srm://stormfe1.pi.infn.it:8444/srm/managerv2?SFN=/cms/store/user/lenzip/BTag/14Mar/"
mcDirOut="root://xrootd-cms.infn.it///store/user/lenzip/BTag/14Mar/"
dataSubdir1=$(gfal-ls $dataDir | grep BTagMu)
mcSubdir1=$(gfal-ls $mcDir | grep MuEnriched)

nFilesDATA=10
outDir="lists/"

mkdir $outDir

rm /tmp/tempDATA.txt

for dir1 in $dataSubdir1; do
  echo $dir1
  dataSubdir2=$(gfal-ls $dataDir/$dir1)
  for dir2 in $dataSubdir2; do
    echo $dir2
    dataSubdir3=$(gfal-ls $dataDir/$dir1/$dir2)
    for dir3 in $dataSubdir3; do
      echo $dir3
      files=$(gfal-ls $dataDir/$dir1/$dir2/$dir3 | grep root)
      for file in $files; do
        echo "$dataDirOut/$dir1/$dir2/$dir3/$file" >> /tmp/tempDATA.txt
      done  
    done  
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


for dir1 in $mcSubdir1; do
  echo $dir1
  dataSubdir2=$(gfal-ls $mcDir/$dir1)
  for dir2 in $dataSubdir2; do
    echo $dir2
    dataSubdir3=$(gfal-ls $mcDir/$dir1/$dir2)
    for dir3 in $dataSubdir3; do
      echo $dir3
      dataSubdir4=$(gfal-ls $mcDir/$dir1/$dir2/$dir3)
      for dir4 in $dataSubdir4; do
        files=$(gfal-ls $mcDir/$dir1/$dir2/$dir3/$dir4/ | grep root)
          for file in $files; do
          echo "$mcDirOut/$dir1/$dir2/$dir3/$dir4/$file" >> /tmp/tempMC.txt
        done  
      done 
    done  
  done
  split -a 5 -l ${nFilesDATA} -d /tmp/tempMC.txt /tmp/${dir1}_
  lsfi=$(ls /tmp/${dir1}_*)
  jid=0
  for fil in $lsfi; do
    sampStrip=$dir1
    mv ${fil} ${outDir}/${dir1}_ID${jid}.txt
    jid=$(( $jid+1 ))
    echo $jid
  done
  rm -f /tmp/tempMC.txt
done

#!/bin/bash

dataDir="/gpfs/ddn/srm/cms/store/user/lenzip/BTag/14Mar/BTagMu/"
dataDirOut="/gpfs/ddn/srm/cms/store/user/lenzip/BTag/14Mar/BTagMu/"
mcDir="/gpfs/ddn/srm/cms/store/user/lenzip/BTag/14Mar/"
mcDirOut="/gpfs/ddn/srm/cms/store/user/lenzip/BTag/14Mar/"
dataSubdir1=$(ls $dataDir | grep BTagMu)
mcSubdir1=$(ls $mcDir | grep MuEnriched)

nFilesDATA=5
outDir="lists/"

mkdir $outDir

rm /tmp/tempDATA.txt

for dir1 in $dataSubdir1; do
  echo $dir1
  dataSubdir2=$(ls $dataDir/$dir1)
  for dir2 in $dataSubdir2; do
    echo $dir2
    dataSubdir3=$(ls $dataDir/$dir1/$dir2)
    for dir3 in $dataSubdir3; do
      echo $dir3
      files=$(ls $dataDir/$dir1/$dir2/$dir3 | grep root)
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
  dataSubdir2=$(ls $mcDir/$dir1)
  for dir2 in $dataSubdir2; do
    echo $dir2
    dataSubdir3=$(ls $mcDir/$dir1/$dir2)
    for dir3 in $dataSubdir3; do
      echo $dir3
      dataSubdir4=$(ls $mcDir/$dir1/$dir2/$dir3)
      for dir4 in $dataSubdir4; do
        files=$(ls $mcDir/$dir1/$dir2/$dir3/$dir4/ | grep root)
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

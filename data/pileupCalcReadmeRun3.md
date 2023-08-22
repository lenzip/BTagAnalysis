Since there is no imputLumiJson I did the following:
- To get the per bunch crossing lumi:
`brilcalc lumi --normtag /cvmfs/cms-bril.cern.ch/cms-lumi-pog/Normtags/normtag_BRIL.json  -i run2022FG.json --byls --xing -o /tmp/lenzip/run2022FG_lumi_byls_xing.csv`
- to compute the inputLumiJson:
`makePileupJSON.py /tmp/lenzip/run2022FG_lumi_byls_xing.csv pileup_latext.txt`
- to make the pileup histogram:
`pileupCalc.py -i run2022FG.json --inputLumiJSON pileup_latext.txt --calcMode true --minBiasXsec 69200 --maxPileupBin 100 --numPileupBins 100 MyDataPileupHistogram.root`

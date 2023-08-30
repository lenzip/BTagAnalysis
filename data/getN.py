#!/usr/bin/env python3

import ROOT

import sys

chain=ROOT.TChain("btagana/ttree")
chain.Add("/eos/cms/store/group/phys_btag/coli/BTA_Run3_NANO130X/mc_summer22EE/addPFMuons/"+sys.argv[1]+"/*")

print(sys.argv[1], chain.GetEntries())

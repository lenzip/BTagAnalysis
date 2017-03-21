#!/usr/bin/env python

from ROOT import *
from optparse import OptionParser
import os.path
import sys
from muon import *
from jet import *

def skim(tree, eventSel):
  mylist = TEventList("mylist") 
  tree.Draw(">> mylist", eventSel)
  tree.SetEventList(mylist)
  print "total chain entries:", tree.GetEntries()
  mylist.Print()

def book(outFileName, variables, cuts):
  outFile = TFile(outFileName, "recreate")
  outFile.cd()
  histos={}
  for varname in variables.keys():
    histos[varname]={}
    for cutname in cuts.keys():
      hname = varname+"__"+cutname
      h = TH1F(hname, hname, variables[varname]['nbins'], variables[varname]['xmin'], variables[varname]['xmax'])
      histos[varname][cutname] = h

  return outFile, histos    
    



usage="usage: %prog [options] inputList outputFile"
  
parser = OptionParser(usage=usage)
parser.add_option("-t", action="store", help="tree name from BTagAnalyzer (default=btagana/ttree)", default="btagana/ttree", dest="tree")
parser.add_option("-c", action="store", help="cuts file name (default cuts.py)", default="cuts.py", dest="cutsFile")
parser.add_option("-v", action="store", help="variables file name (default variables.py)", default="variables.py", dest="variablesFile")

(options, args) = parser.parse_args()
if len(args) != 2:
  print parser.print_help() 
  sys.exit(1)

activeBranches=[]

activeBranches.extend([
"PFMuon_isGlobal",
"PFMuon_nMuHit",
"PFMuon_nTkHit",
"PFMuon_nPixHit",
"PFMuon_nOutHit",
"PFMuon_nMatched",
"PFMuon_chi2",
"PFMuon_chi2Tk"]
)

cutsFile = options.cutsFile

if os.path.exists(cutsFile) :
  handle = open(cutsFile,'r')
  exec(handle)
  handle.close()
else:
  print "!!! ERROR file ", cutsFile, " does not exist."
  sys.exit(1)

variablesFile = options.variablesFile  
if os.path.exists(variablesFile) :
  handle = open(variablesFile,'r')
  exec(handle)
  handle.close()
else:
  print "!!! ERROR file ", variablesFile, " does not exist."
  sys.exit(1)


fileList=open(args[0])
outputFile=args[1]
print "creating chain..."
# create a chain with all files in the list
chain = TChain(options.tree)
for line in fileList:
  chain.Add(line)
print "...done"

#skim the chain according to the gloval event selection
#print "skimming..."
#skim(chain, eventsel)
#print "...done"

# book histos
print "booking histos..."
outFile, histos = book(outputFile, variables, cuts)
print "...done"

# disable all branches, then reenable only the used ones
chain.SetBranchStatus("*", 0)
for branch in activeBranches:
  chain.SetBranchStatus(branch, 1)


i=0
for event in chain:
  try:
    i=i+1
    if (i%10==0):
      sys.stdout.write("\rprocessing event %d" %i)
      sys.stdout.flush()

# global event selection    
    if not (eventsel(event)): continue
# prepare lists with jets and leptons    
    nJet=event.nJet
    nPFMuon=event.nPFMuon
    jets=[]
    for IJ in range(nJet):
      jet=Jet(event,IJ)
      if (jet.fourMomentum.Pt()>30. and abs(jet.fourMomentum.Eta()<2.4)):
        jets.append(jet)
    muons=[]
    for IM in range(nPFMuon):
      muon=Muon(event,IM)
      if (muon.fourMomentum.Pt()>5. and abs(muon.fourMomentum.Eta()<2.4)):
        muons.append(muon)
# at least one jet matching an identified muon    
    matchedMuon=False
    for muon in muons:
      if not muon.passMuId(): continue
      for jet in jets:
        if muon.match(jet):
           matchedMuon=True
           break
    if not matchedMuon: continue
# loop over jets, apply jet specific categorization and fill plots   
    for IJ in range(nJet):
      for cut in cuts.keys():
        if cutFunctions[cut](event, IJ):
          for variable in variables.keys():
            histos[variable][cut].Fill(variables[variable]["expression"](event, IJ))
  except KeyboardInterrupt:
    print "\nInterrupted"
    break

print "\n"
outFile.Write()          

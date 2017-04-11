# global event selection
eventsel="(event.nJet>=2 and event.nPFMuon>=1)"

cuts={}


#pt bins for the sf calculation
ptbins=[20., 30., 50., 70., 100., 140., 200., 300., 670., 1000.]
#ptbins=[20.,1000.]

# algorithms for which SF are to be computed and corresponding working points
# the algorithm name must match the branch name in the BTagAnalyzer output, i.e. Jet_<algo>
algos = ["CombIVF"]
wps={
"CombIVF":
  {"L": 0.5426, "M":  0.8484, "T":  0.9535},
}

# flavor names
flavors=["l","b","c"]

# store the list of branches to activate 
# this is very importnt to speed up data access
activeBranches.extend([
"nJet",
"Jet_pt",
"Jet_eta",
"Jet_flavour",
"nPFMuon"
]
)


for algo in algos:
  activeBranches.append("Jet_"+algo)

# loop over the pt bins and flavors to build the jet selection criteria to be used event by event
for ipt in range(len(ptbins)-1):  
  ptmin = str(ptbins[ipt])
  ptmax = str(ptbins[ipt+1])
  
  baseCutName = "ptbin_"+str(ptmin)+"-"+str(ptmax)
  
  cuts[baseCutName] = "((event.Jet_pt[IJ]>"+ptmin+" and event.Jet_pt[IJ]<"+ptmax+")"+ \
                               " and (abs(event.Jet_eta[IJ])<2.4) and (event.Jet_Proba[IJ] != 0))"
  
  cuts[baseCutName+"_JP0"] = cuts[baseCutName] + "*(event.Jet_Proba[IJ]==0)"

  for algo in algos:
    for wp in wps[algo].keys():
      baseCutNameAndTagger=baseCutName+"_"+algo+wp
      cuts[baseCutNameAndTagger] = cuts[baseCutName] + "*(event.Jet_"+algo+"[IJ]>"+str(wps[algo][wp])+ ")"
                               
  for flavor in flavors:
    if flavor == "l":
      baseCutNameAndFlavor = baseCutName+"_l"
      cuts[baseCutNameAndFlavor] = cuts[baseCutName]+("*((event.Jet_flavour[IJ] >= 1 and event.Jet_flavour[IJ]<=3) or event.Jet_flavour[IJ] == 21)") 
    elif flavor == "c":
      baseCutNameAndFlavor = baseCutName+"_c"
      cuts[baseCutNameAndFlavor] = cuts[baseCutName]+("*(event.Jet_flavour[IJ] == 4)")   
    else:
      baseCutNameAndFlavor = baseCutName+"_b"
      cuts[baseCutNameAndFlavor] = cuts[baseCutName]+("*(event.Jet_flavour[IJ] == 5)") 
    
    for algo in algos:
      for wp in wps[algo].keys():
        baseCutNameAndFlavorAndTagger=baseCutNameAndFlavor+"_"+algo+wp
        cuts[baseCutNameAndFlavorAndTagger] = cuts[baseCutNameAndFlavor] + "*(event.Jet_"+algo+"[IJ]>"+str(wps[algo][wp])+ ")"                         
        baseCutNameAndFlavorAndTaggerFail = baseCutNameAndFlavorAndTagger+"_Fail"
        cuts[baseCutNameAndFlavorAndTaggerFail] = cuts[baseCutNameAndFlavor] + "*(event.Jet_"+algo+"[IJ]<="+str(wps[algo][wp])+ ")"

# now transform the strings representing each cut in a 
# lambda function of the event and of the Jet number (IJ)
# (to avoid the need of doing eval at every event)
cutFunctions={}
for cut in cuts.keys():
  #print stringcut
  cutFunctions[cut]=eval("lambda event,IJ:"+cuts[cut])
  #cuts[cut]=lambda event,IJ: eval(stringcut)
  #print cut, cuts[cut]



eventSelString = eventsel
eventsel=eval("lambda event: " + eventSelString)

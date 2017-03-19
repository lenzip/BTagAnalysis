# global event selection
eventsel="(event.nJet>=7)"

cuts={}


#pt bins for the sf calculation
ptbins=[20., 30., 50., 70., 100., 140., 200., 300., 670., 1000.]

# algorithms for which SF are to be computed and corresponding working points
# the algorithm name must match the branch name in the BTagAnalyzer output, i.e. Jet_<algo>
algos = ["cMVAv2"]
wps={
"cMVAv2":
  {"L": -0.715, "M": 0.185, "T": 0.875},
}

# flavor names
flavors=["l","b","c"]


# store the list of branches to activate 
# this is very importnt to speed up data access
activeBranches.extend([
"nJet",
"Jet_pt",
"Jet_eta",
"Jet_flavour"
]
)

for algo in algos:
  activeBranches.append("Jet_"+algo)

# loop over the pt bins and flavors to build the jet selection criteria to be used event by event
for ipt in range(len(ptbins)-1):  
  ptmin = str(ptbins[ipt])
  ptmax = str(ptbins[ipt+1])
  
  baseCutName = "ptbin_"+str(ptmin)+"-"+str(ptmax)
  
  cuts[baseCutName] = "(event.Jet_pt[IJ]>"+ptmin+" and event.Jet_pt[IJ]<"+ptmax+")"+ \
                               "*(abs(event.Jet_eta[IJ])<2.4)"
                               
  for flavor in flavors:
    if flavor == "l":
      baseCutNameAndFlavor = baseCutName+"_l"
      cuts[baseCutNameAndFlavor] = cuts[baseCutName]+("*(event.Jet_flavour[IJ] == 1 or event.Jet_flavour[IJ] == 21)") 
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

# now transform the strings representing each cut in a 
# lambda function of the event and of the Jet number (IJ)
# (to avoid the need of doing eval at every event)
for cut in cuts.keys():
  stringcut=cuts[cut]
  #print stringcut
  cuts[cut] = lambda event, IJ: eval(stringcut)
  #print cut, cuts[cut]i

eventSelString = eventsel
eventsel=lambda event: eval(eventSelString)

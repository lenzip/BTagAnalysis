# global event selection
eventsel="(nJet>=2 and nPFMuon>=1)"

cuts={}


#pt bins for the sf calculation
ptbins=[20, 30, 50, 70, 100, 140, 200, 300, 600, 1000]
#ptbins=[20,1000]

# algorithms for which SF are to be computed and corresponding working points
# the algorithm name must match the branch name in the BTagAnalyzer output, i.e. Jet_<algo>
#algos = ["DeepCSVBDisc"]
#wps={
#"DeepCSVBDisc":
#  {"L": 0.1522, "M":  0.4941, "T":  0.8001},
#}

algos = ["DeepFlavourBDisc"]#, "ParTBDisc", "PNetBDisc"]
wps={
"DeepFlavourBDisc":
  {"L": 0.0614, "M":  0.3196, "T":  0.73,   "XT": 0.8184, "XXT": 0.9542},
#"ParTBDisc":
#  {"L": 0.0897, "M":  0.451,  "T":  0.8604, "XT": 0.9234, "XXT": 0.9893},
#"PNetBDisc":
#  {"L": 0.0499, "M":  0.2605, "T":  0.6915, "XT": 0.8033, "XXT": 0.9664}
}

# flavor names
flavors=["l","b","c"]

# store the list of branches to activate 
# this is very importnt to speed up data access
activeBranches.extend([
"nJet",
"Jet_pT",
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
  
  baseCutName = "ptbin_"+str(ptmin)+"_"+str(ptmax)
  
  cuts[baseCutName] = "((GoodJet_pT>"+ptmin+" && GoodJet_pT<"+ptmax+")"+ \
                               " && (abs(GoodJet_eta)<2.4) && (GoodJet_Proba > 0))"
  
  cuts[baseCutName+"_JP0"] = cuts[baseCutName].replace("GoodJet_Proba > 0","GoodJet_Proba<=0")

  for algo in algos:
    for wp in list(wps[algo].keys()):
      baseCutNameAndTagger=baseCutName+"_"+algo+wp
      cuts[baseCutNameAndTagger] = cuts[baseCutName] + "&& (GoodJet_"+algo+">"+str(wps[algo][wp])+ ")"
      cuts[baseCutNameAndTagger+"SV"] = cuts[baseCutNameAndTagger] + "&& (GoodTagVarCSV_vertexMass>0)"
      cuts[baseCutNameAndTagger+"NoSV"] = cuts[baseCutNameAndTagger] + "&& (GoodTagVarCSV_vertexMass<0)"
      baseCutNameAndTaggerFail=baseCutNameAndTagger+"_Fail"
      cuts[baseCutNameAndTaggerFail] = cuts[baseCutName] + "&& (GoodJet_"+algo+"<="+str(wps[algo][wp])+ ")"
  
  baseCutNameAndSV = baseCutName+"_SV"
  cuts[baseCutNameAndSV] = cuts[baseCutName] + " && (GoodTagVarCSV_vertexMass>0)"
  baseCutNameAndNoSV = baseCutName+"_NoSV"
  cuts[baseCutNameAndNoSV] = cuts[baseCutName] + "&& (GoodTagVarCSV_vertexMass<0)"
  if opzioni.isData:
    continue
  for flavor in flavors:
    if flavor == "l":
      baseCutNameAndFlavor = baseCutName+"_l"
      cuts[baseCutNameAndFlavor] = cuts[baseCutName]+("&& ((abs(GoodJet_flavour) >= 0 && abs(GoodJet_flavour)<=3) || GoodJet_flavour == 21)")
      cuts[baseCutNameAndFlavor+"_JP0"] = cuts[baseCutNameAndFlavor].replace("GoodJet_Proba > 0","GoodJet_Proba<=0")
      cuts[baseCutNameAndFlavor+"_SV"] = cuts[baseCutNameAndFlavor] + ("&& (GoodTagVarCSV_vertexMass>0)")
      cuts[baseCutNameAndFlavor+"_NoSV"] = cuts[baseCutNameAndFlavor] + ("&& (GoodTagVarCSV_vertexMass<0)")
    elif flavor == "c":
      baseCutNameAndFlavor = baseCutName+"_c"
      cuts[baseCutNameAndFlavor] = cuts[baseCutName]+("&& (abs(GoodJet_flavour) == 4)")   
      cuts[baseCutNameAndFlavor+"_JP0"] = cuts[baseCutNameAndFlavor].replace("GoodJet_Proba > 0","GoodJet_Proba<=0")
      cuts[baseCutNameAndFlavor+"_SV"] = cuts[baseCutNameAndFlavor] + ("&& (GoodTagVarCSV_vertexMass>0)")
      cuts[baseCutNameAndFlavor+"_NoSV"] = cuts[baseCutNameAndFlavor] + ("&& (GoodTagVarCSV_vertexMass<0)")            
    else:
      baseCutNameAndFlavor = baseCutName+"_b"
      cuts[baseCutNameAndFlavor] = cuts[baseCutName]+("&& (abs(GoodJet_flavour) == 5)") 
      cuts[baseCutNameAndFlavor+"_JP0"] = cuts[baseCutNameAndFlavor].replace("GoodJet_Proba > 0","GoodJet_Proba<=0")
      cuts[baseCutNameAndFlavor+"_SV"] = cuts[baseCutNameAndFlavor] + ("&& (GoodTagVarCSV_vertexMass>0)")
      cuts[baseCutNameAndFlavor+"_NoSV"] = cuts[baseCutNameAndFlavor] + ("&& (GoodTagVarCSV_vertexMass<0)")

    
    for algo in algos:
      for wp in list(wps[algo].keys()):
        baseCutNameAndFlavorAndTagger=baseCutNameAndFlavor+"_"+algo+wp
        cuts[baseCutNameAndFlavorAndTagger] = cuts[baseCutNameAndFlavor] + "&& (GoodJet_"+algo+">"+str(wps[algo][wp])+ ")"
        cuts[baseCutNameAndFlavorAndTagger+"_SV"] = cuts[baseCutNameAndFlavorAndTagger] + "&& (GoodTagVarCSV_vertexMass>0)"
        cuts[baseCutNameAndFlavorAndTagger+"_NoSV"] = cuts[baseCutNameAndFlavorAndTagger] + "&& (GoodTagVarCSV_vertexMass<0)"
        cuts[baseCutNameAndFlavorAndTagger+"_JP0"] = cuts[baseCutNameAndFlavorAndTagger].replace("GoodJet_Proba > 0","GoodJet_Proba<=0")                         
        baseCutNameAndFlavorAndTaggerFail = baseCutNameAndFlavorAndTagger+"_Fail"
        cuts[baseCutNameAndFlavorAndTaggerFail] = cuts[baseCutNameAndFlavor] + "&& (GoodJet_"+algo+"<="+str(wps[algo][wp])+ ")"



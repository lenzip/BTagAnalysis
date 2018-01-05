variables={}

variables["JP"] = {
  "expression": "min(event.Jet_Proba[IJ], 1.99)",
  "xmin": 0,
  "xmax":  2,
  "nbins":  40 
}

variables["PT"] = {
  "expression": "min(event.Jet_pt[IJ], 599)",
  "xmin": 20,
  "xmax": 600,
  "nbins": 60
}

variables["nPV"] = {
  "expression": "event.nPV",
  "xmin": 0,
  "xmax": 100,
  "nbins": 100

}
activeBranches.extend([
'Jet_Proba',
'Jet_pt',
'nPV'
])

variableFunctions={}

for name in variables.keys():
  variableFunctions[name]=eval("lambda event, IJ: "+variables[name]["expression"])
  

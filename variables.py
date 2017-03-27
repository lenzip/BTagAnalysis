variables={}

variables["JP"] = {
  "expression": "min(event.Jet_Proba[IJ], 1.99)",
  "xmin": 0,
  "xmax":  2,
  "nbins":  20 
}          

variables["PT"] = {
  "expression": "event.Jet_pt[IJ]",
  "xmin": 0,
  "xmax": 1000,
  "nbins": 1000
}

activeBranches.extend([
'Jet_Proba',
'Jet_pt'
])

variableFunctions={}

for name in variables.keys():
  variableFunctions[name]=eval("lambda event, IJ: "+variables[name]["expression"])
  

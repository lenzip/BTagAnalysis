variables={}

variables["JP"] = {
  "expression": "min(event.Jet_Proba[IJ], 1.99)",
  "xmin": 0,
  "xmax":  2,
  "nbins":  40 
}
'''
variables['JPkirill'] = {
  "expression": "min(event.Jet_Proba[IJ], 1.99)",
  "xmin": 0,
  "xmax":  1.7,
  "nbins":  25
}

variables["PT"] = {
  "expression": "min(event.Jet_pt[IJ], 599)",
  "xmin": 20,
  "xmax": 600,
  "nbins": 60
}
'''
activeBranches.extend([
'Jet_Proba',
'Jet_pt'
])

variableFunctions={}

for name in variables.keys():
  variableFunctions[name]=eval("lambda event, IJ: "+variables[name]["expression"])
  

variables={}

variables["JP"] = {
  "expression": "event.Jet_Proba[IJ]",
  "xmin": -10,
  "xmax":  10,
  "nbins":  100
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

for name in variables.keys():
  stringExpression = variables[name]["expression"]
  variables[name]["expression"] = lambda event, IJ: eval(stringExpression)
  

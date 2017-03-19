variables={}

variables["JP"] = {
  "expression": "event.Jet_Proba[IJ]",
  "xmin": -10,
  "xmax":  10,
  "nbins":  100
}          

activeBranches.extend([
'Jet_Proba'
])

for name in variables.keys():
  stringExpression = variables[name]["expression"]
  variables[name]["expression"] = lambda event, IJ: eval(stringExpression)
  

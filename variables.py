variables={}

variables["JP"] = {
  "expression": "min(event.Jet_Proba[IJ], 1.99)",
  "xmin": 0,
  "xmax":  2,
  "nbins":  40 
}

variables["SVmass"] = {
  "expression": "max(-1,event.TagVarCSV_vertexMass[IJ])",
  "xmin": -1,
  "xmax":  10,
  "nbins":  50
}
'''
variables["MuPtOverJetPt"] = {
  "expression": "event.PFMuon_pt[event.associatedMuonIds[IJ]]/event.Jet_pt[IJ] if event.associatedMuonIds[IJ]>= 0 else -10.",
  "xmin": 0,
  "xmax": 1,
  "nbins": 20
}
'''
'''
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

variables["ETA"] = {
  "expression": "event.Jet_eta[IJ]",
  "xmin": -3,
  "xmax": 3,
  "nbins": 60
}

variables["MuPt"] = {
  "expression": "event.PFMuon_pt[event.associatedMuonIds[IJ]] if event.associatedMuonIds[IJ]>= 0 else -10.",
  "xmin": 5,
  "xmax": 100,
  "nbins": 60
}
'''
activeBranches.extend([
'Jet_Proba',
'Jet_pt',
'Jet_eta',
'nPV',
'PFMuon_pt',
'TagVarCSV_vertexMass'
])

variableFunctions={}

for name in variables.keys():
  variableFunctions[name]=eval("lambda event, IJ: "+variables[name]["expression"])
  

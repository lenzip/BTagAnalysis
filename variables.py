variables={}

variables['events'] = {
  'expression': "1",
  'xmin': 0,
  'xmax': 2,
  'nbins': 1
}

variables["JP"] = {
  "expression": "GoodJet_Proba[mask]",
  "xmin": 0,
  "xmax":  2,
  "nbins":  40 
}

variables["SVmass"] = {
  "expression": "GoodTagVarCSV_vertexMass[mask]",
  "xmin": 0,
  "xmax":  10,
  "nbins":  50
}


variables["PT"] = {
  "expression": "GoodJet_pT[mask]",
  "xmin": 20,
  "xmax": 600,
  "nbins": 60
}

variables["ETA"] = {
  "expression": "GoodJet_eta[mask]",
  "xmin": -3,
  "xmax": 3,
  "nbins": 60
}

activeBranches.extend([
'Jet_Proba',
'Jet_pT',
'Jet_eta',
'nPU',
'PFMuon_pt',
'TagVarCSV_vertexMass'
])


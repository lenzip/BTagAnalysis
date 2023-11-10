variables={}

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
'''
variables["MuPtOverJetPt"] = {
  "expression": "event.PFMuon_pt[event.associatedMuonIds[IJ]]/event.Jet_pT[IJ] if event.associatedMuonIds[IJ]>= 0 else -10.",
  "xmin": 0,
  "xmax": 1,
  "nbins": 20
}
'''

variables["PT"] = {
  "expression": "GoodJet_pT[mask]",
  "xmin": 20,
  "xmax": 600,
  "nbins": 60
}
'''
variables["nPU"] = {
  "expression": "event.nPU",
  "xmin": 0,
  "xmax": 100,
  "nbins": 100

}
'''
variables["ETA"] = {
  "expression": "GoodJet_eta[mask]",
  "xmin": -3,
  "xmax": 3,
  "nbins": 60
}
'''
variables["MuPt"] = {
  "expression": "event.PFMuon_pt[event.associatedMuonIds[IJ]] if event.associatedMuonIds[IJ]>= 0 else -10.",
  "xmin": 5,
  "xmax": 100,
  "nbins": 60
}
'''
activeBranches.extend([
'Jet_Proba',
'Jet_pT',
'Jet_eta',
'nPU',
'PFMuon_pt',
'TagVarCSV_vertexMass'
])


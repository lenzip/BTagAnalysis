from ROOT import *

class Jet:
  def __init__(self, event, index):
    l4 = TLorentzVector()
    l4.SetPtEtaPhiM(event.Jet_pt[index], event.Jet_eta[index], event.Jet_phi[index], 0)
    self.fourMomentum = l4
    self.index = index
    self.Jet_Proba = event.Jet_Proba[index]
    self.associatedMuonId = -1.

  def printMe(self):
    print("jet pt", self.fourMomentum.Pt())
    print("jet eta", self.fourMomentum.Eta())
    print("jet JP", self.Jet_Proba)
  
  def associateMuon(self, index):
    self.associatedMuonId = index

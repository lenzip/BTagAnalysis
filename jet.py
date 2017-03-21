from ROOT import *

class Jet:
  def __init__(self, event, index):
    l4 = TLorentzVector()
    l4.SetPtEtaPhiM(event.Jet_pt[index], event.Jet_eta[index], event.Jet_phi[index], 0)
    self.fourMomentum = l4

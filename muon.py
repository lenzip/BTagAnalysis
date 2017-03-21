from ROOT import *

class Muon:
  def __init__(self, event, index):
    l4 = TLorentzVector()
    l4.SetPtEtaPhiM(event.PFMuon_pt[index], event.PFMuon_eta[index], event.PFMuon_phi[index], 0.10566)
    self.fourMomentum = l4
    self.isGlobal = event.PFMuon_isGlobal[index]
    self.nMuHit = event.PFMuon_nMuHit[index]
    self.nTkHit = event.PFMuon_nTkHit[index]
    self.nPixHit = event.PFMuon_nPixHit[index]
    self.nOutHit = event.PFMuon_nOutHit[index]
    self.nMatched = event.PFMuon_nMatched[index]
    self.chi2 = event.PFMuon_chi2[index]
    self.chi2Tk = event.PFMuon_chi2Tk[index]

  def passMuId(self):
    if (self.fourMomentum.Pt() < 5): return False
    if (abs(self.fourMomentum.Eta() > 2.4)): return False
    if (self.isGlobal == 0): return False
    if (self.nMuHit==0): return False
    if (self.nTkHit<11): return False
    if (self.nPixHit<2): return False
    if (self.nOutHit>2): return False
    if (self.nMatched<2): return False
    if (self.chi2>10): return False
    if (self.chi2Tk>10): return False
    return True

  def match(self, jet):
    if self.fourMomentum.DeltaR(jet.fourMomentum) < 0.4:
      return True
    return False  

from ROOT import *

class Muon:
  def __init__(self, event, index):
    l4 = TLorentzVector()
    l4.SetPtEtaPhiM(event.PFMuon_pt[index], event.PFMuon_eta[index], event.PFMuon_phi[index], 0.10566)
    self.fourMomentum = l4
    self.quality = event.PFMuon_GoodQuality[index]
    #self.isGlobal = event.PFMuon_isGlobal[index]
    #self.nMuHit = event.PFMuon_nMuHit[index]
    #self.nTkHit = event.PFMuon_nTkHit[index]
    #self.nPixHit = event.PFMuon_nPixHit[index]
    #self.nOutHit = event.PFMuon_nOutHit[index]
    #self.nMatched = event.PFMuon_nMatched[index]
    #self.chi2 = event.PFMuon_chi2[index]
    #self.chi2Tk = event.PFMuon_chi2Tk[index]
    self.IdxJet = event.PFMuon_IdxJet[index]
    self.index = index
  def passMuId(self):
    if (self.fourMomentum.Pt() < 5): return False
    if (abs(self.fourMomentum.Eta()) > 2.4): return False
    #if (self.isGlobal == 0): return False
    #if (self.nMuHit==0): return False
    #if (self.nTkHit<11): return False
    #if (self.nPixHit<2): return False
    #if (self.nOutHit>2): return False
    #if (self.nMatched<2): return False
    #if (self.chi2>10): return False
    #if (self.chi2Tk>10): return False
    return True
  
  def printMe(self):
    print("muon pt", self.fourMomentum.Pt())
    print("muon eta", self.fourMomentum.Eta())
    print("muon quality", self.quality)
    #print "muon isGlobal", self.isGlobal
    #print "muon nMuHit", self.nMuHit
    #print "muon nTkHit", self.nTkHit
    #print "muon nPixHit", self.nPixHit
    #print "muon nOutHit", self.nOutHit
    #print "muon nMatched", self.nMatched
    #print "muon chi2", self.chi2
    #print "muon chi2Tk", self.chi2Tk
  def match(self, jet):
    if self.fourMomentum.DeltaR(jet.fourMomentum) < 0.4 and self.IdxJet == jet.index:
      #print "muon", self.index, "matching with jet", jet.index
      #self.fourMomentum.Print()
      #jet.fourMomentum.Print()
      return True
    return False  

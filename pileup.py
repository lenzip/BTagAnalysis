from ROOT import *

class Pileup:
  # initialize from a sed of data histograms and corresponding weights 
  # i.e. weight the different periods with data luminosity
  def __init__(self, dataHistos, dataLumis, mcTree):
    self.files=[]
    self.files.append(TFile(dataHistos[0]))
    self.dataHist = self.files[0].Get("pileup").Clone()
    self.dataHist.Scale(1./self.dataHist.Integral())
    self.dataHist.Scale(dataLumis[0])
    for i in range(1, len(dataLumis)):
      self.files.append(TFile(dataHistos[i]))
      h = self.files[i].Get("pileup")
      h.Scale(1./h.Integral())  
      h.Scale(dataLumis[i])
      self.dataHist.Add(h)
    
    self.dataHist.Scale(1./self.dataHist.Integral())
    self.mcHist = self.dataHist.Clone()
    self.mcHist.SetNameTitle("mcPU", "mcPU")
    
    mcTree.Draw("nPUtrue >> mcPU")
    self.mcHist.Scale(1./self.mcHist.Integral())
    self.ratio = self.dataHist.Clone()
    self.ratio.Divide(self.mcHist)

  def getWeight(self, nPU):
    return self.ratio.GetBinContent(self.ratio.FindBin(nPU))





from ROOT import *

class Pileup:
  # initialize from a sed of data histograms and corresponding weights 
  # i.e. weight the different periods with data luminosity
  def __init__(self, dataHistos, dataLumis, mcTree):
    file0 = TFile(dataHistos[0])
    self.dataHist = file0.Get("pileup").Clone()
    self.dataHist.Scale(dataLumis[0])
    for i in range(1, len(dataLumis)):
      filei=TFile(dataHistos[i])
      h = filei.Get("pileup")
      h.Scale(dataLumis[i])
      self.dataHist.Add(h)
    
    self.dataHist.Scale(1./self.dataHist.Integral())
    self.mcHist = self.dataHist.Clone()
    self.mcHist.SetNameTitle("mcPU", "mcPU")
    
    mcTree.Draw("nPUtrue >> mcPU")
    self.ratio = self.dataHist.Clone()
    self.ratio.Divide(self.mcHist)

  def getWeight(self, nPU):
    return self.ratio.GetBinContent(self.ratio.FindBin(nPU))



    



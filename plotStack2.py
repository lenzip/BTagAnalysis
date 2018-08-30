#!/usr/bin/env python

from ROOT import *
import CMS_lumi
CMS_lumi.lumi_13TeV = "42 fb^{-1}"
#CMS_lumi.writeExtraText = 1
#CMS_lumi.writeExtraText2 = 1
CMS_lumi.extraText = "Preliminary"
import sys
import math
import array

gROOT.ProcessLine(".L ~/tdrStyle.C");
setTDRStyle()
gStyle.SetOptStat(0)
gROOT.SetBatch(True)


mc=sys.argv[1]
data=sys.argv[2]
data_inverted=sys.argv[3]
var=sys.argv[4]
ptbin=sys.argv[5]
selection=sys.argv[6]
normalize=sys.argv[7]

mcfile = TFile(mc)
datafile = TFile(data)
datafile_inverted = TFile(data_inverted)
print var+"__"+ptbin+"_l"+selection

handle = open("systematics.py",'r')
exec(handle)
handle.close()
allSystematics = []
allSystematics.extend(weightSystematics)
allSystematics.extend(shapeSystematics)


hl = mcfile.Get(var+"__"+ptbin+"_l"+selection)
hl.SetFillColor(4)
hl.SetLineColor(4)
hc = mcfile.Get(var+"__"+ptbin+"_c"+selection)
hc.SetFillColor(3)
hc.SetLineColor(3)
hb = mcfile.Get(var+"__"+ptbin+"_b"+selection)
hb.SetFillColor(2)
hb.SetLineColor(2)




htotalmc = hl.Clone()
htotalmc.Add(hc)
htotalmc.Add(hb)

systSquareUp=[]
systSquareDo=[]

for ibin in range(1, htotalmc.GetNbinsX()+1):
  systSquareUp.append(0.)
  systSquareDo.append(0.)

for syst in allSystematics:
  print syst
  htotalUp = mcfile.Get(hl.GetName()+"_"+syst+"_up")
  htotalDo = mcfile.Get(hl.GetName()+"_"+syst+"_do")
  hcUp     = mcfile.Get(hc.GetName()+"_"+syst+"_up")
  hcDo     = mcfile.Get(hc.GetName()+"_"+syst+"_do")
  hbUp     = mcfile.Get(hb.GetName()+"_"+syst+"_up")
  hbDo     = mcfile.Get(hb.GetName()+"_"+syst+"_do")

  htotalUp.Add(hcUp)
  htotalUp.Add(hbUp)
  htotalDo.Add(hcDo)
  htotalDo.Add(hbDo)


  for ibin in range(1, htotalmc.GetNbinsX()+1):
    if htotalUp.GetBinContent(ibin) - htotalmc.GetBinContent(ibin) >  0:
      systSquareUp[ibin-1] += (htotalUp.GetBinContent(ibin) - htotalmc.GetBinContent(ibin))**2
    if htotalUp.GetBinContent(ibin) - htotalmc.GetBinContent(ibin) <= 0:
      systSquareDo[ibin-1] += (htotalUp.GetBinContent(ibin) - htotalmc.GetBinContent(ibin))**2
    if htotalDo.GetBinContent(ibin) - htotalmc.GetBinContent(ibin) >  0:
      systSquareUp[ibin-1] += (htotalDo.GetBinContent(ibin) - htotalmc.GetBinContent(ibin))**2
    if htotalDo.GetBinContent(ibin) - htotalmc.GetBinContent(ibin) <= 0:
      systSquareDo[ibin-1] += (htotalDo.GetBinContent(ibin) - htotalmc.GetBinContent(ibin))**2   



x = array.array('f')
y = array.array('f')
yr= array.array('f')
xl = array.array('f')
xh = array.array('f')
yl = array.array('f')
yh = array.array('f')
ylratio = array.array('f')
yhratio = array.array('f')

for ibin in range(1, htotalmc.GetNbinsX()+1):
  x.append(htotalmc.GetBinCenter(ibin))
  xl.append(htotalmc.GetBinWidth (ibin) / 2.)
  xh.append(htotalmc.GetBinWidth (ibin) / 2.)
  yr.append(1.)
  if normalize != None:
    y.append(htotalmc.GetBinContent (ibin)/htotalmc.Integral())
    yl.append(math.sqrt(systSquareDo[ibin-1])/htotalmc.Integral())
    yh.append(math.sqrt(systSquareUp[ibin-1])/htotalmc.Integral())
    ylratio.append(math.sqrt(systSquareDo[ibin-1])/htotalmc.GetBinContent (ibin) if htotalmc.GetBinContent (ibin)> 0 else 0.)
    yhratio.append(math.sqrt(systSquareUp[ibin-1])/htotalmc.GetBinContent (ibin) if htotalmc.GetBinContent (ibin)> 0 else 0.)
  else:
    y.append(htotalmc.GetBinContent (ibin))
    yl.append(math.sqrt(systSquareDo[ibin-1]))
    yh.append(math.sqrt(systSquareUp[ibin-1]))
    ylratio.append(math.sqrt(systSquareDo[ibin-1])/htotalmc.GetBinContent (ibin) if htotalmc.GetBinContent (ibin) > 0 else 0.)
    yhratio.append(math.sqrt(systSquareUp[ibin-1])/htotalmc.GetBinContent (ibin) if htotalmc.GetBinContent (ibin) > 0 else 0.)

tgrMC      = TGraphAsymmErrors()
tgrMCRatio = TGraphAsymmErrors()
#print math.sqrt(systSquareDo[0]), htotalmc.GetBinContent (1), htotalmc.Integral(), ylratio[0]
tgrMC.SetLineColor(12)
tgrMC.SetFillColor(12)
tgrMC.SetLineWidth(2)
tgrMC.SetFillStyle(3004)
tgrMCRatio.SetLineColor(12)
tgrMCRatio.SetFillColor(12)
tgrMCRatio.SetLineWidth(2)
tgrMCRatio.SetFillStyle(3004)
for iBin in range(0, len(x)) : 
  tgrMC.SetPoint     (iBin, x[iBin], y[iBin])
  tgrMC.SetPointError(iBin, xl[iBin], xh[iBin], yl[iBin], yh[iBin])
  tgrMCRatio.SetPoint     (iBin, x[iBin], yr[iBin])
  tgrMCRatio.SetPointError(iBin, xl[iBin], xh[iBin], ylratio[iBin], yhratio[iBin])

if normalize != None:
  hl.Scale(1./htotalmc.Integral())
  hc.Scale(1./htotalmc.Integral())
  hb.Scale(1./htotalmc.Integral())
  htotalmc.Scale(1./htotalmc.Integral())

stack = THStack()
stack.Add(hl)
stack.Add(hc)
stack.Add(hb)


hdata=datafile.Get(var+"__"+ptbin+""+selection)
hdata.SetMarkerStyle(20)
hdata.SetLineWidth(2)
hdata_inverted=datafile_inverted.Get(var+"__"+ptbin+""+selection)
hdata_inverted.SetNameTitle("inverted", "inverted")
hdata_inverted.SetMarkerStyle(21)
hdata_inverted.SetLineWidth(2)

legend=TLegend(0.7, 0.7, 0.9, 0.9)
legend.SetBorderSize(0)
legend.SetFillColor(0)
legend.AddEntry(hb, "b jets", "f")
legend.AddEntry(hc, "c jets", "f")
legend.AddEntry(hl, "light jets", "f")
legend.AddEntry(hdata, "data", "lp")
legend.AddEntry(hdata_inverted, "data (MC Calib)", "lp")

if normalize != None:
  hdata.Scale(1./hdata.Integral())
  hdata_inverted.Scale(1./hdata_inverted.Integral())

hratio=hdata.Clone()
hratio.Divide(htotalmc)

hratio_inverted=hdata_inverted.Clone()
hratio_inverted.Divide(htotalmc)

c = TCanvas()
pad1 = TPad("pad1", "pad1", 0, 1-0.72, 1, 1)
pad1.Draw()
pad1.cd()
stack.Draw("HIST")
tgrMC.Draw("2")
hdata.Draw("sames")
hdata_inverted.Draw("sames")
legend.Draw("same")
CMS_lumi.CMS_lumi(pad1, 4, 11)
pad1.RedrawAxis()
c.cd()
pad2 = TPad("pad2", "pad2",0,0,1,1-0.72)
pad2.SetTopMargin(0.000)
pad2.SetBottomMargin(0.392)
pad2.Draw()
pad2.cd()
oneLine = TLine(hratio.GetXaxis().GetXmin(), 1,  hratio.GetXaxis().GetXmax(), 1);
oneLine.SetLineStyle(3)
oneLine.SetLineWidth(3)
hratio.GetXaxis().SetLabelSize(0.15)
hratio.GetYaxis().SetLabelSize(0.15)
hratio.GetYaxis().SetRangeUser(0., 2.)
hratio.GetYaxis().SetNdivisions(508)
hratio.Draw()
hratio_inverted.Draw("same")
tgrMCRatio.Draw("2")
#oneLine.Draw("same")
pad2.SetGridy()
pad2.RedrawAxis()
c.SaveAs("pics/"+var+"__"+ptbin+""+selection+".png")
pad1.cd()
pad1.SetLogy()
c.SaveAs("pics/log_"+var+"__"+ptbin+""+selection+".png")
#a=raw_input("ciao")

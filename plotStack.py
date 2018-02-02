#!/usr/bin/env python

from ROOT import *
import CMS_lumi
CMS_lumi.lumi_13TeV = "4.2 fb^{-1}"
#CMS_lumi.writeExtraText = 1
#CMS_lumi.writeExtraText2 = 1
CMS_lumi.extraText = "Preliminary"
import sys

gROOT.ProcessLine(".L ~/tdrStyle.C");
setTDRStyle()
gStyle.SetOptStat(0)

mc=sys.argv[1]
data=sys.argv[2]
var=sys.argv[3]
ptbin=sys.argv[4]
selection=sys.argv[5]
normalize=sys.argv[6]

mcfile = TFile(mc)
datafile = TFile(data)
print var+"__"+ptbin+"_l"+selection

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

legend=TLegend(0.7, 0.7, 0.9, 0.9)
legend.SetBorderSize(0)
legend.SetFillColor(0)
legend.AddEntry(hb, "b jets", "f")
legend.AddEntry(hc, "c jets", "f")
legend.AddEntry(hl, "light jets", "f")
legend.AddEntry(hdata, "data", "lp")

if normalize != None:
  hdata.Scale(1./hdata.Integral())

hratio=hdata.Clone()
hratio.Divide(htotalmc)

c = TCanvas()
pad1 = TPad("pad1", "pad1", 0, 1-0.72, 1, 1)
pad1.Draw()
pad1.cd()
stack.Draw("HIST")
hdata.Draw("sames")
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
hratio.Draw()
oneLine.Draw("same")
pad2.SetGridy()
pad2.RedrawAxis()
gPad.Update()
c.SaveAs("pics/"+var+"__"+ptbin+""+selection+".png")
#a=raw_input("ciao")

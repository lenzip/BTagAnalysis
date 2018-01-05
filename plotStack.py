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

mcfile = TFile(mc)
datafile = TFile(data)

hl = mcfile.Get(var+"__ptbin_20.0-1000.0_l")
hl.SetFillColor(4)
hl.SetLineColor(4)
hc = mcfile.Get(var+"__ptbin_20.0-1000.0_c")
hc.SetFillColor(3)
hc.SetLineColor(3)
hb = mcfile.Get(var+"__ptbin_20.0-1000.0_b")
hb.SetFillColor(2)
hb.SetLineColor(2)

stack = THStack()
stack.Add(hl)
stack.Add(hc)
stack.Add(hb)

htotalmc = hl.Clone()
htotalmc.Add(hc)
htotalmc.Add(hb)

hdata=datafile.Get(var+"__ptbin_20.0-1000.0")
hdata.SetMarkerStyle(20)
hdata.SetLineWidth(2)

hratio=hdata.Clone()
hratio.Divide(htotalmc)

c = TCanvas()
pad1 = TPad("pad1", "pad1", 0, 1-0.72, 1, 1)
pad1.Draw()
pad1.cd()
stack.Draw("HIST")
hdata.Draw("sames")
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
a=raw_input("ciao")

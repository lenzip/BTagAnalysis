//////////////////////////////////////////////////////////
// This class has been automatically generated on
// Thu Apr 13 10:18:18 2017 by ROOT version 5.34/36
// from TTree ttree/ttree
// found on file: root://xrootd-cms.infn.it//store/user/lenzip/BTag/14Mar/QCD_Pt-50to80_MuEnrichedPt5_TuneCUETP8M1_13TeV_pythia8/crab_QCD_Pt-50to80/170314_155932/0000/JetTree_mc_18.root
//////////////////////////////////////////////////////////

#ifndef BTagAnalyzerSelector_h
#define BTagAnalyzerSelector_h

#include <TROOT.h>
#include <TChain.h>
#include <TFile.h>
#include <TSelector.h>

// Header file for the classes stored in the TTree if any.

// Fixed size dimensions of array or collections stored in the TTree if any.

class BTagAnalyzerSelector : public TSelector {
public :
   TTree          *fChain;   //!pointer to the analyzed TTree or TChain

   // Declaration of leaf types
   Int_t           nBitTrigger;
   Int_t           BitTrigger[2];   //[nBitTrigger]
   Int_t           Run;
   Int_t           Evt;
   Int_t           LumiBlock;
   Float_t         pthat;
   Float_t         mcweight;
   Int_t           BX;
   Int_t           nPV;
   Float_t         PVz;
   Float_t         PVez;
   Float_t         GenPVz;
   Float_t         nPUtrue;
   Int_t           nPU;
   Int_t           PU_bunch[82];   //[nPU]
   Float_t         PU_z[82];   //[nPU]
   Float_t         PU_sumpT_low[82];   //[nPU]
   Float_t         PU_sumpT_high[82];   //[nPU]
   Int_t           PU_ntrks_low[82];   //[nPU]
   Int_t           PU_ntrks_high[82];   //[nPU]
   Int_t           ncQuarks;
   Float_t         cQuark_pT[1];   //[ncQuarks]
   Float_t         cQuark_eta[1];   //[ncQuarks]
   Float_t         cQuark_phi[1];   //[ncQuarks]
   Int_t           cQuark_pdgID[1];   //[ncQuarks]
   Int_t           cQuark_status[1];   //[ncQuarks]
   Int_t           cQuark_fromGSP[1];   //[ncQuarks]
   Int_t           nbQuarks;
   Float_t         bQuark_pT[1];   //[nbQuarks]
   Float_t         bQuark_eta[1];   //[nbQuarks]
   Float_t         bQuark_phi[1];   //[nbQuarks]
   Int_t           bQuark_pdgID[1];   //[nbQuarks]
   Int_t           bQuark_status[1];   //[nbQuarks]
   Int_t           bQuark_fromGSP[1];   //[nbQuarks]
   Int_t           nBHadrons;
   Float_t         BHadron_pT[12];   //[nBHadrons]
   Float_t         BHadron_eta[12];   //[nBHadrons]
   Float_t         BHadron_phi[12];   //[nBHadrons]
   Float_t         BHadron_mass[12];   //[nBHadrons]
   Int_t           BHadron_pdgID[12];   //[nBHadrons]
   Int_t           BHadron_mother[12];   //[nBHadrons]
   Int_t           BHadron_hasBdaughter[12];   //[nBHadrons]
   Float_t         BHadron_SVx[12];   //[nBHadrons]
   Float_t         BHadron_SVy[12];   //[nBHadrons]
   Float_t         BHadron_SVz[12];   //[nBHadrons]
   Int_t           BHadron_nCharged[12];   //[nBHadrons]
   Int_t           BHadron_DHadron1[12];   //[nBHadrons]
   Int_t           BHadron_DHadron2[12];   //[nBHadrons]
   Int_t           nDHadrons;
   Int_t           nDaughters;
   Float_t         DHadron_pT[15];   //[nDHadrons]
   Float_t         DHadron_eta[15];   //[nDHadrons]
   Float_t         DHadron_phi[15];   //[nDHadrons]
   Int_t           DHadron_pdgID[15];   //[nDHadrons]
   Float_t         DHadron_mass[15];   //[nDHadrons]
   Float_t         DHadron_SVx[15];   //[nDHadrons]
   Float_t         DHadron_SVy[15];   //[nDHadrons]
   Float_t         DHadron_SVz[15];   //[nDHadrons]
   Int_t           DHadron_nDaughters[15];   //[nDHadrons]
   Int_t           DHadron_DaughtersPdgID[16];   //[nDaughters]
   Int_t           DHadron_nChargedDaughters[15];   //[nDHadrons]
   Int_t           DHadron_nCharged[15];   //[nDHadrons]
   Int_t           nGenlep;
   Float_t         Genlep_pT[6];   //[nGenlep]
   Float_t         Genlep_eta[6];   //[nGenlep]
   Float_t         Genlep_phi[6];   //[nGenlep]
   Int_t           Genlep_pdgID[6];   //[nGenlep]
   Int_t           Genlep_status[6];   //[nGenlep]
   Int_t           Genlep_mother[6];   //[nGenlep]
   Int_t           nGenquark;
   Float_t         Genquark_pT[2];   //[nGenquark]
   Float_t         Genquark_eta[2];   //[nGenquark]
   Float_t         Genquark_phi[2];   //[nGenquark]
   Int_t           Genquark_pdgID[2];   //[nGenquark]
   Int_t           Genquark_mother[2];   //[nGenquark]
   Int_t           nGenPruned;
   Float_t         GenPruned_pT[43];   //[nGenPruned]
   Float_t         GenPruned_eta[43];   //[nGenPruned]
   Float_t         GenPruned_phi[43];   //[nGenPruned]
   Float_t         GenPruned_mass[43];   //[nGenPruned]
   Int_t           GenPruned_pdgID[43];   //[nGenPruned]
   Int_t           GenPruned_status[43];   //[nGenPruned]
   Int_t           GenPruned_mother[43];   //[nGenPruned]
   Int_t           nGenV0;
   Float_t         GenV0_pT[2];   //[nGenV0]
   Float_t         GenV0_eta[2];   //[nGenV0]
   Float_t         GenV0_phi[2];   //[nGenV0]
   Int_t           GenV0_pdgID[2];   //[nGenV0]
   Float_t         GenV0_SVx[2];   //[nGenV0]
   Float_t         GenV0_SVy[2];   //[nGenV0]
   Float_t         GenV0_SVz[2];   //[nGenV0]
   Int_t           GenV0_nCharged[2];   //[nGenV0]
   Int_t           nJet;
   Float_t         Jet_pt[10];   //[nJet]
   Float_t         Jet_uncorrpt[10];   //[nJet]
   Float_t         Jet_genpt[10];   //[nJet]
   Float_t         Jet_residual[10];   //[nJet]
   Float_t         Jet_area[10];   //[nJet]
   Float_t         Jet_jes[10];   //[nJet]
   Float_t         Jet_eta[10];   //[nJet]
   Float_t         Jet_phi[10];   //[nJet]
   Float_t         Jet_mass[10];   //[nJet]
   Int_t           Jet_ntracks[10];   //[nJet]
   Int_t           Jet_nseltracks[10];   //[nJet]
   Int_t           Jet_flavour[10];   //[nJet]
   Int_t           Jet_flavourCleaned[10];   //[nJet]
   Int_t           Jet_partonFlavour[10];   //[nJet]
   Int_t           Jet_hadronFlavour[10];   //[nJet]
   Int_t           Jet_nbHadrons[10];   //[nJet]
   Int_t           Jet_ncHadrons[10];   //[nJet]
   Float_t         Jet_Ip2N[10];   //[nJet]
   Float_t         Jet_Ip2P[10];   //[nJet]
   Float_t         Jet_Ip3N[10];   //[nJet]
   Float_t         Jet_Ip3P[10];   //[nJet]
   Float_t         Jet_DeepCSVBDisc[10];   //[nJet]
   Float_t         Jet_DeepCSVBDiscN[10];   //[nJet]
   Float_t         Jet_DeepCSVBDiscP[10];   //[nJet]
   Float_t         Jet_DeepCSVCvsLDisc[10];   //[nJet]
   Float_t         Jet_DeepCSVCvsLDiscN[10];   //[nJet]
   Float_t         Jet_DeepCSVCvsLDiscP[10];   //[nJet]
   Float_t         Jet_DeepCSVCvsBDisc[10];   //[nJet]
   Float_t         Jet_DeepCSVCvsBDiscN[10];   //[nJet]
   Float_t         Jet_DeepCSVCvsBDiscP[10];   //[nJet]
   Float_t         Jet_DeepCSVb[10];   //[nJet]
   Float_t         Jet_DeepCSVc[10];   //[nJet]
   Float_t         Jet_DeepCSVl[10];   //[nJet]
   Float_t         Jet_DeepCSVbb[10];   //[nJet]
   Float_t         Jet_DeepCSVcc[10];   //[nJet]
   Float_t         Jet_DeepCSVbN[10];   //[nJet]
   Float_t         Jet_DeepCSVcN[10];   //[nJet]
   Float_t         Jet_DeepCSVlN[10];   //[nJet]
   Float_t         Jet_DeepCSVbbN[10];   //[nJet]
   Float_t         Jet_DeepCSVccN[10];   //[nJet]
   Float_t         Jet_DeepCSVbP[10];   //[nJet]
   Float_t         Jet_DeepCSVcP[10];   //[nJet]
   Float_t         Jet_DeepCSVlP[10];   //[nJet]
   Float_t         Jet_DeepCSVbbP[10];   //[nJet]
   Float_t         Jet_DeepCSVccP[10];   //[nJet]
   Float_t         Jet_ProbaN[10];   //[nJet]
   Float_t         Jet_ProbaP[10];   //[nJet]
   Float_t         Jet_Proba[10];   //[nJet]
   Float_t         Jet_BprobN[10];   //[nJet]
   Float_t         Jet_BprobP[10];   //[nJet]
   Float_t         Jet_Bprob[10];   //[nJet]
   Float_t         Jet_SvxN[10];   //[nJet]
   Float_t         Jet_Svx[10];   //[nJet]
   Float_t         Jet_SvxNHP[10];   //[nJet]
   Float_t         Jet_SvxHP[10];   //[nJet]
   Float_t         Jet_CombSvxN[10];   //[nJet]
   Float_t         Jet_CombSvxP[10];   //[nJet]
   Float_t         Jet_CombSvx[10];   //[nJet]
   Float_t         Jet_CombIVF[10];   //[nJet]
   Float_t         Jet_CombIVF_P[10];   //[nJet]
   Float_t         Jet_CombIVF_N[10];   //[nJet]
   Float_t         Jet_SoftMuN[10];   //[nJet]
   Float_t         Jet_SoftMuP[10];   //[nJet]
   Float_t         Jet_SoftMu[10];   //[nJet]
   Float_t         Jet_SoftElN[10];   //[nJet]
   Float_t         Jet_SoftElP[10];   //[nJet]
   Float_t         Jet_SoftEl[10];   //[nJet]
   Float_t         Jet_cMVA[10];   //[nJet]
   Float_t         Jet_cMVAv2[10];   //[nJet]
   Float_t         Jet_cMVAv2N[10];   //[nJet]
   Float_t         Jet_cMVAv2P[10];   //[nJet]
   Int_t           Jet_hist1[10];   //[nJet]
   Int_t           Jet_hist2[10];   //[nJet]
   Int_t           Jet_hist3[10];   //[nJet]
   Int_t           Jet_histJet[10];   //[nJet]
   Int_t           Jet_histSvx[10];   //[nJet]
   Int_t           Jet_SV_multi[10];   //[nJet]
   Int_t           Jet_nSM[10];   //[nJet]
   Int_t           Jet_nSE[10];   //[nJet]
   Int_t           Jet_looseID[10];   //[nJet]
   Int_t           Jet_tightID[10];   //[nJet]
   Float_t         Jet_trackSip2dSig_AboveBottom_0[10];   //[nJet]
   Float_t         Jet_trackSip2dSig_AboveBottom_1[10];   //[nJet]
   Int_t           Jet_nFirstSE[10];   //[nJet]
   Int_t           Jet_nLastSE[10];   //[nJet]
   Int_t           nPFElectron;
   Int_t           PFElectron_IdxJet[5];   //[nPFElectron]
   Float_t         PFElectron_pt[5];   //[nPFElectron]
   Float_t         PFElectron_eta[5];   //[nPFElectron]
   Float_t         PFElectron_phi[5];   //[nPFElectron]
   Float_t         PFElectron_ptrel[5];   //[nPFElectron]
   Float_t         PFElectron_deltaR[5];   //[nPFElectron]
   Float_t         PFElectron_ratio[5];   //[nPFElectron]
   Float_t         PFElectron_ratioRel[5];   //[nPFElectron]
   Float_t         PFElectron_IP[5];   //[nPFElectron]
   Float_t         PFElectron_IP2D[5];   //[nPFElectron]
   Int_t           Jet_nFirstSM[10];   //[nJet]
   Int_t           Jet_nLastSM[10];   //[nJet]
   Int_t           nPFMuon;
   Int_t           PFMuon_IdxJet[5];   //[nPFMuon]
   Int_t           PFMuon_nMuHit[5];   //[nPFMuon]
   Int_t           PFMuon_nTkHit[5];   //[nPFMuon]
   Int_t           PFMuon_nPixHit[5];   //[nPFMuon]
   Int_t           PFMuon_nOutHit[5];   //[nPFMuon]
   Int_t           PFMuon_nTkLwM[5];   //[nPFMuon]
   Int_t           PFMuon_nPixLwM[5];   //[nPFMuon]
   Int_t           PFMuon_nMatched[5];   //[nPFMuon]
   Float_t         PFMuon_chi2[5];   //[nPFMuon]
   Float_t         PFMuon_chi2Tk[5];   //[nPFMuon]
   Int_t           PFMuon_isGlobal[5];   //[nPFMuon]
   Int_t           PFMuon_hist[5];   //[nPFMuon]
   Float_t         PFMuon_pt[5];   //[nPFMuon]
   Float_t         PFMuon_eta[5];   //[nPFMuon]
   Float_t         PFMuon_phi[5];   //[nPFMuon]
   Float_t         PFMuon_ptrel[5];   //[nPFMuon]
   Float_t         PFMuon_deltaR[5];   //[nPFMuon]
   Float_t         PFMuon_ratio[5];   //[nPFMuon]
   Float_t         PFMuon_ratioRel[5];   //[nPFMuon]
   Float_t         PFMuon_IP[5];   //[nPFMuon]
   Float_t         PFMuon_IP2D[5];   //[nPFMuon]
   Float_t         PFMuon_IPsig[5];   //[nPFMuon]
   Float_t         PFMuon_IP2Dsig[5];   //[nPFMuon]
   Float_t         PFMuon_dz[5];   //[nPFMuon]
   Int_t           PFMuon_GoodQuality[5];   //[nPFMuon]
   Int_t           Jet_nFirstTrkTagVarCSV[10];   //[nJet]
   Int_t           Jet_nLastTrkTagVarCSV[10];   //[nJet]
   Int_t           Jet_nFirstTrkEtaRelTagVarCSV[10];   //[nJet]
   Int_t           Jet_nLastTrkEtaRelTagVarCSV[10];   //[nJet]
   Float_t         TagVarCSV_trackJetPt[10];   //[nJet]
   Float_t         TagVarCSV_jetNTracks[10];   //[nJet]
   Float_t         TagVarCSV_jetNTracksEtaRel[10];   //[nJet]
   Float_t         TagVarCSV_trackSumJetEtRatio[10];   //[nJet]
   Float_t         TagVarCSV_trackSumJetDeltaR[10];   //[nJet]
   Float_t         TagVarCSV_trackSip2dValAboveCharm[10];   //[nJet]
   Float_t         TagVarCSV_trackSip2dSigAboveCharm[10];   //[nJet]
   Float_t         TagVarCSV_trackSip3dValAboveCharm[10];   //[nJet]
   Float_t         TagVarCSV_trackSip3dSigAboveCharm[10];   //[nJet]
   Float_t         TagVarCSV_vertexCategory[10];   //[nJet]
   Float_t         TagVarCSV_jetNSecondaryVertices[10];   //[nJet]
   Float_t         TagVarCSV_vertexMass[10];   //[nJet]
   Float_t         TagVarCSV_vertexNTracks[10];   //[nJet]
   Float_t         TagVarCSV_vertexEnergyRatio[10];   //[nJet]
   Float_t         TagVarCSV_vertexJetDeltaR[10];   //[nJet]
   Float_t         TagVarCSV_flightDistance2dVal[10];   //[nJet]
   Float_t         TagVarCSV_flightDistance2dSig[10];   //[nJet]
   Float_t         TagVarCSV_flightDistance3dVal[10];   //[nJet]
   Float_t         TagVarCSV_flightDistance3dSig[10];   //[nJet]
   Int_t           nTrkTagVarCSV;
   Int_t           nTrkEtaRelTagVarCSV;
   Float_t         TagVarCSV_trackMomentum[42];   //[nTrkTagVarCSV]
   Float_t         TagVarCSV_trackEta[42];   //[nTrkTagVarCSV]
   Float_t         TagVarCSV_trackPhi[42];   //[nTrkTagVarCSV]
   Float_t         TagVarCSV_trackPtRel[42];   //[nTrkTagVarCSV]
   Float_t         TagVarCSV_trackPPar[42];   //[nTrkTagVarCSV]
   Float_t         TagVarCSV_trackDeltaR[42];   //[nTrkTagVarCSV]
   Float_t         TagVarCSV_trackPtRatio[42];   //[nTrkTagVarCSV]
   Float_t         TagVarCSV_trackPParRatio[42];   //[nTrkTagVarCSV]
   Float_t         TagVarCSV_trackSip2dVal[42];   //[nTrkTagVarCSV]
   Float_t         TagVarCSV_trackSip2dSig[42];   //[nTrkTagVarCSV]
   Float_t         TagVarCSV_trackSip3dVal[42];   //[nTrkTagVarCSV]
   Float_t         TagVarCSV_trackSip3dSig[42];   //[nTrkTagVarCSV]
   Float_t         TagVarCSV_trackDecayLenVal[42];   //[nTrkTagVarCSV]
   Float_t         TagVarCSV_trackDecayLenSig[42];   //[nTrkTagVarCSV]
   Float_t         TagVarCSV_trackJetDistVal[42];   //[nTrkTagVarCSV]
   Float_t         TagVarCSV_trackJetDistSig[42];   //[nTrkTagVarCSV]
   Float_t         TagVarCSV_trackEtaRel[22];   //[nTrkEtaRelTagVarCSV]

   //new branches to add
   Float_t         gluonSplittingWeightUp[100];
   Float_t         gluonSplittingWeightDo[100];

   // List of branches
   TBranch        *b_nBitTrigger;   //!
   TBranch        *b_BitTrigger;   //!
   TBranch        *b_Run;   //!
   TBranch        *b_Evt;   //!
   TBranch        *b_LumiBlock;   //!
   TBranch        *b_pthat;   //!
   TBranch        *b_mcweight;   //!
   TBranch        *b_BX;   //!
   TBranch        *b_nPV;   //!
   TBranch        *b_PVz;   //!
   TBranch        *b_PVez;   //!
   TBranch        *b_GenPVz;   //!
   TBranch        *b_nPUtrue;   //!
   TBranch        *b_nPU;   //!
   TBranch        *b_PU_bunch;   //!
   TBranch        *b_PU_z;   //!
   TBranch        *b_PU_sumpT_low;   //!
   TBranch        *b_PU_sumpT_high;   //!
   TBranch        *b_PU_ntrks_low;   //!
   TBranch        *b_PU_ntrks_high;   //!
   TBranch        *b_ncQuarks;   //!
   TBranch        *b_cQuark_pT;   //!
   TBranch        *b_cQuark_eta;   //!
   TBranch        *b_cQuark_phi;   //!
   TBranch        *b_cQuark_pdgID;   //!
   TBranch        *b_cQuark_status;   //!
   TBranch        *b_cQuark_fromGSP;   //!
   TBranch        *b_nbQuarks;   //!
   TBranch        *b_bQuark_pT;   //!
   TBranch        *b_bQuark_eta;   //!
   TBranch        *b_bQuark_phi;   //!
   TBranch        *b_bQuark_pdgID;   //!
   TBranch        *b_bQuark_status;   //!
   TBranch        *b_bQuark_fromGSP;   //!
   TBranch        *b_nBHadrons;   //!
   TBranch        *b_BHadron_pT;   //!
   TBranch        *b_BHadron_eta;   //!
   TBranch        *b_BHadron_phi;   //!
   TBranch        *b_BHadron_mass;   //!
   TBranch        *b_BHadron_pdgID;   //!
   TBranch        *b_BHadron_mother;   //!
   TBranch        *b_BHadron_hasBdaughter;   //!
   TBranch        *b_BHadron_SVx;   //!
   TBranch        *b_BHadron_SVy;   //!
   TBranch        *b_BHadron_SVz;   //!
   TBranch        *b_BHadron_nCharged;   //!
   TBranch        *b_BHadron_DHadron1;   //!
   TBranch        *b_BHadron_DHadron2;   //!
   TBranch        *b_nDHadrons;   //!
   TBranch        *b_nDaughters;   //!
   TBranch        *b_DHadron_pT;   //!
   TBranch        *b_DHadron_eta;   //!
   TBranch        *b_DHadron_phi;   //!
   TBranch        *b_DHadron_pdgID;   //!
   TBranch        *b_DHadron_mass;   //!
   TBranch        *b_DHadron_SVx;   //!
   TBranch        *b_DHadron_SVy;   //!
   TBranch        *b_DHadron_SVz;   //!
   TBranch        *b_DHadron_nDaughters;   //!
   TBranch        *b_DHadron_DaughtersPdgID;   //!
   TBranch        *b_DHadron_nChargedDaughters;   //!
   TBranch        *b_DHadron_nCharged;   //!
   TBranch        *b_nGenlep;   //!
   TBranch        *b_Genlep_pT;   //!
   TBranch        *b_Genlep_eta;   //!
   TBranch        *b_Genlep_phi;   //!
   TBranch        *b_Genlep_pdgID;   //!
   TBranch        *b_Genlep_status;   //!
   TBranch        *b_Genlep_mother;   //!
   TBranch        *b_nGenquark;   //!
   TBranch        *b_Genquark_pT;   //!
   TBranch        *b_Genquark_eta;   //!
   TBranch        *b_Genquark_phi;   //!
   TBranch        *b_Genquark_pdgID;   //!
   TBranch        *b_Genquark_mother;   //!
   TBranch        *b_nGenPruned;   //!
   TBranch        *b_GenPruned_pT;   //!
   TBranch        *b_GenPruned_eta;   //!
   TBranch        *b_GenPruned_phi;   //!
   TBranch        *b_GenPruned_mass;   //!
   TBranch        *b_GenPruned_pdgID;   //!
   TBranch        *b_GenPruned_status;   //!
   TBranch        *b_GenPruned_mother;   //!
   TBranch        *b_nGenV0;   //!
   TBranch        *b_GenV0_pT;   //!
   TBranch        *b_GenV0_eta;   //!
   TBranch        *b_GenV0_phi;   //!
   TBranch        *b_GenV0_pdgID;   //!
   TBranch        *b_GenV0_SVx;   //!
   TBranch        *b_GenV0_SVy;   //!
   TBranch        *b_GenV0_SVz;   //!
   TBranch        *b_GenV0_nCharged;   //!
   TBranch        *b_nJet;   //!
   TBranch        *b_Jet_pt;   //!
   TBranch        *b_Jet_uncorrpt;   //!
   TBranch        *b_Jet_genpt;   //!
   TBranch        *b_Jet_residual;   //!
   TBranch        *b_Jet_area;   //!
   TBranch        *b_Jet_jes;   //!
   TBranch        *b_Jet_eta;   //!
   TBranch        *b_Jet_phi;   //!
   TBranch        *b_Jet_mass;   //!
   TBranch        *b_Jet_ntracks;   //!
   TBranch        *b_Jet_nseltracks;   //!
   TBranch        *b_Jet_flavour;   //!
   TBranch        *b_Jet_flavourCleaned;   //!
   TBranch        *b_Jet_partonFlavour;   //!
   TBranch        *b_Jet_hadronFlavour;   //!
   TBranch        *b_Jet_nbHadrons;   //!
   TBranch        *b_Jet_ncHadrons;   //!
   TBranch        *b_Jet_Ip2N;   //!
   TBranch        *b_Jet_Ip2P;   //!
   TBranch        *b_Jet_Ip3N;   //!
   TBranch        *b_Jet_Ip3P;   //!
   TBranch        *b_Jet_DeepCSVBDisc;   //!
   TBranch        *b_Jet_DeepCSVBDiscN;   //!
   TBranch        *b_Jet_DeepCSVBDiscP;   //!
   TBranch        *b_Jet_DeepCSVCvsLDisc;   //!
   TBranch        *b_Jet_DeepCSVCvsLDiscN;   //!
   TBranch        *b_Jet_DeepCSVCvsLDiscP;   //!
   TBranch        *b_Jet_DeepCSVCvsBDisc;   //!
   TBranch        *b_Jet_DeepCSVCvsBDiscN;   //!
   TBranch        *b_Jet_DeepCSVCvsBDiscP;   //!
   TBranch        *b_Jet_DeepCSVb;   //!
   TBranch        *b_Jet_DeepCSVc;   //!
   TBranch        *b_Jet_DeepCSVl;   //!
   TBranch        *b_Jet_DeepCSVbb;   //!
   TBranch        *b_Jet_DeepCSVcc;   //!
   TBranch        *b_Jet_DeepCSVbN;   //!
   TBranch        *b_Jet_DeepCSVcN;   //!
   TBranch        *b_Jet_DeepCSVlN;   //!
   TBranch        *b_Jet_DeepCSVbbN;   //!
   TBranch        *b_Jet_DeepCSVccN;   //!
   TBranch        *b_Jet_DeepCSVbP;   //!
   TBranch        *b_Jet_DeepCSVcP;   //!
   TBranch        *b_Jet_DeepCSVlP;   //!
   TBranch        *b_Jet_DeepCSVbbP;   //!
   TBranch        *b_Jet_DeepCSVccP;   //!
   TBranch        *b_Jet_ProbaN;   //!
   TBranch        *b_Jet_ProbaP;   //!
   TBranch        *b_Jet_Proba;   //!
   TBranch        *b_Jet_BprobN;   //!
   TBranch        *b_Jet_BprobP;   //!
   TBranch        *b_Jet_Bprob;   //!
   TBranch        *b_Jet_SvxN;   //!
   TBranch        *b_Jet_Svx;   //!
   TBranch        *b_Jet_SvxNHP;   //!
   TBranch        *b_Jet_SvxHP;   //!
   TBranch        *b_Jet_CombSvxN;   //!
   TBranch        *b_Jet_CombSvxP;   //!
   TBranch        *b_Jet_CombSvx;   //!
   TBranch        *b_Jet_CombIVF;   //!
   TBranch        *b_Jet_CombIVF_P;   //!
   TBranch        *b_Jet_CombIVF_N;   //!
   TBranch        *b_Jet_SoftMuN;   //!
   TBranch        *b_Jet_SoftMuP;   //!
   TBranch        *b_Jet_SoftMu;   //!
   TBranch        *b_Jet_SoftElN;   //!
   TBranch        *b_Jet_SoftElP;   //!
   TBranch        *b_Jet_SoftEl;   //!
   TBranch        *b_Jet_cMVA;   //!
   TBranch        *b_Jet_cMVAv2;   //!
   TBranch        *b_Jet_cMVAv2N;   //!
   TBranch        *b_Jet_cMVAv2P;   //!
   TBranch        *b_Jet_hist1;   //!
   TBranch        *b_Jet_hist2;   //!
   TBranch        *b_Jet_hist3;   //!
   TBranch        *b_Jet_histJet;   //!
   TBranch        *b_Jet_histSvx;   //!
   TBranch        *b_Jet_SV_multi;   //!
   TBranch        *b_Jet_nSM;   //!
   TBranch        *b_Jet_nSE;   //!
   TBranch        *b_Jet_looseID;   //!
   TBranch        *b_Jet_tightID;   //!
   TBranch        *b_Jet_trackSip2dSig_AboveBottom_0;   //!
   TBranch        *b_Jet_trackSip2dSig_AboveBottom_1;   //!
   TBranch        *b_Jet_nFirstSE;   //!
   TBranch        *b_Jet_nLastSE;   //!
   TBranch        *b_nPFElectron;   //!
   TBranch        *b_PFElectron_IdxJet;   //!
   TBranch        *b_PFElectron_pt;   //!
   TBranch        *b_PFElectron_eta;   //!
   TBranch        *b_PFElectron_phi;   //!
   TBranch        *b_PFElectron_ptrel;   //!
   TBranch        *b_PFElectron_deltaR;   //!
   TBranch        *b_PFElectron_ratio;   //!
   TBranch        *b_PFElectron_ratioRel;   //!
   TBranch        *b_PFElectron_IP;   //!
   TBranch        *b_PFElectron_IP2D;   //!
   TBranch        *b_Jet_nFirstSM;   //!
   TBranch        *b_Jet_nLastSM;   //!
   TBranch        *b_nPFMuon;   //!
   TBranch        *b_PFMuon_IdxJet;   //!
   TBranch        *b_PFMuon_nMuHit;   //!
   TBranch        *b_PFMuon_nTkHit;   //!
   TBranch        *b_PFMuon_nPixHit;   //!
   TBranch        *b_PFMuon_nOutHit;   //!
   TBranch        *b_PFMuon_nTkLwM;   //!
   TBranch        *b_PFMuon_nPixLwM;   //!
   TBranch        *b_PFMuon_nMatched;   //!
   TBranch        *b_PFMuon_chi2;   //!
   TBranch        *b_PFMuon_chi2Tk;   //!
   TBranch        *b_PFMuon_isGlobal;   //!
   TBranch        *b_PFMuon_hist;   //!
   TBranch        *b_PFMuon_pt;   //!
   TBranch        *b_PFMuon_eta;   //!
   TBranch        *b_PFMuon_phi;   //!
   TBranch        *b_PFMuon_ptrel;   //!
   TBranch        *b_PFMuon_deltaR;   //!
   TBranch        *b_PFMuon_ratio;   //!
   TBranch        *b_PFMuon_ratioRel;   //!
   TBranch        *b_PFMuon_IP;   //!
   TBranch        *b_PFMuon_IP2D;   //!
   TBranch        *b_PFMuon_IPsig;   //!
   TBranch        *b_PFMuon_IP2Dsig;   //!
   TBranch        *b_PFMuon_dz;   //!
   TBranch        *b_PFMuon_GoodQuality;   //!
   TBranch        *b_Jet_nFirstTrkTagVarCSV;   //!
   TBranch        *b_Jet_nLastTrkTagVarCSV;   //!
   TBranch        *b_Jet_nFirstTrkEtaRelTagVarCSV;   //!
   TBranch        *b_Jet_nLastTrkEtaRelTagVarCSV;   //!
   TBranch        *b_TagVarCSV_trackJetPt;   //!
   TBranch        *b_TagVarCSV_jetNTracks;   //!
   TBranch        *b_TagVarCSV_jetNTracksEtaRel;   //!
   TBranch        *b_TagVarCSV_trackSumJetEtRatio;   //!
   TBranch        *b_TagVarCSV_trackSumJetDeltaR;   //!
   TBranch        *b_TagVarCSV_trackSip2dValAboveCharm;   //!
   TBranch        *b_TagVarCSV_trackSip2dSigAboveCharm;   //!
   TBranch        *b_TagVarCSV_trackSip3dValAboveCharm;   //!
   TBranch        *b_TagVarCSV_trackSip3dSigAboveCharm;   //!
   TBranch        *b_TagVarCSV_vertexCategory;   //!
   TBranch        *b_TagVarCSV_jetNSecondaryVertices;   //!
   TBranch        *b_TagVarCSV_vertexMass;   //!
   TBranch        *b_TagVarCSV_vertexNTracks;   //!
   TBranch        *b_TagVarCSV_vertexEnergyRatio;   //!
   TBranch        *b_TagVarCSV_vertexJetDeltaR;   //!
   TBranch        *b_TagVarCSV_flightDistance2dVal;   //!
   TBranch        *b_TagVarCSV_flightDistance2dSig;   //!
   TBranch        *b_TagVarCSV_flightDistance3dVal;   //!
   TBranch        *b_TagVarCSV_flightDistance3dSig;   //!
   TBranch        *b_nTrkTagVarCSV;   //!
   TBranch        *b_nTrkEtaRelTagVarCSV;   //!
   TBranch        *b_TagVarCSV_trackMomentum;   //!
   TBranch        *b_TagVarCSV_trackEta;   //!
   TBranch        *b_TagVarCSV_trackPhi;   //!
   TBranch        *b_TagVarCSV_trackPtRel;   //!
   TBranch        *b_TagVarCSV_trackPPar;   //!
   TBranch        *b_TagVarCSV_trackDeltaR;   //!
   TBranch        *b_TagVarCSV_trackPtRatio;   //!
   TBranch        *b_TagVarCSV_trackPParRatio;   //!
   TBranch        *b_TagVarCSV_trackSip2dVal;   //!
   TBranch        *b_TagVarCSV_trackSip2dSig;   //!
   TBranch        *b_TagVarCSV_trackSip3dVal;   //!
   TBranch        *b_TagVarCSV_trackSip3dSig;   //!
   TBranch        *b_TagVarCSV_trackDecayLenVal;   //!
   TBranch        *b_TagVarCSV_trackDecayLenSig;   //!
   TBranch        *b_TagVarCSV_trackJetDistVal;   //!
   TBranch        *b_TagVarCSV_trackJetDistSig;   //!
   TBranch        *b_TagVarCSV_trackEtaRel;   //!

   //new branches to add
   TBranch        *b_gluonSplittingWeightUp;
   TBranch        *b_gluonSplittingWeightDo;


   BTagAnalyzerSelector(TTree * /*tree*/ =0) : fChain(0) { }
   virtual ~BTagAnalyzerSelector() { }
   virtual Int_t   Version() const { return 2; }
   virtual void    Begin(TTree *tree);
   virtual void    SlaveBegin(TTree *tree);
   virtual void    Init(TTree *tree);
   virtual Bool_t  Notify();
   virtual Bool_t  Process(Long64_t entry);
   virtual Int_t   GetEntry(Long64_t entry, Int_t getall = 0) { return fChain ? fChain->GetTree()->GetEntry(entry, getall) : 0; }
   virtual void    SetOption(const char *option) { fOption = option; }
   virtual void    SetObject(TObject *obj) { fObject = obj; }
   virtual void    SetInputList(TList *input) { fInput = input; }
   virtual TList  *GetOutputList() const { return fOutput; }
   virtual void    SlaveTerminate();
   virtual void    Terminate();
   void cleanForNewEvent();
   void fillNewBranches();
   void GluonSplitting(int ij);

   ClassDef(BTagAnalyzerSelector,0);
};

#endif

#ifdef BTagAnalyzerSelector_cxx
void BTagAnalyzerSelector::Init(TTree *tree)
{
   // The Init() function is called when the selector needs to initialize
   // a new tree or chain. Typically here the branch addresses and branch
   // pointers of the tree will be set.
   // It is normally not necessary to make changes to the generated
   // code, but the routine can be extended by the user if needed.
   // Init() will be called many times when running on PROOF
   // (once per file to be processed).

   // Set branch addresses and branch pointers
   if (!tree) return;
   fChain = tree;
   fChain->SetMakeClass(1);

   fChain->SetBranchAddress("nBitTrigger", &nBitTrigger, &b_nBitTrigger);
   fChain->SetBranchAddress("BitTrigger", BitTrigger, &b_BitTrigger);
   fChain->SetBranchAddress("Run", &Run, &b_Run);
   fChain->SetBranchAddress("Evt", &Evt, &b_Evt);
   fChain->SetBranchAddress("LumiBlock", &LumiBlock, &b_LumiBlock);
   fChain->SetBranchAddress("pthat", &pthat, &b_pthat);
   fChain->SetBranchAddress("mcweight", &mcweight, &b_mcweight);
   fChain->SetBranchAddress("BX", &BX, &b_BX);
   fChain->SetBranchAddress("nPV", &nPV, &b_nPV);
   fChain->SetBranchAddress("PVz", &PVz, &b_PVz);
   fChain->SetBranchAddress("PVez", &PVez, &b_PVez);
   fChain->SetBranchAddress("GenPVz", &GenPVz, &b_GenPVz);
   fChain->SetBranchAddress("nPUtrue", &nPUtrue, &b_nPUtrue);
   fChain->SetBranchAddress("nPU", &nPU, &b_nPU);
   fChain->SetBranchAddress("PU_bunch", PU_bunch, &b_PU_bunch);
   fChain->SetBranchAddress("PU_z", PU_z, &b_PU_z);
   fChain->SetBranchAddress("PU_sumpT_low", PU_sumpT_low, &b_PU_sumpT_low);
   fChain->SetBranchAddress("PU_sumpT_high", PU_sumpT_high, &b_PU_sumpT_high);
   fChain->SetBranchAddress("PU_ntrks_low", PU_ntrks_low, &b_PU_ntrks_low);
   fChain->SetBranchAddress("PU_ntrks_high", PU_ntrks_high, &b_PU_ntrks_high);
   fChain->SetBranchAddress("ncQuarks", &ncQuarks, &b_ncQuarks);
   fChain->SetBranchAddress("cQuark_pT", &cQuark_pT, &b_cQuark_pT);
   fChain->SetBranchAddress("cQuark_eta", &cQuark_eta, &b_cQuark_eta);
   fChain->SetBranchAddress("cQuark_phi", &cQuark_phi, &b_cQuark_phi);
   fChain->SetBranchAddress("cQuark_pdgID", &cQuark_pdgID, &b_cQuark_pdgID);
   fChain->SetBranchAddress("cQuark_status", &cQuark_status, &b_cQuark_status);
   fChain->SetBranchAddress("cQuark_fromGSP", &cQuark_fromGSP, &b_cQuark_fromGSP);
   fChain->SetBranchAddress("nbQuarks", &nbQuarks, &b_nbQuarks);
   fChain->SetBranchAddress("bQuark_pT", &bQuark_pT, &b_bQuark_pT);
   fChain->SetBranchAddress("bQuark_eta", &bQuark_eta, &b_bQuark_eta);
   fChain->SetBranchAddress("bQuark_phi", &bQuark_phi, &b_bQuark_phi);
   fChain->SetBranchAddress("bQuark_pdgID", &bQuark_pdgID, &b_bQuark_pdgID);
   fChain->SetBranchAddress("bQuark_status", &bQuark_status, &b_bQuark_status);
   fChain->SetBranchAddress("bQuark_fromGSP", &bQuark_fromGSP, &b_bQuark_fromGSP);
   fChain->SetBranchAddress("nBHadrons", &nBHadrons, &b_nBHadrons);
   fChain->SetBranchAddress("BHadron_pT", BHadron_pT, &b_BHadron_pT);
   fChain->SetBranchAddress("BHadron_eta", BHadron_eta, &b_BHadron_eta);
   fChain->SetBranchAddress("BHadron_phi", BHadron_phi, &b_BHadron_phi);
   fChain->SetBranchAddress("BHadron_mass", BHadron_mass, &b_BHadron_mass);
   fChain->SetBranchAddress("BHadron_pdgID", BHadron_pdgID, &b_BHadron_pdgID);
   fChain->SetBranchAddress("BHadron_mother", BHadron_mother, &b_BHadron_mother);
   fChain->SetBranchAddress("BHadron_hasBdaughter", BHadron_hasBdaughter, &b_BHadron_hasBdaughter);
   fChain->SetBranchAddress("BHadron_SVx", BHadron_SVx, &b_BHadron_SVx);
   fChain->SetBranchAddress("BHadron_SVy", BHadron_SVy, &b_BHadron_SVy);
   fChain->SetBranchAddress("BHadron_SVz", BHadron_SVz, &b_BHadron_SVz);
   fChain->SetBranchAddress("BHadron_nCharged", BHadron_nCharged, &b_BHadron_nCharged);
   fChain->SetBranchAddress("BHadron_DHadron1", BHadron_DHadron1, &b_BHadron_DHadron1);
   fChain->SetBranchAddress("BHadron_DHadron2", BHadron_DHadron2, &b_BHadron_DHadron2);
   fChain->SetBranchAddress("nDHadrons", &nDHadrons, &b_nDHadrons);
   fChain->SetBranchAddress("nDaughters", &nDaughters, &b_nDaughters);
   fChain->SetBranchAddress("DHadron_pT", DHadron_pT, &b_DHadron_pT);
   fChain->SetBranchAddress("DHadron_eta", DHadron_eta, &b_DHadron_eta);
   fChain->SetBranchAddress("DHadron_phi", DHadron_phi, &b_DHadron_phi);
   fChain->SetBranchAddress("DHadron_pdgID", DHadron_pdgID, &b_DHadron_pdgID);
   fChain->SetBranchAddress("DHadron_mass", DHadron_mass, &b_DHadron_mass);
   fChain->SetBranchAddress("DHadron_SVx", DHadron_SVx, &b_DHadron_SVx);
   fChain->SetBranchAddress("DHadron_SVy", DHadron_SVy, &b_DHadron_SVy);
   fChain->SetBranchAddress("DHadron_SVz", DHadron_SVz, &b_DHadron_SVz);
   fChain->SetBranchAddress("DHadron_nDaughters", DHadron_nDaughters, &b_DHadron_nDaughters);
   fChain->SetBranchAddress("DHadron_DaughtersPdgID", DHadron_DaughtersPdgID, &b_DHadron_DaughtersPdgID);
   fChain->SetBranchAddress("DHadron_nChargedDaughters", DHadron_nChargedDaughters, &b_DHadron_nChargedDaughters);
   fChain->SetBranchAddress("DHadron_nCharged", DHadron_nCharged, &b_DHadron_nCharged);
   fChain->SetBranchAddress("nGenlep", &nGenlep, &b_nGenlep);
   fChain->SetBranchAddress("Genlep_pT", Genlep_pT, &b_Genlep_pT);
   fChain->SetBranchAddress("Genlep_eta", Genlep_eta, &b_Genlep_eta);
   fChain->SetBranchAddress("Genlep_phi", Genlep_phi, &b_Genlep_phi);
   fChain->SetBranchAddress("Genlep_pdgID", Genlep_pdgID, &b_Genlep_pdgID);
   fChain->SetBranchAddress("Genlep_status", Genlep_status, &b_Genlep_status);
   fChain->SetBranchAddress("Genlep_mother", Genlep_mother, &b_Genlep_mother);
   fChain->SetBranchAddress("nGenquark", &nGenquark, &b_nGenquark);
   fChain->SetBranchAddress("Genquark_pT", Genquark_pT, &b_Genquark_pT);
   fChain->SetBranchAddress("Genquark_eta", Genquark_eta, &b_Genquark_eta);
   fChain->SetBranchAddress("Genquark_phi", Genquark_phi, &b_Genquark_phi);
   fChain->SetBranchAddress("Genquark_pdgID", Genquark_pdgID, &b_Genquark_pdgID);
   fChain->SetBranchAddress("Genquark_mother", Genquark_mother, &b_Genquark_mother);
   fChain->SetBranchAddress("nGenPruned", &nGenPruned, &b_nGenPruned);
   fChain->SetBranchAddress("GenPruned_pT", GenPruned_pT, &b_GenPruned_pT);
   fChain->SetBranchAddress("GenPruned_eta", GenPruned_eta, &b_GenPruned_eta);
   fChain->SetBranchAddress("GenPruned_phi", GenPruned_phi, &b_GenPruned_phi);
   fChain->SetBranchAddress("GenPruned_mass", GenPruned_mass, &b_GenPruned_mass);
   fChain->SetBranchAddress("GenPruned_pdgID", GenPruned_pdgID, &b_GenPruned_pdgID);
   fChain->SetBranchAddress("GenPruned_status", GenPruned_status, &b_GenPruned_status);
   fChain->SetBranchAddress("GenPruned_mother", GenPruned_mother, &b_GenPruned_mother);
   fChain->SetBranchAddress("nGenV0", &nGenV0, &b_nGenV0);
   fChain->SetBranchAddress("GenV0_pT", GenV0_pT, &b_GenV0_pT);
   fChain->SetBranchAddress("GenV0_eta", GenV0_eta, &b_GenV0_eta);
   fChain->SetBranchAddress("GenV0_phi", GenV0_phi, &b_GenV0_phi);
   fChain->SetBranchAddress("GenV0_pdgID", GenV0_pdgID, &b_GenV0_pdgID);
   fChain->SetBranchAddress("GenV0_SVx", GenV0_SVx, &b_GenV0_SVx);
   fChain->SetBranchAddress("GenV0_SVy", GenV0_SVy, &b_GenV0_SVy);
   fChain->SetBranchAddress("GenV0_SVz", GenV0_SVz, &b_GenV0_SVz);
   fChain->SetBranchAddress("GenV0_nCharged", GenV0_nCharged, &b_GenV0_nCharged);
   fChain->SetBranchAddress("nJet", &nJet, &b_nJet);
   fChain->SetBranchAddress("Jet_pt", Jet_pt, &b_Jet_pt);
   fChain->SetBranchAddress("Jet_uncorrpt", Jet_uncorrpt, &b_Jet_uncorrpt);
   fChain->SetBranchAddress("Jet_genpt", Jet_genpt, &b_Jet_genpt);
   fChain->SetBranchAddress("Jet_residual", Jet_residual, &b_Jet_residual);
   fChain->SetBranchAddress("Jet_area", Jet_area, &b_Jet_area);
   fChain->SetBranchAddress("Jet_jes", Jet_jes, &b_Jet_jes);
   fChain->SetBranchAddress("Jet_eta", Jet_eta, &b_Jet_eta);
   fChain->SetBranchAddress("Jet_phi", Jet_phi, &b_Jet_phi);
   fChain->SetBranchAddress("Jet_mass", Jet_mass, &b_Jet_mass);
   fChain->SetBranchAddress("Jet_ntracks", Jet_ntracks, &b_Jet_ntracks);
   fChain->SetBranchAddress("Jet_nseltracks", Jet_nseltracks, &b_Jet_nseltracks);
   fChain->SetBranchAddress("Jet_flavour", Jet_flavour, &b_Jet_flavour);
   fChain->SetBranchAddress("Jet_flavourCleaned", Jet_flavourCleaned, &b_Jet_flavourCleaned);
   fChain->SetBranchAddress("Jet_partonFlavour", Jet_partonFlavour, &b_Jet_partonFlavour);
   fChain->SetBranchAddress("Jet_hadronFlavour", Jet_hadronFlavour, &b_Jet_hadronFlavour);
   fChain->SetBranchAddress("Jet_nbHadrons", Jet_nbHadrons, &b_Jet_nbHadrons);
   fChain->SetBranchAddress("Jet_ncHadrons", Jet_ncHadrons, &b_Jet_ncHadrons);
   fChain->SetBranchAddress("Jet_Ip2N", Jet_Ip2N, &b_Jet_Ip2N);
   fChain->SetBranchAddress("Jet_Ip2P", Jet_Ip2P, &b_Jet_Ip2P);
   fChain->SetBranchAddress("Jet_Ip3N", Jet_Ip3N, &b_Jet_Ip3N);
   fChain->SetBranchAddress("Jet_Ip3P", Jet_Ip3P, &b_Jet_Ip3P);
   fChain->SetBranchAddress("Jet_DeepCSVBDisc", Jet_DeepCSVBDisc, &b_Jet_DeepCSVBDisc);
   fChain->SetBranchAddress("Jet_DeepCSVBDiscN", Jet_DeepCSVBDiscN, &b_Jet_DeepCSVBDiscN);
   fChain->SetBranchAddress("Jet_DeepCSVBDiscP", Jet_DeepCSVBDiscP, &b_Jet_DeepCSVBDiscP);
   fChain->SetBranchAddress("Jet_DeepCSVCvsLDisc", Jet_DeepCSVCvsLDisc, &b_Jet_DeepCSVCvsLDisc);
   fChain->SetBranchAddress("Jet_DeepCSVCvsLDiscN", Jet_DeepCSVCvsLDiscN, &b_Jet_DeepCSVCvsLDiscN);
   fChain->SetBranchAddress("Jet_DeepCSVCvsLDiscP", Jet_DeepCSVCvsLDiscP, &b_Jet_DeepCSVCvsLDiscP);
   fChain->SetBranchAddress("Jet_DeepCSVCvsBDisc", Jet_DeepCSVCvsBDisc, &b_Jet_DeepCSVCvsBDisc);
   fChain->SetBranchAddress("Jet_DeepCSVCvsBDiscN", Jet_DeepCSVCvsBDiscN, &b_Jet_DeepCSVCvsBDiscN);
   fChain->SetBranchAddress("Jet_DeepCSVCvsBDiscP", Jet_DeepCSVCvsBDiscP, &b_Jet_DeepCSVCvsBDiscP);
   fChain->SetBranchAddress("Jet_DeepCSVb", Jet_DeepCSVb, &b_Jet_DeepCSVb);
   fChain->SetBranchAddress("Jet_DeepCSVc", Jet_DeepCSVc, &b_Jet_DeepCSVc);
   fChain->SetBranchAddress("Jet_DeepCSVl", Jet_DeepCSVl, &b_Jet_DeepCSVl);
   fChain->SetBranchAddress("Jet_DeepCSVbb", Jet_DeepCSVbb, &b_Jet_DeepCSVbb);
   fChain->SetBranchAddress("Jet_DeepCSVcc", Jet_DeepCSVcc, &b_Jet_DeepCSVcc);
   fChain->SetBranchAddress("Jet_DeepCSVbN", Jet_DeepCSVbN, &b_Jet_DeepCSVbN);
   fChain->SetBranchAddress("Jet_DeepCSVcN", Jet_DeepCSVcN, &b_Jet_DeepCSVcN);
   fChain->SetBranchAddress("Jet_DeepCSVlN", Jet_DeepCSVlN, &b_Jet_DeepCSVlN);
   fChain->SetBranchAddress("Jet_DeepCSVbbN", Jet_DeepCSVbbN, &b_Jet_DeepCSVbbN);
   fChain->SetBranchAddress("Jet_DeepCSVccN", Jet_DeepCSVccN, &b_Jet_DeepCSVccN);
   fChain->SetBranchAddress("Jet_DeepCSVbP", Jet_DeepCSVbP, &b_Jet_DeepCSVbP);
   fChain->SetBranchAddress("Jet_DeepCSVcP", Jet_DeepCSVcP, &b_Jet_DeepCSVcP);
   fChain->SetBranchAddress("Jet_DeepCSVlP", Jet_DeepCSVlP, &b_Jet_DeepCSVlP);
   fChain->SetBranchAddress("Jet_DeepCSVbbP", Jet_DeepCSVbbP, &b_Jet_DeepCSVbbP);
   fChain->SetBranchAddress("Jet_DeepCSVccP", Jet_DeepCSVccP, &b_Jet_DeepCSVccP);
   fChain->SetBranchAddress("Jet_ProbaN", Jet_ProbaN, &b_Jet_ProbaN);
   fChain->SetBranchAddress("Jet_ProbaP", Jet_ProbaP, &b_Jet_ProbaP);
   fChain->SetBranchAddress("Jet_Proba", Jet_Proba, &b_Jet_Proba);
   fChain->SetBranchAddress("Jet_BprobN", Jet_BprobN, &b_Jet_BprobN);
   fChain->SetBranchAddress("Jet_BprobP", Jet_BprobP, &b_Jet_BprobP);
   fChain->SetBranchAddress("Jet_Bprob", Jet_Bprob, &b_Jet_Bprob);
   fChain->SetBranchAddress("Jet_SvxN", Jet_SvxN, &b_Jet_SvxN);
   fChain->SetBranchAddress("Jet_Svx", Jet_Svx, &b_Jet_Svx);
   fChain->SetBranchAddress("Jet_SvxNHP", Jet_SvxNHP, &b_Jet_SvxNHP);
   fChain->SetBranchAddress("Jet_SvxHP", Jet_SvxHP, &b_Jet_SvxHP);
   fChain->SetBranchAddress("Jet_CombSvxN", Jet_CombSvxN, &b_Jet_CombSvxN);
   fChain->SetBranchAddress("Jet_CombSvxP", Jet_CombSvxP, &b_Jet_CombSvxP);
   fChain->SetBranchAddress("Jet_CombSvx", Jet_CombSvx, &b_Jet_CombSvx);
   fChain->SetBranchAddress("Jet_CombIVF", Jet_CombIVF, &b_Jet_CombIVF);
   fChain->SetBranchAddress("Jet_CombIVF_P", Jet_CombIVF_P, &b_Jet_CombIVF_P);
   fChain->SetBranchAddress("Jet_CombIVF_N", Jet_CombIVF_N, &b_Jet_CombIVF_N);
   fChain->SetBranchAddress("Jet_SoftMuN", Jet_SoftMuN, &b_Jet_SoftMuN);
   fChain->SetBranchAddress("Jet_SoftMuP", Jet_SoftMuP, &b_Jet_SoftMuP);
   fChain->SetBranchAddress("Jet_SoftMu", Jet_SoftMu, &b_Jet_SoftMu);
   fChain->SetBranchAddress("Jet_SoftElN", Jet_SoftElN, &b_Jet_SoftElN);
   fChain->SetBranchAddress("Jet_SoftElP", Jet_SoftElP, &b_Jet_SoftElP);
   fChain->SetBranchAddress("Jet_SoftEl", Jet_SoftEl, &b_Jet_SoftEl);
   fChain->SetBranchAddress("Jet_cMVA", Jet_cMVA, &b_Jet_cMVA);
   fChain->SetBranchAddress("Jet_cMVAv2", Jet_cMVAv2, &b_Jet_cMVAv2);
   fChain->SetBranchAddress("Jet_cMVAv2N", Jet_cMVAv2N, &b_Jet_cMVAv2N);
   fChain->SetBranchAddress("Jet_cMVAv2P", Jet_cMVAv2P, &b_Jet_cMVAv2P);
   fChain->SetBranchAddress("Jet_hist1", Jet_hist1, &b_Jet_hist1);
   fChain->SetBranchAddress("Jet_hist2", Jet_hist2, &b_Jet_hist2);
   fChain->SetBranchAddress("Jet_hist3", Jet_hist3, &b_Jet_hist3);
   fChain->SetBranchAddress("Jet_histJet", Jet_histJet, &b_Jet_histJet);
   fChain->SetBranchAddress("Jet_histSvx", Jet_histSvx, &b_Jet_histSvx);
   fChain->SetBranchAddress("Jet_SV_multi", Jet_SV_multi, &b_Jet_SV_multi);
   fChain->SetBranchAddress("Jet_nSM", Jet_nSM, &b_Jet_nSM);
   fChain->SetBranchAddress("Jet_nSE", Jet_nSE, &b_Jet_nSE);
   fChain->SetBranchAddress("Jet_looseID", Jet_looseID, &b_Jet_looseID);
   fChain->SetBranchAddress("Jet_tightID", Jet_tightID, &b_Jet_tightID);
   fChain->SetBranchAddress("Jet_trackSip2dSig_AboveBottom_0", Jet_trackSip2dSig_AboveBottom_0, &b_Jet_trackSip2dSig_AboveBottom_0);
   fChain->SetBranchAddress("Jet_trackSip2dSig_AboveBottom_1", Jet_trackSip2dSig_AboveBottom_1, &b_Jet_trackSip2dSig_AboveBottom_1);
   fChain->SetBranchAddress("Jet_nFirstSE", Jet_nFirstSE, &b_Jet_nFirstSE);
   fChain->SetBranchAddress("Jet_nLastSE", Jet_nLastSE, &b_Jet_nLastSE);
   fChain->SetBranchAddress("nPFElectron", &nPFElectron, &b_nPFElectron);
   fChain->SetBranchAddress("PFElectron_IdxJet", PFElectron_IdxJet, &b_PFElectron_IdxJet);
   fChain->SetBranchAddress("PFElectron_pt", PFElectron_pt, &b_PFElectron_pt);
   fChain->SetBranchAddress("PFElectron_eta", PFElectron_eta, &b_PFElectron_eta);
   fChain->SetBranchAddress("PFElectron_phi", PFElectron_phi, &b_PFElectron_phi);
   fChain->SetBranchAddress("PFElectron_ptrel", PFElectron_ptrel, &b_PFElectron_ptrel);
   fChain->SetBranchAddress("PFElectron_deltaR", PFElectron_deltaR, &b_PFElectron_deltaR);
   fChain->SetBranchAddress("PFElectron_ratio", PFElectron_ratio, &b_PFElectron_ratio);
   fChain->SetBranchAddress("PFElectron_ratioRel", PFElectron_ratioRel, &b_PFElectron_ratioRel);
   fChain->SetBranchAddress("PFElectron_IP", PFElectron_IP, &b_PFElectron_IP);
   fChain->SetBranchAddress("PFElectron_IP2D", PFElectron_IP2D, &b_PFElectron_IP2D);
   fChain->SetBranchAddress("Jet_nFirstSM", Jet_nFirstSM, &b_Jet_nFirstSM);
   fChain->SetBranchAddress("Jet_nLastSM", Jet_nLastSM, &b_Jet_nLastSM);
   fChain->SetBranchAddress("nPFMuon", &nPFMuon, &b_nPFMuon);
   fChain->SetBranchAddress("PFMuon_IdxJet", PFMuon_IdxJet, &b_PFMuon_IdxJet);
   fChain->SetBranchAddress("PFMuon_nMuHit", PFMuon_nMuHit, &b_PFMuon_nMuHit);
   fChain->SetBranchAddress("PFMuon_nTkHit", PFMuon_nTkHit, &b_PFMuon_nTkHit);
   fChain->SetBranchAddress("PFMuon_nPixHit", PFMuon_nPixHit, &b_PFMuon_nPixHit);
   fChain->SetBranchAddress("PFMuon_nOutHit", PFMuon_nOutHit, &b_PFMuon_nOutHit);
   fChain->SetBranchAddress("PFMuon_nTkLwM", PFMuon_nTkLwM, &b_PFMuon_nTkLwM);
   fChain->SetBranchAddress("PFMuon_nPixLwM", PFMuon_nPixLwM, &b_PFMuon_nPixLwM);
   fChain->SetBranchAddress("PFMuon_nMatched", PFMuon_nMatched, &b_PFMuon_nMatched);
   fChain->SetBranchAddress("PFMuon_chi2", PFMuon_chi2, &b_PFMuon_chi2);
   fChain->SetBranchAddress("PFMuon_chi2Tk", PFMuon_chi2Tk, &b_PFMuon_chi2Tk);
   fChain->SetBranchAddress("PFMuon_isGlobal", PFMuon_isGlobal, &b_PFMuon_isGlobal);
   fChain->SetBranchAddress("PFMuon_hist", PFMuon_hist, &b_PFMuon_hist);
   fChain->SetBranchAddress("PFMuon_pt", PFMuon_pt, &b_PFMuon_pt);
   fChain->SetBranchAddress("PFMuon_eta", PFMuon_eta, &b_PFMuon_eta);
   fChain->SetBranchAddress("PFMuon_phi", PFMuon_phi, &b_PFMuon_phi);
   fChain->SetBranchAddress("PFMuon_ptrel", PFMuon_ptrel, &b_PFMuon_ptrel);
   fChain->SetBranchAddress("PFMuon_deltaR", PFMuon_deltaR, &b_PFMuon_deltaR);
   fChain->SetBranchAddress("PFMuon_ratio", PFMuon_ratio, &b_PFMuon_ratio);
   fChain->SetBranchAddress("PFMuon_ratioRel", PFMuon_ratioRel, &b_PFMuon_ratioRel);
   fChain->SetBranchAddress("PFMuon_IP", PFMuon_IP, &b_PFMuon_IP);
   fChain->SetBranchAddress("PFMuon_IP2D", PFMuon_IP2D, &b_PFMuon_IP2D);
   fChain->SetBranchAddress("PFMuon_IPsig", PFMuon_IPsig, &b_PFMuon_IPsig);
   fChain->SetBranchAddress("PFMuon_IP2Dsig", PFMuon_IP2Dsig, &b_PFMuon_IP2Dsig);
   fChain->SetBranchAddress("PFMuon_dz", PFMuon_dz, &b_PFMuon_dz);
   fChain->SetBranchAddress("PFMuon_GoodQuality", PFMuon_GoodQuality, &b_PFMuon_GoodQuality);
   fChain->SetBranchAddress("Jet_nFirstTrkTagVarCSV", Jet_nFirstTrkTagVarCSV, &b_Jet_nFirstTrkTagVarCSV);
   fChain->SetBranchAddress("Jet_nLastTrkTagVarCSV", Jet_nLastTrkTagVarCSV, &b_Jet_nLastTrkTagVarCSV);
   fChain->SetBranchAddress("Jet_nFirstTrkEtaRelTagVarCSV", Jet_nFirstTrkEtaRelTagVarCSV, &b_Jet_nFirstTrkEtaRelTagVarCSV);
   fChain->SetBranchAddress("Jet_nLastTrkEtaRelTagVarCSV", Jet_nLastTrkEtaRelTagVarCSV, &b_Jet_nLastTrkEtaRelTagVarCSV);
   fChain->SetBranchAddress("TagVarCSV_trackJetPt", TagVarCSV_trackJetPt, &b_TagVarCSV_trackJetPt);
   fChain->SetBranchAddress("TagVarCSV_jetNTracks", TagVarCSV_jetNTracks, &b_TagVarCSV_jetNTracks);
   fChain->SetBranchAddress("TagVarCSV_jetNTracksEtaRel", TagVarCSV_jetNTracksEtaRel, &b_TagVarCSV_jetNTracksEtaRel);
   fChain->SetBranchAddress("TagVarCSV_trackSumJetEtRatio", TagVarCSV_trackSumJetEtRatio, &b_TagVarCSV_trackSumJetEtRatio);
   fChain->SetBranchAddress("TagVarCSV_trackSumJetDeltaR", TagVarCSV_trackSumJetDeltaR, &b_TagVarCSV_trackSumJetDeltaR);
   fChain->SetBranchAddress("TagVarCSV_trackSip2dValAboveCharm", TagVarCSV_trackSip2dValAboveCharm, &b_TagVarCSV_trackSip2dValAboveCharm);
   fChain->SetBranchAddress("TagVarCSV_trackSip2dSigAboveCharm", TagVarCSV_trackSip2dSigAboveCharm, &b_TagVarCSV_trackSip2dSigAboveCharm);
   fChain->SetBranchAddress("TagVarCSV_trackSip3dValAboveCharm", TagVarCSV_trackSip3dValAboveCharm, &b_TagVarCSV_trackSip3dValAboveCharm);
   fChain->SetBranchAddress("TagVarCSV_trackSip3dSigAboveCharm", TagVarCSV_trackSip3dSigAboveCharm, &b_TagVarCSV_trackSip3dSigAboveCharm);
   fChain->SetBranchAddress("TagVarCSV_vertexCategory", TagVarCSV_vertexCategory, &b_TagVarCSV_vertexCategory);
   fChain->SetBranchAddress("TagVarCSV_jetNSecondaryVertices", TagVarCSV_jetNSecondaryVertices, &b_TagVarCSV_jetNSecondaryVertices);
   fChain->SetBranchAddress("TagVarCSV_vertexMass", TagVarCSV_vertexMass, &b_TagVarCSV_vertexMass);
   fChain->SetBranchAddress("TagVarCSV_vertexNTracks", TagVarCSV_vertexNTracks, &b_TagVarCSV_vertexNTracks);
   fChain->SetBranchAddress("TagVarCSV_vertexEnergyRatio", TagVarCSV_vertexEnergyRatio, &b_TagVarCSV_vertexEnergyRatio);
   fChain->SetBranchAddress("TagVarCSV_vertexJetDeltaR", TagVarCSV_vertexJetDeltaR, &b_TagVarCSV_vertexJetDeltaR);
   fChain->SetBranchAddress("TagVarCSV_flightDistance2dVal", TagVarCSV_flightDistance2dVal, &b_TagVarCSV_flightDistance2dVal);
   fChain->SetBranchAddress("TagVarCSV_flightDistance2dSig", TagVarCSV_flightDistance2dSig, &b_TagVarCSV_flightDistance2dSig);
   fChain->SetBranchAddress("TagVarCSV_flightDistance3dVal", TagVarCSV_flightDistance3dVal, &b_TagVarCSV_flightDistance3dVal);
   fChain->SetBranchAddress("TagVarCSV_flightDistance3dSig", TagVarCSV_flightDistance3dSig, &b_TagVarCSV_flightDistance3dSig);
   fChain->SetBranchAddress("nTrkTagVarCSV", &nTrkTagVarCSV, &b_nTrkTagVarCSV);
   fChain->SetBranchAddress("nTrkEtaRelTagVarCSV", &nTrkEtaRelTagVarCSV, &b_nTrkEtaRelTagVarCSV);
   fChain->SetBranchAddress("TagVarCSV_trackMomentum", TagVarCSV_trackMomentum, &b_TagVarCSV_trackMomentum);
   fChain->SetBranchAddress("TagVarCSV_trackEta", TagVarCSV_trackEta, &b_TagVarCSV_trackEta);
   fChain->SetBranchAddress("TagVarCSV_trackPhi", TagVarCSV_trackPhi, &b_TagVarCSV_trackPhi);
   fChain->SetBranchAddress("TagVarCSV_trackPtRel", TagVarCSV_trackPtRel, &b_TagVarCSV_trackPtRel);
   fChain->SetBranchAddress("TagVarCSV_trackPPar", TagVarCSV_trackPPar, &b_TagVarCSV_trackPPar);
   fChain->SetBranchAddress("TagVarCSV_trackDeltaR", TagVarCSV_trackDeltaR, &b_TagVarCSV_trackDeltaR);
   fChain->SetBranchAddress("TagVarCSV_trackPtRatio", TagVarCSV_trackPtRatio, &b_TagVarCSV_trackPtRatio);
   fChain->SetBranchAddress("TagVarCSV_trackPParRatio", TagVarCSV_trackPParRatio, &b_TagVarCSV_trackPParRatio);
   fChain->SetBranchAddress("TagVarCSV_trackSip2dVal", TagVarCSV_trackSip2dVal, &b_TagVarCSV_trackSip2dVal);
   fChain->SetBranchAddress("TagVarCSV_trackSip2dSig", TagVarCSV_trackSip2dSig, &b_TagVarCSV_trackSip2dSig);
   fChain->SetBranchAddress("TagVarCSV_trackSip3dVal", TagVarCSV_trackSip3dVal, &b_TagVarCSV_trackSip3dVal);
   fChain->SetBranchAddress("TagVarCSV_trackSip3dSig", TagVarCSV_trackSip3dSig, &b_TagVarCSV_trackSip3dSig);
   fChain->SetBranchAddress("TagVarCSV_trackDecayLenVal", TagVarCSV_trackDecayLenVal, &b_TagVarCSV_trackDecayLenVal);
   fChain->SetBranchAddress("TagVarCSV_trackDecayLenSig", TagVarCSV_trackDecayLenSig, &b_TagVarCSV_trackDecayLenSig);
   fChain->SetBranchAddress("TagVarCSV_trackJetDistVal", TagVarCSV_trackJetDistVal, &b_TagVarCSV_trackJetDistVal);
   fChain->SetBranchAddress("TagVarCSV_trackJetDistSig", TagVarCSV_trackJetDistSig, &b_TagVarCSV_trackJetDistSig);
   fChain->SetBranchAddress("TagVarCSV_trackEtaRel", TagVarCSV_trackEtaRel, &b_TagVarCSV_trackEtaRel);


   //Add branches 
   b_gluonSplittingWeightUp = fChain->Branch("gluonSplittingWeightUp", gluonSplittingWeightUp, "gluonSplittingWeightUp[nJet]/F");
   b_gluonSplittingWeightDo = fChain->Branch("gluonSplittingWeightDo", gluonSplittingWeightDo, "gluonSplittingWeightDo[nJet]/F");
}
void BTagAnalyzerSelector::cleanForNewEvent(){
  for (unsigned int i = 0; i < 100; ++i){
    gluonSplittingWeightUp[i] = -9999;
    gluonSplittingWeightDo[i] = -9999;
  }
}

void BTagAnalyzerSelector::fillNewBranches(){
  b_gluonSplittingWeightUp->Fill();
  b_gluonSplittingWeightDo->Fill();
}

Bool_t BTagAnalyzerSelector::Notify()
{
   // The Notify() function is called when a new file is opened. This
   // can be either for a new TTree in a TChain or when when a new TTree
   // is started when using PROOF. It is normally not necessary to make changes
   // to the generated code, but the routine can be extended by the
   // user if needed. The return value is currently not used.

   return kTRUE;
}

#endif // #ifdef BTagAnalyzerSelector_cxx

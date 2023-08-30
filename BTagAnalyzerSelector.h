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
#include <TTreeReader.h>
#include <TTreeReaderValue.h>
#include <TTreeReaderArray.h>

//#include "CondFormats/JetMETObjects/interface/JetCorrectorParameters.h"
#include "CondFormats/JetMETObjects/interface/JetCorrectionUncertainty.h"

#define NMAX 500

// Header file for the classes stored in the TTree if any.

// Fixed size dimensions of array or collections stored in the TTree if any.

class BTagAnalyzerSelector : public TSelector {
public :

   // data members needed for computing systematics
   float BTemplateCorrections[NMAX][20][2];
   JetCorrectionUncertainty* jesTotal;
   double cJER[NMAX];
   double cJER_down[NMAX];
   double cJER_up[NMAX];


   TTreeReader     fReader;  //!the tree reader
   TTree          *fChain = 0;   //!pointer to the analyzed TTree or TChain

   // Readers to access the data (delete the ones you do not need).
   TTreeReaderValue<UInt_t> Run = {fReader, "Run"};
   TTreeReaderValue<ULong64_t> Evt = {fReader, "Evt"};
   TTreeReaderValue<UInt_t> LumiBlock = {fReader, "LumiBlock"};
   TTreeReaderValue<Int_t> nPU = {fReader, "nPU"};
   TTreeReaderValue<Float_t> nPUtrue = {fReader, "nPUtrue"};
   TTreeReaderValue<Float_t> rho = {fReader, "rho"};
   TTreeReaderValue<Float_t> pthat = {fReader, "pthat"};
   TTreeReaderValue<Int_t> nBitTrigger = {fReader, "nBitTrigger"};
   TTreeReaderArray<Long64_t> BitTrigger = {fReader, "BitTrigger"};
   TTreeReaderValue<Float_t> PV_x = {fReader, "PV_x"};
   TTreeReaderValue<Float_t> PV_y = {fReader, "PV_y"};
   TTreeReaderValue<Float_t> PV_z = {fReader, "PV_z"};
   TTreeReaderValue<Float_t> PV_ndof = {fReader, "PV_ndof"};
   TTreeReaderValue<Float_t> PV_chi2 = {fReader, "PV_chi2"};
   TTreeReaderValue<Int_t> nbQuark = {fReader, "nbQuark"};
   TTreeReaderArray<Float_t> bQuark_pT = {fReader, "bQuark_pT"};
   TTreeReaderArray<Float_t> bQuark_eta = {fReader, "bQuark_eta"};
   TTreeReaderArray<Float_t> bQuark_phi = {fReader, "bQuark_phi"};
   TTreeReaderArray<Int_t> bQuark_pdgId = {fReader, "bQuark_pdgId"};
   TTreeReaderArray<Int_t> bQuark_status = {fReader, "bQuark_status"};
   TTreeReaderArray<bool> bQuark_fromGSP = {fReader, "bQuark_fromGSP"};
   TTreeReaderValue<Int_t> ncQuark = {fReader, "ncQuark"};
   TTreeReaderArray<Float_t> cQuark_pT = {fReader, "cQuark_pT"};
   TTreeReaderArray<Float_t> cQuark_eta = {fReader, "cQuark_eta"};
   TTreeReaderArray<Float_t> cQuark_phi = {fReader, "cQuark_phi"};
   TTreeReaderArray<Int_t> cQuark_pdgId = {fReader, "cQuark_pdgId"};
   TTreeReaderArray<Int_t> cQuark_status = {fReader, "cQuark_status"};
   TTreeReaderArray<bool> cQuark_fromGSP = {fReader, "cQuark_fromGSP"};
   TTreeReaderValue<Int_t> nBHadron = {fReader, "nBHadron"};
   TTreeReaderArray<Float_t> BHadron_pT = {fReader, "BHadron_pT"};
   TTreeReaderArray<Float_t> BHadron_eta = {fReader, "BHadron_eta"};
   TTreeReaderArray<Float_t> BHadron_phi = {fReader, "BHadron_phi"};
   TTreeReaderArray<Int_t> BHadron_pdgID = {fReader, "BHadron_pdgID"};
   TTreeReaderArray<Double_t> BHadron_mass = {fReader, "BHadron_mass"};
   TTreeReaderArray<Long64_t> BHadron_hasBdaughter = {fReader, "BHadron_hasBdaughter"};
   TTreeReaderArray<Long64_t> BHadron_DHadron1 = {fReader, "BHadron_DHadron1"};
   TTreeReaderArray<Long64_t> BHadron_DHadron2 = {fReader, "BHadron_DHadron2"};
   TTreeReaderValue<Int_t> nDHadron = {fReader, "nDHadron"};
   TTreeReaderArray<Float_t> DHadron_pT = {fReader, "DHadron_pT"};
   TTreeReaderArray<Float_t> DHadron_eta = {fReader, "DHadron_eta"};
   TTreeReaderArray<Float_t> DHadron_phi = {fReader, "DHadron_phi"};
   TTreeReaderArray<Int_t> DHadron_pdgID = {fReader, "DHadron_pdgID"};
   TTreeReaderArray<Double_t> DHadron_mass = {fReader, "DHadron_mass"};
   TTreeReaderValue<Int_t> nGenlep = {fReader, "nGenlep"};
   TTreeReaderArray<Float_t> Genlep_pT = {fReader, "Genlep_pT"};
   TTreeReaderArray<Float_t> Genlep_eta = {fReader, "Genlep_eta"};
   TTreeReaderArray<Float_t> Genlep_phi = {fReader, "Genlep_phi"};
   TTreeReaderArray<Int_t> Genlep_pdgID = {fReader, "Genlep_pdgID"};
   TTreeReaderArray<Int_t> Genlep_status = {fReader, "Genlep_status"};
   TTreeReaderArray<Long64_t> Genlep_mother = {fReader, "Genlep_mother"};
   TTreeReaderValue<Int_t> nGenV0 = {fReader, "nGenV0"};
   TTreeReaderArray<Float_t> GenV0_pT = {fReader, "GenV0_pT"};
   TTreeReaderArray<Float_t> GenV0_eta = {fReader, "GenV0_eta"};
   TTreeReaderArray<Float_t> GenV0_phi = {fReader, "GenV0_phi"};
   TTreeReaderArray<Int_t> GenV0_pdgId = {fReader, "GenV0_pdgId"};
   TTreeReaderArray<Long64_t> GenV0_nCharged = {fReader, "GenV0_nCharged"};
   TTreeReaderArray<Double_t> GenV0_SVx = {fReader, "GenV0_SVx"};
   TTreeReaderArray<Double_t> GenV0_SVy = {fReader, "GenV0_SVy"};
   TTreeReaderArray<Double_t> GenV0_SVz = {fReader, "GenV0_SVz"};
   TTreeReaderValue<Int_t> nJet = {fReader, "nJet"};
   TTreeReaderArray<Float_t> Jet_pT = {fReader, "Jet_pT"};
   TTreeReaderArray<Float_t> Jet_eta = {fReader, "Jet_eta"};
   TTreeReaderArray<Float_t> Jet_phi = {fReader, "Jet_phi"};
   TTreeReaderArray<Float_t> Jet_mass = {fReader, "Jet_mass"};
   TTreeReaderArray<Float_t> Jet_uncorrpt = {fReader, "Jet_uncorrpt"};
   TTreeReaderArray<bool> Jet_looseID = {fReader, "Jet_looseID"};
   TTreeReaderArray<bool> Jet_tightID = {fReader, "Jet_tightID"};
   TTreeReaderArray<Float_t> Jet_area = {fReader, "Jet_area"};
   TTreeReaderArray<Float_t> Jet_Proba = {fReader, "Jet_Proba"};
   TTreeReaderArray<Float_t> Jet_ProbaN = {fReader, "Jet_ProbaN"};
   TTreeReaderArray<Float_t> Jet_Bprob = {fReader, "Jet_Bprob"};
   TTreeReaderArray<Float_t> Jet_BprobN = {fReader, "Jet_BprobN"};
   TTreeReaderArray<Float_t> Jet_DeepFlavourBDisc = {fReader, "Jet_DeepFlavourBDisc"};
   TTreeReaderArray<Float_t> Jet_DeepFlavourCvsLDisc = {fReader, "Jet_DeepFlavourCvsLDisc"};
   TTreeReaderArray<Float_t> Jet_DeepFlavourCvsBDisc = {fReader, "Jet_DeepFlavourCvsBDisc"};
   TTreeReaderArray<Float_t> Jet_DeepFlavourBDiscN = {fReader, "Jet_DeepFlavourBDiscN"};
   TTreeReaderArray<Float_t> Jet_DeepFlavourCvsLDiscN = {fReader, "Jet_DeepFlavourCvsLDiscN"};
   TTreeReaderArray<Float_t> Jet_DeepFlavourCvsBDiscN = {fReader, "Jet_DeepFlavourCvsBDiscN"};
   TTreeReaderArray<Int_t> Jet_nbHadrons = {fReader, "Jet_nbHadrons"};
   TTreeReaderArray<Int_t> Jet_ncHadrons = {fReader, "Jet_ncHadrons"};
   TTreeReaderArray<short> Jet_partonFlavour = {fReader, "Jet_partonFlavour"};
   TTreeReaderArray<unsigned char> Jet_hadronFlavour = {fReader, "Jet_hadronFlavour"};
   TTreeReaderArray<Long64_t> Jet_flavour = {fReader, "Jet_flavour"};
   TTreeReaderArray<Double_t> Jet_genpt = {fReader, "Jet_genpt"};
   TTreeReaderArray<Long64_t> Jet_flavourCleaned = {fReader, "Jet_flavourCleaned"};
   TTreeReaderArray<Long64_t> Jet_nFirstTrkInc = {fReader, "Jet_nFirstTrkInc"};
   TTreeReaderArray<Long64_t> Jet_nLastTrkInc = {fReader, "Jet_nLastTrkInc"};
   TTreeReaderArray<Long64_t> Jet_nFirstSM = {fReader, "Jet_nFirstSM"};
   TTreeReaderArray<Long64_t> Jet_nLastSM = {fReader, "Jet_nLastSM"};
   TTreeReaderValue<Int_t> nTagVarCSV = {fReader, "nTagVarCSV"};
   TTreeReaderArray<Float_t> TagVarCSV_trackJetPt = {fReader, "TagVarCSV_trackJetPt"};
   TTreeReaderArray<Float_t> TagVarCSV_vertexCategory = {fReader, "TagVarCSV_vertexCategory"};
   TTreeReaderArray<Int_t> TagVarCSV_jetNSecondaryVertices = {fReader, "TagVarCSV_jetNSecondaryVertices"};
   TTreeReaderArray<Float_t> TagVarCSV_trackSumJetEtRatio = {fReader, "TagVarCSV_trackSumJetEtRatio"};
   TTreeReaderArray<Float_t> TagVarCSV_trackSumJetDeltaR = {fReader, "TagVarCSV_trackSumJetDeltaR"};
   TTreeReaderArray<Float_t> TagVarCSV_vertexMass = {fReader, "TagVarCSV_vertexMass"};
   TTreeReaderArray<Int_t> TagVarCSV_vertexNTracks = {fReader, "TagVarCSV_vertexNTracks"};
   TTreeReaderArray<Float_t> TagVarCSV_vertexEnergyRatio = {fReader, "TagVarCSV_vertexEnergyRatio"};
   TTreeReaderArray<Float_t> TagVarCSV_vertexJetDeltaR = {fReader, "TagVarCSV_vertexJetDeltaR"};
   TTreeReaderValue<Int_t> nTrkInc = {fReader, "nTrkInc"};
   TTreeReaderArray<Double_t> TrkInc_pt = {fReader, "TrkInc_pt"};
   TTreeReaderArray<Double_t> TrkInc_eta = {fReader, "TrkInc_eta"};
   TTreeReaderArray<Double_t> TrkInc_phi = {fReader, "TrkInc_phi"};
   TTreeReaderArray<Double_t> TrkInc_ptrel = {fReader, "TrkInc_ptrel"};
   TTreeReaderValue<Int_t> nPFMuon = {fReader, "nPFMuon"};
   TTreeReaderArray<Long64_t> PFMuon_IdxJet = {fReader, "PFMuon_IdxJet"};
   TTreeReaderArray<Double_t> PFMuon_pt = {fReader, "PFMuon_pt"};
   TTreeReaderArray<Double_t> PFMuon_eta = {fReader, "PFMuon_eta"};
   TTreeReaderArray<Double_t> PFMuon_phi = {fReader, "PFMuon_phi"};
   TTreeReaderArray<Double_t> PFMuon_ptrel = {fReader, "PFMuon_ptrel"};
   TTreeReaderArray<Double_t> PFMuon_ratio = {fReader, "PFMuon_ratio"};
   TTreeReaderArray<Double_t> PFMuon_ratioRel = {fReader, "PFMuon_ratioRel"};
   TTreeReaderArray<Double_t> PFMuon_deltaR = {fReader, "PFMuon_deltaR"};
   TTreeReaderArray<Double_t> PFMuon_IP = {fReader, "PFMuon_IP"};
   TTreeReaderArray<Double_t> PFMuon_IPsig = {fReader, "PFMuon_IPsig"};
   TTreeReaderArray<Double_t> PFMuon_IP2D = {fReader, "PFMuon_IP2D"};
   TTreeReaderArray<Double_t> PFMuon_IP2Dsig = {fReader, "PFMuon_IP2Dsig"};
   TTreeReaderArray<Long64_t> PFMuon_GoodQuality = {fReader, "PFMuon_GoodQuality"};	  
  

   //new branches to add
   TTree* newTree;

   Float_t         gluonSplittingWeightUp[NMAX];
   Float_t         gluonSplittingWeightDo[NMAX];
   Float_t         bFragmentationWeightUp[NMAX];
   Float_t         bFragmentationWeightDo[NMAX];
   Float_t         cdFragmentationWeightUp[NMAX];
   Float_t         cdFragmentationWeightDo[NMAX];
   Float_t         cFragmentationWeightUp[NMAX];
   Float_t         cFragmentationWeightDo[NMAX];
   Float_t         v0WeightUp[NMAX];
   Float_t         v0WeightDo[NMAX];
   Float_t         cSVmassWeightUp[NMAX]; 
   Float_t         cSVmassWeightDo[NMAX]; 
   Float_t         Jet_pTJERUp[NMAX];
   Float_t         Jet_pTJERDo[NMAX];
   Float_t         Jet_pTJESUp[NMAX];
   Float_t         Jet_pTJESDo[NMAX];
   Int_t           Evt_new;

   //new branches to add
   TBranch        *b_gluonSplittingWeightUp;
   TBranch        *b_gluonSplittingWeightDo;
   TBranch        *b_bFragmentationWeightUp;
   TBranch        *b_bFragmentationWeightDo;
   TBranch        *b_cdFragmentationWeightUp;
   TBranch        *b_cdFragmentationWeightDo;
   TBranch        *b_cFragmentationWeightUp;
   TBranch        *b_cFragmentationWeightDo;
   TBranch        *b_v0WeightUp;
   TBranch        *b_v0WeightDo;
   TBranch        *b_cSVmassWeightUp;
   TBranch        *b_cSVmassWeightDo;
   TBranch        *b_Jet_pTJERUp;
   TBranch        *b_Jet_pTJERDo;
   TBranch        *b_Jet_pTJESUp;
   TBranch        *b_Jet_pTJESDo;
   TBranch        *b_Evt_new;

   BTagAnalyzerSelector(TTree* tree = 0); 
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
   void GluonSplitting(int ij);
   void bFrag(int ij);
   void cdFrag(int ij);
   void cFrag(int ij);
   void Ks(int ij);
   void JEC(int ij);
   void cSVmass(int ij);
   double svmassReweight(double rw);
   TTree* getHelperTree() {return newTree;}

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
   fReader.SetTree(tree);

/*
   //Add branches
   newTree = new TTree("helper", "helper");
   b_gluonSplittingWeightUp = newTree->Branch("gluonSplittingWeightUp", gluonSplittingWeightUp, "gluonSplittingWeightUp[500]/F");
   b_gluonSplittingWeightDo = newTree->Branch("gluonSplittingWeightDo", gluonSplittingWeightDo, "gluonSplittingWeightDo[500]/F");
   b_bFragmentationWeightUp = newTree->Branch("bFragmentationWeightUp", bFragmentationWeightUp, "bFragmentationWeightUp[500]/F");
   b_bFragmentationWeightDo = newTree->Branch("bFragmentationWeightDo", bFragmentationWeightDo, "bFragmentationWeightDo[500]/F");
   b_cdFragmentationWeightUp = newTree->Branch("cdFragmentationWeightUp", cdFragmentationWeightUp, "cdFragmentationWeightUp[500]/F");
   b_cdFragmentationWeightDo = newTree->Branch("cdFragmentationWeightDo", cdFragmentationWeightDo, "cdFragmentationWeightDo[500]/F");
   b_cFragmentationWeightUp = newTree->Branch("cFragmentationWeightUp", cFragmentationWeightUp, "cFragmentationWeightUp[500]/F");
   b_cFragmentationWeightDo = newTree->Branch("cFragmentationWeightDo", cFragmentationWeightDo, "cFragmentationWeightDo[500]/F");
   b_v0WeightUp = newTree->Branch("v0WeightUp", v0WeightUp, "v0WeightUp[500]/F");
   b_v0WeightDo = newTree->Branch("v0WeightDo", v0WeightDo, "v0WeightDo[500]/F");
   b_Jet_pTJERUp = newTree->Branch("Jet_pTJERUp", Jet_pTJERUp, "Jet_pTJERUp[500]/F");
   b_Jet_pTJERDo = newTree->Branch("Jet_pTJERDo", Jet_pTJERDo, "Jet_pTJERDo[500]/F");
   b_Jet_pTJESUp = newTree->Branch("Jet_pTJESUp", Jet_pTJESUp, "Jet_pTJESUp[500]/F");
   b_Jet_pTJESDo = newTree->Branch("Jet_pTJESDo", Jet_pTJESDo, "Jet_pTJESDo[500]/F");
   b_Evt_new     = newTree->Branch("b_Evt_new", &Evt_new, "Evt_new/I");
*/
}
void BTagAnalyzerSelector::cleanForNewEvent(){
  for (unsigned int i = 0; i < NMAX; ++i){
    gluonSplittingWeightUp[i] = 1.;
    gluonSplittingWeightDo[i] = 1.;
    bFragmentationWeightUp[i] = 1.;
    bFragmentationWeightDo[i] = 1.;
    cdFragmentationWeightUp[i] = 1.;
    cdFragmentationWeightDo[i] = 1.;
    cFragmentationWeightUp[i] = 1.;
    cFragmentationWeightDo[i] = 1.;
    v0WeightUp[i] = 1.;
    v0WeightDo[i] = 1.;
    cSVmassWeightUp[i] = 1.;
    cSVmassWeightDo[i] = 1.;
    Jet_pTJERUp[i] = 1.;
    Jet_pTJERDo[i] = 1.;
    Jet_pTJESUp[i] = 1.;
    Jet_pTJESDo[i] = 1.;
  }
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

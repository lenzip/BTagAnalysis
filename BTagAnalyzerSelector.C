#define BTagAnalyzerSelector_cxx
// The class definition in BTagAnalyzerSelector.h has been generated automatically
// by the ROOT utility TTree::MakeSelector(). This class is derived
// from the ROOT class TSelector. For more information on the TSelector
// framework see $ROOTSYS/README/README.SELECTOR or the ROOT User Manual.

// The following methods are defined in this file:
//    Begin():        called every time a loop on the tree starts,
//                    a convenient place to create your histograms.
//    SlaveBegin():   called after Begin(), when on PROOF called only on the
//                    slave servers.
//    Process():      called for each event, in this function you decide what
//                    to read and fill your histograms.
//    SlaveTerminate: called at the end of the loop on the tree, when on PROOF
//                    called only on the slave servers.
//    Terminate():    called at the end of the loop on the tree,
//                    a convenient place to draw/fit your histograms.
//
// To use this file, try the following session on your Tree T:
//
// Root > T->Process("BTagAnalyzerSelector.C")
// Root > T->Process("BTagAnalyzerSelector.C","some options")
// Root > T->Process("BTagAnalyzerSelector.C+")
//

#include "BTagAnalyzerSelector.h"
#include "TLorentzVector.h"
#include <TH2.h>
#include <TStyle.h>
#include <iostream>
#include <fstream>

using namespace std;

BTagAnalyzerSelector::BTagAnalyzerSelector(TTree * tree) : fChain(0){
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
  b_cSVmassWeightUp = newTree->Branch("cSVmassWeightUp", cSVmassWeightUp, "cSVmassWeightUp[500]/F"); 
  b_cSVmassWeightDo = newTree->Branch("cSVmassWeightDo", cSVmassWeightDo, "cSVmassWeightDo[500]/F"); 
  b_Jet_pTJERUp = newTree->Branch("Jet_pTJERUp", Jet_pTJERUp, "Jet_pTJERUp[500]/F");
  b_Jet_pTJERDo = newTree->Branch("Jet_pTJERDo", Jet_pTJERDo, "Jet_pTJERDo[500]/F");
  b_Jet_pTJESUp = newTree->Branch("Jet_pTJESUp", Jet_pTJESUp, "Jet_pTJESUp[500]/F");
  b_Jet_pTJESDo = newTree->Branch("Jet_pTJESDo", Jet_pTJESDo, "Jet_pTJESDo[500]/F");
  b_Evt_new     = newTree->Branch("Evt_new", &Evt_new, "Evt_new/I");
 


  //JES and JER
  //jesTotal = new JetCorrectionUncertainty(*(new JetCorrectorParameters("data/Summer16_23Sep2016V5_MC_UncertaintySources_AK4PFchs.txt", "Total")));
  jesTotal = new JetCorrectionUncertainty("data/Winter22Run3_V2_MC_Uncertainty_AK4PFPuppi.txt");

   // JER taken from https://twiki.cern.ch/twiki/bin/view/CMS/JetResolution
   
   cJER[0] = 1.052; // 0.0-0.5
   cJER[1] = 1.057; // 0.5-1.1
   cJER[2] = 1.096; // 1.1-1.7
   cJER[3] = 1.134; // 1.7-2.3
   cJER[4] = 1.288; // 2.3-5.0
   
   cJER_down[0] = 0.990;
   cJER_down[1] = 1.001;
   cJER_down[2] = 1.032;
   cJER_down[3] = 1.042;
   cJER_down[4] = 1.089;

   cJER_up[0] = 1.115;
   cJER_up[1] = 1.114;
   cJER_up[2] = 1.161;
   cJER_up[3] = 1.228;
   cJER_up[4] = 1.488; 

  int nPtRelPtBins = 15;
  TString PtRelPtBin[] = {
     "Pt2030", "Pt3040", "Pt4050", "Pt5060", "Pt6070"
     , "Pt7080", "Pt80100", "Pt100120", "Pt120160", "Pt160210"
     , "Pt210260", "Pt260320", "Pt320400", "Pt400500", "Pt500" 
  };
  
  for( int ptb=0;ptb<nPtRelPtBins;ptb++ ){      
     for(int ib=0;ib<100;ib++ ) {
        BTemplateCorrections[ib][ptb][0] = 1.;
        BTemplateCorrections[ib][ptb][1] = 1.;
     }
     
     std::ifstream MnusCorrectionsFile;
     MnusCorrectionsFile.open("data/PtRel/EnergyFraction_" + PtRelPtBin[ptb] + "_m5.txt");
     while( MnusCorrectionsFile )
       {
        float xBin, efcorr;
        MnusCorrectionsFile >> xBin >> efcorr;
        if ( efcorr > 4. ) efcorr = 1.;
        int ib = int(xBin/0.02);
        BTemplateCorrections[ib][ptb][0] = efcorr;
       }
     
     std::ifstream PlusCorrectionsFile; 
     PlusCorrectionsFile.open("data/PtRel/EnergyFraction_" + PtRelPtBin[ptb] + "_p5.txt");
     while( PlusCorrectionsFile )
       {
        float xBin, efcorr;
        PlusCorrectionsFile >> xBin >> efcorr;
        if ( efcorr > 4. ) efcorr = 1.;
        int ib = int(xBin/0.02);
        BTemplateCorrections[ib][ptb][1] = efcorr;
       }
  }
}


void BTagAnalyzerSelector::Begin(TTree * /*tree*/)
{
   // The Begin() function is called at the start of the query.
   // When running with PROOF Begin() is only called on the client.
   // The tree argument is deprecated (on PROOF 0 is passed).

   TString option = GetOption();

}

void BTagAnalyzerSelector::SlaveBegin(TTree * /*tree*/)
{
   // The SlaveBegin() function is called after the Begin() function.
   // When running with PROOF SlaveBegin() is called on each slave server.
   // The tree argument is deprecated (on PROOF 0 is passed).

   TString option = GetOption();

}

Bool_t BTagAnalyzerSelector::Process(Long64_t entry)
{
   // The Process() function is called for each entry in the tree (or possibly
   // keyed object in the case of PROOF) to be processed. The entry argument
   // specifies which entry in the currently loaded tree is to be processed.
   // It can be passed to either BTagAnalyzerSelector::GetEntry() or TBranch::GetEntry()
   // to read either all or the required parts of the data. When processing
   // keyed objects with PROOF, the object is already loaded and is available
   // via the fObject pointer.
   //
   // This function should contain the "body" of the analysis. It can contain
   // simple or elaborate selection criteria, run algorithms on the data
   // of the event and typically fill histograms.
   //
   // The processing can be stopped by calling Abort().
   //
   // Use fStatus to set the return value of TTree::Process().
   //
   // The return value is currently not used.
   cleanForNewEvent();
   fReader.SetLocalEntry(entry);
 
   Evt_new = *Evt; 
   for (int ij = 0; ij < *nJet; ++ij){
      GluonSplitting(ij);    
      bFrag(ij);
      cdFrag(ij);
      cFrag(ij);
      Ks(ij);
      JEC(ij);
      cSVmass(ij);
   }

   newTree->Fill(); 

   return kTRUE;
}

void BTagAnalyzerSelector::SlaveTerminate()
{
   // The SlaveTerminate() function is called after all entries or objects
   // have been processed. When running with PROOF SlaveTerminate() is called
   // on each slave server.

}

void BTagAnalyzerSelector::Terminate()
{
   // The Terminate() function is the last function to be called during
   // a query. It always runs on the client, it can be used to present
   // the results graphically or save the results to file.

}

double BTagAnalyzerSelector::svmassReweight(double rw){

  double a = 1.04340e+00;
  double b = -4.44267e-01;
  double c = 4.81803e-01;
  double d = -1.20184e-01;

  double rwt = a+b*rw+c*rw*rw+d*rw*rw*rw;
  if (rw > 2.5) rwt = 1.0;
  if (rw < 0.) rwt = 1.0;
  return rwt;

}

void BTagAnalyzerSelector::cSVmass(int ij){
  float sfUp = 1.;
  float sfDo = 1.;

  int jFlavour = abs(Jet_flavour[ij]);
  //cout << "Jet flavor " << jFlavour << endl;
  if (jFlavour == 4){
    sfUp *= svmassReweight(TagVarCSV_vertexMass[ij]);
    //cout << "SV weight " << sfUp << endl;
  }

  cSVmassWeightUp[ij] = sfUp;
  cSVmassWeightDo[ij] = sfDo;
  

}
void BTagAnalyzerSelector::GluonSplitting(int ij)
{
  float sfUp = 1.;
  float sfDo = 1.;
  int flavch = 0;
  int jFlavour = abs(Jet_flavour[ij]);
  if( jFlavour == 5 )  flavch = 1;
  if( jFlavour == 4 )  flavch = 2;
  if( jFlavour == 1 || jFlavour == 21 )  flavch = 3;
  if( jFlavour == 0 ) flavch = 3;

  float drMin = 0.4;   
   
  bool GSPc = false, GSPb = false;

  float jeta = Jet_eta[ij];
  float jphi = Jet_phi[ij];   
  float jpt  = Jet_pT[ij];   

  TLorentzVector jet;
  jet.SetPtEtaPhiM(jpt, jeta, jphi, 0.);
  //std::cout << "flavch " << flavch << std::endl;
  // post-ICHEP 
  if( flavch == 2 )
    {        
       int ndHadronsFound = 0;
       for( int k=0;k<*nDHadron;k++ )
         {
         TLorentzVector D;
         D.SetPtEtaPhiM(DHadron_pT[k], DHadron_eta[k], DHadron_phi[k], 0.);
         double dRqj = jet.DeltaR(D);
         if( dRqj < 0.4 ) ndHadronsFound++;
         }
       if( ndHadronsFound >= 2 ) GSPc = 1;
    }
  
  if( flavch == 1 )
    {
       int nbHadronsFound = 0;
       for( int k=0;k<*nBHadron;k++ )
         {
         TLorentzVector B;
         B.SetPtEtaPhiM(BHadron_pT[k], BHadron_eta[k], BHadron_phi[k], 0.);
         double dRqj = jet.DeltaR(B);;
         //std::cout << "dRqj " << dRqj << std::endl;
         if( dRqj < 0.4 ) nbHadronsFound++;
         }
       
       if( nbHadronsFound >= 2 ) GSPb = 1;
    }
    
  if( 
     ((GSPc && flavch == 2) || (GSPb && flavch == 1))
    ) sfDo *= 0.75;       
  if( 
     ((GSPc && flavch == 2) || (GSPb && flavch == 1))
    ) sfUp *= 1.25;   
 
  //std::cout << *nDHadron << " " << *nBHadron << " " << flavch << " " << sfUp << " " << sfDo << std::endl;
  gluonSplittingWeightUp[ij] = sfUp;
  gluonSplittingWeightDo[ij] = sfDo;

}

// b fragmentation sys
void BTagAnalyzerSelector::bFrag(int ij)
{
  float sfUp = 1.;       
  float sfDo = 1.;
  int flavch = 0;
  
  int jFlavour = abs(Jet_flavour[ij]);
  if( jFlavour == 5 )  flavch = 1;
  if( jFlavour == 4 )  flavch = 2;
  if( jFlavour == 1 || jFlavour == 21 )  flavch = 3;
  if( jFlavour == 0 ) flavch = 3;
 

  float drMin = 0.4;   
  float jPT = Jet_pT[ij];
  float jeta = Jet_eta[ij];
  float jphi = Jet_phi[ij];
  float WeightBFrag = 1.;
  float EnergyFraction = 0.; 
  
  TLorentzVector jet;
  jet.SetPtEtaPhiM(jPT, jeta, jphi, 0.); 

  int iB = -1, iptBin = 0, efbin = -1;
  if( flavch == 1  )  {
       if( jPT > 500 ) iptBin = 14;
       else if( jPT > 400 ) iptBin = 13;
       else if( jPT > 320 ) iptBin = 12;  
       else if( jPT > 260 ) iptBin = 11;
       else if( jPT > 210 ) iptBin = 10;
       else if( jPT > 160 ) iptBin =  9;
       else if( jPT > 120 ) iptBin =  8;  
       else if( jPT > 100 ) iptBin =  7;  
       else if( jPT >  80 ) iptBin =  6;  
       else if( jPT >  70 ) iptBin =  5;  
       else if( jPT >  60 ) iptBin =  4;  
       else if( jPT >  50 ) iptBin =  3;  
       else if( jPT >  40 ) iptBin =  2;  
       else if( jPT >  30 ) iptBin =  1;  
       else                 iptBin =  0;
       
       float B_Mass = 0.;
       for( int ib=0;ib<*nBHadron;ib++ ){
         
          TLorentzVector B;
          B.SetPtEtaPhiM(BHadron_pT[ib], BHadron_eta[ib], BHadron_phi[ib], BHadron_mass[ib]);
          float drB = jet.DeltaR(B);
      
          if( drB < drMin ){
              if( BHadron_mass[ib] > B_Mass ) 
              {
                B_Mass = BHadron_mass[ib];
                iB = ib;
              }                                 
          }                           
       }
       
       if( iB >= 0 ){
          EnergyFraction = BHadron_pT[iB] / Jet_genpt[ij];
          efbin = int( EnergyFraction / 0.02 );
          if( efbin >= 0 && efbin < 100 ) 
            {
              sfUp *= BTemplateCorrections[efbin][iptBin][1];
              sfDo *= BTemplateCorrections[efbin][iptBin][0];
            }                           
       }
          
  }
  
  bFragmentationWeightUp[ij] = sfUp;
  bFragmentationWeightDo[ij] = sfDo;

}

// c->D fragmentation sys
void BTagAnalyzerSelector::cdFrag(int ij)
{       
  float sfUp = 1.;
  float sfDo = 1.;
  /*
  int flavch = 0;

  float drMin = 0.4;   
  float jeta = Jet_eta[ij];
  float jphi = Jet_phi[ij];
  float jpt  = Jet_pT[ij];

  int jFlavour = abs(Jet_flavour[ij]);
  if( jFlavour == 5 )  flavch = 1;
  if( jFlavour == 4 )  flavch = 2;
  if( jFlavour == 1 || jFlavour == 21 )  flavch = 3;
  if( jFlavour == 0 ) flavch = 3;

  TLorentzVector jet;
  jet.SetPtEtaPhiM(jpt, jeta, jphi, 0.);

  if( flavch == 2 ||
      flavch == 1 )
    {
       bool isDplusMu = false, isDzeroMu = false, isDsubsMu = false;
       
       int ndaughters = 0;
       for( int k=0;k<*nDHadron;k++ ){
         TLorentzVector D;
         D.SetPtEtaPhiM(DHadron_pT[k], DHadron_eta[k], DHadron_phi[k], 0.);
         double dR = jet.DeltaR(D); 
         if( dR > drMin ) continue;
         bool isSemiMu = false;
         int nd = DHadron_nDaughters[k];
         for( int kk=0;kk<nd;kk++ ){
           if( abs(DHadron_DaughtersPdgID[kk+ndaughters]) == 13 ) isSemiMu = true;
         }
      
         ndaughters += nd;
      
         if( !isSemiMu ) continue;
         if( abs(DHadron_pdgID[k]) == 411 ) isDplusMu = true;
         if( abs(DHadron_pdgID[k]) == 421 ) isDzeroMu = true;
         if( abs(DHadron_pdgID[k]) == 431 ) isDsubsMu = true;
       }
       
       // weight for D->mu decay: Pythia vs PDG2013
       if( isDplusMu ) sfDo *= 0.176 / 0.172;
       if( isDzeroMu ) sfDo *= 0.067 / 0.077;
       if( isDsubsMu ) sfDo *= 0.067 / 0.080;
   }
   */
   cdFragmentationWeightUp[ij] = sfUp;
   cdFragmentationWeightDo[ij] = sfDo;  
}

// c fragmentation sys
void BTagAnalyzerSelector::cFrag(int ij)
{

  float sfUp = 1.;
  float sfDo = 1.;

  int flavch = 0;

  float drMin = 0.4;
  float jeta = Jet_eta[ij];
  float jphi = Jet_phi[ij];
  float jpt  = Jet_pT[ij];

  int jFlavour = abs(Jet_flavour[ij]);
  if( jFlavour == 5 )  flavch = 1;
  if( jFlavour == 4 )  flavch = 2;
  if( jFlavour == 1 || jFlavour == 21 )  flavch = 3;
  if( jFlavour == 0 ) flavch = 3;

  TLorentzVector jet;
  jet.SetPtEtaPhiM(jpt, jeta, jphi, 0.); 

  if( flavch == 2 ){
       bool hasCquark = 0;
       for( int c=0;c<*ncQuark;c++ ){
          TLorentzVector C;
          C.SetPtEtaPhiM(cQuark_pT[c], cQuark_eta[c], cQuark_phi[c], 0.);
          double dRc = jet.DeltaR(C); 
          if( dRc < drMin ) hasCquark = 1;
       }
       
       if( hasCquark ){                               
          bool isDplus = false, isDzero = false, isDsubs = false, isDbary = false;
          for( int k=0;k<*nDHadron;k++ ){
            TLorentzVector D;
            D.SetPtEtaPhiM(DHadron_pT[k], DHadron_eta[k], DHadron_phi[k], DHadron_mass[k]);
            double dR = jet.DeltaR(D); 
            if( dR > drMin ) continue;
           
            if( abs(DHadron_pdgID[k]) == 411 ) isDplus = true;
            if( abs(DHadron_pdgID[k]) == 421 ) isDzero = true;
            if( abs(DHadron_pdgID[k]) == 431 ) isDsubs = true;
            if((abs(DHadron_pdgID[k])/1000)%10 == 4 ) isDbary = true;
          }                      
      
           // weight for c->D fragmentation rate: Pythia6(!) vs PDG2008
           // DB
           if( isDplus ) sfDo *= 1.37; // PDG2008(0.246+-0.020)
           if( isDzero ) sfDo *= 0.91; // PDG2008(0.565+-0.032)
           if( isDsubs ) sfDo *= 0.67; // PDG2008(0.080+-0.017)
           // 0.185072, 0.58923, 0.115961
         }                          
   }
   cFragmentationWeightUp[ij] = sfUp;
   cFragmentationWeightDo[ij] = sfDo;   
}

// K0s Lambda sys
void BTagAnalyzerSelector::Ks(int ij)
{       
  float sfUp = 1.;
  float sfDo = 1.;
   
  int flavch = 0; 
  float jeta = Jet_eta[ij];
  float jphi = Jet_phi[ij];
  float jpt  = Jet_pT[ij];

  int jFlavour = abs(Jet_flavour[ij]);
  if( jFlavour == 5 )  flavch = 1;
  if( jFlavour == 4 )  flavch = 2;
  if( jFlavour == 1 || jFlavour == 21 )  flavch = 3;
  if( jFlavour == 0 ) flavch = 3;

  TLorentzVector jet;
  jet.SetPtEtaPhiM(jpt, jeta, jphi, 0.);

  int nK0s = 0, nLambda = 0;
  if( flavch == 3 )
    {
       for( int k=0;k<*nGenV0;k++ ){
         TLorentzVector V0;
         V0.SetPtEtaPhiM(GenV0_pT[k], GenV0_eta[k], GenV0_phi[k], 0.);
         double dR = jet.DeltaR(V0); 
         if( dR > 0.3 ) continue;
         int pdgid = abs(GenV0_pdgId[k]);
         if( pdgid == 310 )  nK0s++;
         if( pdgid == 3122 ) nLambda++;
       }
       if( nK0s > 0 )    sfUp *= 1.3;
       if( nLambda > 0 ) sfUp *= 1.5;
    }
  v0WeightUp[ij] = sfUp;
  v0WeightDo[ij] = sfDo;   
}

void  BTagAnalyzerSelector::JEC(int ij)
{       
  float jeta = 0;
  float jphi = 0;
  float jm = 0;
  float jpt = 0;
   
  jeta = Jet_eta[ij];
  jphi = Jet_phi[ij];
  jm = Jet_mass[ij];
  jpt = Jet_pT[ij];
   
  int etaIdx = -1;
  if( fabs(jeta) >= 0. && fabs(jeta) < 0.5 ) etaIdx = 0;
  if( fabs(jeta) >= 0.5 && fabs(jeta) < 1.1 ) etaIdx = 1;
  if( fabs(jeta) >= 1.1 && fabs(jeta) < 1.7 ) etaIdx = 2;
  if( fabs(jeta) >= 1.7 && fabs(jeta) < 2.3 ) etaIdx = 3;
  if( fabs(jeta) >= 2.3 && fabs(jeta) < 5.0 ) etaIdx = 4;
  
  double jpt_c = jpt;
  double jpt_c_down = jpt;
  double jpt_c_up = jpt;
  if( etaIdx >= 0 ){
      double genpt = 0;
      genpt = Jet_genpt[ij];
      if( genpt >= 0. ) {
        jpt_c = genpt + cJER[etaIdx]*(jpt-genpt);
      
        jpt_c_down = genpt + cJER_down[etaIdx]*(jpt-genpt);
        jpt_c_up = genpt + cJER_up[etaIdx]*(jpt-genpt);
      
        if( jpt_c < 0. ) jpt_c = 0.;
        if( jpt_c_down < 0. ) jpt_c_down = 0.;
        if( jpt_c_up < 0. ) jpt_c_up = 0.;

      }
  
      //jpt = jpt_c;
   }  
    

   Jet_pTJERUp[ij] = jpt_c_up;
   Jet_pTJERDo[ij] = jpt_c_down;
   
   // JES
   jesTotal->setJetPt(jpt);
   jesTotal->setJetEta(jeta);
   double uncert = jesTotal->getUncertainty(true);
  
   Jet_pTJESUp[ij] = jpt*(1.+uncert);
   Jet_pTJESDo[ij] = jpt*(1.-uncert);

  
}



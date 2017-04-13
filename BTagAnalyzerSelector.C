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

using namespace std;

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
   fChain->GetEntry(entry);
   //cout << "njets "<< nJet  << endl;
  
   for (int ij = 0; ij < nJet; ++ij){
      GluonSplitting(ij);     
   }

   newTree->Fill(); 
   //fillNewBranches(); 

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
  float jpt  = Jet_pt[ij];   

  TLorentzVector jet;
  jet.SetPtEtaPhiM(jpt, jeta, jphi, 0.);

  // post-ICHEP 
  if( flavch == 2 )
    {        
       int ndHadronsFound = 0;
       for( int k=0;k<nDHadrons;k++ )
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
       for( int k=0;k<nBHadrons;k++ )
         {
         TLorentzVector B;
         B.SetPtEtaPhiM(BHadron_pT[k], BHadron_eta[k], BHadron_phi[k], 0.);
      double dRqj = jet.DeltaR(B);;
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

  gluonSplittingWeightUp[ij] = sfUp;
  gluonSplittingWeightDo[ij] = sfDo;

}
/*
// b fragmentation sys
void BTagAnalyzerSelector::bFrag(int ij)
{
  float sf = 1.;        
  int flavch = Jet_flavour[ij];
  float drMin = 0.4;   
  float jPT = Jet_pt[ij];
  float jeta = Jet_eta[ij];
  float jphi = Jet_phi[ij];
  float WeightBFrag = 1.;
  float EnergyFraction = 0.; 
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
       for( int ib=0;ib<nBHadrons;ib++ )
         {
      float drB = helper->DeltaR(jeta,
               jphi,
               BHadron_eta[ib], 
               BHadron_phi[ib]);
      
      if( drB < drMin )
        {
           if( BHadron_mass[ib] > B_Mass ) 
       {
          B_Mass = BHadron_mass[ib];
          iB = ib;
       }                                 
        }                           
         }
       
       if( iB >= 0 ) 
         {
      EnergyFraction = BHadron_pT[iB]/Jet_genpt[ij];
      efbin = int( EnergyFraction / 0.02 );
      if( efbin >= 0 && efbin < 100 ) 
        {
           if( isys == SYS_BFRAG_DOWN ) WeightBFrag = BTemplateCorrections[efbin][iptBin][0];
           if( isys == SYS_BFRAG_UP ) WeightBFrag = BTemplateCorrections[efbin][iptBin][1];
        }                           
         }
          
       sf *= WeightBFrag;
  }
   
}

// c->D fragmentation sys
float BTagAnalyzerSelector::cdFrag(int ij,int flavch)
{       
  float sf = 1.;

  float drMin = 0.4;   
  float jeta = Jet_eta[ij];
  float jphi = Jet_phi[ij];

  if( flavch == 2 ||
      flavch == 1 )
    {
       bool isDplusMu = false, isDzeroMu = false, isDsubsMu = false;
       
       int ndaughters = 0;
       for( int k=0;k<nDHadrons;k++ )
         {
      double dR = helper->DeltaR(DHadron_eta[k], 
               DHadron_phi[k], 
               jeta,
               jphi);
      if( dR > drMin ) continue;
      bool isSemiMu = false;
      int nd = DHadron_nDaughters[k];
      for( int kk=0;kk<nd;kk++ )
        {
           if( abs(DHadron_DaughtersPdgID[kk+ndaughters]) == 13 ) isSemiMu = true;
        }
      
      ndaughters += nd;
      
      if( !isSemiMu ) continue;
      if( abs(DHadron_pdgID[k]) == 411 ) isDplusMu = true;
      if( abs(DHadron_pdgID[k]) == 421 ) isDzeroMu = true;
      if( abs(DHadron_pdgID[k]) == 431 ) isDsubsMu = true;
         }
       
       // weight for D->mu decay: Pythia vs PDG2013
       if( isys == SYS_CDFRAG_DOWN )
         {                          
      if( isDplusMu ) sf *= 0.176 / 0.172;
      if( isDzeroMu ) sf *= 0.067 / 0.077;
      if( isDsubsMu ) sf *= 0.067 / 0.080;
         }                     
   }
   
   return sf;
}

// c fragmentation sys
float BTagAnalyzerSelector::cFrag(int ij,int flavch)
{
  float sf = 1.;

  float drMin = 0.4;   
  float jeta = Jet_eta[ij];
  float jphi = Jet_phi[ij];
  if( flavch == 2 )
    {
       bool hasCquark = 0;
       for( int c=0;c<ncQuarks;c++ )
         {
      double dRc = helper->DeltaR(cQuark_eta[c], 
                cQuark_phi[c], 
                jeta,
                jphi);
      if( dRc < drMin ) hasCquark = 1;
         }
       
       if( hasCquark )
         {                               
      bool isDplus = false, isDzero = false, isDsubs = false, isDbary = false;
      for( int k=0;k<nDHadrons;k++ )
        {
           double dR = helper->DeltaR(DHadron_eta[k], 
              DHadron_phi[k], 
              jeta, 
              jphi);
           if( dR > drMin ) continue;
           
           if( abs(DHadron_pdgID[k]) == 411 ) isDplus = true;
           if( abs(DHadron_pdgID[k]) == 421 ) isDzero = true;
           if( abs(DHadron_pdgID[k]) == 431 ) isDsubs = true;
           if((abs(DHadron_pdgID[k])/1000)%10 == 4 ) isDbary = true;
        }                      
      
      // weight for c->D fragmentation rate: Pythia6(!) vs PDG2008
      if( isys == SYS_CFRAG_DOWN )
        {
           // DB
           if( isDplus ) sf *= 1.37; // PDG2008(0.246+-0.020)
           if( isDzero ) sf *= 0.91; // PDG2008(0.565+-0.032)
           if( isDsubs ) sf *= 0.67; // PDG2008(0.080+-0.017)
           // 0.185072, 0.58923, 0.115961
        }                      
         }                          
    }
   
   return sf;
}

// K0s Lambda sys
float BTagAnalyzerSelector::Ks(int ij,int flavch)
{       
  float sf = 1.;
   
  float jeta = Jet_eta[ij];
  float jphi = Jet_phi[ij];
  int nK0s = 0, nLambda = 0;
  if( flavch == 3 )
    {
       for( int k=0;k<nGenV0;k++ )
         {
      double dR = helper->DeltaR(GenV0_eta[k], 
               GenV0_phi[k], 
               jeta,
               jphi);
      if( dR > 0.3 ) continue;
      int pdgid = abs(GenV0_pdgID[k]);
      if( pdgid == 310 )  nK0s++;
      if( pdgid == 3122 ) nLambda++;
         }
       if( isys == SYS_KSL_UP )
         {                          
      if( nK0s > 0 )    sf *= 1.3;
      if( nLambda > 0 ) sf *= 1.5;
         }
    }
   
   return sf;
}
*/

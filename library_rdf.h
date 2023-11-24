#include <string>
#include <TH1.h>
#include <iostream>
#include <ROOT/RDF/RSampleInfo.hxx>
#include <fstream>
#include <sstream>
#include <unordered_map>
#include <ROOT/RVec.hxx>

namespace RDFHelper {


using cRVecF = const ROOT::RVecF &;
using cRVecI = const ROOT::RVecI &;
using cRVecB = const ROOT::RVecB &;

class Pileup{
  public:
  Pileup(const TH1* dataHisto, const TH1* mcHisto) {
    std::cout << "Created!" << std::endl;
    normDataHisto = (TH1*) dataHisto->Clone();
    normDataHisto->Scale(1./normDataHisto->Integral());
    normMCHisto = (TH1*) mcHisto->Clone();
    normMCHisto->Scale(1./normMCHisto->Integral());
    ratio = (TH1*) normDataHisto->Clone();
    ratio->Divide(normMCHisto);
    std::cout << ratio << std::endl;
  };
  
  double operator() (float nPU) const {
    //std::cout << "calling" << nPU << std::endl;
    return ratio->GetBinContent(ratio->FindBin(nPU));
  }  
  
  private:
    TH1* normDataHisto;
    TH1* normMCHisto;
    TH1* ratio;

};

class Prescale{
  public: 
  Prescale(){}

  void load(int trigIdx, std::string csvFile) {
    std::ifstream filein(csvFile);
    std::string line;
    while (std::getline(filein, line)) {
      if (line.find("totprescval") != std::string::npos) {
          continue;
      }
      std::istringstream iss(line);
      std::string run, ls, prescaleidx, prescale;
      std::getline(iss, run, ',');
      std::getline(iss, ls, ',');
      std::getline(iss, prescaleidx, ',');
      std::getline(iss, prescale, ',');
      if (ls == "None") {
          ls = "1";
      }
      data[trigIdx][std::stoi(run)][std::stoi(ls)] = std::stod(prescale);
    }
    filein.close();
  }

  double operator() (cRVecI triggers, const unsigned int& run, const unsigned int& lumi) {
    if (!triggers.size())
      return 0.;
    auto& trigIdx = triggers[0];
    if (data.find(trigIdx) == data.end()){
      std::cout << "No data for trigger index " << trigIdx << std::endl;
      return 1.;
    }
    if (data[trigIdx].find(run) == data[trigIdx].end()) {
       std::cout << "This run "<< run << " was not found for this trigger " << trigIdx << std::endl;
       return 1.;
    }
    auto& prescaleTable = data[trigIdx][run];
    int distance = 999999;
    int closest = 1;
    for (const auto& kv : prescaleTable) {
        int ls = kv.first;
        if (lumi - ls >= 0 && lumi - ls < distance) {
            distance = lumi - ls;
            closest = kv.first;
        }
    }
    if (closest != 0) {
        return prescaleTable[closest];
    } else {
        std::cout << "Warning: prescale table requested for ls 0. This should not happen. Run " << run << " lumi " << lumi << std::endl;
        return 1.0;
    }
  
  }

  private:
  std::unordered_map<int, std::unordered_map<int, std::unordered_map<int, double>>> data;
};  

double getXsectionWeight(unsigned int slot, const ROOT::RDF::RSampleInfo &sample){
  if (sample.Contains("QCD_PT-15to20_MuEnrichedPt5"))
    return 2.948e+06/16191725;
  else if (sample.Contains("QCD_PT-20to30_MuEnrichedPt5"))  
    return 2.695e+06/97331894;
  else if (sample.Contains("QCD_PT-30to50_MuEnrichedPt5")) 
    return 1.446e+06/102810021;
  else if (sample.Contains("QCD_PT-50to80_MuEnrichedPt5"))  
    return 4.060e+05/41330577;
  else if (sample.Contains("QCD_PT-80to120_MuEnrichedPt5"))
    return 9.643e+04/87342853; 
  else if (sample.Contains("QCD_PT-120to170_MuEnrichedPt5"))   
    return 2.310e+04/69874302;
  else if (sample.Contains("QCD_PT-170to300_MuEnrichedPt5"))
    return 7.789e+03/102039909;
  else if (sample.Contains("QCD_PT-300to470_MuEnrichedPt5"))
    return 7.028e+02/97185423;
  else if (sample.Contains("QCD_PT-470to600_MuEnrichedPt5"))
    return 6.864e+01/69336360;
  else if (sample.Contains("QCD_PT-600to800_MuEnrichedPt5"))
    return 2.128e+01/72411423;
  else if (sample.Contains("QCD_PT-800to1000_MuEnrichedPt5"))
    return 3.880e+00/116801203;
  else if (sample.Contains("QCD_PT-1000_MuEnrichedPt5"))
    return 1.322e+00/46767938;
  std::cout << "Error. Unknown sample " << sample.AsString() << std::endl;
  return 0;

};





ROOT::RVecI FindGoodJets(cRVecF jetpt, cRVecF jeteta){
  ROOT::RVecI result;
  for(auto i = 0; i < jetpt.size(); i++) {
    if (jetpt[i] > 20. && fabs(jeteta[i]< 2.4)) result.push_back(i);
    
  }    
  return result;
}

ROOT::RVecI FindMatchedJets(cRVecF jeteta, cRVecF jetphi, cRVecF muoneta, cRVecF muonphi){
  ROOT::RVecI result;
  for(auto i = 0; i < jeteta.size(); i++) {
    for (auto j = 0; j < muoneta.size(); j++){
      if (ROOT::VecOps::DeltaR(jeteta[i], muoneta[j], jetphi[i], muonphi[j])<0.4){
        result.push_back(i);  
      } 
    }
  }    
  return result;
}

ROOT::RVecI FindGoodMuons(cRVecF muonpt, cRVecF muoneta){
  ROOT::RVecI result;
  for(auto i = 0; i < muonpt.size(); i++) {
    if (muonpt[i] > 5. && fabs(muoneta[i]< 2.4)) result.push_back(i);
  }    
  return result;

}

ROOT::RVecI GetTriggersFires(cRVecI BitTrigger){
  ROOT::RVecI result;
  for (int trigIdx = 32; trigIdx < 38; trigIdx++){
    int bitIdx = int(trigIdx/32) ;
    if ( BitTrigger[bitIdx] & ( 1 << (trigIdx - bitIdx*32) ) ) result.push_back(trigIdx);
  }
  return result;
}

ROOT::RVecI GetTriggerPtBins(int nJets20, int nJets50, int nJets80, int nJets120, int nJets180, int nJets320, 
                             int nMuJets20, int nMuJets50, int nMuJets80, int nMuJets120, int nMuJets180, int nMuJets320){
  ROOT::RVecI triggerPtBins;                            
  if ( nJets20 >= 2  && nMuJets20 >= 1 )   triggerPtBins.push_back(32);
  if ( nJets50 >= 2  && nMuJets50 >= 1 )   triggerPtBins.push_back(33);
  if ( nJets80 >= 2  && nMuJets80 >= 1 )   triggerPtBins.push_back(34);
  if ( nJets120 >= 2 && nMuJets120 >= 1 )  triggerPtBins.push_back(35);
  if ( nJets180 >= 2 && nMuJets180 >= 1 )  triggerPtBins.push_back(36);
  if ( nJets320 > 0  && nMuJets320 >= 1 )  triggerPtBins.push_back(37);

  return triggerPtBins;                         
}

ROOT::RVecB InPtBin(cRVecF pts, cRVecF etas, cRVecF probas, float ptmin, float ptmax){
  ROOT::RVecB result;
  for (auto i = 0; i < pts.size(); i++){
    result.push_back(pts[i]>ptmin && pts[i]<ptmax && fabs(etas[i])<2.4 && probas[i]>0);  
  }
  return result;
}

ROOT::RVecB InPtBinJP0(cRVecF pts, cRVecF etas, cRVecF probas, float ptmin, float ptmax){
  ROOT::RVecB result;
  for (auto i = 0; i < pts.size(); i++){
    result.push_back(pts[i]>ptmin && pts[i]<ptmax && fabs(etas[i])<2.4 && probas[i]<=0);  
  }
  return result;
}
ROOT::RVecB InPtBinAndTaggerPass(cRVecF pts, cRVecF etas, cRVecF probas, cRVecF tagger, float ptmin, float ptmax, float wp){
  ROOT::RVecB result;
  for (auto i = 0; i < pts.size(); i++){
    result.push_back(pts[i]>ptmin && pts[i]<ptmax && fabs(etas[i])<2.4 && probas[i]>0 &&
                     tagger[i]>wp);  
  }
  return result;
}
ROOT::RVecB InPtBinAndTaggerFail(cRVecF pts, cRVecF etas, cRVecF probas, cRVecF tagger, float ptmin, float ptmax, float wp){
  ROOT::RVecB result;
  for (auto i = 0; i < pts.size(); i++){
    result.push_back(pts[i]>ptmin && pts[i]<ptmax && fabs(etas[i])<2.4 && probas[i]>0 &&
                     tagger[i]<=wp);  
  }
  return result;
}
ROOT::RVecB InPtBinAndTaggerPassAndSVMass(cRVecF pts, cRVecF etas, cRVecF probas, cRVecF tagger, cRVecF svmass, float ptmin, float ptmax, float wp){
  ROOT::RVecB result;
  for (auto i = 0; i < pts.size(); i++){
    result.push_back(pts[i]>ptmin && pts[i]<ptmax && fabs(etas[i])<2.4 && probas[i]>0 &&
                     tagger[i]>wp && svmass[i]>0);  
  }
  return result;
}
ROOT::RVecB InPtBinAndTaggerPassAndSVMassFail(cRVecF pts, cRVecF etas, cRVecF probas, cRVecF tagger, cRVecF svmass, float ptmin, float ptmax, float wp){
  ROOT::RVecB result;
  for (auto i = 0; i < pts.size(); i++){
    result.push_back(pts[i]>ptmin && pts[i]<ptmax && fabs(etas[i])<2.4 && probas[i]>0 &&
                     tagger[i]>wp && svmass[i]<=0);  
  }
  return result;
}
}

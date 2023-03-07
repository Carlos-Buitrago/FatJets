#define TreeModifierClass_cxx
#include "TreeModifierClass.h"
#include <TH2.h>
#include <TStyle.h>
#include <TCanvas.h>

void TreeModifierClass::Loop()
{
//     This is the loop skeleton where:
//    jentry is the global entry number in the chain
//    ientry is the entry number in the current Tree
//  Note that the argument to GetEntry must be:
//    jentry for TChain::GetEntry
//    ientry for TTree::GetEntry and TBranch::GetEntry
   if (fChain == 0) return;
   

   // branches for selected towers
   std::vector<Float_t> myTowerETvec;
   std::vector<Float_t> myTowerEtavec;
   std::vector<Float_t> myTowerPhivec;
   
   std::vector<Float_t> myTrackPTvec;
   std::vector<Float_t> myTrackEtavec;
   std::vector<Float_t> myTrackPhivec;

   std::vector<Float_t> myParticlePTvec;
   std::vector<Float_t> myParticleEtavec;
   std::vector<Float_t> myParticlePhivec;

   TBranch *myTowerETbranch = fChain->Branch("myTowerET", &myTowerETvec);
   TBranch *myTowerEtabranch = fChain->Branch("myTowerEta", &myTowerEtavec);
   TBranch *myTowerPhibranch = fChain->Branch("myTowerPhi", &myTowerPhivec);

   TBranch *myTrackPTbranch = fChain->Branch("myTrackPT", &myTrackPTvec);
   TBranch *myTrackEtabranch = fChain->Branch("myTrackEta", &myTrackEtavec);
   TBranch *myTrackPhibranch = fChain->Branch("myTrackPhi", &myTrackPhivec);

   TBranch *myParticlePTbranch = fChain->Branch("myParticlePT", &myParticlePTvec);
   TBranch *myParticleEtabranch = fChain->Branch("myParticleEta", &myParticleEtavec);
   TBranch *myParticlePhibranch = fChain->Branch("myParticlePhi", &myParticlePhivec);
   
   Long64_t nentries = fChain->GetEntries();

   Long64_t nbytes = 0, nb = 0;
   for (Long64_t jentry=0; jentry<nentries;jentry++) {
      Long64_t ientry = LoadTree(jentry);
      if (ientry < 0) break;

      nb = fChain->GetEntry(jentry);   nbytes += nb;

      std::cout << "Processing event numer " << ientry << std::endl;

      for (int i = 0; i < Tower_size; i++){
        for (int j = 0; j < Jet_size; j++){
          if ((sqrt((Tower_Eta[i] - Jet_Eta[j])*(Tower_Eta[i] - Jet_Eta[j]) + (Tower_Phi[i] - Jet_Phi[j])*(Tower_Phi[i] - Jet_Phi[j])) < 0.6) && (Tower_ET[i] > 20.0)){
            myTowerETvec.push_back(Tower_ET[i]);
            myTowerEtavec.push_back(Tower_Eta[i]);
            myTowerPhivec.push_back(Tower_Phi[i]);
            goto cnt1;
          }
        }
        cnt1:;
      }

      for (int i = 0; i < Track_size; i++){
        for (int j = 0; j < Jet_size; j++){
          if ((sqrt((Track_Eta[i] - Jet_Eta[j])*(Track_Eta[i] - Jet_Eta[j]) + (Track_Phi[i] - Jet_Phi[j])*(Track_Phi[i] - Jet_Phi[j])) < 0.6) && (Track_PT[i] > 50.0)){
            myTrackPTvec.push_back(Track_PT[i]);
            myTrackEtavec.push_back(Track_Eta[i]);
            myTrackPhivec.push_back(Track_Phi[i]);
            goto cnt2;
          }
        }
        cnt2:;
      }

      for (int i = 0; i < Particle_size; i++){
        for (int j = 0; j < Jet_size; j++){
          if ((sqrt((Particle_Eta[i] - Jet_Eta[j])*(Particle_Eta[i] - Jet_Eta[j]) + (Particle_Phi[i] - Jet_Phi[j])*(Particle_Phi[i] - Jet_Phi[j])) < 0.6) && (Particle_PT[i] > 350.0)){
            myParticlePTvec.push_back(Particle_PT[i]);
            myParticleEtavec.push_back(Particle_Eta[i]);
            myParticlePhivec.push_back(Particle_Phi[i]);
            goto cnt3;
          }
        }
        cnt3:;
      }


      myTowerETbranch->Fill();
      myTowerEtabranch->Fill();
      myTowerPhibranch->Fill();

      myTrackPTbranch->Fill();
      myTrackEtabranch->Fill();
      myTrackPhibranch->Fill();

      myParticlePTbranch->Fill();
      myParticleEtabranch->Fill();
      myParticlePhibranch->Fill();

      myTowerETvec.clear();
      myTowerEtavec.clear();
      myTowerPhivec.clear();

      myTrackPTvec.clear();
      myTrackEtavec.clear();
      myTrackPhivec.clear();

      myParticlePTvec.clear();
      myParticleEtavec.clear();
      myParticlePhivec.clear();

   }

   fChain->Write();

}

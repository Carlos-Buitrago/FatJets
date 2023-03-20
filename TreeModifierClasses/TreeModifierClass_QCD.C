#define TreeModifierClass_QCD_cxx
#include "TreeModifierClass_QCD.h"
#include <TH2.h>
#include <TStyle.h>
#include <TCanvas.h>

void TreeModifierClass_QCD::Loop()
{
//     This is the loop skeleton where:
//    jentry is the global entry number in the chain
//    ientry is the entry number in the current Tree
//  Note that the argument to GetEntry must be:
//    jentry for TChain::GetEntry
//    ientry for TTree::GetEntry and TBranch::GetEntry
   if (fChain == 0) return;

   /* std::vector<Float_t> DeltaR_Tower_Jet; */
   /* std::vector<Float_t> DeltaR_Tower_FatJet; */
   /* std::vector<Float_t> DeltaR_Track_Jet; */
   /* std::vector<Float_t> DeltaR_Track_FatJet; */

   Int_t Tower_number_total = 0;
   Int_t Track_number_total = 0;
   Int_t Particle_number_total = 0;

   Int_t Tower_number_20 = 0;
   Int_t Track_number_50 = 0;
   Int_t Particle_number_350 = 0;

   Int_t Particle_number_100 = 0;
   
   std::vector<Float_t> myTowerETvec;
   std::vector<Float_t> myTowerEtavec;
   std::vector<Float_t> myTowerPhivec;
   
   std::vector<Float_t> myTrackPTvec;
   std::vector<Float_t> myTrackEtavec;
   std::vector<Float_t> myTrackPhivec;

   std::vector<Float_t> myParticlePTvec;
   std::vector<Float_t> myParticleEtavec;
   std::vector<Float_t> myParticlePhivec;

   /* TBranch *myDeltaRTowerJetbranch = fChain->Branch("myDeltaRTowerJet", &DeltaR_Tower_Jet); */
   /* TBranch *myDeltaRTowerFatJetbranch = fChain->Branch("myDeltaRTowerFatJet", &DeltaR_Tower_FatJet); */
   /* TBranch *myDeltaRTrackJetbranch = fChain->Branch("myDeltaRTrackJet", &DeltaR_Track_Jet); */
   /* TBranch *myDeltaRTrackFatJetbranch = fChain->Branch("myDeltaRTrackFatJet", &DeltaR_Track_FatJet); */
   
   TBranch *myTowerNumberTotalbranch = fChain->Branch("myTowerNumberTotal", &Tower_number_total, "Tower_number_total/I");
   TBranch *myTrackNumberTotalbranch = fChain->Branch("myTrackNumberTotal", &Track_number_total, "Track_number_total/I");
   TBranch *myParticleNumberTotalbranch = fChain->Branch("myParticleNumberTotal", &Particle_number_total, "Particle_number_total/I");

   TBranch *myTowerNumber20branch = fChain->Branch("myTowerNumber20", &Tower_number_20, "Tower_number_20/I");
   TBranch *myTrackNumber50branch = fChain->Branch("myTrackNumber50", &Track_number_50, "Track_number_50/I");
   TBranch *myParticleNumber350branch = fChain->Branch("myParticleNumber350", &Particle_number_350, "Particle_number_350/I");

   TBranch *myParticleNumber100branch = fChain->Branch("myParticleNumber100", &Particle_number_100, "Particle_number_100/I");

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

      /* for (int i = 0; i < Tower_size; i++){ */
      /*   for (int j = 0; j < Jet_size; j++){ */
      /*     Float_t deltaRTowerJet = sqrt((Tower_Eta[i] - Jet_Eta[j])*(Tower_Eta[i] - Jet_Eta[j]) + (Tower_Phi[i] - Jet_Phi[j])*(Tower_Phi[i] - Jet_Phi[j])); */
      /*     DeltaR_Tower_Jet.push_back(deltaRTowerJet); */ 
      /*   } */
      /*   for (int k = 0; k < FatJet_size; k++){ */
      /*     Float_t deltaRTowerFatJet = sqrt((Tower_Eta[i] - FatJet_Eta[k])*(Tower_Eta[i] - FatJet_Eta[k]) + (Tower_Phi[i] - FatJet_Phi[k])*(Tower_Phi[i] - FatJet_Phi[k])); */
      /*     DeltaR_Tower_FatJet.push_back(deltaRTowerFatJet); */ 
      /*   } */
      /* } */

      /* for (int i = 0; i < Track_size; i++){ */
      /*   for (int j = 0; j < Jet_size; j++){ */
      /*     Float_t deltaRTrackJet = sqrt((Track_Eta[i] - Jet_Eta[j])*(Track_Eta[i] - Jet_Eta[j]) + (Track_Phi[i] - Jet_Phi[j])*(Track_Phi[i] - Jet_Phi[j])); */
      /*     DeltaR_Track_Jet.push_back(deltaRTrackJet); */ 
      /*   } */
      /*   for (int k = 0; k < FatJet_size; k++){ */
      /*     Float_t deltaRTrackFatJet = sqrt((Track_Eta[i] - FatJet_Eta[k])*(Track_Eta[i] - FatJet_Eta[k]) + (Track_Phi[i] - FatJet_Phi[k])*(Track_Phi[i] - FatJet_Phi[k])); */
      /*     DeltaR_Track_FatJet.push_back(deltaRTrackFatJet); */ 
      /*   } */
      /* } */

      for (int i = 0; i < Tower_size; i++){
        for (int j = 0; j < FatJet_size; j++){
          if (sqrt((Tower_Eta[i] - FatJet_Eta[j])*(Tower_Eta[i] - FatJet_Eta[j]) + (Tower_Phi[i] - FatJet_Phi[j])*(Tower_Phi[i] - FatJet_Phi[j])) < 1.0) {
            Tower_number_total = Tower_number_total + 1;
            if (Tower_ET[i] > 20.0){
              myTowerETvec.push_back(Tower_ET[i]);
              myTowerEtavec.push_back(Tower_Eta[i]);
              myTowerPhivec.push_back(Tower_Phi[i]);
              Tower_number_20 = Tower_number_20 + 1;
            }
            goto cnt1;
          }
        }
        cnt1:;
      }

      for (int i = 0; i < Track_size; i++){
        for (int j = 0; j < FatJet_size; j++){
          if (sqrt((Track_Eta[i] - FatJet_Eta[j])*(Track_Eta[i] - FatJet_Eta[j]) + (Track_Phi[i] - FatJet_Phi[j])*(Track_Phi[i] - FatJet_Phi[j])) < 1.0) {
            Track_number_total = Track_number_total + 1;
            if (Track_PT[i] > 50.0){
              myTrackPTvec.push_back(Track_PT[i]);
              myTrackEtavec.push_back(Track_Eta[i]);
              myTrackPhivec.push_back(Track_Phi[i]);
              Track_number_50 = Track_number_50 + 1;
            }
            goto cnt2;
          }
        }
        cnt2:;
      }

      for (int i = 0; i < Particle_size; i++){
        for (int j = 0; j < FatJet_size; j++){
          if (sqrt((Particle_Eta[i] - FatJet_Eta[j])*(Particle_Eta[i] - FatJet_Eta[j]) + (Particle_Phi[i] - FatJet_Phi[j])*(Particle_Phi[i] - FatJet_Phi[j])) < 1.0) {
            Particle_number_total = Particle_number_total + 1;
            if (Particle_PT[i] > 100.0){
              Particle_number_100 = Particle_number_100 + 1;
              if (Particle_PT[i] > 350.0){
                myParticlePTvec.push_back(Particle_PT[i]);
                myParticleEtavec.push_back(Particle_Eta[i]);
                myParticlePhivec.push_back(Particle_Phi[i]);
                Particle_number_350 = Particle_number_350 + 1;
              }
            }
            goto cnt3;
          }
        }
        cnt3:;
      }
      
      /* myDeltaRTowerJetbranch->Fill(); */
      /* myDeltaRTowerFatJetbranch->Fill(); */
      /* myDeltaRTrackJetbranch->Fill(); */
      /* myDeltaRTrackFatJetbranch->Fill(); */

      myTowerNumberTotalbranch->Fill();
      myTrackNumberTotalbranch->Fill();
      myParticleNumberTotalbranch->Fill();

      myTowerNumber20branch->Fill();
      myTrackNumber50branch->Fill();
      myParticleNumber350branch->Fill();
      myParticleNumber100branch->Fill();

      myTowerETbranch->Fill();
      myTowerEtabranch->Fill();
      myTowerPhibranch->Fill();

      myTrackPTbranch->Fill();
      myTrackEtabranch->Fill();
      myTrackPhibranch->Fill();

      myParticlePTbranch->Fill();
      myParticleEtabranch->Fill();
      myParticlePhibranch->Fill();

      /* DeltaR_Tower_Jet.clear(); */
      /* DeltaR_Tower_FatJet.clear(); */
      /* DeltaR_Track_Jet.clear(); */
      /* DeltaR_Track_FatJet.clear(); */

      Tower_number_total = 0;
      Track_number_total = 0;
      Particle_number_total = 0;

      Tower_number_20 = 0;
      Track_number_50 = 0;
      Particle_number_350 = 0;
      Particle_number_100 = 0;

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

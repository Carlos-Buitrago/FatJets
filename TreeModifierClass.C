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
   
   // TEST - Adding a new branch
   /* Float_t myFloat = 42.0; */
   /* TBranch *myNewBranch = fChain->Branch("MyNewBranchName", &myFloat, "MyNewBranchName/F"); */

   // branches for selected towers
   std::vector<Float_t> myTowerETvec;
   std::vector<Float_t> myTowerEtavec;
   std::vector<Float_t> myTowerPhivec;
   TBranch *myTowerETbranch = fChain->Branch("myTowerET", &myTowerETvec);
   TBranch *myTowerEtabranch = fChain->Branch("myTowerEta", &myTowerEtavec);
   TBranch *myTowerPhibranch = fChain->Branch("myTowerPhi", &myTowerPhivec);

   Long64_t nentries = fChain->GetEntries();

   Long64_t nbytes = 0, nb = 0;
   for (Long64_t jentry=0; jentry<nentries;jentry++) {
      Long64_t ientry = LoadTree(jentry);
      if (ientry < 0) break;

      nb = fChain->GetEntry(jentry);   nbytes += nb;

      std::cout << "Processing event numer " << ientry << std::endl;

      // TEST - Adding a new branch
      /* Float_t newBranchValue = FatJet_PT[0]; */
      /* myFloat = newBranchValue; */
      /* myNewBranch->Fill(); */
      /* std::cout << "The value stored in myNewBranch is " << myFloat << std::endl; */

      for (int i = 0; i < Tower_size; i++){
        if (Tower_ET[i] > 20.0){
          myTowerETvec.push_back(Tower_ET[i]);
          myTowerEtavec.push_back(Tower_Eta[i]);
          myTowerPhivec.push_back(Tower_Phi[i]);
        }
      }

      myTowerETbranch->Fill();
      myTowerEtabranch->Fill();
      myTowerPhibranch->Fill();

      myTowerETvec.clear();
      myTowerEtavec.clear();
      myTowerPhivec.clear();

   }

   fChain->Write();

}

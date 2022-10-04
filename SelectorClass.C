#define SelectorClass_cxx
#include "SelectorClass.h"
#include <TH2.h>
#include <TStyle.h>
#include <TCanvas.h>

void SelectorClass::Loop()
{
//   In a ROOT session, you can do:
//      root> .L SelectorClass.C
//      root> SelectorClass t
//      root> t.GetEntry(12); // Fill t data members with entry number 12
//      root> t.Show();       // Show values of entry 12
//      root> t.Show(16);     // Read and show values of entry 16
//      root> t.Loop();       // Loop on all entries

   if (fChain == 0) return;

   TH1F *hist_FatJet_Tau1 = new TH1F("Tau_1", "FatJet Tau_1 Subjettiness; Tau_1; Events", 100, 0, 1);
   TH1F *hist_FatJet_Tau2 = new TH1F("Tau_2", "FatJet Tau_2 Subjettiness; Tau_2; Events", 100, 0, 1);

   Long64_t nentries = fChain->GetEntries();
   for (Long64_t jentry=0; jentry<nentries;jentry++) {
   
      fChain->GetEntry(jentry);

      
      for (int i = 0; i < FatJet_size; i++){
         hist_FatJet_Tau1->Fill(FatJet_Tau[0][i]);
         hist_FatJet_Tau2->Fill(FatJet_Tau[1][i]);
      }
   
   /*  this selection doesnt work (it is written for a TMakeSelector, not a TMakeClass)   
   // Event must have exactly 2 b-jets
   int n_bjets = 0;
   int bjet1_index = 0;
   int bjet2_index = 0;
   for (unsigned int i = 0; i < Jet_PT.GetSize(); i++){
      if (Jet_BTag[i] == 1){
         n_bjets++;
         if (bjet1_index == 0) bjet1_index = i;
         if (bjet1_index != 0) bjet2_index = i;
      }
   }
   if (n_bjets != 2) return kTRUE;

   // Mass of FatJets with 2SubJets that are near the 2 bjets
   float DeltaR_bjet1_FatJet = 0;
   float DeltaR_bjet2_FatJet = 0;
   if (FatJet_PT.GetSize() > 0){
      for (unsigned int i = 0; i < FatJet_PT.GetSize(); i++){
         if (FatJet_NSubJetsTrimmed[i] == 2){
            DeltaR_bjet1_FatJet = sqrt((Jet_Eta[bjet1_index] - FatJet_Eta[i])*(Jet_Eta[bjet1_index] - FatJet_Eta[i]) + (Jet_Phi[bjet1_index] - FatJet_Phi[i])*(Jet_Phi[bjet1_index] - FatJet_Phi[i]));
            DeltaR_bjet2_FatJet = sqrt((Jet_Eta[bjet2_index] - FatJet_Eta[i])*(Jet_Eta[bjet2_index] - FatJet_Eta[i]) + (Jet_Phi[bjet2_index] - FatJet_Phi[i])*(Jet_Phi[bjet2_index] - FatJet_Phi[i]));
            if (DeltaR_bjet1_FatJet < 1.0 && DeltaR_bjet2_FatJet < 1.0){
               hist_FatJetMass_2SubJetsNear2bjets->Fill(FatJet_Mass[i]);
            }
         }
      }
   }
   */
      
   }

   TCanvas *canvas_FatJet_Tau1 = new TCanvas("canvas_FatJet_Tau1","canvas_FatJet_Tau1",1000,800);
   hist_FatJet_Tau1->SetFillColor(kYellow);
   hist_FatJet_Tau1->Draw();
   canvas_FatJet_Tau1->Print("./SelecClass_FatJet_Tau1.pdf");

   TCanvas *canvas_FatJet_Tau2 = new TCanvas("canvas_FatJet_Tau2","canvas_FatJet_Tau2",1000,800);
   hist_FatJet_Tau2->SetFillColor(kYellow);
   hist_FatJet_Tau2->Draw();
   canvas_FatJet_Tau2->Print("./SelecClass_FatJet_Tau2.pdf");

}
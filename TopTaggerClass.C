#define TopTaggerClass_cxx
#include "TopTaggerClass.h"
#include <TH2.h>
#include <TStyle.h>
#include <TCanvas.h>

//       TopTaggerClass::Loop() is the loop skeleton where:
//    jentry is the global entry number in the chain
//    ientry is the entry number in the current Tree
//       Note that the argument to GetEntry must be:
//    jentry for TChain::GetEntry
//    ientry for TTree::GetEntry and TBranch::GetEntry
//
//       To read only selected branches, Insert statements like:
//    fChain->SetBranchStatus("*",0);  // disable all branches
//    fChain->SetBranchStatus("branchname",1);  // activate branchname
//
//    when looping on fChain a value of fCurrent == 0 corresponds to the signal rootfile and fCurrent == 1 corresponds to the background rootfile

void TopTaggerClass::Loop()
{

   TH1F *hist_Signal_FatJet_Tau2 = new TH1F("Signal_FatJet_Tau2", "FatJet #tau_{2}; #tau_{2}; Events", 25, 0, 1);
   TH1F *hist_Background_FatJet_Tau2 = new TH1F("Background_FatJet_Tau2", "FatJet #tau_{2}; #tau_{2}; Events", 25, 0, 1);
   TH1F *hist_Signal_FatJet_Tau3 = new TH1F("Signal_FatJet_Tau3", "FatJet #tau_{3}; #tau_{3}; Events", 25, 0, 1);
   TH1F *hist_Background_FatJet_Tau3 = new TH1F("Background_FatJet_Tau3", "FatJet #tau_{3}; #tau_{3}; Events", 25, 0, 1);
   TH1F *hist_Signal_FatJet_RatioTau3Tau2 = new TH1F("Signal_FatJet_RatioTau3Tau2", "FatJet #tau_{3}/#tau_{2}; #tau_{3}/#tau_{2}; Events", 25, 0, 1);
   TH1F *hist_Background_FatJet_RatioTau3Tau2 = new TH1F("Background_FatJet_RatioTau3Tau2", "FatJet #tau_{3}/#tau_{2}; #tau_{3}/#tau_{2}; Events", 25, 0, 1);

   TH1F *hist_Signal_FatJet_Tau2_Normalized = new TH1F("Signal_FatJet_Tau2_Normalized", "FatJet #tau_{2}; #tau_{2}; Events", 25, 0, 1);
   TH1F *hist_Background_FatJet_Tau2_Normalized = new TH1F("Background_FatJet_Tau2_Normalized", "FatJet #tau_{2}; #tau_{2}; Events", 25, 0, 1);
   TH1F *hist_Signal_FatJet_Tau3_Normalized = new TH1F("Signal_FatJet_Tau3_Normalized", "FatJet #tau_{3}; #tau_{3}; Events", 25, 0, 1);
   TH1F *hist_Background_FatJet_Tau3_Normalized = new TH1F("Background_FatJet_Tau3_Normalized", "FatJet #tau_{3}; #tau_{3}; Events", 25, 0, 1);
   TH1F *hist_Signal_FatJet_RatioTau3Tau2_Normalized = new TH1F("Signal_FatJet_RatioTau3Tau2_Normalized", "FatJet #tau_{3}/#tau_{2}; #tau_{3}/#tau_{2}; Events", 25, 0, 1);
   TH1F *hist_Background_FatJet_RatioTau3Tau2_Normalized = new TH1F("Background_FatJet_RatioTau3Tau2_Normalized", "FatJet #tau_{3}/#tau_{2}; #tau_{3}/#tau_{2}; Events", 25, 0, 1);

   if (fChain == 0) return;

   Long64_t nentries = fChain->GetEntries();

   Long64_t nbytes = 0, nb = 0;
   for (Long64_t jentry=0; jentry<nentries;jentry++) {

      Long64_t ientry = LoadTree(jentry);
      if (ientry < 0) break;

      nb = fChain->GetEntry(jentry);   nbytes += nb;


      // evt contains at least one FatJet
      if (FatJet_size < 1) continue;

      // cut on leading FatJet
      if (FatJet_PT[0] < 350.) continue;

      // mass cut on leading FatJet
      if (FatJet_Mass[0] < 145. || FatJet_Mass[0] > 205.) continue;
   
      // eta cut on leading FatJet
      if (TMath::Abs(FatJet_Eta[0]) < 2.0) continue;
      
      // signal histos for leading FatJet
      if (fCurrent == 0){
         // tau2 histo
         hist_Signal_FatJet_Tau2->Fill(FatJet_Tau[1][0]);
         hist_Signal_FatJet_Tau2_Normalized->Fill(FatJet_Tau[1][0]);
         // tau3 histo
         hist_Signal_FatJet_Tau3->Fill(FatJet_Tau[2][0]);
         hist_Signal_FatJet_Tau3_Normalized->Fill(FatJet_Tau[2][0]);
         // tau3/tau2 histo
         hist_Signal_FatJet_RatioTau3Tau2->Fill((FatJet_Tau[2][0])/(FatJet_Tau[1][0]));
         hist_Signal_FatJet_RatioTau3Tau2_Normalized->Fill((FatJet_Tau[2][0])/(FatJet_Tau[1][0]));
      }

      // background histos for leading FatJet
      if (fCurrent == 1){
         // tau2 histo
         hist_Background_FatJet_Tau2->Fill(FatJet_Tau[1][0]);
         hist_Background_FatJet_Tau2_Normalized->Fill(FatJet_Tau[1][0]);
         // tau3 histo
         hist_Background_FatJet_Tau3->Fill(FatJet_Tau[2][0]);
         hist_Background_FatJet_Tau3_Normalized->Fill(FatJet_Tau[2][0]);
         // tau3/tau2 histo
         hist_Background_FatJet_RatioTau3Tau2->Fill((FatJet_Tau[2][0])/(FatJet_Tau[1][0]));
         hist_Background_FatJet_RatioTau3Tau2_Normalized->Fill((FatJet_Tau[2][0])/(FatJet_Tau[1][0]));
      }

      /*
      // loop over all FatJets in the Event
      for (int i = 0; i < FatJet_size; i++){

         // pT cut on FatJets ( pT > 2*m(t)/R )
         if (FatJet_PT[i] < 350.) continue;

         // mass cut on FatJets
         if (FatJet_Mass[i] < 145. || FatJet_Mass[i] > 205.) continue;

         // signal histos
         if (fCurrent == 0){
            // tau2 histo
            hist_Signal_FatJet_Tau2->Fill(FatJet_Tau[1][i]);
            hist_Signal_FatJet_Tau2_Normalized->Fill(FatJet_Tau[1][i]);
            // tau3 histo
            hist_Signal_FatJet_Tau3->Fill(FatJet_Tau[2][i]);
            hist_Signal_FatJet_Tau3_Normalized->Fill(FatJet_Tau[2][i]);
            // tau3/tau2 histo
            hist_Signal_FatJet_RatioTau3Tau2->Fill((FatJet_Tau[2][i])/(FatJet_Tau[1][i]));
            hist_Signal_FatJet_RatioTau3Tau2_Normalized->Fill((FatJet_Tau[2][i])/(FatJet_Tau[1][i]));
         }

         // background histos
         if (fCurrent == 1){
            // tau2 histo
            hist_Background_FatJet_Tau2->Fill(FatJet_Tau[1][i]);
            hist_Background_FatJet_Tau2_Normalized->Fill(FatJet_Tau[1][i]);
            // tau3 histo
            hist_Background_FatJet_Tau3->Fill(FatJet_Tau[2][i]);
            hist_Background_FatJet_Tau3_Normalized->Fill(FatJet_Tau[2][i]);
            // tau3/tau2 histo
            hist_Background_FatJet_RatioTau3Tau2->Fill((FatJet_Tau[2][i])/(FatJet_Tau[1][i]));
            hist_Background_FatJet_RatioTau3Tau2_Normalized->Fill((FatJet_Tau[2][i])/(FatJet_Tau[1][i]));
         }
      }
      */

   }

   // drawing of histograms

   TCanvas *canvas_FatJet_Tau2 = new TCanvas("canvas_FatJet_Tau2","canvas_FatJet_Tau2",1000,800);
   hist_Background_FatJet_Tau2->SetLineColor(kBlue);
   hist_Background_FatJet_Tau2->Draw();
   hist_Signal_FatJet_Tau2->SetLineColor(kRed);
   hist_Signal_FatJet_Tau2->Draw("SAME");
   canvas_FatJet_Tau2->Print("./FatJet_Tau2.pdf");

   TCanvas *canvas_FatJet_Tau3 = new TCanvas("canvas_FatJet_Tau3","canvas_FatJet_Tau3",1000,800);
   hist_Background_FatJet_Tau3->SetLineColor(kBlue);
   hist_Background_FatJet_Tau3->Draw();
   hist_Signal_FatJet_Tau3->SetLineColor(kRed);
   hist_Signal_FatJet_Tau3->Draw("SAME");
   canvas_FatJet_Tau3->Print("./FatJet_Tau3.pdf");

   TCanvas *canvas_FatJet_RatioTau3Tau2 = new TCanvas("canvas_FatJet_RatioTau3Tau2","canvas_FatJet_RatioTau3Tau2",1000,800);
   hist_Background_FatJet_RatioTau3Tau2->SetLineColor(kBlue);
   hist_Background_FatJet_RatioTau3Tau2->Draw();
   hist_Signal_FatJet_RatioTau3Tau2->SetLineColor(kRed);
   hist_Signal_FatJet_RatioTau3Tau2->Draw("SAME");
   canvas_FatJet_RatioTau3Tau2->Print("./FatJet_RatioTau3Tau2.pdf");   

   TCanvas *canvas_FatJet_Tau2_Normalized = new TCanvas("canvas_FatJet_Tau2_Normalized","canvas_FatJet_Tau2_Normalized",1000,800);
   hist_Background_FatJet_Tau2_Normalized->SetLineColor(kBlue);
   hist_Background_FatJet_Tau2_Normalized->Scale(1./hist_Background_FatJet_Tau2_Normalized->Integral());
   hist_Background_FatJet_Tau2_Normalized->Draw("HIST");
   hist_Signal_FatJet_Tau2_Normalized->SetLineColor(kRed);
   hist_Signal_FatJet_Tau2_Normalized->Scale(1./hist_Signal_FatJet_Tau2->Integral());
   hist_Signal_FatJet_Tau2_Normalized->Draw("SAME, HIST");
   canvas_FatJet_Tau2_Normalized->Print("./FatJet_Tau2_Normalized.pdf");

   TCanvas *canvas_FatJet_Tau3_Normalized = new TCanvas("canvas_FatJet_Tau3_Normalized","canvas_FatJet_Tau3_Normalized",1000,800);
   hist_Background_FatJet_Tau3_Normalized->SetLineColor(kBlue);
   hist_Background_FatJet_Tau3_Normalized->Scale(1./hist_Background_FatJet_Tau3_Normalized->Integral());
   hist_Background_FatJet_Tau3_Normalized->Draw("HIST");
   hist_Signal_FatJet_Tau3_Normalized->SetLineColor(kRed);
   hist_Signal_FatJet_Tau3_Normalized->Scale(1./hist_Signal_FatJet_Tau3_Normalized->Integral());
   hist_Signal_FatJet_Tau3_Normalized->Draw("SAME, HIST");
   canvas_FatJet_Tau3_Normalized->Print("./FatJet_Tau3_Normalized.pdf");

   TCanvas *canvas_FatJet_RatioTau3Tau2_Normalized = new TCanvas("canvas_FatJet_RatioTau3Tau2_Normalized","canvas_FatJet_RatioTau3Tau2_Normalized",1000,800);
   hist_Background_FatJet_RatioTau3Tau2_Normalized->SetLineColor(kBlue);
   hist_Background_FatJet_RatioTau3Tau2_Normalized->Scale(1./hist_Background_FatJet_RatioTau3Tau2_Normalized->Integral());
   hist_Background_FatJet_RatioTau3Tau2_Normalized->Draw("HIST");
   hist_Signal_FatJet_RatioTau3Tau2_Normalized->SetLineColor(kRed);
   hist_Signal_FatJet_RatioTau3Tau2_Normalized->Scale(1./hist_Signal_FatJet_RatioTau3Tau2_Normalized->Integral());
   hist_Signal_FatJet_RatioTau3Tau2_Normalized->Draw("SAME, HIST");
   canvas_FatJet_RatioTau3Tau2_Normalized->Print("./FatJet_RatioTau3Tau2_Normalized.pdf");   

}

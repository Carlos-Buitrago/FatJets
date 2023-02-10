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

   TH1F *hist_Signal_FatJet_Tau2 = new TH1F("Signal_FatJet_Tau2", "FatJet #tau_{2}; #tau_{2}; Events", 50, 0, 1);
   TH1F *hist_Background_FatJet_Tau2 = new TH1F("Background_FatJet_Tau2", "FatJet #tau_{2}; #tau_{2}; Events", 50, 0, 1);
   TH1F *hist_Signal_FatJet_Tau3 = new TH1F("Signal_FatJet_Tau3", "FatJet #tau_{3}; #tau_{3}; Events", 50, 0, 1);
   TH1F *hist_Background_FatJet_Tau3 = new TH1F("Background_FatJet_Tau3", "FatJet #tau_{3}; #tau_{3}; Events", 50, 0, 1);
   TH1F *hist_Signal_FatJet_RatioTau3Tau2 = new TH1F("Signal_FatJet_RatioTau3Tau2", "FatJet #tau_{3}/#tau_{2}; #tau_{3}/#tau_{2}; Events", 50, 0, 1);
   TH1F *hist_Background_FatJet_RatioTau3Tau2 = new TH1F("Background_FatJet_RatioTau3Tau2", "FatJet #tau_{3}/#tau_{2}; #tau_{3}/#tau_{2}; Events", 50, 0, 1);

   TH1F *hist_Signal_FatJet_Tau2_Normalized = new TH1F("Signal_FatJet_Tau2_Normalized", "FatJet #tau_{2}; #tau_{2}; Events", 50, 0, 1);
   TH1F *hist_Background_FatJet_Tau2_Normalized = new TH1F("Background_FatJet_Tau2_Normalized", "FatJet #tau_{2}; #tau_{2}; Events", 50, 0, 1);
   TH1F *hist_Signal_FatJet_Tau3_Normalized = new TH1F("Signal_FatJet_Tau3_Normalized", "FatJet #tau_{3}; #tau_{3}; Events", 50, 0, 1);
   TH1F *hist_Background_FatJet_Tau3_Normalized = new TH1F("Background_FatJet_Tau3_Normalized", "FatJet #tau_{3}; #tau_{3}; Events", 50, 0, 1);
   TH1F *hist_Signal_FatJet_RatioTau3Tau2_Normalized = new TH1F("Signal_FatJet_RatioTau3Tau2_Normalized", "FatJet #tau_{3}/#tau_{2}; #tau_{3}/#tau_{2}; Events", 50, 0, 1);
   TH1F *hist_Background_FatJet_RatioTau3Tau2_Normalized = new TH1F("Background_FatJet_RatioTau3Tau2_Normalized", "FatJet #tau_{3}/#tau_{2}; #tau_{3}/#tau_{2}; Events", 50, 0, 1);

   TH1F *hist_Signal_FatJet_RatioTau2Tau1_Normalized = new TH1F("Signal_FatJet_RatioTau2Tau1_Normalized", "FatJet #tau_{2}/#tau_{1}; #tau_{2}/#tau_{1}; Events", 50, 0, 1);
   TH1F *hist_Background_FatJet_RatioTau2Tau1_Normalized = new TH1F("Background_FatJet_RatioTau2Tau1_Normalized", "FatJet #tau_{2}/#tau_{1}; #tau_{2}/#tau_{1}; Events", 50, 0, 1);
   TH1F *hist_Signal_FatJet_RatioTau4Tau3_Normalized = new TH1F("Signal_FatJet_RatioTau4Tau3_Normalized", "FatJet #tau_{4}/#tau_{3}; #tau_{4}/#tau_{3}; Events", 50, 0, 1);
   TH1F *hist_Background_FatJet_RatioTau4Tau3_Normalized = new TH1F("Background_FatJet_RatioTau4Tau3_Normalized", "FatJet #tau_{4}/#tau_{3}; #tau_{4}/#tau_{3}; Events", 50, 0, 1);


   TH1F *hist_Signal_FatJet_Mass = new TH1F("Signal_FatJet_Mass", "FatJet Mass; Mass [GeV]; Events", 100, 0, 500);
   TH1F *hist_Background_FatJet_Mass = new TH1F("Background_FatJet_Mass", "FatJet Mass; Mass [GeV]; Events", 100, 0, 500);

   TH1F *hist_Signal_FatJet_Mass_Normalized = new TH1F("Signal_FatJet_Mass_Normalized", "FatJet Mass; Mass [GeV]; Events", 100, 0, 500);
   TH1F *hist_Background_FatJet_Mass_Normalized = new TH1F("Background_FatJet_Mass_Normalized", "FatJet Mass; Mass [GeV]; Events", 100, 0, 500);


   TH1F *hist_Background_cutflow = new TH1F("Background Cutflow","Cutflow; Cut; Events",10,0,10);
   TH1F *hist_Signal_cutflow = new TH1F("Signal Cutflow","Cutflow; Cut; Events",10,0,10);

   int cut1 = 0;
   int cut2 = 0;
   int cut3 = 0;
   int cut4 = 0;
   int cut5 = 0;

   int cut1s = 0;
   int cut2s = 0;
   int cut3s = 0;
   int cut4s = 0;
   int cut5s = 0;

   if (fChain == 0) return;

   Long64_t nentries = fChain->GetEntries();

   Long64_t nbytes = 0, nb = 0;
   for (Long64_t jentry=0; jentry<nentries;jentry++) {

      Long64_t ientry = LoadTree(jentry);
      if (ientry < 0) break;

      nb = fChain->GetEntry(jentry);   nbytes += nb;

      if (fCurrent == 1){
         cut1++;
         hist_Background_cutflow->Fill(1);
      }

      if (fCurrent == 0){
         cut1s++;
         hist_Signal_cutflow->Fill(1);
      }

      // evt contains at least one FatJet
      if (FatJet_size == 0) continue;
      
      if (fCurrent == 1){
         cut2++;
         hist_Background_cutflow->Fill(2);
      }

      if (fCurrent == 0){
         cut2s++;
         hist_Signal_cutflow->Fill(2);
      }
            
      // cut on leading FatJet
      if (FatJet_PT[0] < 350.) continue;

      if (fCurrent == 1){
         cut3++;
         hist_Background_cutflow->Fill(3);
      }

      if (fCurrent == 0){
         cut3s++;
         hist_Signal_cutflow->Fill(3);
      }

      // mass cut on leading FatJet
      /* //if (FatJet_Mass[0] < 145. || FatJet_Mass[0] > 205.) continue; */

      /* if (fCurrent == 1){ */
      /*    cut4++; */
      /*    hist_Background_cutflow->Fill(4); */
      /* } */

      /* if (fCurrent == 0){ */
      /*    cut4s++; */
      /*    hist_Signal_cutflow->Fill(4); */
      /* } */
   
      // eta cut on leading FatJet
      if (TMath::Abs(FatJet_Eta[0]) > 1.3) continue;

      if (fCurrent == 1){
         cut4++;
         hist_Background_cutflow->Fill(4);
      }

      if (fCurrent == 0){
         cut4s++;
         hist_Signal_cutflow->Fill(4);
      }
      
      // nsubjettiness signal histos for leading FatJet
      if (fCurrent == 0){
         // tau2 histo
         hist_Signal_FatJet_Tau2->Fill(FatJet_Tau[0][1]);
         hist_Signal_FatJet_Tau2_Normalized->Fill(FatJet_Tau[0][1]);
         // tau3 histo
         hist_Signal_FatJet_Tau3->Fill(FatJet_Tau[0][2]);
         hist_Signal_FatJet_Tau3_Normalized->Fill(FatJet_Tau[0][2]);
         // tau3/tau2 histo
         hist_Signal_FatJet_RatioTau3Tau2->Fill((FatJet_Tau[0][2])/(FatJet_Tau[0][1]));
         hist_Signal_FatJet_RatioTau3Tau2_Normalized->Fill((FatJet_Tau[0][2])/(FatJet_Tau[0][1]));
         // tau2/tau1 histo
         hist_Signal_FatJet_RatioTau2Tau1_Normalized->Fill((FatJet_Tau[0][1])/(FatJet_Tau[0][0]));
         // tau4/tau3 histo
         hist_Signal_FatJet_RatioTau4Tau3_Normalized->Fill((FatJet_Tau[0][3])/(FatJet_Tau[0][2]));
      }

      // nsubjettiness background histos for leading FatJet
      if (fCurrent == 1){
         // tau2 histo
         hist_Background_FatJet_Tau2->Fill(FatJet_Tau[0][1]);
         hist_Background_FatJet_Tau2_Normalized->Fill(FatJet_Tau[0][1]);
         // tau3 histo
         hist_Background_FatJet_Tau3->Fill(FatJet_Tau[0][2]);
         hist_Background_FatJet_Tau3_Normalized->Fill(FatJet_Tau[0][2]);
         // tau3/tau2 histo
         hist_Background_FatJet_RatioTau3Tau2->Fill((FatJet_Tau[0][2])/(FatJet_Tau[0][1]));
         hist_Background_FatJet_RatioTau3Tau2_Normalized->Fill((FatJet_Tau[0][2])/(FatJet_Tau[0][1]));
         // tau2/tau1 histo
         hist_Background_FatJet_RatioTau2Tau1_Normalized->Fill((FatJet_Tau[0][1])/(FatJet_Tau[0][0]));
         // tau4/tau3 histo
         hist_Background_FatJet_RatioTau4Tau3_Normalized->Fill((FatJet_Tau[0][3])/(FatJet_Tau[0][2]));
      }

      
      // mass histos for leading FatJet
      if (fCurrent == 0){
        hist_Signal_FatJet_Mass->Fill(FatJet_Mass[0]);
        hist_Signal_FatJet_Mass_Normalized->Fill(FatJet_Mass[0]);
      }
      if (fCurrent == 1){
        hist_Background_FatJet_Mass->Fill(FatJet_Mass[0]);
        hist_Background_FatJet_Mass_Normalized->Fill(FatJet_Mass[0]);
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
   hist_Signal_FatJet_Tau2->SetLineColor(kRed);
   hist_Signal_FatJet_Tau2->Draw();
   hist_Background_FatJet_Tau2->SetLineColor(kBlue);
   hist_Background_FatJet_Tau2->Draw("SAME");
   canvas_FatJet_Tau2->Print("./FatJet_Tau2.pdf");

   TCanvas *canvas_FatJet_Tau3 = new TCanvas("canvas_FatJet_Tau3","canvas_FatJet_Tau3",1000,800);
   hist_Signal_FatJet_Tau3->SetLineColor(kRed);
   hist_Signal_FatJet_Tau3->Draw();
   hist_Background_FatJet_Tau3->SetLineColor(kBlue);
   hist_Background_FatJet_Tau3->Draw("SAME");
   canvas_FatJet_Tau3->Print("./FatJet_Tau3.pdf");

   TCanvas *canvas_FatJet_RatioTau3Tau2 = new TCanvas("canvas_FatJet_RatioTau3Tau2","canvas_FatJet_RatioTau3Tau2",1000,800);
   hist_Background_FatJet_RatioTau3Tau2->SetLineColor(kBlue);
   hist_Background_FatJet_RatioTau3Tau2->Draw();
   hist_Signal_FatJet_RatioTau3Tau2->SetLineColor(kRed);
   hist_Signal_FatJet_RatioTau3Tau2->Draw("SAME");
   canvas_FatJet_RatioTau3Tau2->Print("./FatJet_RatioTau3Tau2.pdf");   

   TCanvas *canvas_FatJet_Tau2_Normalized = new TCanvas("canvas_FatJet_Tau2_Normalized","canvas_FatJet_Tau2_Normalized",1000,800);
   hist_Signal_FatJet_Tau2_Normalized->SetLineColor(kRed);
   hist_Signal_FatJet_Tau2_Normalized->Scale(1./hist_Signal_FatJet_Tau2->Integral());
   hist_Signal_FatJet_Tau2_Normalized->Draw("HIST");
   hist_Background_FatJet_Tau2_Normalized->SetLineColor(kBlue);
   hist_Background_FatJet_Tau2_Normalized->Scale(1./hist_Background_FatJet_Tau2_Normalized->Integral());
   hist_Background_FatJet_Tau2_Normalized->Draw("SAME, HIST");
   canvas_FatJet_Tau2_Normalized->Print("./FatJet_Tau2_Normalized.pdf");

   TCanvas *canvas_FatJet_Tau3_Normalized = new TCanvas("canvas_FatJet_Tau3_Normalized","canvas_FatJet_Tau3_Normalized",1000,800);
   hist_Signal_FatJet_Tau3_Normalized->SetLineColor(kRed);
   hist_Signal_FatJet_Tau3_Normalized->Scale(1./hist_Signal_FatJet_Tau3_Normalized->Integral());
   hist_Signal_FatJet_Tau3_Normalized->Draw("HIST");
   hist_Background_FatJet_Tau3_Normalized->SetLineColor(kBlue);
   hist_Background_FatJet_Tau3_Normalized->Scale(1./hist_Background_FatJet_Tau3_Normalized->Integral());
   hist_Background_FatJet_Tau3_Normalized->Draw("SAME, HIST");
   canvas_FatJet_Tau3_Normalized->Print("./FatJet_Tau3_Normalized.pdf");

   TCanvas *canvas_FatJet_RatioTau3Tau2_Normalized = new TCanvas("canvas_FatJet_RatioTau3Tau2_Normalized","canvas_FatJet_RatioTau3Tau2_Normalized",1000,800);
   hist_Background_FatJet_RatioTau3Tau2_Normalized->SetLineColor(kBlue);
   hist_Background_FatJet_RatioTau3Tau2_Normalized->Scale(1./hist_Background_FatJet_RatioTau3Tau2_Normalized->Integral());
   hist_Background_FatJet_RatioTau3Tau2_Normalized->Draw("HIST");
   hist_Signal_FatJet_RatioTau3Tau2_Normalized->SetLineColor(kRed);
   hist_Signal_FatJet_RatioTau3Tau2_Normalized->Scale(1./hist_Signal_FatJet_RatioTau3Tau2_Normalized->Integral());
   hist_Signal_FatJet_RatioTau3Tau2_Normalized->Draw("SAME, HIST");
   canvas_FatJet_RatioTau3Tau2_Normalized->Print("./FatJet_RatioTau3Tau2_Normalized.pdf");  
   
   TCanvas *canvas_FatJet_RatioTau2Tau1_Normalized = new TCanvas("canvas_FatJet_RatioTau2Tau1_Normalized","canvas_FatJet_RatioTau2Tau1_Normalized",1000,800);
   hist_Signal_FatJet_RatioTau2Tau1_Normalized->SetLineColor(kRed);
   hist_Signal_FatJet_RatioTau2Tau1_Normalized->Scale(1./hist_Signal_FatJet_RatioTau2Tau1_Normalized->Integral());
   hist_Signal_FatJet_RatioTau2Tau1_Normalized->Draw("HIST");
   hist_Background_FatJet_RatioTau2Tau1_Normalized->SetLineColor(kBlue);
   hist_Background_FatJet_RatioTau2Tau1_Normalized->Scale(1./hist_Background_FatJet_RatioTau2Tau1_Normalized->Integral());
   hist_Background_FatJet_RatioTau2Tau1_Normalized->Draw("SAME, HIST");
   canvas_FatJet_RatioTau2Tau1_Normalized->Print("./FatJet_RatioTau2Tau1_Normalized.pdf");  

   TCanvas *canvas_FatJet_RatioTau4Tau3_Normalized = new TCanvas("canvas_FatJet_RatioTau4Tau3_Normalized","canvas_FatJet_RatioTau4Tau3_Normalized",1000,800);
   hist_Background_FatJet_RatioTau4Tau3_Normalized->SetLineColor(kBlue);
   hist_Background_FatJet_RatioTau4Tau3_Normalized->Scale(1./hist_Background_FatJet_RatioTau4Tau3_Normalized->Integral());
   hist_Background_FatJet_RatioTau4Tau3_Normalized->Draw("HIST");
   hist_Signal_FatJet_RatioTau4Tau3_Normalized->SetLineColor(kRed);
   hist_Signal_FatJet_RatioTau4Tau3_Normalized->Scale(1./hist_Signal_FatJet_RatioTau4Tau3_Normalized->Integral());
   hist_Signal_FatJet_RatioTau4Tau3_Normalized->Draw("SAME, HIST");
   canvas_FatJet_RatioTau4Tau3_Normalized->Print("./FatJet_RatioTau4Tau3_Normalized.pdf");  

   TCanvas *canvas_FatJet_Mass = new TCanvas("canvas_FatJet_Mass","canvas_FatJet_Mass",1000,800);
   hist_Signal_FatJet_Mass->SetLineColor(kRed);
   hist_Signal_FatJet_Mass->Draw();
   hist_Background_FatJet_Mass->SetLineColor(kBlue);
   hist_Background_FatJet_Mass->Draw("SAME");
   canvas_FatJet_Mass->Print("./FatJet_Mass.pdf");    

   TCanvas *canvas_FatJet_Mass_Normalized = new TCanvas("canvas_FatJet_Mass_Normalized","canvas_FatJet_Mass_Normalized",1000,800);
   hist_Signal_FatJet_Mass_Normalized->SetLineColor(kRed);
   hist_Signal_FatJet_Mass_Normalized->Scale(1./hist_Signal_FatJet_Mass_Normalized->Integral());
   hist_Signal_FatJet_Mass_Normalized->Draw("HIST");
   hist_Background_FatJet_Mass_Normalized->SetLineColor(kBlue);
   hist_Background_FatJet_Mass_Normalized->Scale(1./hist_Background_FatJet_Mass_Normalized->Integral());
   hist_Background_FatJet_Mass_Normalized->Draw("SAME, HIST");
   canvas_FatJet_Mass_Normalized->Print("./FatJet_Mass_Normalized.pdf");   

   TCanvas *canvas_Background_cutflow = new TCanvas("Canvas__Background_Cutflow","",1000,800);
	hist_Background_cutflow->Draw("");
	canvas_Background_cutflow->Print("./Background_Cutflow.pdf");

   TCanvas *canvas_Signal_cutflow = new TCanvas("Canvas__Signal_Cutflow","",1000,800);
	hist_Signal_cutflow->Draw("");
   hist_Signal_cutflow->SetLineColor(kRed);
	canvas_Signal_cutflow->Print("./Signal_Cutflow.pdf");

}

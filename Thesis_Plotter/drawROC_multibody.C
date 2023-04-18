#include <TROOT.h>
#include <TH1.h>
#include <TCanvas.h>
#include <TFile.h>

void drawROC_multibody(){
  // open the rootfiles
  TFile *f_top_mass_tau4321 = new TFile("../TMVAResults/dataset_mass_4321Subjettiness/TMVA.root");
  TFile *f_top_mass_tau321 = new TFile("../TMVAResults/dataset_mass_321Subjettiness/TMVA.root");
  TFile *f_top_mass_tau21 = new TFile("../TMVAResults/dataset_mass_21Subjettiness/TMVA.root");
  TFile *f_top_mass_tau1 = new TFile("../TMVAResults/dataset_mass_1Subjettiness/TMVA.root");

  TFile *f_W_mass_tau4321 = new TFile("../TMVAResults/dataset_WW_mass_4321Subjettiness/TMVA.root");
  TFile *f_W_mass_tau321 = new TFile("../TMVAResults/dataset_WW_mass_321Subjettiness/TMVA.root");
  TFile *f_W_mass_tau21 = new TFile("../TMVAResults/dataset_WW_mass_21Subjettiness/TMVA.root");
  TFile *f_W_mass_tau1 = new TFile("../TMVAResults/dataset_WW_mass_1Subjettiness/TMVA.root");

  // histos top signal
  TH1F *h_top_mass_tau4321_BDT = (TH1F*)f_top_mass_tau4321->Get("dataset/Method_BDT/BDT/MVA_BDT_rejBvsS");
  TH1F *h_top_mass_tau321_BDT = (TH1F*)f_top_mass_tau321->Get("dataset/Method_BDT/BDT/MVA_BDT_rejBvsS");
  TH1F *h_top_mass_tau21_BDT = (TH1F*)f_top_mass_tau21->Get("dataset/Method_BDT/BDT/MVA_BDT_rejBvsS");
  TH1F *h_top_mass_tau1_BDT = (TH1F*)f_top_mass_tau1->Get("dataset/Method_BDT/BDT/MVA_BDT_rejBvsS");

  // histos W signal
  TH1F *h_W_mass_tau4321_BDT = (TH1F*)f_W_mass_tau4321->Get("dataset/Method_BDT/BDT/MVA_BDT_rejBvsS");
  TH1F *h_W_mass_tau321_BDT = (TH1F*)f_W_mass_tau321->Get("dataset/Method_BDT/BDT/MVA_BDT_rejBvsS");
  TH1F *h_W_mass_tau21_BDT = (TH1F*)f_W_mass_tau21->Get("dataset/Method_BDT/BDT/MVA_BDT_rejBvsS");
  TH1F *h_W_mass_tau1_BDT = (TH1F*)f_W_mass_tau1->Get("dataset/Method_BDT/BDT/MVA_BDT_rejBvsS");

  // styles top signal
  h_top_mass_tau4321_BDT->SetLineColor(kRed);
  h_top_mass_tau321_BDT->SetLineColor(kBlue);
  h_top_mass_tau21_BDT->SetLineColor(kGreen);
  h_top_mass_tau1_BDT->SetLineColor(kMagenta);

  h_top_mass_tau4321_BDT->SetLineWidth(4);
  h_top_mass_tau321_BDT->SetLineWidth(4);
  h_top_mass_tau21_BDT->SetLineWidth(4);
  h_top_mass_tau1_BDT->SetLineWidth(4);

  h_top_mass_tau4321_BDT->SetStats(false);
  h_top_mass_tau321_BDT->SetStats(false);
  h_top_mass_tau21_BDT->SetStats(false);
  h_top_mass_tau1_BDT->SetStats(false);

  // titles top signal
  h_top_mass_tau4321_BDT->SetTitle("Top tagging (BDT)");
  h_top_mass_tau321_BDT->SetTitle("Top tagging (BDT)");
  h_top_mass_tau21_BDT->SetTitle("Top tagging (BDT)");
  h_top_mass_tau1_BDT->SetTitle("Top tagging (BDT)");

  h_top_mass_tau4321_BDT->GetXaxis()->SetTitle("Top signal efficiency");
  h_top_mass_tau321_BDT->GetXaxis()->SetTitle("Top signal efficiency");
  h_top_mass_tau21_BDT->GetXaxis()->SetTitle("Top signal efficiency");
  h_top_mass_tau1_BDT->GetXaxis()->SetTitle("Top signal efficiency");
  
  h_top_mass_tau4321_BDT->GetYaxis()->SetTitle("Background rejection");
  h_top_mass_tau321_BDT->GetYaxis()->SetTitle("Background rejection");
  h_top_mass_tau21_BDT->GetYaxis()->SetTitle("Background rejection");
  h_top_mass_tau1_BDT->GetYaxis()->SetTitle("Background rejection");

  // draw canvas and legend top signal
  TCanvas *canvas_top = new TCanvas("canvas_top_multibody", "Multibody_ROC_Curves_top", 800, 600);
  canvas_top->SetGrid();

  h_top_mass_tau4321_BDT->Draw("C");
  h_top_mass_tau321_BDT->Draw("C SAME");
  h_top_mass_tau21_BDT->Draw("C SAME");
  h_top_mass_tau1_BDT->Draw("C SAME");

  TLegend *leg_top_multibody = new TLegend(0.15, 0.15, 0.5, 0.5);
  leg_top_multibody->SetBorderSize(1);
  leg_top_multibody->AddEntry(h_top_mass_tau4321_BDT, "#tau_{4} + #tau_{3} + #tau_{2} + #tau_{1} ");
  leg_top_multibody->AddEntry(h_top_mass_tau321_BDT, "#tau_{3} + #tau_{2} + #tau_{1} ");
  leg_top_multibody->AddEntry(h_top_mass_tau21_BDT, "#tau_{2} + #tau_{1} ");
  leg_top_multibody->AddEntry(h_top_mass_tau1_BDT, "#tau_{1} ");
  leg_top_multibody->Draw();

  canvas_top->Print("top_multibody.pdf");

  // styles W signal
  h_W_mass_tau4321_BDT->SetLineColor(kRed);
  h_W_mass_tau321_BDT->SetLineColor(kBlue);
  h_W_mass_tau21_BDT->SetLineColor(kGreen);
  h_W_mass_tau1_BDT->SetLineColor(kMagenta);

  h_W_mass_tau4321_BDT->SetLineWidth(4);
  h_W_mass_tau321_BDT->SetLineWidth(4);
  h_W_mass_tau21_BDT->SetLineWidth(4);
  h_W_mass_tau1_BDT->SetLineWidth(4);

  h_W_mass_tau4321_BDT->SetStats(false);
  h_W_mass_tau321_BDT->SetStats(false);
  h_W_mass_tau21_BDT->SetStats(false);
  h_W_mass_tau1_BDT->SetStats(false);

  // titles W signal
  h_W_mass_tau4321_BDT->SetTitle("W tagging (BDT)");
  h_W_mass_tau321_BDT->SetTitle("W tagging (BDT)");
  h_W_mass_tau21_BDT->SetTitle("W tagging (BDT)");
  h_W_mass_tau1_BDT->SetTitle("W tagging (BDT)");

  h_W_mass_tau4321_BDT->GetXaxis()->SetTitle("W signal efficiency");
  h_W_mass_tau321_BDT->GetXaxis()->SetTitle("W signal efficiency");
  h_W_mass_tau21_BDT->GetXaxis()->SetTitle("W signal efficiency");
  h_W_mass_tau1_BDT->GetXaxis()->SetTitle("W signal efficiency");
  
  h_W_mass_tau4321_BDT->GetYaxis()->SetTitle("Background rejection");
  h_W_mass_tau321_BDT->GetYaxis()->SetTitle("Background rejection");
  h_W_mass_tau21_BDT->GetYaxis()->SetTitle("Background rejection");
  h_W_mass_tau1_BDT->GetYaxis()->SetTitle("Background rejection");

  // draw canvas and legend W signal
  TCanvas *canvas_W = new TCanvas("canvas_W_multibody", "Multibody_ROC_Curves_W", 800, 600);
  canvas_W->SetGrid();

  h_W_mass_tau4321_BDT->Draw("C");
  h_W_mass_tau321_BDT->Draw("C SAME");
  h_W_mass_tau21_BDT->Draw("C SAME");
  h_W_mass_tau1_BDT->Draw("C SAME");

  TLegend *leg_W_multibody = new TLegend(0.15, 0.15, 0.5, 0.5);
  leg_W_multibody->SetBorderSize(1);
  leg_W_multibody->AddEntry(h_W_mass_tau4321_BDT, "#tau_{4} + #tau_{3} + #tau_{2} + #tau_{1} ");
  leg_W_multibody->AddEntry(h_W_mass_tau321_BDT, "#tau_{3} + #tau_{2} + #tau_{1} ");
  leg_W_multibody->AddEntry(h_W_mass_tau21_BDT, "#tau_{2} + #tau_{1} ");
  leg_W_multibody->AddEntry(h_W_mass_tau1_BDT, "#tau_{1} ");
  leg_W_multibody->Draw();

  canvas_W->Print("W_multibody.pdf");

}


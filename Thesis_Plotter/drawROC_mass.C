#include <TROOT.h>
#include <TH1.h>
#include <TCanvas.h>
#include <TFile.h>

void drawROC_mass(){
  // open the rootfiles
  TFile *f_top_mass_tau4321 = new TFile("../TMVAResults/dataset_mass_4321Subjettiness/TMVA.root");
  TFile *f_top_nomass_tau4321 = new TFile("../TMVAResults/dataset_nomass_4321Subjettiness/TMVA.root");
  TFile *f_W_mass_tau4321 = new TFile("../TMVAResults/dataset_WW_mass_4321Subjettiness/TMVA.root");
  TFile *f_W_nomass_tau4321 = new TFile("../TMVAResults/dataset_WW_nomass_4321Subjettiness/TMVA.root");

  // histos mass top signal
  TH1F *h_top_mass_tau4321_BDT = (TH1F*)f_top_mass_tau4321->Get("dataset/Method_BDT/BDT/MVA_BDT_rejBvsS");
  TH1F *h_top_mass_tau4321_DNN = (TH1F*)f_top_mass_tau4321->Get("dataset/Method_DL/DNN_CPU/MVA_DNN_CPU_rejBvsS");

  // histos nomass top signal
  TH1F *h_top_nomass_tau4321_BDT = (TH1F*)f_top_nomass_tau4321->Get("dataset/Method_BDT/BDT/MVA_BDT_rejBvsS");
  TH1F *h_top_nomass_tau4321_DNN = (TH1F*)f_top_nomass_tau4321->Get("dataset/Method_DL/DNN_CPU/MVA_DNN_CPU_rejBvsS");

  // histos mass W signal
  TH1F *h_W_mass_tau4321_BDT = (TH1F*)f_W_mass_tau4321->Get("dataset/Method_BDT/BDT/MVA_BDT_rejBvsS");
  TH1F *h_W_mass_tau4321_DNN = (TH1F*)f_W_mass_tau4321->Get("dataset/Method_DL/DNN_CPU/MVA_DNN_CPU_rejBvsS");

  // histos nomass W signal
  TH1F *h_W_nomass_tau4321_BDT = (TH1F*)f_W_nomass_tau4321->Get("dataset/Method_BDT/BDT/MVA_BDT_rejBvsS");
  TH1F *h_W_nomass_tau4321_DNN = (TH1F*)f_W_nomass_tau4321->Get("dataset/Method_DL/DNN_CPU/MVA_DNN_CPU_rejBvsS");

  // styles top signal
  h_top_mass_tau4321_BDT->SetLineColor(kRed);
  h_top_mass_tau4321_DNN->SetLineColor(kRed);
  h_top_nomass_tau4321_BDT->SetLineColor(kBlue);
  h_top_nomass_tau4321_DNN->SetLineColor(kBlue);

  h_top_mass_tau4321_DNN->SetLineWidth(4);
  h_top_mass_tau4321_BDT->SetLineWidth(4);
  h_top_nomass_tau4321_DNN->SetLineWidth(4);
  h_top_nomass_tau4321_BDT->SetLineWidth(4);

  h_top_mass_tau4321_DNN->SetStats(false);
  h_top_mass_tau4321_BDT->SetStats(false);
  h_top_nomass_tau4321_DNN->SetStats(false);
  h_top_nomass_tau4321_BDT->SetStats(false);

  h_top_mass_tau4321_DNN->SetLineStyle(2);
  h_top_nomass_tau4321_DNN->SetLineStyle(2);

  // titles top signal
  h_top_mass_tau4321_BDT->SetTitle("Top tagging");
  h_top_mass_tau4321_DNN->SetTitle("Top tagging");
  h_top_nomass_tau4321_BDT->SetTitle("Top tagging");
  h_top_nomass_tau4321_DNN->SetTitle("Top tagging");

  h_top_mass_tau4321_BDT->GetXaxis()->SetTitle("Top signal efficiency");
  h_top_mass_tau4321_DNN->GetXaxis()->SetTitle("Top signal efficiency");
  h_top_nomass_tau4321_BDT->GetXaxis()->SetTitle("Top signal efficiency");
  h_top_nomass_tau4321_DNN->GetXaxis()->SetTitle("Top signal efficiency");
  
  h_top_mass_tau4321_BDT->GetYaxis()->SetTitle("Background rejection");
  h_top_mass_tau4321_DNN->GetYaxis()->SetTitle("Background rejection");
  h_top_nomass_tau4321_BDT->GetYaxis()->SetTitle("Background rejection");
  h_top_nomass_tau4321_DNN->GetYaxis()->SetTitle("Background rejection");

  // draw canvas and legend top signal
  TCanvas *canvas_top = new TCanvas("canvas_top_massVsnomass", "Mass_ROC_Curves_top", 800, 600);
  canvas_top->SetGrid();

  h_top_mass_tau4321_BDT->Draw("C");
  h_top_mass_tau4321_DNN->Draw("C SAME");
  h_top_nomass_tau4321_BDT->Draw("C SAME");
  h_top_nomass_tau4321_DNN->Draw("C SAME");

  TLegend *leg_top_mass = new TLegend(0.15, 0.15, 0.5, 0.5);
  leg_top_mass->SetBorderSize(1);
  leg_top_mass->AddEntry(h_top_mass_tau4321_BDT, "#tau_{N} + mass (BDT)");
  leg_top_mass->AddEntry(h_top_mass_tau4321_DNN, "#tau_{N} + mass (DNN)");
  leg_top_mass->AddEntry(h_top_nomass_tau4321_BDT, "#tau_{N} (BDT)");
  leg_top_mass->AddEntry(h_top_nomass_tau4321_DNN, "#tau_{N} (DNN)");
  leg_top_mass->Draw();

  canvas_top->Print("top_mass_nomass.pdf");

  // styles W signal
  h_W_mass_tau4321_BDT->SetLineColor(kGreen);
  h_W_mass_tau4321_DNN->SetLineColor(kGreen);
  h_W_nomass_tau4321_BDT->SetLineColor(kMagenta);
  h_W_nomass_tau4321_DNN->SetLineColor(kMagenta);

  h_W_mass_tau4321_DNN->SetLineWidth(4);
  h_W_mass_tau4321_BDT->SetLineWidth(4);
  h_W_nomass_tau4321_DNN->SetLineWidth(4);
  h_W_nomass_tau4321_BDT->SetLineWidth(4);

  h_W_mass_tau4321_DNN->SetStats(false);
  h_W_mass_tau4321_BDT->SetStats(false);
  h_W_nomass_tau4321_DNN->SetStats(false);
  h_W_nomass_tau4321_BDT->SetStats(false);

  h_W_mass_tau4321_DNN->SetLineStyle(2);
  h_W_nomass_tau4321_DNN->SetLineStyle(2);

  // titles W signal
  h_W_mass_tau4321_BDT->SetTitle("W tagging");
  h_W_mass_tau4321_DNN->SetTitle("W tagging");
  h_W_nomass_tau4321_BDT->SetTitle("W tagging");
  h_W_nomass_tau4321_DNN->SetTitle("W tagging");

  h_W_mass_tau4321_BDT->GetXaxis()->SetTitle("W signal efficiency");
  h_W_mass_tau4321_DNN->GetXaxis()->SetTitle("W signal efficiency");
  h_W_nomass_tau4321_BDT->GetXaxis()->SetTitle("W signal efficiency");
  h_W_nomass_tau4321_DNN->GetXaxis()->SetTitle("W signal efficiency");
  
  h_W_mass_tau4321_BDT->GetYaxis()->SetTitle("Background rejection");
  h_W_mass_tau4321_DNN->GetYaxis()->SetTitle("Background rejection");
  h_W_nomass_tau4321_BDT->GetYaxis()->SetTitle("Background rejection");
  h_W_nomass_tau4321_DNN->GetYaxis()->SetTitle("Background rejection");

  // draw canvas and legend W signal
  TCanvas *canvas_W = new TCanvas("canvas_W_massVsnomass", "Mass_ROC_Curves_W", 800, 600);
  canvas_W->SetGrid();

  h_W_mass_tau4321_BDT->Draw("C");
  h_W_mass_tau4321_DNN->Draw("C SAME");
  h_W_nomass_tau4321_BDT->Draw("C SAME");
  h_W_nomass_tau4321_DNN->Draw("C SAME");

  TLegend *leg_W_mass = new TLegend(0.15, 0.15, 0.5, 0.5);
  leg_W_mass->SetBorderSize(1);
  leg_W_mass->AddEntry(h_W_mass_tau4321_BDT, "#tau_{N} + mass (BDT)");
  leg_W_mass->AddEntry(h_W_mass_tau4321_DNN, "#tau_{N} + mass (DNN)");
  leg_W_mass->AddEntry(h_W_nomass_tau4321_BDT, "#tau_{N} (BDT)");
  leg_W_mass->AddEntry(h_W_nomass_tau4321_DNN, "#tau_{N} (DNN)");
  leg_W_mass->Draw();

  canvas_W->Print("W_mass_nomass.pdf");


}


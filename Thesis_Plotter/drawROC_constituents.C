#include <TROOT.h>
#include <TH1.h>
#include <TCanvas.h>
#include <TFile.h>

void drawROC_constituents(){
  // open the rootfiles
  TFile *f_top_mass_tau4321 = new TFile("../TMVAResults/dataset_mass_4321Subjettiness/TMVA.root");
  TFile *f_top_towerinfo = new TFile("../TMVAResults_Constituents/dataset_FatJets_TowerNumber_TowerKinematics/TMVA.root");

  TFile *f_W_mass_tau4321 = new TFile("../TMVAResults/dataset_WW_mass_4321Subjettiness/TMVA.root");
  TFile *f_W_towerinfo = new TFile("../TMVAResults_Constituents/dataset_WW_FatJets_TowerNumber_TowerKinematics/TMVA.root");


  // histos top signal
  TH1F *h_top_mass_tau4321_BDT = (TH1F*)f_top_mass_tau4321->Get("dataset/Method_BDT/BDT/MVA_BDT_rejBvsS");
  TH1F *h_top_mass_tau4321_DNN = (TH1F*)f_top_mass_tau4321->Get("dataset/Method_DL/DNN_CPU/MVA_DNN_CPU_rejBvsS");
  TH1F *h_top_towerinfo_BDT = (TH1F*)f_top_towerinfo->Get("dataset/Method_BDT/BDT/MVA_BDT_rejBvsS");
  TH1F *h_top_towerinfo_DNN = (TH1F*)f_top_towerinfo->Get("dataset/Method_DL/DNN_CPU/MVA_DNN_CPU_rejBvsS");

  // histos W signal
  TH1F *h_W_mass_tau4321_BDT = (TH1F*)f_W_mass_tau4321->Get("dataset/Method_BDT/BDT/MVA_BDT_rejBvsS");
  TH1F *h_W_mass_tau4321_DNN = (TH1F*)f_W_mass_tau4321->Get("dataset/Method_DL/DNN_CPU/MVA_DNN_CPU_rejBvsS");
  TH1F *h_W_towerinfo_BDT = (TH1F*)f_W_towerinfo->Get("dataset/Method_BDT/BDT/MVA_BDT_rejBvsS");
  TH1F *h_W_towerinfo_DNN = (TH1F*)f_W_towerinfo->Get("dataset/Method_DL/DNN_CPU/MVA_DNN_CPU_rejBvsS");

  // styles top signal
  h_top_mass_tau4321_BDT->SetLineColor(kRed);
  h_top_mass_tau4321_DNN->SetLineColor(kRed);
  h_top_towerinfo_BDT->SetLineColor(kBlue);
  h_top_towerinfo_DNN->SetLineColor(kBlue);

  h_top_mass_tau4321_DNN->SetLineWidth(4);
  h_top_mass_tau4321_BDT->SetLineWidth(4);
  h_top_towerinfo_DNN->SetLineWidth(4);
  h_top_towerinfo_BDT->SetLineWidth(4);

  h_top_mass_tau4321_DNN->SetStats(false);
  h_top_mass_tau4321_BDT->SetStats(false);
  h_top_towerinfo_DNN->SetStats(false);
  h_top_towerinfo_BDT->SetStats(false);

  h_top_mass_tau4321_DNN->SetLineStyle(2);
  h_top_towerinfo_DNN->SetLineStyle(2);

  // titles top signal
  h_top_mass_tau4321_BDT->SetTitle("Top tagging");
  h_top_mass_tau4321_DNN->SetTitle("Top tagging");
  h_top_towerinfo_BDT->SetTitle("Top tagging");
  h_top_towerinfo_DNN->SetTitle("Top tagging");

  h_top_mass_tau4321_BDT->GetXaxis()->SetTitle("Top signal efficiency");
  h_top_mass_tau4321_DNN->GetXaxis()->SetTitle("Top signal efficiency");
  h_top_towerinfo_BDT->GetXaxis()->SetTitle("Top signal efficiency");
  h_top_towerinfo_DNN->GetXaxis()->SetTitle("Top signal efficiency");
  
  h_top_mass_tau4321_BDT->GetYaxis()->SetTitle("Background rejection");
  h_top_mass_tau4321_DNN->GetYaxis()->SetTitle("Background rejection");
  h_top_towerinfo_BDT->GetYaxis()->SetTitle("Background rejection");
  h_top_towerinfo_DNN->GetYaxis()->SetTitle("Background rejection");

  // draw canvas and legend top signal
  TCanvas *canvas_top = new TCanvas("canvas_top_constituents", "Constituents_ROC_Curves_top", 800, 600);
  canvas_top->SetGrid();

  h_top_mass_tau4321_BDT->Draw("C");
  h_top_mass_tau4321_DNN->Draw("C SAME");
  h_top_towerinfo_BDT->Draw("C SAME");
  h_top_towerinfo_DNN->Draw("C SAME");

  TLegend *leg_top_constituents = new TLegend(0.15, 0.15, 0.5, 0.5);
  leg_top_constituents->SetBorderSize(1);
  leg_top_constituents->AddEntry(h_top_mass_tau4321_BDT, "#tau_{N} + mass (BDT)");
  leg_top_constituents->AddEntry(h_top_mass_tau4321_DNN, "#tau_{N} + mass (DNN)");
  leg_top_constituents->AddEntry(h_top_towerinfo_BDT, "Tower information (BDT)");
  leg_top_constituents->AddEntry(h_top_towerinfo_DNN, "Tower information (DNN)");
  leg_top_constituents->Draw();

  canvas_top->Print("top_constituents.pdf");

  // styles W signal
  h_W_mass_tau4321_BDT->SetLineColor(kGreen);
  h_W_mass_tau4321_DNN->SetLineColor(kGreen);
  h_W_towerinfo_BDT->SetLineColor(kMagenta);
  h_W_towerinfo_DNN->SetLineColor(kMagenta);

  h_W_mass_tau4321_DNN->SetLineWidth(4);
  h_W_mass_tau4321_BDT->SetLineWidth(4);
  h_W_towerinfo_DNN->SetLineWidth(4);
  h_W_towerinfo_BDT->SetLineWidth(4);

  h_W_mass_tau4321_DNN->SetStats(false);
  h_W_mass_tau4321_BDT->SetStats(false);
  h_W_towerinfo_DNN->SetStats(false);
  h_W_towerinfo_BDT->SetStats(false);

  h_W_mass_tau4321_DNN->SetLineStyle(2);
  h_W_towerinfo_DNN->SetLineStyle(2);

  // titles W signal
  h_W_mass_tau4321_BDT->SetTitle("W tagging");
  h_W_mass_tau4321_DNN->SetTitle("W tagging");
  h_W_towerinfo_BDT->SetTitle("W tagging");
  h_W_towerinfo_DNN->SetTitle("W tagging");

  h_W_mass_tau4321_BDT->GetXaxis()->SetTitle("W signal efficiency");
  h_W_mass_tau4321_DNN->GetXaxis()->SetTitle("W signal efficiency");
  h_W_towerinfo_BDT->GetXaxis()->SetTitle("W signal efficiency");
  h_W_towerinfo_DNN->GetXaxis()->SetTitle("W signal efficiency");
  
  h_W_mass_tau4321_BDT->GetYaxis()->SetTitle("Background rejection");
  h_W_mass_tau4321_DNN->GetYaxis()->SetTitle("Background rejection");
  h_W_towerinfo_BDT->GetYaxis()->SetTitle("Background rejection");
  h_W_towerinfo_DNN->GetYaxis()->SetTitle("Background rejection");

  // draw canvas and legend W signal
  TCanvas *canvas_W = new TCanvas("canvas_W_constituents", "Constituents_ROC_Curves_W", 800, 600);
  canvas_W->SetGrid();

  h_W_mass_tau4321_BDT->Draw("C");
  h_W_mass_tau4321_DNN->Draw("C SAME");
  h_W_towerinfo_BDT->Draw("C SAME");
  h_W_towerinfo_DNN->Draw("C SAME");

  TLegend *leg_W_constituents = new TLegend(0.15, 0.15, 0.5, 0.5);
  leg_W_constituents->SetBorderSize(1);
  leg_W_constituents->AddEntry(h_W_mass_tau4321_BDT, "#tau_{N} + mass (BDT)");
  leg_W_constituents->AddEntry(h_W_mass_tau4321_DNN, "#tau_{N} + mass (DNN)");
  leg_W_constituents->AddEntry(h_W_towerinfo_BDT, "Tower information (BDT)");
  leg_W_constituents->AddEntry(h_W_towerinfo_DNN, "Tower information (DNN)");
  leg_W_constituents->Draw();

  canvas_W->Print("W_constituents.pdf");

}


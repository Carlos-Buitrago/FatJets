#include <TROOT.h>
#include <TH1.h>
#include <TCanvas.h>
#include <TFile.h>

void drawROC_multiclassifiers(){
  // open the rootfiles
  TFile *f_top_mass_tau4321 = new TFile("../TMVAResults/dataset_mass_4321Subjettiness/TMVA.root");
  TFile *f_W_mass_tau4321 = new TFile("../TMVAResults/dataset_WW_mass_4321Subjettiness/TMVA.root");

  // histos multiple classifiers top signal
  TH1F *h_top_mass_tau4321_Likelihood = (TH1F*)f_top_mass_tau4321->Get("dataset/Method_Likelihood/LikelihoodPCA/MVA_LikelihoodPCA_rejBvsS");
  TH1F *h_top_mass_tau4321_KNN = (TH1F*)f_top_mass_tau4321->Get("dataset/Method_KNN/KNN/MVA_KNN_rejBvsS");
  TH1F *h_top_mass_tau4321_LD = (TH1F*)f_top_mass_tau4321->Get("dataset/Method_LD/LD/MVA_LD_rejBvsS");
  TH1F *h_top_mass_tau4321_FDA = (TH1F*)f_top_mass_tau4321->Get("dataset/Method_FDA/FDA_GA/MVA_FDA_GA_rejBvsS");
  TH1F *h_top_mass_tau4321_MLP = (TH1F*)f_top_mass_tau4321->Get("dataset/Method_MLP/MLPBNN/MVA_MLPBNN_rejBvsS");
  TH1F *h_top_mass_tau4321_DNN = (TH1F*)f_top_mass_tau4321->Get("dataset/Method_DL/DNN_CPU/MVA_DNN_CPU_rejBvsS");
  TH1F *h_top_mass_tau4321_BDT = (TH1F*)f_top_mass_tau4321->Get("dataset/Method_BDT/BDT/MVA_BDT_rejBvsS");
  TH1F *h_top_mass_tau4321_RuleFit = (TH1F*)f_top_mass_tau4321->Get("dataset/Method_RuleFit/RuleFit/MVA_RuleFit_rejBvsS");

  // histos multiple classifiers W signal
  TH1F *h_W_mass_tau4321_Likelihood = (TH1F*)f_W_mass_tau4321->Get("dataset/Method_Likelihood/LikelihoodPCA/MVA_LikelihoodPCA_rejBvsS");
  TH1F *h_W_mass_tau4321_KNN = (TH1F*)f_W_mass_tau4321->Get("dataset/Method_KNN/KNN/MVA_KNN_rejBvsS");
  TH1F *h_W_mass_tau4321_LD = (TH1F*)f_W_mass_tau4321->Get("dataset/Method_LD/LD/MVA_LD_rejBvsS");
  TH1F *h_W_mass_tau4321_FDA = (TH1F*)f_W_mass_tau4321->Get("dataset/Method_FDA/FDA_GA/MVA_FDA_GA_rejBvsS");
  TH1F *h_W_mass_tau4321_MLP = (TH1F*)f_W_mass_tau4321->Get("dataset/Method_MLP/MLPBNN/MVA_MLPBNN_rejBvsS");
  TH1F *h_W_mass_tau4321_DNN = (TH1F*)f_W_mass_tau4321->Get("dataset/Method_DL/DNN_CPU/MVA_DNN_CPU_rejBvsS");
  TH1F *h_W_mass_tau4321_BDT = (TH1F*)f_W_mass_tau4321->Get("dataset/Method_BDT/BDT/MVA_BDT_rejBvsS");
  TH1F *h_W_mass_tau4321_RuleFit = (TH1F*)f_W_mass_tau4321->Get("dataset/Method_RuleFit/RuleFit/MVA_RuleFit_rejBvsS");

  // styles multiple classifiers top signal
  h_top_mass_tau4321_Likelihood->SetLineColor(kRed);
  h_top_mass_tau4321_KNN->SetLineColor(kBlue);
  h_top_mass_tau4321_LD->SetLineColor(kGreen);
  h_top_mass_tau4321_FDA->SetLineColor(kMagenta+3);
  h_top_mass_tau4321_MLP->SetLineColor(kCyan);
  h_top_mass_tau4321_DNN->SetLineColor(kOrange);
  h_top_mass_tau4321_BDT->SetLineColor(kViolet);
  h_top_mass_tau4321_RuleFit->SetLineColor(kTeal+3);

  h_top_mass_tau4321_Likelihood->SetLineWidth(4);
  h_top_mass_tau4321_KNN->SetLineWidth(4);
  h_top_mass_tau4321_LD->SetLineWidth(4);
  h_top_mass_tau4321_FDA->SetLineWidth(4);
  h_top_mass_tau4321_MLP->SetLineWidth(4);
  h_top_mass_tau4321_DNN->SetLineWidth(4);
  h_top_mass_tau4321_BDT->SetLineWidth(4);
  h_top_mass_tau4321_RuleFit->SetLineWidth(4);

  h_top_mass_tau4321_Likelihood->SetStats(false);
  h_top_mass_tau4321_KNN->SetStats(false);
  h_top_mass_tau4321_LD->SetStats(false);
  h_top_mass_tau4321_FDA->SetStats(false);
  h_top_mass_tau4321_MLP->SetStats(false);
  h_top_mass_tau4321_DNN->SetStats(false);
  h_top_mass_tau4321_BDT->SetStats(false);
  h_top_mass_tau4321_RuleFit->SetStats(false);

  h_top_mass_tau4321_Likelihood->SetTitle("");
  h_top_mass_tau4321_KNN->SetTitle("");
  h_top_mass_tau4321_LD->SetTitle("");
  h_top_mass_tau4321_FDA->SetTitle("");
  h_top_mass_tau4321_MLP->SetTitle("");
  h_top_mass_tau4321_DNN->SetTitle("");
  h_top_mass_tau4321_BDT->SetTitle("");
  h_top_mass_tau4321_RuleFit->SetTitle("");

  h_top_mass_tau4321_Likelihood->GetXaxis()->SetTitle("Top signal efficiency");
  h_top_mass_tau4321_KNN->GetXaxis()->SetTitle("Top signal efficiency");
  h_top_mass_tau4321_LD->GetXaxis()->SetTitle("Top signal efficiency");
  h_top_mass_tau4321_FDA->GetXaxis()->SetTitle("Top signal efficiency");
  h_top_mass_tau4321_MLP->GetXaxis()->SetTitle("Top signal efficiency");
  h_top_mass_tau4321_DNN->GetXaxis()->SetTitle("Top signal efficiency");
  h_top_mass_tau4321_BDT->GetXaxis()->SetTitle("Top signal efficiency");
  h_top_mass_tau4321_RuleFit->GetXaxis()->SetTitle("Top signal efficiency");
  
  h_top_mass_tau4321_Likelihood->GetYaxis()->SetTitle("Background rejection");
  h_top_mass_tau4321_KNN->GetYaxis()->SetTitle("Background rejection");
  h_top_mass_tau4321_LD->GetYaxis()->SetTitle("Background rejection");
  h_top_mass_tau4321_FDA->GetYaxis()->SetTitle("Background rejection");
  h_top_mass_tau4321_MLP->GetYaxis()->SetTitle("Background rejection");
  h_top_mass_tau4321_DNN->GetYaxis()->SetTitle("Background rejection");
  h_top_mass_tau4321_BDT->GetYaxis()->SetTitle("Background rejection");
  h_top_mass_tau4321_RuleFit->GetYaxis()->SetTitle("Background rejection");

  // styles multiple classifiers W signal
  h_W_mass_tau4321_Likelihood->SetLineColor(kRed);
  h_W_mass_tau4321_KNN->SetLineColor(kBlue);
  h_W_mass_tau4321_LD->SetLineColor(kGreen);
  h_W_mass_tau4321_FDA->SetLineColor(kMagenta+3);
  h_W_mass_tau4321_MLP->SetLineColor(kCyan);
  h_W_mass_tau4321_DNN->SetLineColor(kOrange);
  h_W_mass_tau4321_BDT->SetLineColor(kViolet);
  h_W_mass_tau4321_RuleFit->SetLineColor(kTeal+3);

  h_W_mass_tau4321_Likelihood->SetLineWidth(4);
  h_W_mass_tau4321_KNN->SetLineWidth(4);
  h_W_mass_tau4321_LD->SetLineWidth(4);
  h_W_mass_tau4321_FDA->SetLineWidth(4);
  h_W_mass_tau4321_MLP->SetLineWidth(4);
  h_W_mass_tau4321_DNN->SetLineWidth(4);
  h_W_mass_tau4321_BDT->SetLineWidth(4);
  h_W_mass_tau4321_RuleFit->SetLineWidth(4);

  h_W_mass_tau4321_Likelihood->SetStats(false);
  h_W_mass_tau4321_KNN->SetStats(false);
  h_W_mass_tau4321_LD->SetStats(false);
  h_W_mass_tau4321_FDA->SetStats(false);
  h_W_mass_tau4321_MLP->SetStats(false);
  h_W_mass_tau4321_DNN->SetStats(false);
  h_W_mass_tau4321_BDT->SetStats(false);
  h_W_mass_tau4321_RuleFit->SetStats(false);

  h_W_mass_tau4321_Likelihood->SetTitle("");
  h_W_mass_tau4321_KNN->SetTitle("");
  h_W_mass_tau4321_LD->SetTitle("");
  h_W_mass_tau4321_FDA->SetTitle("");
  h_W_mass_tau4321_MLP->SetTitle("");
  h_W_mass_tau4321_DNN->SetTitle("");
  h_W_mass_tau4321_BDT->SetTitle("");
  h_W_mass_tau4321_RuleFit->SetTitle("");

  h_W_mass_tau4321_Likelihood->GetXaxis()->SetTitle("W signal efficiency");
  h_W_mass_tau4321_KNN->GetXaxis()->SetTitle("W signal efficiency");
  h_W_mass_tau4321_LD->GetXaxis()->SetTitle("W signal efficiency");
  h_W_mass_tau4321_FDA->GetXaxis()->SetTitle("W signal efficiency");
  h_W_mass_tau4321_MLP->GetXaxis()->SetTitle("W signal efficiency");
  h_W_mass_tau4321_DNN->GetXaxis()->SetTitle("W signal efficiency");
  h_W_mass_tau4321_BDT->GetXaxis()->SetTitle("W signal efficiency");
  h_W_mass_tau4321_RuleFit->GetXaxis()->SetTitle("W signal efficiency");
  
  h_W_mass_tau4321_Likelihood->GetYaxis()->SetTitle("Background rejection");
  h_W_mass_tau4321_KNN->GetYaxis()->SetTitle("Background rejection");
  h_W_mass_tau4321_LD->GetYaxis()->SetTitle("Background rejection");
  h_W_mass_tau4321_FDA->GetYaxis()->SetTitle("Background rejection");
  h_W_mass_tau4321_MLP->GetYaxis()->SetTitle("Background rejection");
  h_W_mass_tau4321_DNN->GetYaxis()->SetTitle("Background rejection");
  h_W_mass_tau4321_BDT->GetYaxis()->SetTitle("Background rejection");
  h_W_mass_tau4321_RuleFit->GetYaxis()->SetTitle("Background rejection");

  // draw canvas and legend multiple classifiers top signal
  TCanvas *canvas_top_mass_tau4321 = new TCanvas("canvas_top_mass_tau4321", "Multiclassifiers_ROC_Curves_top", 800, 600);
  canvas_top_mass_tau4321->SetGrid();

  h_top_mass_tau4321_Likelihood->Draw("L");
  h_top_mass_tau4321_KNN->Draw("L,SAME");
  h_top_mass_tau4321_LD->Draw("L,SAME");
  h_top_mass_tau4321_FDA->Draw("L,SAME");
  h_top_mass_tau4321_MLP->Draw("L,SAME");
  h_top_mass_tau4321_DNN->Draw("L,SAME");
  h_top_mass_tau4321_BDT->Draw("L,SAME");
  h_top_mass_tau4321_RuleFit->Draw("L,SAME");

  TLegend *leg_top_mass_tau4321 = new TLegend(0.15, 0.15, 0.5, 0.5);
  leg_top_mass_tau4321->SetBorderSize(1);
  leg_top_mass_tau4321->AddEntry(h_top_mass_tau4321_Likelihood, "Likelihood");
  leg_top_mass_tau4321->AddEntry(h_top_mass_tau4321_KNN, "KNN");
  leg_top_mass_tau4321->AddEntry(h_top_mass_tau4321_LD, "LD");
  leg_top_mass_tau4321->AddEntry(h_top_mass_tau4321_FDA, "FDA");
  leg_top_mass_tau4321->AddEntry(h_top_mass_tau4321_MLP, "MLP");
  leg_top_mass_tau4321->AddEntry(h_top_mass_tau4321_DNN, "DNN");
  leg_top_mass_tau4321->AddEntry(h_top_mass_tau4321_BDT, "BDT");
  leg_top_mass_tau4321->AddEntry(h_top_mass_tau4321_RuleFit, "RuleFit");
  leg_top_mass_tau4321->Draw();

  canvas_top_mass_tau4321->Print("top_multipleclassifiers.pdf");

  // draw canvas and legend multiple classifiers W signal
  TCanvas *canvas_W_mass_tau4321 = new TCanvas("canvas_W_mass_tau4321", "Multiclassifiers_ROC_Curves_W", 800, 600);
  canvas_W_mass_tau4321->SetGrid();

  h_W_mass_tau4321_Likelihood->Draw("L");
  h_W_mass_tau4321_KNN->Draw("L,SAME");
  h_W_mass_tau4321_LD->Draw("L,SAME");
  h_W_mass_tau4321_FDA->Draw("L,SAME");
  h_W_mass_tau4321_MLP->Draw("L,SAME");
  h_W_mass_tau4321_DNN->Draw("L,SAME");
  h_W_mass_tau4321_BDT->Draw("L,SAME");
  h_W_mass_tau4321_RuleFit->Draw("L,SAME");

  TLegend *leg_W_mass_tau4321 = new TLegend(0.15, 0.15, 0.5, 0.5);
  leg_W_mass_tau4321->SetBorderSize(1);
  leg_W_mass_tau4321->AddEntry(h_W_mass_tau4321_Likelihood, "Likelihood");
  leg_W_mass_tau4321->AddEntry(h_W_mass_tau4321_KNN, "KNN");
  leg_W_mass_tau4321->AddEntry(h_W_mass_tau4321_LD, "LD");
  leg_W_mass_tau4321->AddEntry(h_W_mass_tau4321_FDA, "FDA");
  leg_W_mass_tau4321->AddEntry(h_W_mass_tau4321_MLP, "MLP");
  leg_W_mass_tau4321->AddEntry(h_W_mass_tau4321_DNN, "DNN");
  leg_W_mass_tau4321->AddEntry(h_W_mass_tau4321_BDT, "BDT");
  leg_W_mass_tau4321->AddEntry(h_W_mass_tau4321_RuleFit, "RuleFit");
  leg_W_mass_tau4321->Draw();

  canvas_W_mass_tau4321->Print("W_multipleclassifiers.pdf");


}


#include <TROOT.h>
#include <TH1.h>
#include <TCanvas.h>
#include <TFile.h> 

void PlotMerger(){

  TFile *file_nomass_Tau4321 = TFile::Open("dataset_nomass_4321Subjettiness/TMVA.root");
  TFile *file_mass_Tau4321 = TFile::Open("dataset_mass_4321Subjettiness/TMVA.root");
  TFile *file_mass_Tau321 = TFile::Open("dataset_mass_321Subjettiness/TMVA.root");
  TFile *file_mass_Tau32 = TFile::Open("dataset_mass_32Subjettiness/TMVA.root");
  TFile *file_mass_Tau3 = TFile::Open("dataset_mass_3Subjettiness/TMVA.root");
  TFile *file_mass_Tau1 = TFile::Open("dataset_mass_1Subjettiness/TMVA.root");
  
  TFile *file_particles = TFile::Open("../TMVAResults_Constituents/dataset_particles_350/TMVA.root");

  TFile *file_constituentsNum = TFile::Open("../TMVAResults_Constituents/dataset_constituents_number_nocuts/TMVA.root");

  TH1F *h_nomass_Tau4321 = (TH1F*)file_nomass_Tau4321->Get("dataset/Method_BDT/BDT/MVA_BDT_rejBvsS");
  TH1F *h_mass_Tau4321 = (TH1F*)file_mass_Tau4321->Get("dataset/Method_BDT/BDT/MVA_BDT_rejBvsS");
  TH1F *h_mass_Tau321 = (TH1F*)file_mass_Tau321->Get("dataset/Method_BDT/BDT/MVA_BDT_rejBvsS");
  TH1F *h_mass_Tau32 = (TH1F*)file_mass_Tau32->Get("dataset/Method_BDT/BDT/MVA_BDT_rejBvsS");
  TH1F *h_mass_Tau3 = (TH1F*)file_mass_Tau3->Get("dataset/Method_BDT/BDT/MVA_BDT_rejBvsS");
  TH1F *h_mass_Tau1 = (TH1F*)file_mass_Tau1->Get("dataset/Method_BDT/BDT/MVA_BDT_rejBvsS");
  
  TH1F *h_mass_Tau4321_DNN = (TH1F*)file_mass_Tau4321->Get("dataset/Method_DL/DNN_CPU/MVA_DNN_CPU_rejBvsS");
  TH1F *h_particles_DNN = (TH1F*)file_particles->Get("dataset/Method_DL/DNN_CPU/MVA_DNN_CPU_rejBvsS");
  TH1F *h_constituentsNum_DNN = (TH1F*)file_constituentsNum->Get("dataset/Method_DL/DNN_CPU/MVA_DNN_CPU_rejBvsS");


  if (!h_mass_Tau4321 || !h_mass_Tau3 || !h_mass_Tau1 || !h_particles_DNN){
    std::cout << "histo not found in file" << std::endl;
    return;
  }

  h_nomass_Tau4321->SetLineColor(kBlack);
  h_mass_Tau4321->SetLineColor(kRed);
  h_mass_Tau321->SetLineColor(kBlue);
  h_mass_Tau32->SetLineColor(kGreen);
  h_mass_Tau3->SetLineColor(kOrange+3);
  h_mass_Tau1->SetLineColor(kViolet);

  h_mass_Tau4321_DNN->SetLineColor(kRed);
  h_particles_DNN->SetLineColor(kBlue);
  h_constituentsNum_DNN->SetLineWidth(kBlack);

  h_nomass_Tau4321->SetLineWidth(3);
  h_mass_Tau4321->SetLineWidth(3);
  h_mass_Tau321->SetLineWidth(3);
  h_mass_Tau32->SetLineWidth(3);
  h_mass_Tau3->SetLineWidth(3);
  h_mass_Tau1->SetLineWidth(3);

  h_mass_Tau4321_DNN->SetLineWidth(3);
  h_particles_DNN->SetLineWidth(3);
  h_constituentsNum_DNN->SetLineWidth(3);

  h_nomass_Tau4321->SetStats(false);
  h_mass_Tau4321->SetStats(false);
  h_mass_Tau321->SetStats(false);
  h_mass_Tau32->SetStats(false);
  h_mass_Tau3->SetStats(false);
  h_mass_Tau1->SetStats(false);

  h_mass_Tau4321_DNN->SetStats(false);
  h_particles_DNN->SetStats(false);
  h_constituentsNum_DNN->SetStats(false);

  TCanvas *canvas_mass_TauN = new TCanvas("Canvas_Mass_TauN", "m+NSubjettiness", 1000, 800);

  h_mass_Tau4321->Draw("L");
  h_mass_Tau321->Draw("L SAME");
  h_mass_Tau32->Draw("L SAME");
  h_mass_Tau3->Draw("L SAME");

  TLegend *legend_mass_TauN = new TLegend(0.2, 0.3, 0.5, 0.5);
  legend_mass_TauN->AddEntry(h_mass_Tau4321, "m + 4-body");
  legend_mass_TauN->AddEntry(h_mass_Tau321, "m + 3-body");
  legend_mass_TauN->AddEntry(h_mass_Tau32, "m + 2-body");
  legend_mass_TauN->AddEntry(h_mass_Tau3, "m + 1-body");
  legend_mass_TauN->Draw();
  
  canvas_mass_TauN->Print("Mass_TauN.pdf");


  TCanvas *canvas_mass_nomass = new TCanvas("Canvas_Mass_NoMass", "Mass and no mass taken into account", 1000, 800);

  h_nomass_Tau4321->Draw("L");
  h_mass_Tau4321->Draw("L SAME");

  TLegend *legend_mass_nomass = new TLegend(0.2, 0.3, 0.5, 0.5);
  legend_mass_nomass->AddEntry(h_nomass_Tau4321, "4-body");
  legend_mass_nomass->AddEntry(h_mass_Tau4321, "m + 4-body");
  legend_mass_nomass->Draw();

  canvas_mass_nomass->Print("Mass_vs_NoMass.pdf");


  TCanvas *canvas_Tau3_Tau1 = new TCanvas("Canvas_Tau3_Tau1", "Using Tau3 vs using Tau1", 1000, 800);

  h_mass_Tau3->Draw("L");
  h_mass_Tau1->Draw("L SAME");

  TLegend *legend_Tau3_Tau1 = new TLegend(0.2, 0.3, 0.5, 0.5);
  legend_Tau3_Tau1->AddEntry(h_mass_Tau3, "m + 3Subjettiness");
  legend_Tau3_Tau1->AddEntry(h_mass_Tau1, "m + 1Subjettiness");
  legend_Tau3_Tau1->Draw();

  canvas_Tau3_Tau1->Print("Tau3_vs_Tau1.pdf");


  TCanvas *canvas_TauN_Particles_DNN = new TCanvas("Canvas_TauN_Particles_DNN", "DNN using m + 4-subjetiness vs using particles", 1000, 800);

  h_mass_Tau4321_DNN->Draw("L");
  h_particles_DNN->Draw("L SAME");

  TLegend *legend_TauN_Particles_DNN = new TLegend(0.2, 0.3, 0.5, 0.5);
  legend_TauN_Particles_DNN->AddEntry(h_mass_Tau4321_DNN, "m + 4Subjettiness (DNN)");
  legend_TauN_Particles_DNN->AddEntry(h_particles_DNN, "particles (DNN)");
  legend_TauN_Particles_DNN->Draw();

  canvas_TauN_Particles_DNN->Print("TauN_vs_Particles_DNN.pdf");


  TCanvas *canvas_TauN_ConstituentsNum_DNN = new TCanvas("Canvas_TauN_ConstituentsNum_DNN", "DNN using m + 4-subjetiness vs using number of constituents", 1000, 800);

  h_mass_Tau4321_DNN->Draw("L");
  h_constituentsNum_DNN->Draw("L SAME");

  TLegend *legend_TauN_ConstituentsNum_DNN = new TLegend(0.2, 0.3, 0.5, 0.5);
  legend_TauN_ConstituentsNum_DNN->AddEntry(h_mass_Tau4321_DNN, "m + 4Subjettiness (DNN)");
  legend_TauN_ConstituentsNum_DNN->AddEntry(h_constituentsNum_DNN, "No. of constituents (DNN)");
  legend_TauN_ConstituentsNum_DNN->Draw();

  canvas_TauN_ConstituentsNum_DNN->Print("TauN_vs_ConstituentNumberNoCut_DNN.pdf");

}

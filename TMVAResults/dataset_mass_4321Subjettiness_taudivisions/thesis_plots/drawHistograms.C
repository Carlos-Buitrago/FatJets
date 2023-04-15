#include <TH1F.h>
#include <TFile.h>
#include <TCanvas.h>

void drawHistograms() {
  // Open the rootfile
  TFile *file = new TFile("../TMVA.root");

  // Extract the two histograms
  TH1F *histo1 = (TH1F*)file->Get("dataset/InputVariables_Id/tau43__Signal_Id");
  TH1F *histo2 = (TH1F*)file->Get("dataset/InputVariables_Id/tau43__Background_Id");

  // Normalize the histograms to 1 in the y axis
  histo1->Scale(1/histo1->Integral());
  histo2->Scale(1/histo2->Integral());

  // Set fill color and style for the first histogram
  histo1->SetFillColorAlpha(kBlue-7, 0.5); // Set lighter blue
  histo1->SetLineColor(kBlue); // Set original blue for line

  // Set fill color and style for the second histogram
  histo2->SetFillStyle(3354);
  histo2->SetFillColorAlpha(kRed-7, 0.5); // Set lighter red for stripes
  histo2->SetLineColor(kRed); // Set red for line

  // Set custom axis titles
  histo1->GetXaxis()->SetTitle("#tau_{4}/#tau_{3}");
  histo1->GetYaxis()->SetTitle("Relative occurence");
  histo2->GetXaxis()->SetTitle("#tau_{4}/#tau_{3}");
  histo2->GetYaxis()->SetTitle("Relative occurence");

  // Set custom histogram title
  histo1->SetTitle("Fat jet #tau_{4}/#tau_{3}");
  histo2->SetTitle("Fat jet #tau_{4}/#tau_{3}");

  // Remove statistics information
  histo1->SetStats(false);
  histo2->SetStats(false);

  // Create a new canvas to draw the histograms
  TCanvas *canvas = new TCanvas("canvas", "Histograms", 800, 600); // Increased width

  // Adjust left margin of the first histogram so that the y axis title fits
  canvas->SetLeftMargin(0.15);

  // Draw the tallest histogram first
  if (histo1->GetMaximum() > histo2->GetMaximum()) {
    histo1->Draw("HIST");
    histo2->Draw("HIST,histsame");
  }
  else {
    histo2->Draw("HIST");
    histo1->Draw("HIST,histsame");
  }

  // Set the line and fill colors for the histograms
  histo1->SetLineColor(kBlue);
  histo1->SetFillColorAlpha(kBlue-7, 0.5);
  histo2->SetLineColor(kRed);
  histo2->SetFillColorAlpha(kRed-7, 0.5);

  // Create a legend for the histograms
  TLegend *legend = new TLegend(0.7, 0.7, 0.9, 0.9);
  legend->AddEntry(histo1, "Top Signal", "f");
  legend->AddEntry(histo2, "QCD Background", "f");
  legend->Draw();

  // Save the canvas as a pdf file
  canvas->SaveAs("top_tau43_distribution.pdf");

  // Close the file
  file->Close();
}

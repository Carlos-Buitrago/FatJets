#include <TROOT.h>
#include <TFile.h>

void rootfileModifier(){
  
  TFile *file = TFile::Open("pp_tt_hadronic_14TeV500kEvtsGenCutT350_CutQCD350_InclusiveCut350_delphes_events.root", "update");
  TFile *file = TFile::Open("pp_QCD_14TeV500kEvtsGenCutQCD350_InclusiveCut350_delphes_events.root", "update");
  TFile *file = TFile::Open("pp_WW_hadronic_14TeV500kEvtsGenCutW350_CutQCD350_InclusiveCut350_delphes_events.root", "update");

}

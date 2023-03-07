#include <iostream>
#include <string>
#include <stdio.h>

#include "TestTreeModifierSelector.h"
#include "TestTreeModifierSelector.C"


void TestTreeModifierSelector_runningMacro(){

	TFile *f = TFile::Open("pp_tt_hadronic_14TeV500kEvtsGenCutT350_CutQCD350_InclusiveCut350_delphes_events.root");
  TTree *t = (TTree *)f->Get("Delphes");

	t->Process("TestTreeModifierSelector.C");

}

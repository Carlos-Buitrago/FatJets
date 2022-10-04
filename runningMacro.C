#include <iostream>
#include <string>
#include <stdio.h>

#include "SelectorClass.h"
#include "SelectorClass.C"


void runningMacro(){

	TFile *file10 = TFile::Open("pp_WW_100kEvtsGenCutW250_RFatJet10_ATLAS.root");

	gROOT->TROOT::ProcessLine(".L SelectorClass.C");

	SelectorClass t;

	t.Loop();

}
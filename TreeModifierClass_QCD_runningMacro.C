#include <iostream>
#include <string>
#include <stdio.h>

#include "TreeModifierClass_QCD.h"
#include "TreeModifierClass_QCD.C"


void TreeModifierClass_QCD_runningMacro(){

	gROOT->TROOT::ProcessLine(".L TreeModifierClass_QCD.C");

	TreeModifierClass_QCD t;

	t.Loop();

}

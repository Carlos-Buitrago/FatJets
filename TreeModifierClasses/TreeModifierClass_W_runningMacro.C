#include <iostream>
#include <string>
#include <stdio.h>

#include "TreeModifierClass_W.h"
#include "TreeModifierClass_W.C"


void TreeModifierClass_W_runningMacro(){

	gROOT->TROOT::ProcessLine(".L TreeModifierClass_W.C");

	TreeModifierClass_W t;

	t.Loop();

}

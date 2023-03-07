#include <iostream>
#include <string>
#include <stdio.h>

#include "TreeModifierClass.h"
#include "TreeModifierClass.C"


void TreeModifierClass_runningMacro(){

	gROOT->TROOT::ProcessLine(".L TreeModifierClass.C");

	TreeModifierClass t;

	t.Loop();

}

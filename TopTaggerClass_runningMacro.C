#include <iostream>
#include <string>
#include <stdio.h>

#include "TopTaggerClass.h"
#include "TopTaggerClass.C"


void TopTaggerClass_runningMacro(){

	gROOT->TROOT::ProcessLine(".L TopTaggerClass.C");

	TopTaggerClass t;

	t.Loop();

}
#include <iostream>
#include <cmath>

#include "TROOT.h"
#include "TFile.h"
#include "TTree.h"
#include "TBrowser.h"
#include "TH2.h"
#include "TRandom.h"

void banal(char* filename)
{
    TFile *f = new TFile(filename);

    TTree *t1 = (TTree*)f->Get("ntp1");

    // Declare the variables we will need.
    int nB;
    // Note that these are arrays, because you may
    // have multiple B-candidates.
    int Bd1Idx[100], Bd2Idx[100];
    int Bd1Lund[100], Bd2Lund[100];
    // float protoncosth[100];
    float BpostFitMes[100];
    float BpostFitDeltaE[100];
    float pipMass[100];
    float protonMass[100];
}

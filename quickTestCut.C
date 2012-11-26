#include <iostream>
#include <cmath>

#include "TROOT.h"
#include "TFile.h"
#include "TTree.h"
#include "TBrowser.h"
#include "TH2.h"
#include "TRandom.h"

void quickTestCut(char* filename)
{
    TFile *f = new TFile(filename);

    TTree *t1 = (TTree*)f->Get("ntp1");

    // Declare the variables we will need.
    int nB; //number of B candidates
    int npip; //number of charged pion candidates
    int nproton;
    int npi0;
    int pipMCIdx;
    int pipTrkIdx[100];
    int protonTrkIdx[100];
    int pi0TrkIdx[100];
    int nTRK;
    // Note that these are arrays, because you may
    // have multiple B-candidates.
    int Bd1Idx[100], Bd2Idx[100];
    int Bd1Lund[100], Bd2Lund[100];
    float BpostFitMes[100];
    float BpostFitDeltaE[100];
    float pipp3[100];

    t1->SetBranchAddress("nB",&nB);
    t1->SetBranchAddress("npip",&npip);
    t1->SetBranchAddress("nproton",&nproton);
    t1->SetBranchAddress("npi0",&npi0);
    t1->SetBranchAddress("pipMCIdx",&pipMCIdx);
    t1->SetBranchAddress("pipTrkIdx",pipTrkIdx);
    t1->SetBranchAddress("protonTrkIdx",protonTrkIdx);
    t1->SetBranchAddress("pi0TrkIdx",pi0TrkIdx);
    t1->SetBranchAddress("nTRK",&nTRK);

    t1->SetBranchAddress("Bd1Idx",Bd1Idx);
    t1->SetBranchAddress("Bd2Idx",Bd2Idx);
    t1->SetBranchAddress("Bd1Lund",Bd1Lund);
    t1->SetBranchAddress("Bd2Lund",Bd2Lund);
    t1->SetBranchAddress("BpostFitMes",BpostFitMes);
    t1->SetBranchAddress("BpostFitDeltaE",BpostFitDeltaE);
    t1->SetBranchAddress("pipp3",pipp3);

    TH1F *pipInsideCut  = new TH1F("pipInsideCut","Charged #pi 3-momentum inside cut",40,0.0,4.0);
    TH1F *pipOutsideCut = new TH1F("pipOutsideCut","Charged #pi 3-momentum outside cut",40,0.0,4.0);

    //Get the number of entries in the file to use as iterator limit
    Int_t nentries = (Int_t)t1->GetEntries();

    //Loop over the entries
    for (Int_t i=0;i<6;i++) {
      t1->GetEntry(i); //As I understand it, this command is necessary to convince
                       //ROOT that you really do want to look at material in that entry
                       //This may not turn out to really be required. YMMV
      cout << "B-cands for this entry: " << nB << endl;
      cout << "Number of TRACKS: " << nTRK << endl;
      cout << "Entry-level npip is " << npip << endl;
      cout << "Entry-level nproton is " << nproton << endl;
      cout << "Entry-level npi0 is " << npi0 << endl;
      cout << "ENTRY-level pip TrkID is " << pipTrkIdx[i] << endl;
      cout << "ENTRY-level p TrkId is " << protonTrkIdx[i] << endl;
      cout << "ENTRY-level pi0 TrkId is " << pi0TrkIdx[i] << endl;
      cout << "-----" << endl;

      //Each entry in the ntuple is an event - a collision in the detector
      //So for each entry/event, there is a list of, e.g., pi, B, proton candidates 
      //We can grab the "pipp3" array *for that event* and look at each one
      for (Int_t j=0;j<nB;j++) {
	//cout << "Bcand-level npip is " << npip << endl;
	cout << "***BCAND " << j << "***" << endl;
	cout << "BCAND-level pip TrkID is " << pipTrkIdx[j] << endl;
	cout << "BCAND-level p TrkID is " << protonTrkIdx[j] << endl;
	cout << "BCAND-level pi0 TrkId is " << pi0TrkIdx[i] << endl;
// 	if (abs(BpostFitDeltaE[j])<0.1 && BpostFitMes[j]>5.25 && BpostFitMes[j]<5.3){
// 	  for (Int_t k=0;k<npip;k++) {
// 	    pipInsideCut->Fill(pipp3[k]);
// 	  }
// 	}
// 	else {
// 	  for (Int_t m=0;m<npip;m++) {
// 	    pipOutsideCut->Fill(pipp3[m]);
// 	  }
// 	}
      }
      cout << "------END OF ENTRY " << i << "------" << endl;
    }
    //Now add up the pipPlots to see if they add up to the original (original not included in this script)
    
//     TH1F *pipTotal = new TH1F((*pipInsideCut) + (*pipOutsideCut));
//     pipTotal->Draw();

}

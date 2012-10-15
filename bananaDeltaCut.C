#include <iostream>
#include <cmath>

#include "TROOT.h"
#include "TFile.h"
#include "TTree.h"
#include "TBrowser.h"
#include "TH2.h"
#include "TRandom.h"

void bananaDeltaCut(char* filename)
{
    TFile *f = new TFile(filename);

    TTree *t1 = (TTree*)f->Get("ntp1");

    // Declare the variables we will need.
    int nB;
    // Note that these are arrays, because you may
    // have multiple B-candidates.
    float BpostFitMes[100];
    float BpostFitDeltaE[100];
    int Bd1Idx[100], Bd2Idx[100];
    int Bd1Lund[100], Bd2Lund[100];
    float DeltappMass[100];
    float percentDiff;
    float bestVal = 999.0;
    int bestEntry = 0;

    int signalpeak = 0;
    int signaltail = 0;

    // Initialize the addresses (?)
    t1->SetBranchAddress("nB",&nB);
    // Because these are arrays, we don't need the ampersand
    // for the second argument.
    t1->SetBranchAddress("BpostFitMes",BpostFitMes);
    t1->SetBranchAddress("BpostFitDeltaE",BpostFitDeltaE);
    t1->SetBranchAddress("Bd1Idx",Bd1Idx);
    t1->SetBranchAddress("Bd2Idx",Bd2Idx);
    t1->SetBranchAddress("Bd1Lund",Bd1Lund);
    t1->SetBranchAddress("Bd2Lund",Bd2Lund);
    t1->SetBranchAddress("DeltappMass",DeltappMass);

    // Create some empty histograms
    //    TH1F *hnB          = new TH1F("hnB","The number of B candidates",10,0,10);
    TH1F *DelMCutbestCandMass = new TH1F("DelMCutbestCandMass","m_{ES}",40,5.2,5.3);
    TH1F *DelMCutbestCandDelE = new TH1F("DelMCutbestCandDelE","#Delta E",40,-0.1,0.1);
    TH2F *DelMCutmESvsDelE    = new TH2F("DelMCutmESvsDelE","m_{ES} vs. #Delta E",40,5.2,5.3,40,-0.1,0.1);

    TH1F *DelMCutmassDeltapp  = new TH1F("DelMCutmassDeltapp","#Delta++ mass",40,1.0,1.7);

    // Name the images
    

    // Get the number of entries in this file.
    Int_t nentries = (Int_t)t1->GetEntries();

    // Loop over the entries
    for (Int_t i=0;i<nentries;i++) {

      t1->GetEntry(i);

      if (nB == 1) {
	if ( DeltappMass[Bd2Idx[0]] > 1.4 ) {
	  DelMCutbestCandMass->Fill(BpostFitMes[0]);
	  DelMCutbestCandDelE->Fill(BpostFitDeltaE[0]);
	  DelMCutmESvsDelE->Fill(BpostFitMes[0],BpostFitDeltaE[0]);
	  
	  DelMCutmassDeltapp->Fill(DeltappMass[Bd2Idx[0]]);	  

	if (BpostFitMes[0] < (5.279 + 0.008) && BpostFitMes[0] > (5.279-0.008)) signalpeak++;
	if (BpostFitMes[0] < (5.279 - 0.008) || BpostFitMes[0] > (5.279+0.008)) signaltail++;

	}
      }
      else {
	for (Int_t j=0;j<nB;j++) {
	  percentDiff = fabs(BpostFitMes[j]-5.279);
	  if (percentDiff < bestVal) {
	    bestVal = percentDiff;
	    bestEntry = j;
	  }
	}
	if ( DeltappMass[Bd2Idx[bestEntry]] > 1.4 ) {
	  DelMCutbestCandMass->Fill(BpostFitMes[bestEntry]);
	  DelMCutbestCandDelE->Fill(BpostFitDeltaE[bestEntry]);
	  DelMCutmESvsDelE->Fill(BpostFitMes[bestEntry],BpostFitDeltaE[bestEntry]);
	  
	  DelMCutmassDeltapp->Fill(DeltappMass[Bd2Idx[bestEntry]]);

	if (BpostFitMes[bestEntry] < (5.279 + 0.008) && BpostFitMes[bestEntry] > (5.279-0.008)) signalpeak++;
	if (BpostFitMes[bestEntry] < (5.279 - 0.008) || BpostFitMes[bestEntry] > (5.279+0.008)) signaltail++;

	}
      }
    }

    DelMCutbestCandMass->Draw();
    // c1->SaveAs("DelMCutbestCandMassMulticand.png");
    // c1->Clear();
    
    // DelMCutbestCandDelE->Draw();
    // c1->SaveAs("DelMCutbestCandDelEMulticand.png");
    // c1->Clear();

    // DelMCutmESvsDelE->Draw();
    // c1->SaveAs("DelMCutmESvsDelEMulticand2.png");
    // c1->Clear();

    // DelMCutmassDeltapp->Draw();
    // c1->SaveAs("DelMCutmassDeltapp2.png");
    // c1->Clear();

    cout << "The number of candidates in the peak was " << signalpeak << endl;
    cout << "The number of candidates in the tail was " << signaltail << endl;

}

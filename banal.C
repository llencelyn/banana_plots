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
    int Bd1Idx[32], Bd2Idx[32];
    int Bd1Lund[32], Bd2Lund[32];
    // float protoncosth[32];
    float BpostFitMes[32];
    float BpostFitDeltaE[32];

    double mRatio1 = 0.0;
    double mRatio2 = 0.0;
    int countExtra = 0;

    int peak = 0;
    int notpeak = 0;

    // Initialize the addresses (?)
    t1->SetBranchAddress("nB",&nB);
    // Because these are arrays, we don't need the ampersand
    // for the second argument.
    t1->SetBranchAddress("Bd1Idx",Bd1Idx);
    t1->SetBranchAddress("Bd2Idx",Bd2Idx);
    t1->SetBranchAddress("Bd1Lund",Bd1Lund);
    t1->SetBranchAddress("Bd2Lund",Bd2Lund);
    // t1->SetBranchAddress("protoncosth",protoncosth);
    t1->SetBranchAddress("BpostFitMes",BpostFitMes);
    t1->SetBranchAddress("BpostFitDeltaE",BpostFitDeltaE);

    // Create some empty histograms
    TH1F *hnB     = new TH1F("hnB","The number of B candidates",10,0,10);
    TH1F *OneB    = new TH1F("OneB","m_{ES}: 1-cand black, multi-cand red",40,5.2,5.3);
    TH1F *MoreB   = new TH1F("MoreB","m_{ES}",40,5.2,5.3);
    TH1F *MoreThan2B = new TH1F("MoreThan2B","m_{ES}",40,5.2,5.3);
    TH2F *TwoDSignal = new TH2F("TwoDSignal","m_{ES} vs. #Delta E for 11066",40,5.2,5.3,40,-0.15,0.15);
    TH2F *TwoDMulti = new TH2F("TwoDMulti","m_{ES} vs. #Delta E for 11066",40,5.2,5.3,40,-0.15,0.15);
    TH2F *TwoDMoreThan2 = new TH2F("TwoDMoreThan2","m_{ES} vs. #Delta E for 11066",40,5.2,5.3,40,-0.15,0.15);

    // Get the number of entries in this file.
    Int_t nentries = (Int_t)t1->GetEntries();

    // Loop over the entries
    for (Int_t i=0;i<nentries;i++) {

      t1->GetEntry(i);
      
      hnB->Fill(nB);

      // if (nB == 1) {
      // 	continue;
      // }
      // else if (nB == 2) {
      // 	mRatio1 = abs(BpostFitMes[0]-5.279)/5.279;
      // 	mRatio2 = abs(BpostFitMes[1]-5.279)/5.279;

      // 	if (mRatio1 < mRatio2) {
      // 	  TwoDMulti->Fill(BpostFitMes[0],BpostFitDeltaE[0]);
      // 	}
      // 	else if (mRatio1 > mRatio2) {
      // 	  TwoDMulti->Fill(BpostFitMes[1],BpostFitDeltaE[1]);
      // 	}
      // 	else {
      // 	  cout << "Your percent diff was exactly equal!\n";
      // 	  abort();
      // 	}
      // }
      // else {
      // 	countExtra++;
      // }

      
      // Loop over the number of B-candidates
      for (Int_t j=0;j<nB;j++) {

	if (BpostFitMes[j] < (5.279+0.008) && BpostFitMes[j] > (5.279-0.008)) peak++;

	if (BpostFitMes[j] > (5.279+0.008) || BpostFitMes[j] < (5.279-0.008)) notpeak++;

      // 	if (nB == 1) {
      // 	  OneB->Fill(BpostFitMes[j]);
      // 	  TwoDSignal->Fill(BpostFitMes[j],BpostFitDeltaE[j]);
      // 	}
      // 	else if (nB == 2) {
      // 	  MoreB->Fill(BpostFitMes[j]);
      // 	  TwoDMulti->Fill(BpostFitMes[j],BpostFitDeltaE[j]);

	  
      // 	}
      // 	else {
      // 	  MoreThan2B->Fill(BpostFitMes[j]);
      // 	  TwoDMoreThan2->Fill(BpostFitMes[j],BpostFitDeltaE[j]);
      // 	}
      }
    }

    cout << "There were " << peak << " candidates in the peak." << endl;
    cout << "There were " << notpeak << " candidates in the not-peak." << endl;

    //   cout << "There were " << countExtra << " events with more than 2 candidates.\n";
    
    //    hnB->Draw();
    
    // OneB->SetLineWidth(2);
    // OneB->Draw();
    // MoreB->SetLineWidth(2);
    // MoreB->SetLineColor(kRed);
    // MoreB->Draw("same");

    // c1->Clear();

    // TwoDSignal->SetMarkerStyle(1);
    // TwoDSignal->Draw();
    // c1->SaveAs("TwoDSignal.png");
    // c1->Clear();
    // TwoDMulti->SetMarkerStyle(1);
    // TwoDMulti->SetMarkerColor(2);
    // TwoDMulti->Draw();
    // c1->SaveAs("TwoDMulti.png");
    // c1->Clear();
}

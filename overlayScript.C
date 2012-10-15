{

  //Use this from in ~jlboug01/work/babar/charmless/phase1/Ana11066/
  
  TFile *mc66 = new TFile("SP11066_Run5.root");
  // TFile *mc65 = new TFile("SP11065_Run1.root");
  // TFile *mc1005 = new TFile("SP1005_Run1.root");
  // TFile *mc998 = new TFile("SP998_Run1.root");
  // TFile *mc1235 = new TFile("genericB/SP1235_Run1.root");
  // TFile *mc1237 = new TFile("genericB/SP1237_Run1.root");
  
  TNtuple *pDelta=(TNtuple*)mc66->Get("ntp1");
  // TNtuple *deltaDelta=(TNtuple*)mc65->Get("ntp1");
  // TNtuple *ccbar=(TNtuple*)mc1005->Get("ntp1");
  // TNtuple *uds=(TNtuple*)mc998->Get("ntp1");
  // TNtuple *charB=(TNtuple*)mc1235->Get("ntp1");
  // TNtuple *neutB=(TNtuple*)mc1237->Get("ntp1");
  
  ////////////////////////

  TH2F *TwoD66R5 = new TH2F("TwoD66R5","m_{ES} vs. #Delta E for 66, ALL CANDIDATES",40,5.2,5.3,40,-0.1,0.1);
  pDelta->Draw("BpostFitDeltaE:BpostFitMes>>TwoD66R5");
  c1->SaveAs("TwoD66R5allCands.png");
  
  // TH1F *overlay66mass = new TH1F("overlay66mass","66 Bmass compared to m_ES;mass (GeV/c^{2})",60,5.25,5.3);
  // pDelta->Draw("BMass>>overlay66mass");
  // TH1F *overlay66mes = new TH1F("overlay66mes","66 Bmass compared to m_ES;mass (GeV/c^{2})",60,5.25,5.3);
  // pDelta->Draw("BpostFitMes>>overlay66mes");
  // overlay66mes->SetLineWidth(2);
  // overlay66mass->SetLineWidth(2);
  // overlay66mes->SetLineColor(2);
  // overlay66mes->Draw();
  // overlay66mass->Draw("same");
  // c1->SaveAs("overlayMassSP11066R1.png");
  // c1->Clear();

  // TH1F *overlay65mass = new TH1F("overlay65mass","65 Bmass compared to m_ES;mass (GeV/c^{2})",60,4.5,5.4);
  // deltaDelta->Draw("BMass>>overlay65mass");
  // TH1F *overlay65mes = new TH1F("overlay65mes","65 Bmass compared to m_ES;mass (GeV/c^{2})",60,4.5,5.4);
  // deltaDelta->Draw("BpostFitMes>>overlay65mes");
  // overlay65mes->SetLineWidth(2);
  // overlay65mass->SetLineWidth(2);
  // overlay65mes->SetLineColor(2);
  // overlay65mes->Draw();
  // overlay65mass->Draw("same");
  // c1->SaveAs("overlayMassSP11065R1.png");
  // c1->Clear();

  // TH1F *overlay1005mass = new TH1F("overlay1005mass","1005 Bmass compared to m_ES;mass (GeV/c^{2})",60,4.5,5.35);
  // ccbar->Draw("BMass>>overlay1005mass");
  // TH1F *overlay1005mes = new TH1F("overlay1005mes","1005 Bmass compared to m_ES;mass (GeV/c^{2})",60,4.5,5.35);
  // ccbar->Draw("BpostFitMes>>overlay1005mes");
  // overlay1005mes->SetLineWidth(2);
  // overlay1005mass->SetLineWidth(2);
  // overlay1005mes->SetLineColor(2);
  // overlay1005mes->Draw();
  // overlay1005mass->Draw("same");
  // c1->SaveAs("overlayMassSP1005R1.png");
  // c1->Clear();

  // TH1F *overlay998mass = new TH1F("overlay998mass","998 Bmass compared to m_ES;mass (GeV/c^{2})",60,4.5,5.35);
  // uds->Draw("BMass>>overlay998mass");
  // TH1F *overlay998mes = new TH1F("overlay998mes","998 Bmass compared to m_ES;mass (GeV/c^{2})",60,4.5,5.35);
  // uds->Draw("BpostFitMes>>overlay998mes");
  // overlay998mes->SetLineWidth(2);
  // overlay998mass->SetLineWidth(2);
  // overlay998mes->SetLineColor(2);
  // overlay998mes->Draw();
  // overlay998mass->Draw("same");
  // c1->SaveAs("overlayMassSP998R1.png");
  // c1->Clear();

  // TH1F *overlay1235mass = new TH1F("overlay1235mass","1235 Bmass compared to m_ES;mass (GeV/c^{2})",60,4.5,5.4);
  // charB->Draw("BMass>>overlay1235mass");
  // TH1F *overlay1235mes = new TH1F("overlay1235mes","1235 Bmass compared to m_ES;mass (GeV/c^{2})",60,4.5,5.4);
  // charB->Draw("BpostFitMes>>overlay1235mes");
  // overlay1235mes->SetLineWidth(2);
  // overlay1235mass->SetLineWidth(2);
  // overlay1235mes->SetLineColor(2);
  // overlay1235mes->Draw();
  // overlay1235mass->Draw("same");
  // c1->SaveAs("overlayMassSP1235R1.png");
  // c1->Clear();

  // TH1F *overlay1237mass = new TH1F("overlay1237mass","1237 Bmass compared to m_ES;mass (GeV/c^{2})",60,4.5,5.4);
  // neutB->Draw("BMass>>overlay1237mass");
  // TH1F *overlay1237mes = new TH1F("overlay1237mes","1237 Bmass compared to m_ES;mass (GeV/c^{2})",60,4.5,5.4);
  // neutB->Draw("BpostFitMes>>overlay1237mes");
  // overlay1237mes->SetLineWidth(2);
  // overlay1237mass->SetLineWidth(2);
  // overlay1237mes->SetLineColor(2);
  // overlay1237mes->Draw();
  // overlay1237mass->Draw("same");
  // c1->SaveAs("overlayMassSP1237R1.png");
  // c1->Clear();

}

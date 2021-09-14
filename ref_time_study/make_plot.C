void make_histos(TString hist_name=""){

  gROOT->SetBatch(kTRUE);
  gROOT->ForceStyle();
  gStyle->SetOptStat(0);
  
  //black(11799), blue(11829), green(11847), magenta (11883), red (11947)


  TString s1 = "Time_cuts_test11799/refTime_coin_histos_run11799.root";
  TString s2 = "Time_cuts_test11829/refTime_coin_histos_run11829.root";
  TString s3 = "Time_cuts_test11847/refTime_coin_histos_run11847.root";
  TString s4 = "Time_cuts_test11883/refTime_coin_histos_run11883.root";
  TString s5 = "Time_cuts_test11947/refTime_coin_histos_run11947.root";

  TCanvas *c1 = new TCanvas();

  Float_t y_min = 0.001;
  Float_t y_max = 1.e6; 

  Double_t ref_cut = -1.e06;
  Double_t new_ref_cut = -1.e06;

  
  if(hist_name=="hT1_ref_CUT"){
    ref_cut = 1500.;
    new_ref_cut = 2400.;
  }

  else if(hist_name=="hDC1_refTime_CUT"|| hist_name=="hDC2_refTime_CUT"|| hist_name=="hDC3_refTime_CUT"|| hist_name=="hDC4_refTime_CUT"){
    ref_cut = 10000.;
    new_ref_cut = 14500.;
  }
  
  else if(hist_name=="hFADC_ref_CUT"){
    ref_cut = 2000.;
    new_ref_cut = 3200.;

  }
  
  else if(hist_name=="pT1_ref_CUT" || hist_name=="pT2_ref_CUT"){
    ref_cut = 2000.;
    new_ref_cut = 3700.;
  }

  else if(hist_name=="pDC1_refTime_CUT"||hist_name=="pDC2_refTime_CUT"||hist_name=="pDC3_refTime_CUT"||hist_name=="pDC4_refTime_CUT"||hist_name=="pDC5_refTime_CUT"||hist_name=="pDC6_refTime_CUT"||hist_name=="pDC7_refTime_CUT"||hist_name=="pDC8_refTime_CUT"||hist_name=="pDC9_refTime_CUT"||hist_name=="pDC10_refTime_CUT"){
    ref_cut = 10000.;
    new_ref_cut = 14000.;

  }
  
  else if(hist_name=="pFADC_ref_CUT"){
    ref_cut = 2000.;
    new_ref_cut = 4500.;
	
  }


  cout << ref_cut << endl;
  c1->SetLogy();
  
  TFile *f1 = new TFile(s1.Data(), "READ");
  TH1F *h1 = (TH1F*)f1->Get(hist_name.Data());  
  // Run 11799 (de-focused)
  h1->Draw("hist");
  h1->SetLineColor(kBlack);
  h1->SetFillStyle(3004);
  h1->SetFillColorAlpha(kBlack, 0.4);
  h1->GetYaxis()->SetRangeUser(0.001, 1e6);
 

    
  TFile *f2 = new TFile(s2.Data(), "READ");
  TH1F *h2 = (TH1F*)f2->Get(hist_name.Data());
  // Run 11829 (Heep Kin A)
  h2->Draw("hist same");  
  h2->SetLineColor(kBlue);
  h2->SetFillStyle(3004);
  h2->SetFillColorAlpha(kBlue, 0.4);

  // Run 11847 (Heep Kin B)
  TFile *f3 = new TFile(s3.Data(), "READ");
  TH1F *h3 = (TH1F*)f3->Get(hist_name.Data());
  h3->Draw("same");
  h3->SetLineColor(kGreen);
  h3->SetFillStyle(3004);
  h3->SetFillColorAlpha(kGreen, 0.4);
  
  // Run 11883 (PION-LT Physics KIN-I)
  TFile *f4 = new TFile(s4.Data(), "READ");
  TH1F *h4 = (TH1F*)f4->Get(hist_name.Data());
  h4->Draw("same");
  h4->SetLineColor(kMagenta);
  h4->SetFillStyle(3004);
  h4->SetFillColorAlpha(kMagenta, 0.4);

  // Run 11799 (PION-LT Physics KIN-II)
  TFile *f5 = new TFile(s5.Data(), "READ");
  TH1F *h5 = (TH1F*)f5->Get(hist_name.Data());
  h5->Draw("same");
  h5->SetLineColor(kRed);
  h5->SetFillStyle(3004);
  h5->SetFillColorAlpha(kRed, 0.4);

  TLine l(ref_cut, y_min, ref_cut, y_max);
  l.SetLineStyle(9);
  l.SetLineWidth(2);
  l.Draw();

  TLine l2(new_ref_cut, y_min, new_ref_cut, y_max);
  l2.SetLineColor(kRed);
  l2.SetLineStyle(9);
  l2.SetLineWidth(2);
  l2.Draw("same");
  
  TString fout_name = hist_name +".pdf";

  c1->SaveAs(fout_name.Data());
    
}

void make_plot(){
  //hist_names = "hT1_ref_CUT", "hDC1_refTime_CUT", "hFADC_ref_CUT", "pT1_ref_CUT"   "pT2_ref_CUT", "pDC1_refTime_CUT", "pFADC_ref_CUT"

  make_histos("hT1_ref_CUT");
    
  make_histos("hDC1_refTime_CUT");
  make_histos("hDC2_refTime_CUT");
  make_histos("hDC3_refTime_CUT");
  make_histos("hDC4_refTime_CUT");


  
  make_histos("hFADC_ref_CUT");
  
  make_histos("pT1_ref_CUT");
  make_histos("pT2_ref_CUT");
  
  make_histos("pDC1_refTime_CUT");
  make_histos("pDC2_refTime_CUT");
  make_histos("pDC3_refTime_CUT");
  make_histos("pDC4_refTime_CUT");
  make_histos("pDC5_refTime_CUT");
  make_histos("pDC6_refTime_CUT");
  make_histos("pDC7_refTime_CUT");
  make_histos("pDC8_refTime_CUT");
  make_histos("pDC9_refTime_CUT");
  make_histos("pDC10_refTime_CUT");

  
  make_histos("pFADC_ref_CUT");
  
}

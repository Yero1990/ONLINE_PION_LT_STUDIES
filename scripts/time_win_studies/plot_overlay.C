void overlay_histos(TString hist_name=""){

  
  /*
    Description: This script takes as input a histogram object name,
    and reads that histogram from pre-defined ROOTfiles the user chooses.
    These histograms from the different files are then overlayed for a
    direct comparison. The histograms MUST have the same dimensions (bins, range)
   */
  
  gROOT->SetBatch(kTRUE);
  gROOT->ForceStyle();
  gStyle->SetOptStat(0);

  //Boolean to overlay refTimes or det. time windows
  Bool_t refTimes = false;
  Bool_t timeWin = true;

  TString s1;
  TString s2;
  TString s3;
  TString s4;
  TString s5;
  TString s6;

  TString s7;  //misc. run number to compare with heep elastics
  
  //--- run range from the first few kinematics taken during the PION-LT 2021 experiment---
  //black(11799), blue(11829), green(11847), magenta (11883), red (11947)

  //--- H(e,e'p) singles PION-LT 2021 runs
  // black (12080), blue (12084), green (12086), magenta (12090), red (12092), violet (12094)

  if(refTimes){
    s1 = "./heep_elastics/Time_cuts_refTime12080/refTime_coin_histos_run12080.root";
    s2 = "./heep_elastics/Time_cuts_refTime12084/refTime_coin_histos_run12084.root";
    s3 = "./heep_elastics/Time_cuts_refTime12086/refTime_coin_histos_run12086.root";
    s4 = "./heep_elastics/Time_cuts_refTime12090/refTime_coin_histos_run12090.root";
    s5 = "./heep_elastics/Time_cuts_refTime12092/refTime_coin_histos_run12092.root";
    s6 = "./heep_elastics/Time_cuts_refTime12094/refTime_coin_histos_run12094.root";

    s7 = "./misc_runs/Time_cuts_refTime12269/refTime_coin_histos_run12269.root";

  }

  if(timeWin){
    s1 = "./heep_elastics/Time_cuts_tWinSet12080/detTimeWin_coin_histos_run12080.root";
    s2 = "./heep_elastics/Time_cuts_tWinSet12084/detTimeWin_coin_histos_run12084.root";
    s3 = "./heep_elastics/Time_cuts_tWinSet12086/detTimeWin_coin_histos_run12086.root";
    s4 = "./heep_elastics/Time_cuts_tWinSet12090/detTimeWin_coin_histos_run12090.root";
    s5 = "./heep_elastics/Time_cuts_tWinSet12092/detTimeWin_coin_histos_run12092.root";
    s6 = "./heep_elastics/Time_cuts_tWinSet12094/detTimeWin_coin_histos_run12094.root";

    s7 = "./misc_runs/Time_cuts_tWinSet12269/detTimeWin_coin_histos_run12269.root";


  }
  
  TCanvas *c1 = new TCanvas();

  //initialize plot limits and ref_time TLine range (in case they need to be set)
  Float_t y_min = 0.1;
  Float_t y_max = 1.e5; 

  Double_t ref_cut = -1.e06;
  Double_t new_ref_cut = -1.e06;

  if(refTimes){
    if(hist_name=="hT1_ref_CUT"){
      //ref_cut = 1500.;
      new_ref_cut = 2400.;
    }
    
    else if(hist_name=="hDC1_refTime_CUT"|| hist_name=="hDC2_refTime_CUT"|| hist_name=="hDC3_refTime_CUT"|| hist_name=="hDC4_refTime_CUT"){
      //ref_cut = 10000.;
      new_ref_cut = 14500.;
    }
    
    else if(hist_name=="hFADC_ref_CUT"){
      //ref_cut = 2000.;
      new_ref_cut = 3200.;
      
    }
    
    else if(hist_name=="pT1_ref_CUT" || hist_name=="pT2_ref_CUT"){
      //ref_cut = 2000.;
      new_ref_cut = 3700.;
    }
    
    else if(hist_name=="pDC1_refTime_CUT"||hist_name=="pDC2_refTime_CUT"||hist_name=="pDC3_refTime_CUT"||hist_name=="pDC4_refTime_CUT"||hist_name=="pDC5_refTime_CUT"||hist_name=="pDC6_refTime_CUT"||hist_name=="pDC7_refTime_CUT"||hist_name=="pDC8_refTime_CUT"||hist_name=="pDC9_refTime_CUT"||hist_name=="pDC10_refTime_CUT"){
      //ref_cut = 10000.;
      new_ref_cut = 14000.;
      
    }
    
    else if(hist_name=="pFADC_ref_CUT"){
      //ref_cut = 2000.;
      new_ref_cut = 4500.;
      
    }
  }
  
  c1->SetLogy();

  //----Plot and Overlay Histograms specified by hist_name ----
  // (this works in general for any histogram)
  /*
  TFile *f1 = new TFile(s1.Data(), "READ");
  TH1F *h1 = (TH1F*)f1->Get(hist_name.Data());  
  cout << hist_name.Data() << endl;
  cout << "filename = " << s1.Data() << endl;
  h1->Draw("hist");
  
  h1->SetLineColor(kBlack);
  h1->SetFillStyle(3004);
  h1->SetFillColorAlpha(kBlack, 0.4);
  h1->GetYaxis()->SetRangeUser(0.001, 1e6);
   
  TFile *f2 = new TFile(s2.Data(), "READ");
  TH1F *h2 = (TH1F*)f2->Get(hist_name.Data());
  h2->Draw("hist same");  
  h2->SetLineColor(kBlue);
  h2->SetFillStyle(3004);
  h2->SetFillColorAlpha(kBlue, 0.4);

  TFile *f3 = new TFile(s3.Data(), "READ");
  TH1F *h3 = (TH1F*)f3->Get(hist_name.Data());
  h3->Draw("same");
  h3->SetLineColor(kGreen);
  h3->SetFillStyle(3004);
  h3->SetFillColorAlpha(kGreen, 0.4);
  
  TFile *f4 = new TFile(s4.Data(), "READ");
  TH1F *h4 = (TH1F*)f4->Get(hist_name.Data());
  h4->Draw("same");
  h4->SetLineColor(kMagenta);
  h4->SetFillStyle(3004);
  h4->SetFillColorAlpha(kMagenta, 0.4);

  TFile *f5 = new TFile(s5.Data(), "READ");
  TH1F *h5 = (TH1F*)f5->Get(hist_name.Data());
  h5->Draw("same");
  h5->SetLineColor(kRed);
  h5->SetFillStyle(3004);
  h5->SetFillColorAlpha(kRed, 0.4);
  */
  
  TFile *f6 = new TFile(s6.Data(), "READ");
  TH1F *h6 = (TH1F*)f6->Get(hist_name.Data());
  //h6->Draw("same");
  h6->Draw("hist");
  //h6->SetLineColor(kViolet);
  h6->SetLineColor(kBlack);
  h6->SetFillStyle(3004);
  h6->SetFillColorAlpha(kBlack, 0.4);
  //h6->SetFillColorAlpha(kViolet, 0.4);

  TFile *f7 = new TFile(s7.Data(), "READ");
  TH1F *h7 = (TH1F*)f7->Get(hist_name.Data());
  h7->Draw("same");
  h7->SetLineColor(kRed);
  h7->SetFillStyle(3004);
  h7->SetFillColorAlpha(kRed, 0.4);
  
  //TLine l(ref_cut, y_min, ref_cut, y_max);
  //l.SetLineStyle(9);
  //l.SetLineWidth(2);
  //l.Draw();
  
  //TLine l2(new_ref_cut, y_min, new_ref_cut, y_max);
  //l2.SetLineColor(kRed);
  //l2.SetLineStyle(9);
  //l2.SetLineWidth(2);
  //l2.Draw();
  
  
  TString fout_name = "./overlayed_plots/" + hist_name +".pdf";

  c1->SaveAs(fout_name.Data());
    
}

void plot_overlay(){

  //Plot ref times for various runs

  /*
  overlay_histos("hT1_ref_CUT");
  overlay_histos("hDC1_refTime_CUT");
  overlay_histos("hFADC_ref_CUT");
  overlay_histos("pT1_ref_CUT");
  overlay_histos("pT2_ref_CUT");
  overlay_histos("pDC1_refTime_CUT");
  overlay_histos("pFADC_ref_CUT");
  */
  //hist_names = "hT1_ref_CUT", "hDC1_refTime_CUT", "hFADC_ref_CUT", "pT1_ref_CUT"   "pT2_ref_CUT", "pDC1_refTime_CUT", "pFADC_ref_CUT"



  //Plot specific detector time windows (overlayed for each PION LT kin)
  
  
  //---HMS----

  //HMS Cherenkov
  overlay_histos("hCER1_timeDiff_CUT");
  overlay_histos("hCER2_timeDiff_CUT");

  //HMS DC
  overlay_histos("hDC1u1_rawTDC_CUT");
  overlay_histos("hDC1u2_rawTDC_CUT");
  overlay_histos("hDC1x1_rawTDC_CUT");
  overlay_histos("hDC1x2_rawTDC_CUT");
  overlay_histos("hDC1v2_rawTDC_CUT");
  overlay_histos("hDC1v1_rawTDC_CUT");

  overlay_histos("hDC2u1_rawTDC_CUT");
  overlay_histos("hDC2u2_rawTDC_CUT");
  overlay_histos("hDC2x1_rawTDC_CUT");
  overlay_histos("hDC2x2_rawTDC_CUT");
  overlay_histos("hDC2v2_rawTDC_CUT");
  overlay_histos("hDC2v1_rawTDC_CUT");
  

  //HMS HODO

  //plot hodo paddles 3
  overlay_histos("hHod1x3+_timeDiff_CUT");
  overlay_histos("hHod1x3-_timeDiff_CUT");
  overlay_histos("hHod1y3+_timeDiff_CUT");
  overlay_histos("hHod1y3-_timeDiff_CUT");

  overlay_histos("hHod2x3+_timeDiff_CUT");
  overlay_histos("hHod2x3-_timeDiff_CUT");
  overlay_histos("hHod2y3+_timeDiff_CUT");
  overlay_histos("hHod2y3-_timeDiff_CUT");
  
  //plot hodo paddles 7
  overlay_histos("hHod1x7+_timeDiff_CUT");
  overlay_histos("hHod1x7-_timeDiff_CUT");
  overlay_histos("hHod1y7+_timeDiff_CUT");
  overlay_histos("hHod1y7-_timeDiff_CUT");

  overlay_histos("hHod2x7+_timeDiff_CUT");
  overlay_histos("hHod2x7-_timeDiff_CUT");
  overlay_histos("hHod2y7+_timeDiff_CUT");
  overlay_histos("hHod2y7-_timeDiff_CUT");

  //plot hodo paddles 10
  overlay_histos("hHod1x10+_timeDiff_CUT");
  overlay_histos("hHod1x10-_timeDiff_CUT");
  overlay_histos("hHod1y10+_timeDiff_CUT");
  overlay_histos("hHod1y10-_timeDiff_CUT");

  overlay_histos("hHod2x10+_timeDiff_CUT");
  overlay_histos("hHod2x10-_timeDiff_CUT");
  overlay_histos("hHod2y10+_timeDiff_CUT");
  overlay_histos("hHod2y10-_timeDiff_CUT");


  
  //HMS CAL

  //plot block 3
  overlay_histos("hCal1pr3+_timeDiff_CUT");
  overlay_histos("hCal1pr3-_timeDiff_CUT");
  overlay_histos("hCal2ta3+_timeDiff_CUT");
  overlay_histos("hCal2ta3-_timeDiff_CUT");
  overlay_histos("hCal3ta3+_timeDiff_CUT");
  overlay_histos("hCal4ta3+_timeDiff_CUT");
  
  //plot block 7
  overlay_histos("hCal1pr7+_timeDiff_CUT");
  overlay_histos("hCal1pr7-_timeDiff_CUT");
  overlay_histos("hCal2ta7+_timeDiff_CUT");
  overlay_histos("hCal2ta7-_timeDiff_CUT");
  overlay_histos("hCal3ta7+_timeDiff_CUT");
  overlay_histos("hCal4ta7+_timeDiff_CUT");

  //plot block 10
  overlay_histos("hCal1pr10+_timeDiff_CUT");
  overlay_histos("hCal1pr10-_timeDiff_CUT");
  overlay_histos("hCal2ta10+_timeDiff_CUT");
  overlay_histos("hCal2ta10-_timeDiff_CUT");
  overlay_histos("hCal3ta10+_timeDiff_CUT");
  overlay_histos("hCal4ta10+_timeDiff_CUT");
  
  //-----------------------------------
  
  //SHMS NGCER
  overlay_histos("pNGCER1_timeDiff_CUT");
  overlay_histos("pNGCER2_timeDiff_CUT");
  overlay_histos("pNGCER3_timeDiff_CUT");
  overlay_histos("pNGCER4_timeDiff_CUT");

  //SHMS HGCER
  overlay_histos("pHGCER1_timeDiff_CUT");
  overlay_histos("pHGCER2_timeDiff_CUT");
  overlay_histos("pHGCER3_timeDiff_CUT");
  overlay_histos("pHGCER4_timeDiff_CUT");

  //SHMS DC
  overlay_histos("pDC1u1_rawTDC_CUT");
  overlay_histos("pDC1u2_rawTDC_CUT");
  overlay_histos("pDC1x1_rawTDC_CUT");
  overlay_histos("pDC1x2_rawTDC_CUT");
  overlay_histos("pDC1v2_rawTDC_CUT");
  overlay_histos("pDC1v1_rawTDC_CUT");

  overlay_histos("pDC2u1_rawTDC_CUT");
  overlay_histos("pDC2u2_rawTDC_CUT");
  overlay_histos("pDC2x1_rawTDC_CUT");
  overlay_histos("pDC2x2_rawTDC_CUT");
  overlay_histos("pDC2v2_rawTDC_CUT");
  overlay_histos("pDC2v1_rawTDC_CUT");
  
  //SHMS HODO

  //plot hodo paddle 3
  overlay_histos("pHod1x3+_timeDiff_CUT");
  overlay_histos("pHod1x3-_timeDiff_CUT");
  overlay_histos("pHod1y3+_timeDiff_CUT");
  overlay_histos("pHod1y3+_timeDiff_CUT");

  overlay_histos("pHod2x3+_timeDiff_CUT");
  overlay_histos("pHod2x3-_timeDiff_CUT");
  overlay_histos("pHod2y3+_timeDiff_CUT");
  overlay_histos("pHod2y3+_timeDiff_CUT");

  
  //plot hodo paddle 7
  overlay_histos("pHod1x7+_timeDiff_CUT");
  overlay_histos("pHod1x7-_timeDiff_CUT");
  overlay_histos("pHod1y7+_timeDiff_CUT");
  overlay_histos("pHod1y7+_timeDiff_CUT");

  overlay_histos("pHod2x7+_timeDiff_CUT");
  overlay_histos("pHod2x7-_timeDiff_CUT");
  overlay_histos("pHod2y7+_timeDiff_CUT");
  overlay_histos("pHod2y7+_timeDiff_CUT");

  //plot hodo paddle 10
  overlay_histos("pHod1x10+_timeDiff_CUT");
  overlay_histos("pHod1x10-_timeDiff_CUT");
  overlay_histos("pHod1y10+_timeDiff_CUT");
  overlay_histos("pHod1y10+_timeDiff_CUT");

  overlay_histos("pHod2x10+_timeDiff_CUT");
  overlay_histos("pHod2x10-_timeDiff_CUT");
  overlay_histos("pHod2y10+_timeDiff_CUT");
  overlay_histos("pHod2y10+_timeDiff_CUT");

  
  // SHMS CAL

  overlay_histos("pPrSh_pmt7+_CUT");
  overlay_histos("pPrSh_pmt7-_CUT");

  overlay_histos("pSh_pmt8_CUT");
  overlay_histos("pSh_pmt16_CUT");
  overlay_histos("pSh_pmt24_CUT");
  overlay_histos("pSh_pmt32_CUT");
  overlay_histos("pSh_pmt40_CUT");
  overlay_histos("pSh_pmt48_CUT");
  overlay_histos("pSh_pmt56_CUT");
  overlay_histos("pSh_pmt64_CUT");
  overlay_histos("pSh_pmt72_CUT");
  overlay_histos("pSh_pmt80_CUT");
  overlay_histos("pSh_pmt88_CUT");
  overlay_histos("pSh_pmt96_CUT");
  overlay_histos("pSh_pmt104_CUT");
  overlay_histos("pSh_pmt112_CUT");
  overlay_histos("pSh_pmt120_CUT");
  overlay_histos("pSh_pmt128_CUT");
  overlay_histos("pSh_pmt136_CUT");
  overlay_histos("pSh_pmt144_CUT");
  overlay_histos("pSh_pmt152_CUT");  
  overlay_histos("pSh_pmt160_CUT");
  
  
}

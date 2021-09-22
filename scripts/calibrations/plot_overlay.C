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
  TString s0;
  TString s1;
  TString s2;
  TString s3;
  TString s4;
  TString s5;
  TString s6;

  TString s7;
  
  //--- run range from the first few kinematics taken during the PION-LT 2021 experiment---
  //black(11799), blue(11829), green(11847), magenta (11883), red (11947)

  //--- H(e,e'p) singles PION-LT 2021 runs
  //black (dashed, 12079) black (12080), blue (12084), green (12086), magenta (12090), red (12092), violet (12094)

  //--- BAD SHMS DC CALIB STUDY (presumably bad drift times at some point)
  
  s0 = "./checkCalib_11799_original/checkCalib_histos11799.root";  //original 11799 calibration
  s1 = "./checkCalib_11799_new/checkCalib_histos11799.root";           //new 11799 calibration
  s2 = "./checkCalib_12288_new/checkCalib_histos12288.root";  //new 11799 calib (test run 12288)

  s3 = "./checkCalib_12259/checkCalib_histos12259.root";
  s4 = "./checkCalib_12260/checkCalib_histos12260.root";
  s5 = "./checkCalib_12261/checkCalib_histos12261.root";   //EXTREMELY BAD DRIFT TIME STAR (COLOR-CODE RED)
  s6 = "./checkCalib_12280/checkCalib_histos12280.root";
  s7 = "./checkCalibs_badSHMSdc_study_Cuts/checkCalib_12288/checkCalib_histos12288.root"; //original 11799 calibration (test run12288)



  
  
  TCanvas *c1 = new TCanvas();  
  //c1->SetLogy();

  //----Plot and Overlay Histograms specified by hist_name ----
  // (this works in general for any histogram)

  /*
  TFile *f0 = new TFile(s0.Data(), "READ");
  TH1F *h0 = (TH1F*)f0->Get(hist_name.Data());     
  h0->SetLineColor(kBlack);
  h0->SetLineStyle(2); //dashed
  h0->SetLineWidth(3);
  h0->SetFillStyle(3004);
  h0->SetFillColorAlpha(kBlack, 0.4);
  h0->DrawNormalized("hist");
  
  
  TFile *f1 = new TFile(s1.Data(), "READ");
  TH1F *h1 = (TH1F*)f1->Get(hist_name.Data());  
  h1->SetLineColor(kBlue);
  h1->SetFillStyle(3004);
  h1->SetLineWidth(3);
  h1->SetFillColorAlpha(kBlue, 0.4);
  h1->DrawNormalized("same");
  */
  TFile *f2 = new TFile(s2.Data(), "READ");
  TH1F *h2 = (TH1F*)f2->Get(hist_name.Data());
  h2->SetLineColor(kRed);
  h2->SetFillStyle(3004);
  h2->SetLineWidth(3);
  h2->SetFillColorAlpha(kRed, 0.4);
  h2->Draw("hist");  
  /*
  TFile *f3 = new TFile(s3.Data(), "READ");
  TH1F *h3 = (TH1F*)f3->Get(hist_name.Data());
  h3->SetLineColor(kViolet);
  h3->SetFillStyle(3004);
  h3->SetLineWidth(3);
  h3->SetFillColorAlpha(kViolet, 0.4);
  h3->DrawNormalized("same");
  
  TFile *f4 = new TFile(s4.Data(), "READ");
  TH1F *h4 = (TH1F*)f4->Get(hist_name.Data());
  h4->SetLineColor(kRed);
  h4->SetLineStyle(2); //dashed
  h4->SetFillStyle(3004);
  h4->SetLineWidth(3);
  h4->SetFillColorAlpha(kRed, 0.4);
  h4->DrawNormalized("same");

  TFile *f5 = new TFile(s5.Data(), "READ");
  TH1F *h5 = (TH1F*)f5->Get(hist_name.Data());
  h5->SetLineColor(kRed);
  h5->SetFillStyle(3004);
  h5->SetLineWidth(3);
  h5->SetFillColorAlpha(kRed, 0.4);
  h5->DrawNormalized("same");
  
  
  TFile *f6 = new TFile(s6.Data(), "READ");
  TH1F *h6 = (TH1F*)f6->Get(hist_name.Data());
  h6->SetLineColor(kMagenta);
  h6->SetFillStyle(3004);
  h6->SetLineWidth(3);
  h6->SetFillColorAlpha(kMagenta, 0.4);
  h6->DrawNormalized("same");
  */
 
  TFile *f7 = new TFile(s7.Data(), "READ");
  TH1F *h7 = (TH1F*)f7->Get(hist_name.Data());
  h7->SetLineColor(kBlue);
  h7->SetFillStyle(3004);
  h7->SetLineWidth(3);
  h7->SetFillColorAlpha(kBlue, 0.4);
  h7->Draw("same");
  
  
  TString fout_name = "./overlayed_plots/" + hist_name +".pdf";

  c1->SaveAs(fout_name.Data());
    
}

void plot_overlay(){

  //Plot specific calibration plots (overlayed for each PION LT kin)

  //----HMS-----

  /*
  //cherenkov
  overlay_histos("hCER_pmt1");
  overlay_histos("hCER_pmt2");

  //hodo
  overlay_histos("hHod_Beta");
  */

  
  //dc

  //drift times
  overlay_histos("hDC_1u1_DriftTime");
  overlay_histos("hDC_1u2_DriftTime");
  overlay_histos("hDC_1v1_DriftTime");
  overlay_histos("hDC_1v1_DriftTime");
  overlay_histos("hDC_1x1_DriftTime");
  overlay_histos("hDC_1x2_DriftTime");

  overlay_histos("hDC_2u1_DriftTime");
  overlay_histos("hDC_2u2_DriftTime");
  overlay_histos("hDC_2v1_DriftTime");
  overlay_histos("hDC_2v1_DriftTime");
  overlay_histos("hDC_2x1_DriftTime");
  overlay_histos("hDC_2x2_DriftTime");  

  //drift distances
  overlay_histos("hDC_1u1_DriftDist");
  overlay_histos("hDC_1u2_DriftDist");
  overlay_histos("hDC_1v1_DriftDist");
  overlay_histos("hDC_1v2_DriftDist");
  overlay_histos("hDC_1x1_DriftDist");
  overlay_histos("hDC_1x2_DriftDist");

  overlay_histos("hDC_2u1_DriftDist");
  overlay_histos("hDC_2u2_DriftDist");
  overlay_histos("hDC_2v1_DriftDist");
  overlay_histos("hDC_2v2_DriftDist");
  overlay_histos("hDC_2x1_DriftDist");
  overlay_histos("hDC_2x2_DriftDist");

  //drift residuals
  overlay_histos("hDC_1u1_DriftResiduals");
  overlay_histos("hDC_1u2_DriftResiduals");
  overlay_histos("hDC_1v1_DriftResiduals");
  overlay_histos("hDC_1v2_DriftResiduals");
  overlay_histos("hDC_1x1_DriftResiduals");
  overlay_histos("hDC_1x2_DriftResiduals");

  overlay_histos("hDC_2u1_DriftResiduals");
  overlay_histos("hDC_2u2_DriftResiduals");
  overlay_histos("hDC_2v1_DriftResiduals");
  overlay_histos("hDC_2v2_DriftResiduals");
  overlay_histos("hDC_2x1_DriftResiduals");
  overlay_histos("hDC_2x2_DriftResiduals");
  
  
  /*
  overlay_histos("hDC_1u1_DriftResiduals");

  overlay_histos("hDC_2u1_DriftTime");
  overlay_histos("hDC_2u1_DriftDist");
  overlay_histos("hDC_2u1_DriftResiduals");
  */
  
  //cal
  //overlay_histos("hCal_eTrkNorm");
  overlay_histos("hCal_eTot");

  //----SHMS-----

  /*
  //cherenkov
  overlay_histos("pNGCER_pmt1");
  overlay_histos("pNGCER_pmt2");
  overlay_histos("pNGCER_pmt3");
  overlay_histos("pNGCER_pmt4");

  overlay_histos("pHGCER_pmt1");
  overlay_histos("pHGCER_pmt2");
  overlay_histos("pHGCER_pmt3");
  overlay_histos("pHGCER_pmt4");
  
  //hodo
  overlay_histos("pHod_Beta");
  */
  //dc
  //drift times
  overlay_histos("pDC_1u1_DriftTime");
  overlay_histos("pDC_1u2_DriftTime");
  overlay_histos("pDC_1v1_DriftTime");
  overlay_histos("pDC_1v2_DriftTime");
  overlay_histos("pDC_1x1_DriftTime");
  overlay_histos("pDC_1x2_DriftTime");
  
  overlay_histos("pDC_2u1_DriftTime");
  overlay_histos("pDC_2u2_DriftTime");
  overlay_histos("pDC_2v1_DriftTime");
  overlay_histos("pDC_2v2_DriftTime");
  overlay_histos("pDC_2x1_DriftTime");
  overlay_histos("pDC_2x2_DriftTime");
  
    //drift distances
  overlay_histos("pDC_1u1_DriftDist");
  overlay_histos("pDC_1u2_DriftDist");
  overlay_histos("pDC_1v1_DriftDist");
  overlay_histos("pDC_1v2_DriftDist");
  overlay_histos("pDC_1x1_DriftDist");
  overlay_histos("pDC_1x2_DriftDist");

  overlay_histos("pDC_2u1_DriftDist");
  overlay_histos("pDC_2u2_DriftDist");
  overlay_histos("pDC_2v1_DriftDist");
  overlay_histos("pDC_2v2_DriftDist");
  overlay_histos("pDC_2x1_DriftDist");
  overlay_histos("pDC_2x2_DriftDist");

  //drift residuals
  overlay_histos("pDC_1u1_DriftResiduals");
  overlay_histos("pDC_1u2_DriftResiduals");
  overlay_histos("pDC_1v1_DriftResiduals");
  overlay_histos("pDC_1v2_DriftResiduals");
  overlay_histos("pDC_1x1_DriftResiduals");
  overlay_histos("pDC_1x2_DriftResiduals");

  overlay_histos("pDC_2u1_DriftResiduals");
  overlay_histos("pDC_2u2_DriftResiduals");
  overlay_histos("pDC_2v1_DriftResiduals");
  overlay_histos("pDC_2v2_DriftResiduals");
  overlay_histos("pDC_2x1_DriftResiduals");
  overlay_histos("pDC_2x2_DriftResiduals");

  
  /*
  overlay_histos("pDC_1u1_DriftResiduals");

  overlay_histos("pDC_2u1_DriftTime");
  overlay_histos("pDC_2u1_DriftDist");
  overlay_histos("pDC_2u1_DriftResiduals");
  */
  //cal
  //overlay_histos("pCal_eTrkNorm");
  overlay_histos("hCal_eTot");

    
}

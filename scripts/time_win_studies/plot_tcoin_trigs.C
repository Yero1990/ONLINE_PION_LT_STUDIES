void plot_tcoin_trigs(){

  /*
    Description: This script takes as input a histogram object name,
    and reads that histogram from pre-defined ROOTfiles the user chooses.
    These histograms from the different files are then overlayed for a
    direct comparison. The histograms MUST have the same dimensions (bins, range)

   */
  
  gROOT->ForceStyle();
  gStyle->SetOptStat(0);
  
  //black(11799), blue(11829), green(11847), magenta (11883), red (11947)


  TString s1 = "../../time_win_study/ROOTfiles/ref_times_set/Pion_coin_replay_timeWin_check_cyero_11799_-1.root";

  TFile *f1 = new TFile(s1.Data(), "READ");
  TTree *T1 = (TTree*)f1->Get("T");

  TCanvas *c1 = new TCanvas();
  
  c1->cd();
  c1->SetLogy();

  T1->Draw("T.coin.pTRIG1_ROC2_tdcTimeRaw(100, 0, 12000)", );
  
  
  /*
  TString s2 = "1829.root";
  TString s3 = "11847.root";
  TString s4 = "11883.root";
  TString s5 = "11947.root";

  TCanvas *c1 = new TCanvas();

  
  c1->SetLogy();
  */
  
  /*
  TFile *f1 = new TFile(s1.Data(), "READ");
  TH1F *h1 = (TH1F*)f1->Get(hist_name.Data());  
  cout << hist_name.Data() << endl;
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

  TString fout_name = "./plots/" + hist_name +".pdf";

  c1->SaveAs(fout_name.Data());
  */
}

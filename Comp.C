void Comp(){

    int const Nplots = 20;
    
    gStyle->SetOptStat(kFALSE);
    gStyle->SetOptStat(0000);
    gStyle->SetOptFit(0000);
    gStyle->SetFillColor(0);
    gStyle->SetPadColor(0);
    gStyle->SetCanvasColor(0);
    gStyle->SetStatColor(0);
    gStyle->SetTitleColor(0);
    gStyle->SetPadBorderMode(0);
    gStyle->SetPadBottomMargin(0.15);
    gStyle->SetPadLeftMargin(0.17);
    gStyle->SetPadRightMargin(0.07);
    gStyle->SetFrameBorderMode(0);
    gStyle->SetCanvasBorderMode(0);
    
    // open files:
    TFile *f1 = new TFile("DataFromPNFS/output_filter_00_01_17_83_numFiles_1_badFoM_targScan.root","read");
    TFile *f2 = new TFile("DataFromPNFS/output_filter_00_01_17_83_numFiles_1_goodFoM_targScan.root","read");
    
    //--------------------------
    // Read histograms:
    TH2F *h1[30];
    TH2F *h2[30];
    
    h1[0] = (TH2F*)f1->Get("h_hp875_vs_fom");
    h2[0] = (TH2F*)f2->Get("h_hp875_vs_fom");
    
    h1[1] = (TH2F*)f1->Get("h_vp875_vs_fom");
    h2[1] = (TH2F*)f2->Get("h_vp875_vs_fom");
    
    //fom vs lm
    h1[2] = (TH2F*)f1->Get("h_fom_vs_lm875a");
    h2[2] = (TH2F*)f2->Get("h_fom_vs_lm875a");

    h1[3] = (TH2F*)f1->Get("h_fom_vs_lm875b");
    h2[3] = (TH2F*)f2->Get("h_fom_vs_lm875b");
    
    h1[4] = (TH2F*)f1->Get("h_fom_vs_lm875c");
    h2[4] = (TH2F*)f2->Get("h_fom_vs_lm875c");
    // pos vs lm
    h1[5] = (TH2F*)f1->Get("h_horpos_vs_lm875a");
    h2[5] = (TH2F*)f2->Get("h_horpos_vs_lm875a");
    
    h1[6] = (TH2F*)f1->Get("h_horpos_vs_lm875b");
    h2[6] = (TH2F*)f2->Get("h_horpos_vs_lm875b");
    
    h1[7] = (TH2F*)f1->Get("h_horpos_vs_lm875c");
    h2[7] = (TH2F*)f2->Get("h_horpos_vs_lm875c");
    
    // angle H vs lm
    h1[8] = (TH2F*)f1->Get("h_horang_vs_lm875a");
    h2[8] = (TH2F*)f2->Get("h_horang_vs_lm875a");
    
    h1[9] = (TH2F*)f1->Get("h_horang_vs_lm875b");
    h2[9] = (TH2F*)f2->Get("h_horang_vs_lm875b");
    
    h1[10] = (TH2F*)f1->Get("h_horang_vs_lm875c");
    h2[10] = (TH2F*)f2->Get("h_horang_vs_lm875c");
    
    // r875 vs lm and fom
    h1[11] = (TH2F*)f1->Get("h_r875_vs_fom");
    h2[11] = (TH2F*)f2->Get("h_r875_vs_fom");
    
    h1[12] = (TH2F*)f1->Get("h_r875_vs_lm875a");
    h2[12] = (TH2F*)f2->Get("h_r875_vs_lm875a");
    
    h1[12] = (TH2F*)f1->Get("h_r875_vs_lm875b");
    h2[12] = (TH2F*)f2->Get("h_r875_vs_lm875b");
    
    h1[13] = (TH2F*)f1->Get("h_r875_vs_lm875c");
    h2[13] = (TH2F*)f2->Get("h_r875_vs_lm875c");
    
    // pos Ver vs lm
    h1[14] = (TH2F*)f1->Get("h_verpos_vs_lm875a");
    h2[14] = (TH2F*)f2->Get("h_verpos_vs_lm875a");
    
    h1[15] = (TH2F*)f1->Get("h_verpos_vs_lm875b");
    h2[15] = (TH2F*)f2->Get("h_verpos_vs_lm875b");
    
    h1[16] = (TH2F*)f1->Get("h_verpos_vs_lm875c");
    h2[16] = (TH2F*)f2->Get("h_verpos_vs_lm875c");
    
    // angle Ver vs lm
    h1[17] = (TH2F*)f1->Get("h_verang_vs_lm875a");
    h2[17] = (TH2F*)f2->Get("h_verang_vs_lm875a");
    
    h1[18] = (TH2F*)f1->Get("h_verang_vs_lm875b");
    h2[18] = (TH2F*)f2->Get("h_verang_vs_lm875b");
    
    h1[19] = (TH2F*)f1->Get("h_verang_vs_lm875c");
    h2[19] = (TH2F*)f2->Get("h_verang_vs_lm875c");
    
    // angle Ver vs lm
    h1[20] = (TH2F*)f1->Get("h_hp875_vs_lm875a");
    h2[20] = (TH2F*)f2->Get("h_hp875_vs_lm875a");
    
    h1[21] = (TH2F*)f1->Get("h_hp875_vs_lm875b");
    h2[21] = (TH2F*)f2->Get("h_hp875_vs_lm875b");
    
    h1[22] = (TH2F*)f1->Get("h_hp875_vs_lm875c");
    h2[22] = (TH2F*)f2->Get("h_hp875_vs_lm875c");
    
    //------------------------
    // Setup plot options:
    h2[0]->GetXaxis()->SetRange(0,1500);
    h2[1]->GetXaxis()->SetRange(0,1500);
    
    for(int i=0; i<23; i++){
        h1[i]->SetMarkerColor(2);
        h1[i]->SetMarkerStyle(2);
        h1[i]->SetMarkerSize(0.2);
        
        h2[i]->SetMarkerColor(1);
        h2[i]->SetMarkerStyle(3);
        h2[i]->SetMarkerSize(0.2);
    }
    
    // Open output file:
    TFile *output = new TFile("output_target_scan.root","recreate");
    
    // Plot histograms on canvas:
    TCanvas *c1[30];
    
    char name[100];
    
    for(int i=0; i<23; i++){
        sprintf(name,"c%d",i);
        
        c1[i] = new TCanvas(name," ",800,800);
        h2[i]->Draw();
        h1[i]->Draw("same");
        c1[i]->Write();
        
    }
    
}

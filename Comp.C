void Comp(){

    int const Nplots = 14;
    
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
    TFile *f1 = new TFile("DataFromPNFS/output_filter_00_01_11_10_numFiles_5_badFoM.root","read");
    TFile *f2 = new TFile("DataFromPNFS/output_filter_00_01_11_10_numFiles_5_goodFoM.root","read");
    
    //--------------------------
    // Read histograms:
    TH2F *h1[20];
    TH2F *h2[20];
    
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
    
    // angle vs lm
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
    
    h1[14] = (TH2F*)f1->Get("h_r875_vs_lm875c");
    h2[14] = (TH2F*)f2->Get("h_r875_vs_lm875c");
    
    //------------------------
    // Setup plot options:
    h2[0]->GetXaxis()->SetRange(0,1500);
    h2[1]->GetXaxis()->SetRange(0,1500);
    
    for(int i=0; i<15; i++){
        h1[i]->SetMarkerColor(2);
        h1[i]->SetMarkerStyle(2);
        h1[i]->SetMarkerSize(0.2);
        
        h2[i]->SetMarkerColor(1);
        h2[i]->SetMarkerStyle(3);
        h2[i]->SetMarkerSize(0.2);
    }
    
    // Plot histograms on cancas:
    TCanvas *c1[20];
    
    char name[100];
    
    for(int i=0; i<15; i++){
        sprintf(name,"c%d",i);
        
        c1[i] = new TCanvas(name," ",800,800);
        h2[i]->Draw();
        h1[i]->Draw("same");
        
    }
    
}

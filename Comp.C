void Comp(){

    int const Nplots = 20;
    
    gStyle->SetOptStat(0);
    //gStyle->SetOptStat(0000);
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
    TH2F *h1[40];
    TH2F *h2[40];
    
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
    
    // tg1 Ver vs lm
    h1[23] = (TH2F*)f1->Get("h_hptg1_vs_lm875a");
    h2[23] = (TH2F*)f2->Get("h_hptg1_vs_lm875a");
    
    h1[24] = (TH2F*)f1->Get("h_hptg1_vs_lm875b");
    h2[24] = (TH2F*)f2->Get("h_hptg1_vs_lm875b");
    
    h1[25] = (TH2F*)f1->Get("h_hptg1_vs_lm875c");
    h2[25] = (TH2F*)f2->Get("h_hptg1_vs_lm875c");
    
    // tg1 Ver vs lm
    h1[26] = (TH2F*)f1->Get("h_vptg1_vs_lm875a");
    h2[26] = (TH2F*)f2->Get("h_vptg1_vs_lm875a");
    
    h1[27] = (TH2F*)f1->Get("h_vptg1_vs_lm875b");
    h2[27] = (TH2F*)f2->Get("h_vptg1_vs_lm875b");
    
    h1[28] = (TH2F*)f1->Get("h_vptg1_vs_lm875c");
    h2[28] = (TH2F*)f2->Get("h_vptg1_vs_lm875c");
    
    // vp875 --
    h1[29] = (TH2F*)f1->Get("h_vp875_vs_lm875a");
    h2[29] = (TH2F*)f2->Get("h_vp875_vs_lm875a");
    
    h1[30] = (TH2F*)f1->Get("h_vp875_vs_lm875b");
    h2[30] = (TH2F*)f2->Get("h_vp875_vs_lm875b");
    
    h1[31] = (TH2F*)f1->Get("h_vp875_vs_lm875c");
    h2[31] = (TH2F*)f2->Get("h_vp875_vs_lm875c");
    //------------------------
    // Setup plot options:
    h2[0]->GetXaxis()->SetRange(0,1500);
    h2[1]->GetXaxis()->SetRange(0,1500);
    
    for(int i=0; i<32; i++){
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
    TCanvas *c1[40];
    
    char name[100];
    char name1[100];
    
    TLegend *leg[40];
    
    for(int i=0; i<32; i++){
        sprintf(name,"c%d",i);
        sprintf(name1,"Plots/c%d.png",i);

        c1[i] = new TCanvas(name," ",800,800);
        
        /*
        if(i>=2 && i <=10){
            //h1[i]->GetXaxis()->SetRange(1, 200);
            //h1[i]->GetXaxis()->SetRange(1, 200);
            h2[i]->Draw();
            h1[i]->Draw("same");
        }else{
            h2[i]->Draw();
            h1[i]->Draw("same");
        }
        
        leg[i] = new TLegend(0.6, 0.7, 0.85, 0.82);
        leg[i]->SetFillColor(0);
        leg[i]->SetBorderSize(0);
        leg[i]->SetTextSize(0.037);
        leg[i]->AddEntry(h1[i],"Bad FoM","p");
        leg[i]->AddEntry(h2[i],"Good FoM","p");
        leg[i]->Draw();
        */
        h2[i]->Draw();
        h1[i]->Draw("same");
        
        c1[i]->Modified();
        c1[i]->Update();
        
        c1[i]->Write();
        c1[i]->SaveAs(name1);
        
    }
    
}

void DataFilter(){
    unsigned int fileOrder = 10;
    int NdataFiles = 1;
    
    TFile *fin;
    TTree *tin;
    char name[500];
    
    //offsets:
    double hp875_offset= -3.40271;
    double vp875_offset= +1.47511;
    double hptg1_offset= +0.457014;
    double vptg1_offset= +0.38914; //mm
    double hptg2_offset= +0.8;
    double vptg2_offset= +1.0;
    //double hptg2_offset= +0.79;
    //double vptg2_offset= +1.02;
    double hp875_zpos= 202.116104; //m
    double vp875_zpos= 202.3193205;
    double hptg1_zpos= 204.833267;
    double vptg1_zpos= 204.629608;
    double hptg2_zpos= 205.240662;
    double vptg2_zpos= 205.036835;
    double target_center_zpos= 206.870895;
    //double p875x[]={0.431857, 0.158077, 0.00303551};
    //double p875y[]={0.279128, 0.337048, 0};
    //double p876x[]={0.166172, 0.30999, -0.00630299};
    //double p876y[]={0.13425, 0.580862, 0};
    
    // -- data variables:
    double tor860;
    double tor875;
    double hp875;
    double vp875;
    double hptg1;
    double vptg1;
    double hptg2;
    double vptg2;
    double lm875a;
    double lm875b;
    double lm875c;
    double mw875[96];
    double mw876[96];
    double mwtgt[96];
    float fom;
    
    //--- Define all histograms ---
    TH2F *h_vp875_vs_fom = new TH2F("h_vp875_vs_fom",";FOM;VP875 ",5000,0,5,1000,0,5);
    TH2F *h_hp875_vs_fom = new TH2F("h_hp875_vs_fom",";FOM;HP875 ",5000,0,5,1000,-5,0);
    TH2F *h_r875_vs_fom = new TH2F("h_r875_vs_fom",";FOM;r_{875} ",5000,0,5,1000,0,5);
    TH2F *h_rtg1_vs_fom = new TH2F("h_rtg1_vs_fom",";FOM;r_{TG1} ",5000,0,5.,1000,0,5);
    
    //lm875a:
    TH2F *h_r875_vs_lm875a = new TH2F("h_r875_vs_lm875a",";LM875a;r_{875} ",1000,0,.2,1000,0,5);
    TH2F *h_fom_vs_lm875a = new TH2F("h_fom_vs_lm875a",";LM875a;FOM ",5000,0,.2,1000,-5,5);
    TH2F *h_hp875_vs_lm875a = new TH2F("h_hp875_vs_lm875a",";LM875a;HP875 ",1000,0,.2,1000,-5,5);
    TH2F *h_hptg1_vs_lm875a = new TH2F("h_hptg1_vs_lm875a",";LM875a;HPTG1 ",1000,0,.2,1000,-5,5);
    TH2F *h_vp875_vs_lm875a = new TH2F("h_vp875_vs_lm875a",";LM875a;VP875 ",1000,0,.2,1000,-5,5);
    TH2F *h_vptg1_vs_lm875a = new TH2F("h_vptg1_vs_lm875a",";LM875a;VPTG1 ",1000,0,.2,1000,-5,5);
    TH2F *h_rtg1_vs_lm875a = new TH2F("h_rtg1_vs_lm875a",";LM875a;r_{TG1} ",1000,0,.2,1000,-5,5);
    TH2F *h_horang_vs_lm875a = new TH2F("h_horang_vs_lm875a",";LM875a;tan(#theta_{H}) ",1000,0,.2,1000,-0.01,0.01);
    TH2F *h_horpos_vs_lm875a = new TH2F("h_horpos_vs_lm875a",";LM875a;pos_{H} (mm) ",1000,0,.2,1000,-5,5);

    //lm875b:
    TH2F *h_r875_vs_lm875b = new TH2F("h_r875_vs_lm875b",";LM875b;r_{875} ",1000,0,.2,1000,0,5);
    TH2F *h_fom_vs_lm875b = new TH2F("h_fom_vs_lm875b",";LM875b;FOM ",1000,0,.2,1000,-5,5);
    TH2F *h_hp875_vs_lm875b = new TH2F("h_hp875_vs_lm875b",";LM875b;HP875 ",1000,0,.2,1000,-5,5);
    TH2F *h_hptg1_vs_lm875b = new TH2F("h_hptg1_vs_lm875b",";LM875b;HPTG1 ",1000,0,.2,1000,-5,5);
    TH2F *h_vp875_vs_lm875b = new TH2F("h_vp875_vs_lm875b",";LM875b;VP875 ",1000,0,.2,1000,-5,5);
    TH2F *h_vptg1_vs_lm875b = new TH2F("h_vptg1_vs_lm875b",";LM875b;VPTG1 ",1000,0,.2,1000,-5,5);
    TH2F *h_rtg1_vs_lm875b = new TH2F("h_rtg1_vs_lm875b",";LM875b;r_{TG1} ",1000,0,.2,1000,-5,5);
    TH2F *h_horang_vs_lm875b = new TH2F("h_horang_vs_lm875b",";LM875b;tan(#theta_{H}) ",1000,0,.2,1000,-0.01,0.01);
    TH2F *h_horpos_vs_lm875b = new TH2F("h_horpos_vs_lm875b",";LM875b;pos_{H} (mm) ",1000,0,.2,1000,-5,5);
    
    //lm875c:
    TH2F *h_r875_vs_lm875c = new TH2F("h_r875_vs_lm875c",";LM875c;r_{875} ",1000,0,.2,1000,0,5);
    TH2F *h_fom_vs_lm875c = new TH2F("h_fom_vs_lm875c",";LM875c;FOM ",1000,0,.2,1000,-5,5);
    TH2F *h_hp875_vs_lm875c = new TH2F("h_hp875_vs_lm875c",";LM875c;HP875 ",1000,0,.2,1000,-5,5);
    TH2F *h_hptg1_vs_lm875c = new TH2F("h_hptg1_vs_lm875c",";LM875c;HPTG1 ",1000,0,.2,1000,-5,5);
    TH2F *h_vp875_vs_lm875c = new TH2F("h_vp875_vs_lm875c",";LM875c;VP875 ",1000,0,.2,1000,-5,5);
    TH2F *h_vptg1_vs_lm875c = new TH2F("h_vptg1_vs_lm875c",";LM875c;VPTG1 ",1000,0,.2,1000,-5,5);
    TH2F *h_rtg1_vs_lm875c = new TH2F("h_rtg1_vs_lm875c",";LM875c;r_{TG1} ",1000,0,.2,1000,-5,5);
    TH2F *h_horang_vs_lm875c = new TH2F("h_horang_vs_lm875c",";LM875c;tan(#theta_{H}) ",1000,0,.2,1000,-0.01,0.01);
    TH2F *h_horpos_vs_lm875c = new TH2F("h_horpos_vs_lm875c",";LM875c;pos_{H} (mm) ",1000,0,.2,1000,-5,5);
    
    //-- loop over the files
    for(int i = 0; i<NdataFiles; i++){
        //--- Open files from the folders:
        sprintf(name,"../BPMandFOMstudy/FOMfromZarko/beamdata_0001%d26.root",fileOrder);
        cout<<" Open file: "<<name<<endl;
        fin = new TFile(name,"read");
        
        //-- Load data from the Tree:
        //Tree branches:
        tin = (TTree*)fin->Get("bnb");
        
        tin->SetBranchAddress("tor860",&tor860);
        tin->SetBranchAddress("tor875",&tor875);
        tin->SetBranchAddress("lm875a",&lm875a);
        tin->SetBranchAddress("lm875b",&lm875b);
        tin->SetBranchAddress("lm875c",&lm875c);
        tin->SetBranchAddress("hp875",&hp875);
        tin->SetBranchAddress("vp875",&vp875);
        tin->SetBranchAddress("hptg1",&hptg1);
        tin->SetBranchAddress("vptg1",&vptg1);
        tin->SetBranchAddress("hptg2",&hptg2);
        tin->SetBranchAddress("vptg2",&vptg2);
        tin->SetBranchAddress("m875bb",mw875);
        tin->SetBranchAddress("m876bb",mw876);
        tin->SetBranchAddress("mmbtbb",mwtgt);
        tin->SetBranchAddress("fom2",&fom);
        
        //-----------------
        // filling data for histograms:
        //-----------------
        // loop over the events:
        for(int j = 0; j<= tin->GetEntries(); j++){
         
            tin->GetEntry(j);
            //if(fom >0.95 || fom <0)
              //  continue;
            if(hp875 == -999)
                continue;
            
            double r_875 = sqrt(vp875*vp875 + hp875*hp875);
            h_r875_vs_fom->Fill(fom,r_875);
            
            double r_tg1 = sqrt(vptg1*vptg1 + hptg1*hptg1);
            h_rtg1_vs_fom->Fill(fom,r_tg1);
            
            h_vp875_vs_fom->Fill(fom,vp875);
            h_hp875_vs_fom->Fill(fom,hp875);
            
            h_hp875_vs_lm875a->Fill(lm875a,hp875);
            h_vp875_vs_lm875a->Fill(lm875a,vp875);
            h_hptg1_vs_lm875a->Fill(lm875a,hptg1);
            h_vptg1_vs_lm875a->Fill(lm875a,vptg1);
            
            h_hp875_vs_lm875b->Fill(lm875b,hp875);
            h_vp875_vs_lm875b->Fill(lm875b,vp875);
            h_hptg1_vs_lm875b->Fill(lm875b,hptg1);
            h_vptg1_vs_lm875b->Fill(lm875b,vptg1);
            
            h_hp875_vs_lm875c->Fill(lm875c,hp875);
            h_vp875_vs_lm875c->Fill(lm875c,vp875);
            h_hptg1_vs_lm875c->Fill(lm875c,hptg1);
            h_vptg1_vs_lm875c->Fill(lm875c,vptg1);
            
            h_rtg1_vs_lm875a->Fill(lm875a,r_tg1);
            h_rtg1_vs_lm875b->Fill(lm875b,r_tg1);
            h_rtg1_vs_lm875c->Fill(lm875c,r_tg1);
            
            h_r875_vs_lm875a->Fill(lm875a,r_875);
            h_fom_vs_lm875a->Fill(lm875a,fom);
            h_r875_vs_lm875b->Fill(lm875b,r_875);
            h_fom_vs_lm875b->Fill(lm875b,fom);
            h_r875_vs_lm875c->Fill(lm875c,r_875);
            h_fom_vs_lm875c->Fill(lm875c,fom);
            
            //extrapolated angles and postions:
            double horang = ((hptg1 - hptg1_offset) - (hp875 - hp875_offset))/(100.0*(hptg1_zpos-hp875_zpos));
            double horpos=(hp875 - hp875_offset) + horang*(target_center_zpos - hp875_zpos);
            
            //if(fom > 3)
            h_horang_vs_lm875a->Fill(lm875a,horang);
            h_horpos_vs_lm875a->Fill(lm875a,horpos);
            h_horang_vs_lm875b->Fill(lm875b,horang);
            h_horpos_vs_lm875b->Fill(lm875b,horpos);
            h_horang_vs_lm875c->Fill(lm875c,horang);
            h_horpos_vs_lm875c->Fill(lm875c,horpos);
            
            cout<<hp875<<endl;
        }
        
        fin->Close();
    }

    //--- Open output file:
    TFile *out = new TFile("output_filter.root","recreate");
    
    h_fom_vs_lm875a->Write();
    h_fom_vs_lm875b->Write();
    h_fom_vs_lm875c->Write();
    
    h_vp875_vs_fom->Write();
    h_hp875_vs_fom->Write();
    h_r875_vs_fom->Write();
    h_rtg1_vs_fom->Write();
    
    h_rtg1_vs_lm875a->Write();
    h_r875_vs_lm875a->Write();
    h_horang_vs_lm875a->Write();
    h_horpos_vs_lm875a->Write();
    
    h_hp875_vs_lm875a->Write();
    h_vp875_vs_lm875a->Write();
    h_hptg1_vs_lm875a->Write();
    h_vptg1_vs_lm875a->Write();
    
    h_rtg1_vs_lm875b->Write();
    h_r875_vs_lm875b->Write();
    h_horang_vs_lm875b->Write();
    h_horpos_vs_lm875b->Write();
    
    h_hp875_vs_lm875b->Write();
    h_vp875_vs_lm875b->Write();
    h_hptg1_vs_lm875b->Write();
    h_vptg1_vs_lm875b->Write();
    
    h_rtg1_vs_lm875c->Write();
    h_r875_vs_lm875c->Write();
    h_horang_vs_lm875c->Write();
    h_horpos_vs_lm875c->Write();
    
    h_hp875_vs_lm875c->Write();
    h_vp875_vs_lm875c->Write();
    h_hptg1_vs_lm875c->Write();
    h_vptg1_vs_lm875c->Write();
    
}

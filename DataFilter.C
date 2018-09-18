{
    unsigned int fileOrder = 10;
    int NdataFiles = 1;
    
    TFile *fin;
    TTree *tin;
    char name[500];
    
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
    
    //--- Define histograms ---
    //lm875b:
    TH2F *h_r875_vs_lm875b = new TH2F("h_r875_vs_lm875b",";LM875b;r_{875} ",1000,0,.2,1000,0,5);
    TH2F *h_fom_vs_lm875b = new TH2F("h_fom_vs_lm875b",";LM875b;FOM ",1000,0,.2,1000,-5,5);
    TH2F *h_hp875_vs_lm875b = new TH2F("h_hp875_vs_lm875b",";LM875b;HP875 ",1000,0,.2,1000,-5,5);
    TH2F *h_hptg1_vs_lm875b = new TH2F("h_hptg1_vs_lm875b",";LM875b;HPTG1 ",1000,0,.2,1000,-5,5);
    TH2F *h_vp875_vs_lm875b = new TH2F("h_vp875_vs_lm875b",";LM875b;VP875 ",1000,0,.2,1000,-5,5);
    TH2F *h_vptg1_vs_lm875b = new TH2F("h_vptg1_vs_lm875b",";LM875b;VPTG1 ",1000,0,.2,1000,-5,5);
    TH2F *h_rtg1_vs_lm875b = new TH2F("h_rtg1_vs_lm875b",";LM875b;r_{TG1} ",1000,0,.2,1000,-5,5);
    //TH2F *h_horang_vs_lm875b = new TH2F("h_horang_vs_lm875b",";LM875b;tan(#theta_{H}) ",1000,0,.2,1000,-5,5);
    //TH2F *h_horpos_vs_lm875b = new TH2F("h_horpos_vs_lm875b",";LM875b;pos_{H} (mm) ",1000,0,.2,1000,-5,5);
    
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
            if(fom >0.95 || fom <0)
                continue;
            if(hp875 == -999)
                continue;
            
            cout<<hp875<<endl;
        }
        
        
        fin->Close();
    }

}

import csv
import pandas as pd
import numpy as np
import matplotlib.pyplot as plt
import sys
from matplotlib import colors
import time
import datetime
from math import *
import ROOT as rt
from ROOT import TH1F, TFile, TH2F, TTree

hp875_offset= -3.40271;
vp875_offset= 1.47511;
hptg1_offset= 0.457014;
vptg1_offset= 0.38914;
hptg2_offset= 0.8;
vptg2_offset= 1.0;

hp875_zpos= 202.116104;
vp875_zpos= 202.3193205;
hptg1_zpos= 204.833267;
vptg1_zpos= 204.629608;
hptg2_zpos= 205.240662;
vptg2_zpos= 205.036835;
target_center_zpos= 206.870895;

def FOM_val():
    return 0.0

def main():

    data = pd.read_csv("http://ifb-data.fnal.gov:8100/ifbeam/data/data?b=BoosterNeutrinoBeam_read&t0=2018-02-05T15:30:00&t1=2018-02-05T15:50:00&f=csv", sep = ',')
    df = pd.DataFrame(data)
    #print(df.head())
    
    #df = df.groupby('name')
    
    print(df[:60])

    #print(df["value(s)"])
    #print(df.iloc[:'E:1DCNT'])
    #print(df.iloc[:,1])
    #print(df.loc[df['name'] == 'E:1DCNT'])
    #print(df.loc[df['name'] == 'E:HP875'])
    
    #list1 = df.loc[df['name'] == 'E:1DCNT']
    #print(list1)
    
    index_list_cnt = df.index[df['name'] == 'E:1DCNT'].tolist()
    index_list_hp875 = df.index[df['name'] == 'E:HP875'].tolist()
    index_list_vp875 = df.index[df['name'] == 'E:VP875'].tolist()
    
    index_list_hptg1 = df.index[df['name'] == 'E:HPTG1'].tolist()
    index_list_vptg1 = df.index[df['name'] == 'E:VPTG1'].tolist()
    
    index_list_lm875a = df.index[df['name'] == 'E:LM875A'].tolist()
    index_list_lm875b = df.index[df['name'] == 'E:LM875B'].tolist()
    index_list_lm875c = df.index[df['name'] == 'E:LM875C'].tolist()
    
    #print(index_list_cnt)
    #print(index_list_hp875)
    #print(index_list_hptg1)
    print(" Number of CNT: ",len(index_list_cnt))
    print(" Number of HP875: ",len(index_list_hp875))
    print(" Number of VP875: ",len(index_list_vp875))
    print(" Number of HPTG1: ",len(index_list_hptg1))
    print(" Number of VPTG1: ",len(index_list_vptg1))
    print(" Number of LM875A: ",len(index_list_lm875a))
    print(" Number of LM875B: ",len(index_list_lm875b))
    print(" Number of LM875C: ",len(index_list_lm875c))
    
    array_time = []
    array_hp875 = []
    array_vp875 = []
    array_hptg1 = []
    array_vptg1 = []
    array_r875 = []
    array_rtg1 = []
    array_lm875a = []
    array_lm875b = []
    array_lm875c = []
    array_horang = []
    array_horpos = []
    array_verang = []
    array_verpos = []
    
    h_hp875 = TH1F("h_hp875"," ",1000,-10,10)
    h_hp875_vs_lm875b = TH2F("h_hp875_vs_lm875b",";LM875b;HP875 ",1000,0,.2,1000,-5,5);
    h_hptg1_vs_lm875b = TH2F("h_hptg1_vs_lm875b",";LM875b;HPTG1 ",1000,0,.2,1000,-5,5);
    
    h_vp875_vs_lm875b = TH2F("h_vp875_vs_lm875b",";LM875b;VP875 ",1000,0,.2,1000,-5,5);
    h_vptg1_vs_lm875b = TH2F("h_vptg1_vs_lm875b",";LM875b;VPTG1 ",1000,0,.2,1000,-5,5);
    
    h_hp875_vs_lm875c = TH2F("h_hp875_vs_lm875c",";LM875b;HP875 ",1000,0,.2,1000,-5,5);
    h_hptg1_vs_lm875c = TH2F("h_hptg1_vs_lm875c",";LM875b;HPTG1 ",1000,0,.2,1000,-5,5);

    h_vp875_vs_lm875c = TH2F("h_vp875_vs_lm875c",";LM875b;VP875 ",1000,0,.2,1000,-5,5);
    h_vptg1_vs_lm875c = TH2F("h_vptg1_vs_lm875c",";LM875b;VPTG1 ",1000,0,.2,1000,-5,5);
    
    if (len(index_list_hp875) == 0) or (len(index_list_vp875) == 0):
        print("No data: Beam is off?")
        sys.exit(1)
    
    j = 0
    N = 0
    
    for i in index_list_hp875:
        
        #print(index_list_hp875[j], index_list_hptg1[j])
        #print(index_list_vptg1[j]  - index_list_hptg1[j])
        #print(df.iloc[index_list_hp875[j]][0])
        #print(time.ctime(df.iloc[index_list_hp875[j]][0]))
        if ((index_list_vptg1[j]  - index_list_hp875[j]) < 20) and (index_list_hp875[j]+1 == index_list_hptg1[j]) and (df.iloc[index_list_hp875[j]][0] - df.iloc[index_list_hptg1[j]][0])<5:
            
            array_time.append(df.iloc[index_list_hp875[j]][0])
            #print(index_list_hp875[j])
            val_hp875 = df.iloc[index_list_hp875[j]][3]
            val_vp875 = df.iloc[index_list_vp875[j]][3]
            
            r_875 = np.sqrt(val_hp875*val_hp875 + val_vp875*val_vp875)
            
            array_hp875.append(val_hp875)
            array_vp875.append(val_vp875)
            array_r875.append(r_875)
            
            h_hp875.Fill(val_hp875)
            
            val_hptg1 = df.iloc[index_list_hptg1[j]][3]
            val_vptg1 = df.iloc[index_list_vptg1[j]][3]
            
            r_tg1 = np.sqrt(val_hptg1*val_hptg1 + val_vptg1*val_vptg1)
                    
            array_hptg1.append(val_hptg1)
            array_vptg1.append(val_vptg1)
            array_rtg1.append(r_tg1)
            
            #Loss monitor data:
            val_lm875a = df.iloc[index_list_lm875a[j]][3]
            val_lm875b = df.iloc[index_list_lm875b[j]][3]
            val_lm875c = df.iloc[index_list_lm875c[j]][3]
            
            array_lm875a.append(val_lm875a)
            array_lm875b.append(val_lm875b)
            array_lm875c.append(val_lm875c)
            
            #extrapolated angles and postions:
            horang=((val_hptg1 - hptg1_offset) - (val_hp875 - hp875_offset))/(hptg1_zpos-hp875_zpos);
            horpos=(val_hp875 - hp875_offset) + horang*(target_center_zpos - hp875_zpos);
            
            array_horang.append(atan(horang))
            array_horpos.append(horpos)
            
            verang=((val_vptg1 - vptg1_offset) - (val_vp875 - vp875_offset))/(vptg1_zpos-vp875_zpos);
            verpos=(val_vp875 - vp875_offset) + horang*(target_center_zpos - vp875_zpos);
            
            array_verang.append(atan(verang))
            array_verpos.append(verpos)
            
            h_hp875_vs_lm875b.Fill(val_lm875b,val_hp875)
            h_vp875_vs_lm875b.Fill(val_lm875b,val_vp875)
            h_hptg1_vs_lm875b.Fill(val_lm875b,val_hptg1)
            h_vptg1_vs_lm875b.Fill(val_lm875b,val_vptg1)
            
            h_hp875_vs_lm875c.Fill(val_lm875c,val_hp875)
            h_vp875_vs_lm875c.Fill(val_lm875c,val_vp875)
            h_hptg1_vs_lm875c.Fill(val_lm875c,val_hptg1)
            h_vptg1_vs_lm875c.Fill(val_lm875c,val_vptg1)
            
            N +=1
            
            #print(val_hp875)
            
        
        #if (index_list_hp875[j+1] > max(index_list_cnt)):
        #    print(index_list_hp875[j+1])
            
        
        #if df.iloc[i][1] == 'E:1DCNT':
        #   print(df.iloc[i][1])
        j +=1
    print(j-1,N)
    #print(df.iloc[index_list_hp875[0]][0])
    print(time.ctime(df.iloc[index_list_hp875[0]][0]/1000), time.ctime(df.iloc[index_list_hp875[j-1]][0]/1000))
    #print(array_hp875)
    #plt.ylim(0,2)
    #plt.xlim(-5,0)

    out = rt.TFile("output.root","recreate")
    h_hp875.Write()
    h_hp875_vs_lm875b.Write()
    h_vp875_vs_lm875b.Write()
    h_hptg1_vs_lm875b.Write()
    h_vptg1_vs_lm875b.Write()

    h_hp875_vs_lm875c.Write()
    h_vp875_vs_lm875c.Write()
    h_hptg1_vs_lm875c.Write()
    h_vptg1_vs_lm875c.Write()
    
    l1 = plt.figure(1)
    plt.hist2d(array_hp875, array_vp875, bins=(50,50),norm=colors.LogNorm())
    
    l2 = plt.figure(2)
    plt.hist2d(array_hptg1, array_vptg1, bins=(50,50),norm=colors.LogNorm())
    
    l3 = plt.figure(3)
    plt.hist2d(array_r875, array_rtg1, bins=(100,100),norm=colors.LogNorm())
    
    l4 = plt.figure(4)
    plt.hist2d(array_time, array_rtg1, bins=(1000,100),norm=colors.LogNorm())
    
    l5 = plt.figure(5)
    plt.hist2d(array_time, array_lm875a, bins=(1000,100),norm=colors.LogNorm())
    
    l6 = plt.figure(6)
    plt.hist2d(array_time, array_lm875c, bins=(1000,100),norm=colors.LogNorm())
    
    l7 = plt.figure(7)
    #plt.yscale('log',basey=2)
    plt.hist2d(array_verang, array_rtg1, bins=(100,100),norm=colors.LogNorm())
    
    l8 = plt.figure(8)
    #plt.yscale('log',basey=2)
    plt.hist2d(array_verang, array_r875, bins=(100,100),norm=colors.LogNorm())

    l9 = plt.figure(9)
    #plt.yscale('log',basey=2)
    #plt.ylim(0,2)
    #plt.xlim(-5,0)
    plt.hist2d(array_verang, array_horpos, bins=(100,100),norm=colors.LogNorm())
    
    l10 = plt.figure(10)
    plt.hist2d(array_hp875, array_lm875c, bins=(1000,100),norm=colors.LogNorm())

    l11 = plt.figure(11)
    plt.hist2d(array_vp875, array_lm875c, bins=(1000,100),norm=colors.LogNorm())
    #plt.colorbar()
    #plt.hexbin(array_hp875, array_vp875)
    #plt.plot(array_time,array_vp875,'ro')
    #c = hist[xidx, yidx]
    #plt.scatter(array_hp875,array_vp875)

    plt.show()
    
    out.Close()

main()

//
//  main.cpp
//  DC3
//
//  Created by Younies Mahmoud on 3/4/16.
//  Copyright © 2016 Younies Mahmoud. All rights reserved.
//


#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <memory.h>
#include <fstream>

#include "radix.hpp"
#include "helpers.hpp"
#include "sort_SL.hpp"
#include "merge_AL_AD.hpp"



using namespace std;

vector<int> sorted_suffix(vector<int> &text , int h);

int main(int argc, const char * argv[]) {
    // insert code here...
    int h  = 3;
    //Read the text
    string textName = "Humanextended.DNA";
    string text;
    string File ="/Users/youniesmahmoud/Documents/spring2016/biosequence_algorithms/project/bio_project/xenoRefMrna.DNA";
    
    ifstream textFile(File);
    if (textFile.is_open())
    {
        
        getline(textFile, text);
        textFile.close();
        
    }
    
    //text = text.substr(0,100);
    
    //test
   // text = "aaaaaaaaaaaaaaaaaaaaaaaaaaataaaaaaaaaaaaaaaaaaaaaaaaat";
    for (int i = 0 ; i < text.size(); ++i)
    {
        text[i] = toupper(text[i]);
    }
    //Adding Dollar Sign $
    text += "$";
    string newText = text;
    int textSize = (int)text.size();
    
    //convert the text to numbers {$ = 0 , A = 1 , C = 2 , G= 3 , T = 4}
    char indicator;
    for (int i = 0 ; i < textSize; ++i)
    {
        indicator = text[i];
        switch (indicator)
        {
            case 'A':
                text[i] = '1';
                break;
            case 'C':
                text[i] = '2';
                break;
            case 'G':
                text[i] = '3';
                break;
            case 'T':
                text[i] = '4';
                break;
                
            case '$':
                text[i] ='0';
                break;
                
            default:
                cerr << "boooooooom";
                break;
        }
    }
    
    //make the vector of int for the text
    
    vector<int> text_int(text.size());
    for (int i = 0  , n = (int)text.size(); i < n ; ++i)
    {
        text_int[i] = text[i] - '0';
    }
    
    // building the sorted suffix
    vector<int> sortedTextSuffix = sorted_suffix(text_int, h);
    
    /*
    for (int i = 0 ; i < sortedTextSuffix.size() ; ++i)
    {
        //cout << sortedTextSuffix[i] << endl;
        int pos = sortedTextSuffix[i] - 1;
       // cout << i << "   " << pos << "  : ";
        for (int i = pos;  i < newText.size(); ++i)
        {
            cout << newText[i];
        }
        cout<< endl;
    }
    */

    vector<char> BWT(sortedTextSuffix.size());
    
    for (int i = 0 , n = (int)sortedTextSuffix.size() ; i < n ; ++i)
    {
        int pos = sortedTextSuffix[i] - 2;
        if(pos < 0)
            BWT[i] = '$';
        else
            BWT[i] = newText[ pos];
    }
    
    /*
    for (int i = 0 , n = (int)sortedTextSuffix.size() ; i < n ; ++i)
        cout << BWT[i];
    cout << endl;
    */
    
    string resultFile = "/Users/youniesmahmoud/Documents/spring2016/biosequence_algorithms/project/bio_project/xenoRefMrna.BWT";
    ofstream  puttingResult(resultFile, std::ofstream::out | std::ofstream::app);
    
    if(puttingResult.is_open())
    {
        for (int i = 0 , n = (int)BWT.size() ; i < n; ++i)
        {
            puttingResult << BWT[i];
        }
        puttingResult.close();
        
    }
    
    
    return 0;
}



vector<int> sorted_suffix(vector<int> &text , int h)
{
    cout << text.size() << endl;
    int text_size = (int)text.size();
    //Building the unsorted suffix array
    vector<int> unsortedSuffix(text.size());
    
    for (int i =0  , n = (int)text.size();  i < n ; ++i)
    {
        unsortedSuffix[i] = i+1;
    }
    
    

    //extracting S_D and D= {0 , 2}
    cerr << "extract SD" << endl;
    vector<int> SD , SL;
    int moded;
    for (int i = 0 , n = (int)text.size() ; i < n; ++i)
    {
        moded = unsortedSuffix[i]%3;
        if(moded == 0 || moded == 2 )
            SD.push_back(unsortedSuffix[i]);

    }

    
    
    
    
    //perform radix sort based on h to return SD'
    
    cerr << "Radix sort SD" << endl;
    vector<int >  SDdag =  radix_sort(SD, text, text_size , h );
    vector<int> bins(SDdag.size());
    
    //filling the bins
    cerr << "fill bins" << endl;

    bool unique = true;
    bins[0] = 1;
    for (int i = 1 , n = (int) SDdag.size(); i < n ; ++i)
    {
        if( key_equal( text,SDdag[i] , SDdag[i-1] , h ))
        {
            bins[i] = bins[i-1];
            unique = false;
        }
        else
            bins[i] = i+1;
    }
    
    cerr << "build B matrix" << endl;

    //building the B matrix
    vector<int> B(text.size(), 0);
    for (int i = 0 , n = (int)SDdag.size() ; i < n ; ++i)
    {
        B[SDdag[i] - 1] = bins[i];
    }
    
    //building I0, I1 ID
    cerr << "ID matrix" << endl;

    vector<int> I0, I2 , ID;
    for (int i = 0 , n = (int)SD.size(); i < n ; ++i)
    {
        int moded = SD[i] % h ;
        if(moded == 0)
            I0.push_back(SD[i]);
        else if (moded == 2)
            I2.push_back(SD[i]);
    }
    
    ID = I0;
    ID.insert(ID.end(), I2.begin(), I2.end());
    
    //building T0, T2 , T
    cerr << "T matrix" << endl;

    vector<int> T0(I0.size()) , T2(I2.size()) , T;
    
    //for T0
    
    for (int i = 0 , n = (int)I0.size(); i < n ; ++i)
    {
        T0[i] = B[I0[i] - 1]; /// loooook at this
    }
    
    // for T2
    for (int i = 0 , n = (int)I2.size(); i < n ; ++i)
    {
        T2[i] = B[I2[i] - 1]; // loooook at this
    }
    
    //for T
    T = T0;
    T.insert(T.end(), T2.begin() , T2.end());
    
    //sort T
    cerr << "Sort T matrix" << endl;

    vector<int> AT;
    if(unique)
    {
        //sort T by it is values to find AT
        T.push_back(0);
        AT = sort_unique_suffix(T);
        AT.erase(AT.begin());
    }
    else
    {
        AT = sorted_suffix( T ,  h);
    }
    
    
    // Now I have SD, SL , T , AT
    
    
    //building RT
    
    cerr << "RT matrix" << endl;

    vector<int> RT(AT.size());
    for (int i = 0 , n = (int)AT.size(); i < n ; ++i)
    {
        RT[AT[i] - 1] = i+1;//putting the positions
    }
    
    //building RD from AT ****** still here
    cerr << "AD matrix" << endl;

    vector<int> RD(text.size(), 0);
    for (int i = 0  , n =(int) ID.size(); i < n; ++i)
    {
        int posi = i+1;
        int elementi = ID[i];
        RD[elementi - 1] = RT[posi - 1];// RD[ i] = RT[]
    }
    
    //Build AD by reversing the RD
    cerr << "RD rev. matrix" << endl;

    vector<int> AD(SD.size());
    for (int i  = 0 , n = (int) RD.size(); i < n ; ++i)
    {
        if(RD[i] == 0)  continue;
        
        AD[ RD[i] - 1] = i + 1;// index of element RD
        
    }
    
    for (int i = 0 , n = (int)text.size() ; i < n; ++i)
    {
        moded = unsortedSuffix[i]%3;
        if(!(moded == 0 || moded == 2 ))
            SL.push_back(unsortedSuffix[i]);
    }
    
    //now we have SD, ID , T , AT , RT , RD , AD
    
    vector<int> AL(SL.size());
    
    AL = sort_AL(SL, text, RD);
    
    //merge AL ,AD to produce A
    cerr << "Merge AL, AD matrix" << endl;

    vector<int> newSD(SD.size());
    for (int i = 0 , n = (int)SDdag.size(); i < n ; ++i)
    {
        newSD[i] = SDdag[i];
    }
    
    vector<int> A = merge_suffixes(AD, AL, text, RD);
    
    ////////returned_the suffix
    AD.clear(); AL.clear() ; text.clear(); RD.clear() ; SD.clear(); SDdag.clear(); I0.clear(); ID.clear();I2.clear();T.clear(); T0.clear();T2.clear();
    return A;
}

















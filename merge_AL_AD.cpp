//
//  merge_AL_AD.cpp
//  DC3
//
//  Created by Younies Mahmoud on 3/5/16.
//  Copyright © 2016 Younies Mahmoud. All rights reserved.
//

#include "merge_AL_AD.hpp"


vector<int> merge_suffixes(vector<int > & AD , vector<int> & AL , vector<int> &text , vector<int> & RD)
{
    vector<int> A(text.size());
    int posAD = 0 , posAL = 0 , posA = 0;
    int AD_size = (int)AD.size() , AL_size = (int) AL.size();
    while (posAD < AD_size && posAL < AL_size)
    {
        if(greaterSegma(AD[posAD] , AL[posAL] , text , RD) )
        {
            A[posA] = AL[posAL];
            posAL++;
            
        }
        else
        {
            A[posA] = AD[posAD];
            posAD++;
        }
        posA++;
    }
    
    for ( ; posAD < AD_size ; ++posAD)
    {
        A[posA] = AD[posAD];
        posA++;
    }
    
    for ( ; posAL < AL_size ; ++posAL)
    {
        A[posA] = AL[posAL];
        posA++;
    }
    
    return A;
}







//*****************************


bool greaterSegma(int segmai , int segmaj , vector<int> &text , vector<int> &RD)
{
    //calculate delta
    int delta;
    for ( delta = 0 ; delta < 3 ; ++delta)
    {
        bool fact1 = ((segmai + delta)% 3 == 0) ||((segmai + delta)% 3 == 2);
        bool fact2 = ((segmaj + delta)% 3 == 0) ||((segmaj + delta)% 3 == 2);
        
        if(fact1 && fact2)
            break;
    }
    
    //compare delta chars
    
    for (int i = 0 ; i < delta; ++i)
    {
        if((segmai + i) > text.size() || (segmaj + i )> text.size())
            break;
        
        if(text[segmai + i - 1 ] > text[segmaj + i - 1 ])
            return true;
        
        if(text[segmai + i - 1 ] < text[segmaj + i - 1 ])
            return false;
    }
    
    return RD[segmai + delta - 1] > RD[segmaj + delta - 1];
}



//
//  sort_SL.cpp
//  DC3
//
//  Created by Younies Mahmoud on 3/5/16.
//  Copyright © 2016 Younies Mahmoud. All rights reserved.
//

#include "sort_SL.hpp"


vector<int> sort_AL(vector<int> &SL , vector<int> &Text , vector<int> &RD)
{
    vector<pair<pair<int, int> , int> > AL_to_sort(SL.size());
    for (int i = 0 , n = (int)AL_to_sort.size() ; i < n ; ++i)
    {
        AL_to_sort[i].first = key(SL[i], Text, RD);
        AL_to_sort[i].second = SL[i];
    }
    
    //sort AL and we have to make it radix after this
    sort(AL_to_sort.begin(), AL_to_sort.end());
    
    vector<int> AL(AL_to_sort.size());
    
    for (int i = 0 , n = (int) AL.size(); i < n ; ++i)
    {
        AL[i]  = AL_to_sort[i].second;
    }
    
    AL_to_sort.clear();
    
    return AL;
    
}


//compare segma return 0 if they equal and 1 if segmai > segmaj and -1 otherwise


int compare( int segmai , int  segmaj , vector<int> & text , vector<int> &RD)
{
    if( text[segmai - 1] > text[segmaj - 1])
        return 1;
    
    if( text[segmai - 1] < text[segmaj - 1])
        return -1;
    
    if(RD[segmai] > RD[segmaj])
        return 1;
    
    return -1;
    
}



pair<int, int> key( int segmai ,  vector<int> & text , vector<int> &RD)
{
    pair<int, int> k;
    
    k.first = text[segmai - 1];
    
    if(segmai == text.size())
        k.second = 0;
    else
        k.second = RD[segmai];
    
    return k;
    
}
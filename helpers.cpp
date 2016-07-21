//
//  helpers.cpp
//  DC3
//
//  Created by Younies Mahmoud on 3/5/16.
//  Copyright © 2016 Younies Mahmoud. All rights reserved.
//

#include "helpers.hpp"

bool key_equal( vector<int> &text,int first , int second , int h )
{
    first-- ;
    second--;
    //if(first == 0 || second == )
    for (int i = 0 ; i < h ; ++i)
    {
        if(text[first + i] != text[second + i])
            return false;
    }
    return true;
}



//sort unique suffix array

vector<int> sort_unique_suffix(vector<int>& suffix_array )
{
    vector<pair<int , int> > sorted_suffix(suffix_array.size());
    
    for (int i = 0 , n = (int)suffix_array.size(); i < n ; ++i )
    {
        sorted_suffix[i].first = suffix_array[i]; // KEY
        sorted_suffix[i].second =i+1;//index of suffix

    }
    
    //sort suffixies based on the key because they are unique
    sort(sorted_suffix.begin() , sorted_suffix.end());
    
    vector<int> return_suffix(sorted_suffix.size());
    for (int i = 0 , n = (int)sorted_suffix.size(); i < n ; ++i)
    {
        return_suffix[i] = sorted_suffix[i].second;
    }
    
    sorted_suffix.clear();
    return return_suffix;
}

















//
//  radix.cpp
//  DC3
//
//  Created by Younies Mahmoud on 3/4/16.
//  Copyright © 2016 Younies Mahmoud. All rights reserved.
//

#include "radix.hpp"



vector< int > radix_sort(vector<int> & SD , vector<int> &text, int text_size  ,int h )
{
   // vector<long long> radix_elements(text_size + 1, 0);
    
    vector<int > newSD_forsort(SD.size() );
    //int textSize = (int) text.size();
    for (int i = 0 , n = (int)SD.size() ; i < n ; ++i)
    {
        newSD_forsort[i] = SD[i];// index
       // newSD_forsort[i].second = getNumberFromText(text, textSize, newSD_forsort[i].first, h);//keys
        
        //cout << newSD_forsort[i].second.size() << endl;
        
    }
    
    radix_h_base( text ,newSD_forsort, text_size, h);
    
   // radix_elements.clear();
    return newSD_forsort;
    
    
}


//for extracting number of the text
int getNumberFromText(vector<int> &text , int &textSize , int pos ,int h )
{
    --pos; // to make it real in the text with zero based index
    
    int keyo = pos + h ;
    if(pos >= textSize)
        return 0;
    
    return text[keyo];
    
}




//to sort with h bases

void radix_h_base( vector<int> &text , vector<int> & newSD_forsort  , int text_size ,int h )
{
    
    //int SD_size = (int) newSD_forsort.size();
    vector<long long> radix_elements(text_size + 1, 0);
    
    //vector<int> transient_sorted(SD_size, 0);
    
    for(int i = h-1 ; i >= 0 ; --i)
    {
        fill(radix_elements.begin() , radix_elements.end() , 0);
        perform_radix_iteration( text ,newSD_forsort, radix_elements, i);
        
    }
    
    radix_elements.clear();
}



void perform_radix_iteration( vector<int> & text ,vector<int > & newSD_forsort , vector<long long> & radix_elements , int & base)
{
    int text_size = (int) text.size();
    //perform radix iteration
    for( int i = 0 , n = (int)newSD_forsort.size() ; i < n ; ++i)
    {
        
        int key = getNumberFromText(text, text_size, newSD_forsort[i], base);
        radix_elements[key]++;
    }
    
    //sum radix elements
    for (int i = 1 , n = (int) radix_elements.size(); i < n ; ++i)
    {
        radix_elements[i]+= radix_elements[i-1];
    }
    
    //put the elements in temporary vector
    
    vector<int > temporary(newSD_forsort.size() );
    int key;
    for(int i = (int) newSD_forsort.size() - 1 ; i >= 0 ; --i)
    {
        key = getNumberFromText(text, text_size, newSD_forsort[i], base);
        temporary[radix_elements[key] - 1] = newSD_forsort[i];
        radix_elements[key]--;
    }
    
    //return the elements again
    for (int i = 0 , n = (int)newSD_forsort.size(); i < n ; ++i)
    {
        newSD_forsort[i] = temporary[i];
    }
    
    
    //clear temp
    temporary.clear();
}




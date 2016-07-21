//
//  radix.hpp
//  DC3
//
//  Created by Younies Mahmoud on 3/4/16.
//  Copyright © 2016 Younies Mahmoud. All rights reserved.
//

#ifndef radix_hpp
#define radix_hpp
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
#include <string>

#include <stdio.h>

using namespace std;

vector< int > radix_sort(vector<int> & SD , vector<int> &text, int text_size  ,int h );

int getNumberFromText(vector<int> &text , int &textSize , int pos ,int h );

void radix_h_base( vector<int> &text, vector<int> & newSD_forsort  , int text_size ,int h );

void perform_radix_iteration( vector<int> & text ,vector<int > & newSD_forsort , vector<long long> & radix_elements , int & base);
#endif /* radix_hpp */

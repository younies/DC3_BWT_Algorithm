//
//  merge_AL_AD.hpp
//  DC3
//
//  Created by Younies Mahmoud on 3/5/16.
//  Copyright © 2016 Younies Mahmoud. All rights reserved.
//

#ifndef merge_AL_AD_hpp
#define merge_AL_AD_hpp

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

vector<int> merge_suffixes(vector<int > & AD , vector<int> & AL , vector<int> &text , vector<int> & RD);

bool greaterSegma(int segmai , int segmaj , vector<int> &text , vector<int> &RD);

#endif /* merge_AL_AD_hpp */

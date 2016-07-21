//
//  sort_SL.hpp
//  DC3
//
//  Created by Younies Mahmoud on 3/5/16.
//  Copyright © 2016 Younies Mahmoud. All rights reserved.
//

#ifndef sort_SL_hpp
#define sort_SL_hpp
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


vector<int> sort_AL(vector<int> &SL , vector<int> &Text , vector<int> &RD);

int compare( int segmai , int  segmaj , vector<int> &text , vector<int> &RD);

pair<int, int> key( int segmai  , vector<int> & text , vector<int> &RD);



#endif /* sort_SL_hpp */

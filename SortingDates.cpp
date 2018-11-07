//
//  SortingDates.cpp
//  
//
//  Created by Zhonglin Zhang on 10/27/18.
//

#include <stdio.h>
#include <iostream>
#include <string>
#include <unordered_map>

unordered_map<string, int> monthdict = {{"JAN", 1}, }

bool mycomparison(string& s1, string& s2) {
    int idx1, idx2;
    if(s1[1] == ' ') idx1 = 1;
    else idx1 = 2;
    if(s2[1] == ' ') idx2 = 1;
    else idx2 = 2;    // the first space position
    
    if(int(s1.substr(idx1+5, 4)) < int(s2.substr(idx2+5, 4))) return true;
    else {
        if(int(s1.substr(idx1+5, 4)) > int(s2.substr(idx2+5, 4))) return false;
        else {
            
        }
    }
}

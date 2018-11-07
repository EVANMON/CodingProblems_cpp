//
//  NextClosestTime.cpp
//  
//
//  Created by Zhonglin Zhang on 10/12/18.
//

#include <stdio.h>
#include <iostream>
#include <vector>
#include <string>
using namespace std;

char nextDigit(char cur, char upper, char* digits) {
    char firstDigit = digits[0];
    for(int i=0; i<4; ++i) {
        if(digits[i] == cur) {
            while(i<3 && digits[i+1] == digits[i]) ++i;
            if(i == 3 || digits[i+1] > upper) return digits[0];
            else return digits[i+1];
        }
    }
}

string nextClosestTime(string time) {
    string next (time);
    char digits[] = {time[0], time[1], time[3], time[4]};
    sort(digits, digits+4);
    
    next[4] = nextDigit(time[4], '9', digits);
    if(next[4] > time[4]) return next;
    
    next[3] = nextDigit(time[3], '5', digits);
    if(next[3] > time[3]) return next;
    
    if(next[0] < '2')
        next[1] = nextDigit(time[1], '9', digits);
    else
        next[1] = nextDigit(time[1], '3', digits);
    if(next[1] > time[1]) return next;
    
    next[0] = nextDigit(time[0], '2', digits);
    return next;
}

int main(){
    cout << nextClosestTime("19:34");
}

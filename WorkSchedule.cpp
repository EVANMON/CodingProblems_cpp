//
//  WorkSchedule.cpp
//  
//
//  Created by Zhonglin Zhang on 10/27/18.
//

#include <stdio.h>
#include <vector>
#include <queue>
#include <string>
#include <iostream>

using namespace std;


void helper(int hours, int dayHours, string plan, vector<string>& res, vector<int>& marks, string pattern) {
    int days = marks.size();
    int freeDays = days - plan.size();
    if(hours > freeDays * dayHours) return;
    if(freeDays == 1) {
        plan += to_string(hours);
        for(int i = 0; i < days; ++i) {
            pattern[marks[i]] = plan[i];
        }
        res.push_back(pattern);
        return;
    }
    for(int h = 0; h <= dayHours; ++h) {
        if(h > hours) break;
        if(hours - h > (freeDays - 1) * dayHours) continue;
        helper(hours - h, dayHours, plan + to_string(h), res, marks, pattern);
    }
}



vector<string> myfunction(int workHours, int dayHours, string pattern) {
    int workedHours = 0;
    vector<int> markpos;
    for(int i=0; i<7; ++i) {
        if(pattern[i] == '?') markpos.push_back(i);
        else workedHours += int(pattern[i] - '0');
    }
    int leftDays = markpos.size();
    int leftHours = workHours - workedHours;
    
    vector<string> res;
    
    if(markpos.empty()) {
        res.push_back(pattern);
        return res;
    }
    
    helper(leftHours, dayHours, "", res, markpos, pattern);
    return res;
}


int main() {
    int workHours = 24;
    int dayHours = 8;
    string pattern = "08??840";
    vector<string> res = myfunction(workHours, dayHours, pattern);
    for(auto & p : res) {
        cout << p << "\n";
    }
    cout << "Done!\n";
    return 0;
}

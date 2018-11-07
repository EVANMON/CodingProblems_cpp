//
//  WorkSchedule.cpp
//  
//
//  Created by Zhonglin Zhang on 10/27/18.
//

#include <stdio.h>
#include <vector.h>
#include <string.h>
#include <queue.h>

vector<string> myfunction(int workHours, int dayHours, string pattern) {
    int workedHours = 0;
    vector<int> markpos;
    for(int i=0; i<7; ++i) {
        if(pattern[i] == '?') markpos.push_back(i);
        else workedHours += int(pattern[i]);
    }
    int leftDays = markpos.size();
    int leftHours = workHours - workedHours;
    
    if(markpos.empty()) return vector<string> (pattern);
    queue<string> q;
    for(int i=0; i<=dayHours; ++i) q.push(to_string(i));
    int plannedDays = 1;
    while(plannedDays+1 < )
}

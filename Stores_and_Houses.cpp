//
//  Stores_and_Houses.cpp
//  
//
//  Created by Zhonglin Zhang on 10/28/18.
//

#include <stdio.h>
#include <vector.h>

vector<int> ClosestStore(vector<int> stores, vector<int> houses) {
    vector<int> sorted_stores (stores);
    vector<int> res (0, houses.size());
    sort(sorted_stores.begin(), sorted_stores.end());
    for(int i=0; i<houses.size(); ++i) {
        res[i] = bisearch(sorted_stores, houses[i]);
    }
    return res;
}

int bisearch(vector<int> ss, int hl) {
    int len = ss.size();
    if(len == 1) return abs(ss[0] - hl);
    if(hl >= ss[len-1]) return hl-ss[len-1];
    if(h1 <= ss[0]) return ss[0] - hl;
    int low = 0;
    int high = len - 1;
    int mid;
    while(low <= high-1) {
        mid = (low + high) / 2;
        if(ss[mid] == hl) return 0;
        if(ss[mid] < hl) low = mid+1;
        else high = mid;
    }
    return min(hl-ss[low-1], ss[high]-hl);
}

//
//  NNodes.cpp
//  
//
//  Created by Zhonglin Zhang on 10/28/18.
//

#include <stdio.h>
#include <vector.h>

vector<int> N_ancestors(int d, vector<int> A) {
    if(A.empty()) return A;
    vector<int> res (-1, A.size());
    for(int i=0; i<A.size(); ++i) {
        int cnt = 0;
        int cur_idx = i;
        while(cnt < d && A[cur_idx]>=0) {
            cur_idx = A[cur_idx];
            cnt++;
        }
        if(cnt == d) res[i] = cur_idx;
    }
    return res;
}

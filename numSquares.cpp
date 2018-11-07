#include <iostream>
#include <vector>
using namespace std;

int leastNum(vector<int>& sqrs, int n){
    vector<int> cnt;
    
    for(int i=0; i < n; i++){
        int least = INT_MAX;
        int j = 0;
        while(j < sqrs.size() && sqrs[j] <= i+1){
            if(sqrs[j] == i+1){
                least = 1;
                break;
            }
            else{
                if (cnt.size() <= i-sqrs[j]) cout << cnt.size() << i << j <<  "GG" << endl;
                least = min(least, 1 + cnt[i-sqrs[j]]);
                j++;
            }
        }
        cout << least << " bb" << endl;
        cnt.push_back(least);
    }
    cout << cnt.back() << " cc" << endl;
    return cnt.back();
/*
    if(dict.find(n) != dict.end()) return dict[n];
    else{
        if(n <= 0) return 0;
        else{
            int i = 0;
            int min = INT_MAX;
            while(i < sqrs.size() && sqrs[i] <= n){
                int tmp = 1 + leastNum(sqrs, dict, n-sqrs[i]);
                if(tmp < min) min = tmp;
                i++; ///!!!!!
            }
            dict[n] = min;
            return min;
        }
    }
*/
}

void sqrsGenerate(vector<int>& sqrs, int n){
    int num = 1;
    while(num * num <= n){
        sqrs.push_back(num * num);
        cout<< num* num << " aa" << endl;
        num ++;
    }
}

int numSquares(int n) {
    vector<int> sqrs;
    //unordered_map<int, int> dict;
    sqrsGenerate(sqrs, n);
    return leastNum(sqrs, n);
    //return leastNum(sqrs, dict, n);
}



int main(){
    int res = numSquares(5);
    cout << res << endl;
    return 0;
}
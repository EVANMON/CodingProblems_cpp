//LeetCode No. 38 Count and Say
//2017-12-19
#include <iostream>
using namespace std;

string countAndSay(int n) {
    if (n == 1) return "1";
    string newStr;
    string preStr = countAndSay(n-1);
    cout<<preStr<<endl;
    int pre = 0;
    int cur = 0;
    while(cur < preStr.size()){
        if(preStr[pre] == preStr[cur]){
            ++cur;
            continue;
        }
        else{
            newStr.push_back((char) cur - pre);
            newStr.push_back(preStr[pre]);
            pre = cur;
            ++cur;
        }
    }
    cout<<cur<<' '<<pre<<endl;
    newStr.push_back((char) '0' + cur - pre);
    cout<<newStr<<endl;
    //cout<< (char) 1<<endl;
    newStr.push_back(preStr[pre]);
    cout<<newStr<<endl;
    return newStr;
}

int main(){
	countAndSay(2);
}
#include <iostream>
#include <string>

using namespace std;

bool stringMatch(string& s1, string& s2) {
	const int m = s1.size();
	const int n = s2.size();
	bool dp[m+1][n+1];
	dp[0][0] = true;
	for(int i=1; i<=m; ++i) {
		for(int j=1; j<=n; ++j) {
            if(s2[j-1] == '?') dp[i][j] = dp[i-1][j-1];
            else if(s2[j-1] == '*') {
                for(int m=0; m<=i; ++m) {
                    if(dp[m][j-1]) {
                        dp[i][j] = true;
                        break;
                    }
                }
            }
            else dp[i][j] = dp[i-1][j-1] && (s1[i-1] == s2[j-1]);
            cout << i << j << dp[i][j] << '\n';
        }
	}
	return dp[m][n];
}

int main() {
	string s1 = "abcdedf";
	string s2 = "*";
	if(stringMatch(s1, s2)) cout<<s1<<" and "<<s2<< " Match!\n";
	else cout <<s1<<" and "<<s2 << " Don't match!\n";
	return 0;
}

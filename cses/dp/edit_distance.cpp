#include <bits/stdc++.h>
using namespace std;

int dp[5005][5005];
int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    string a,b;
    cin >> a >> b;
    int sz_a = a.size(),sz_b = b.size();

    for (int i = 1;i <= sz_a;i++) {
        dp[i][0] = i;
    }
    for (int i = 1;i <= sz_b;i++) {
        dp[0][i] = i;
    }
    for (int i = 1;i <= sz_a;i++) {
        for (int j =1;j <= sz_b;j++) {
            if (a[i-1] == b[j-1]) {
                dp[i][j] = dp[i-1][j-1];
            } else {
                dp[i][j] = min(dp[i-1][j],min(dp[i][j-1],dp[i-1][j-1])) + 1;
            }
        }
    }
    cout << dp[sz_a][sz_b];
    return 0;
}
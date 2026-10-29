#include <bits/stdc++.h>
#define int long long
using namespace std;

const int MOD = 1e9+7;
int dp[1005][1005];
signed main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    int n;
    cin >> n;
    for (int i = 1;i <= n;i++) {
        for (int j = 1;j <= n;j++) {
            char c;
            cin >> c;
            if (i == 1 && j == 1) {
                if (c == '.') {
                    dp[1][1] = 1;
                } else {
                    cout << "0\n";
                    return 0;
                }
            } else {
                if (c == '.') dp[i][j] = (dp[i-1][j] % MOD + dp[i][j-1] % MOD) % MOD;
            }
        }
    }
    cout << dp[n][n]  % MOD ;
    return 0;
}
#include <bits/stdc++.h>
#define int long long
using namespace std;
const int MOD = 1e9+7;
int dp[1000005];
signed main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    int n;
    cin >> n;
    dp[0] = 1;
    dp[1] = 1;
    dp[2] = 2;
    dp[3] = 4;
    dp[4] = 8;
    dp[5] = 16;
    dp[6] = 32;
    for (int i = 7;i <= n;i++) {
        for (int j = i-6;j <= i-1;j++) {
            dp[i] += dp[j] % MOD;
            dp[i] %= MOD;
        }
    }
    cout << dp[n] % MOD;
    return 0;
}
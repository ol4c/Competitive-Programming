#include <bits/stdc++.h>
#define int long long
using namespace std;

const int MOD = 1e9+7;
int dp[1000005];
vector<int> coins;
signed main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n,m;
    cin >> n >> m;
    for (int i = 1;i <= n;i++) {
        int k;
        cin >> k;
        coins.push_back(k);
    }
    dp[0] = 1;
    for (int i = 1;i <= m;i++) {
        for (int &c : coins) {
            if (i - c < 0) continue;
            dp[i] += dp[i-c] % MOD;
            dp[i] %= MOD;
        }
    }
    if (dp[m] == 1e9) {
        cout << "-1";
        return 0;
    }
    cout << dp[m] % MOD;

    
    return 0;
}
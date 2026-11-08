#include <bits/stdc++.h>
#define int long long
using namespace std;


int dp[260];
signed main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    int n,k;
    cin >> n >> k;
    for (int i = 1;i < (1 << k);i++) {
        dp[i] = 1e18;      
    }
    for (int i = 1;i < n;i++) {
        int w;
        cin >> w;
        int mask = 0;
        for (int j = 0;j < k;j++) {
            int c;
            cin >> c;
            if (c) mask |= (1 << j);
        }
        for (int j = 0;j < (1 << k);j++) {
            if (dp[j] != 1e18) dp[j | mask] = min(dp[j | mask], dp[j] + w);
        }
    }
    cout << dp[(1 << k) - 1];
    return 0;
}
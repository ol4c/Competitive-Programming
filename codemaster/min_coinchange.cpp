#include <bits/stdc++.h>
using namespace std;

int dp[10005];
vector<int> coins;
int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    int n,m;
    cin>> n >> m;
    for (int i = 1;i <=n;i++) dp[i] = 1e9;
    for (int i = 1;i <= m;i++) {
        int k;
        cin >> k;
        coins.push_back(k);
        dp[k] = 1;
    }
    
    for (int i = 1;i <= n;i++) {
        for (auto &c : coins) {
            if (i - c < 0) continue;
            dp[i] = min(dp[i-c] + 1, dp[i]);
        }
    }
    cout << dp[n];
    return 0;
}
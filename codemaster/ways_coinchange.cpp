#include <bits/stdc++.h>
using namespace std;

int dp[10005];
vector<int> coins;
int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    int n,m;
    cin>> n >> m;
    for (int i = 1;i <= m;i++) {
        int k;
        cin >> k;
        coins.push_back(k);
    }
    dp[0] = 1;
    for (auto &c : coins) {
        for (int i = 1;i <= n;i++) {
            if (i - c < 0) continue;
            dp[i] += dp[i-c];
        }
    }
    
    cout << dp[n];
    return 0;
}
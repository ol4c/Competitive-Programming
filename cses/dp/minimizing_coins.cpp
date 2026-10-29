#include <bits/stdc++.h>
using namespace std;

int dp[1000005];
vector<int> coins;
int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n,m;
    cin >> n >> m;
    for (int i = 1;i <= n;i++) {
        int k;
        cin >> k;
        coins.push_back(k);
    }

    for (int i = 1;i <= m;i++) {
        dp[i] = 1e9;
        for (int &c : coins) {
            if (i - c < 0) continue;
            dp[i] = min(dp[i],dp[i-c] + 1);
        }
    }
    if (dp[m] == 1e9) {
        cout << "-1";
        return 0;
    }
    cout << dp[m];

    
    return 0;
}
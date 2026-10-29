#include <bits/stdc++.h>
using namespace std;
int dp[1000005];
int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    int n;
    cin >> n;
    for (int i = 1;i <= n;i++) {
        dp[i] = 1e9;
        string s = to_string(i);
        for (auto &c : s) {
            dp[i] = min(dp[i],dp[i-(c - '0')] + 1);
        }
    }
    cout << dp[n];
    return 0;
}
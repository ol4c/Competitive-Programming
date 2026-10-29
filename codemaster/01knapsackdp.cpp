#include <bits/stdc++.h>
using namespace std;


int dp[10005];
int weight[10005];
int val[10005];
int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    int n,m;
    cin >> n >> m;
    for (int i = 1;i <= n;i++) {
        int w,v;
        cin >> w >> v;
        weight[i] = w;
        val[i] = v;
    }

    for (int i = 1;i <= n;i++) {
        for (int j = m;j >= 0;j--) {
            if (j - weight[i] < 0) continue;
            dp[j] = max(dp[j],dp[j-weight[i]] + val[i]);
        }
    }
    cout << dp[m];
    return 0;
}
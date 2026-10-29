
#include <bits/stdc++.h>
using namespace std;

int dp[100005];
int w[1005];
int v[1005];
int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n,m;
    cin >> n >> m;
    vector<int> temp;
    for (int i = 1;i <= n;i++) {
        int k;
        cin >> k;
        w[i] = k;
    }
    for (int i = 1;i <= n;i++) {
        int k;
        cin >> k;
        v[i] = k;
    }
    for (int j = 1;j <= n;j++) {
        for (int i = m;i >= 1;i--) {
            if (i-w[j] < 0) continue;
            dp[i] = max(dp[i],dp[i-w[j]] + v[j]);
        }
    }
    
    cout << dp[m];


    return 0;
}
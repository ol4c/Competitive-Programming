#include <bits/stdc++.h>
#define int long long
using namespace std;

vector<int> a;
const int MOD = 1e9+7;
int dp[100005][105];
// dp[i][j] = ways to create prefixes of length i with the last psition being the number j (1 <= j <= m)
signed main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    int n,m;
    cin >> n >> m;
    for (int i = 1;i <= n;i++) {
        int k;
        cin >> k;
        a.push_back(k);
    }
    for (int i = 1;i <= m;i++) {
        if (a[0] == i || a[0] == 0) {
            dp[1][i] = 1;
        }
    }

    for (int i = 2;i <= n;i++) {
        for (int j = 1;j <= m;j++) {
            if (a[i-1] != 0 && a[i-1] != j) {
                dp[i][j] = 0;
                continue;
            }

            dp[i][j] = dp[i-1][j-1] + dp[i-1][j] + dp[i-1][j+1];
            dp[i][j] %= MOD;
        }
    }

    int ans = 0;
    for (int i = 1;i <= m;i++) {
        ans += dp[n][i];
    }
    ans %= MOD;
    cout << ans;

    return 0;
}
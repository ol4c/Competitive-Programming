#include <bits/stdc++.h>
using namespace std;
double dp[1 << 20 + 1];
int a[25][25];
int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    for (int i = 1;i <= n;i++) {
        for (int j = 1;j <= n;j++) {
            cin >> a[i][j];
        }
    }
    dp[0] = 1;
    for (int i = 0;i < (1 << n);i++) {
        int cnt = __builtin_popcount(i);
        if (cnt == n) continue;
        for (int j = 0;j < n;j++) {
            if (!(i & (1 << j))) {
                dp[i | (1 << j)] = max(dp[i | (1<<j)], (dp[i] * a[cnt+1][j+1]) / 100.0);
            }
        }
    }
    cout << fixed << setprecision(12) << dp[(1 << n) - 1] * 100;
    

    return 0;
}
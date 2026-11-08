#include <bits/stdc++.h>
using namespace std;


signed main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    int q;
    cin >> q;
    
    while (q--) {
        int n;
        cin >> n;
        int ans = -1;
        for (int i = 2;i <= 30;i++) {
            double k = round(pow(n,1.0/i));
            int p = 1;
            for (int j = 1;j <= i;j++) {
                p*=k;
            }
            if (p == n) {
                ans = i;
            }
        }
        if (ans == -1) cout << "NO\n";
        else cout << ans << "\n";
    }
    return 0;
}
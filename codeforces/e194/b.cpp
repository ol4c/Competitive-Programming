#include <bits/stdc++.h>
#define int long long
using namespace std;

signed main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int q;
    cin >> q;
    while (q--) {
        int x,y,k;
        cin >> x >> y >> k;
        int ans = 0;
        for (int i = 0;i <= k - 1;i++) {
            //cout << "----" << y+i << " " << k+i << endl;;
            ans += (y+i) % (x+i);
        }
        cout << ans << "\n";
    }
}
#include <bits/stdc++.h>
#define int long long
using namespace std;

int real_mx = -2e9;
signed main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n;
    int mx;
    cin >> n;
    for (int i = 1;i <= n;i++) {
        int k;
        cin >> k;
        if (i == 1) {
            mx = k;
        } else {
            mx = max(mx+k,k);
        }
        real_mx = max(real_mx,mx);
    }
    cout << real_mx;
}
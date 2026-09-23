#include <bits/stdc++.h>
#define int long long
using namespace std;

signed main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    int n;
    cin >> n;
    for (int i = 1;i <= n;i++) {
        if (i == 1) cout << 0 << "\n";
        else cout << (i*i)*((i*i)-1) / 2 - ((i+1-3)*(i+1-2) * 4) << "\n";
    }
}
#include <bits/stdc++.h>
#define int long long
using namespace std;

signed main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;
    int z = 0;
    for (int i = 5;i <= 10000000000;i*=5) {
        if (n / i == 0) break;
        z += n/i;
    }
    cout << z;
}
#include <bits/stdc++.h>
#define int long long
using namespace std;
double a[1010];
signed main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;
    for (int i = 1;i <= n;i++) {
        cin >> a[i];
    }
    a[n+1] = 69.000;
    for (int i = n;i >= 1;i--) {
        a[i] += a[i] / a[i+1];
    }
    printf("%.6f", a[1]);
}
#include <bits/stdc++.h>
#define int long long
using namespace std;
int mx = -2e9;
int mn = 2e9;
signed main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n;
    int sum = 0;
    cin >> n;
    int nigga = n;
    while (nigga--) {
        int k;
        cin >> k;
        mx = max(mx,k);
        mn = min(mn,k);
        sum += k;
    }
    cout << mx - mn << " ";
    double prod = sum * 1.0 / n;
    cout << fixed << setprecision(2) << prod;  
}
#include <bits/stdc++.h>
#define int long long
using namespace std;

signed main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    int n;
    cin >> n;
    int sum = 1;
    for (int i = 1;i <= n;i++) {
        sum = (sum * 2) % ((long long) (1e9+7));
    }
    cout << sum;
}
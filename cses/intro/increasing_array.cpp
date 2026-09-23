#include <bits/stdc++.h>
#define int long long
using namespace std;

signed main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    int n;
    int prev;
    int sum = 0;

    cin >> n;
    for (int i = 1;i <= n;i++) {
        int k;
        cin >> k;
        if (i == 1) {
            prev = k;
        } else {
            if (k < prev) {
                sum += prev - k;
            } else {
                prev = k;
            }
        }
    }
    cout << sum;
}
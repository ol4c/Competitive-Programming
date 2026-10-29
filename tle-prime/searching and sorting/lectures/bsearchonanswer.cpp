#include <bits/stdc++.h>
using namespace std;


int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    int lo = 1;
    int hi = 1e9;
    int ans = -1;
    while (lo <= hi) {
        int mid = (lo+hi) / 2;
        if (mid * 2 >= 100) {
            ans = mid;
            hi = mid - 1;
        } else {
            lo = mid + 1;
        }
    }
    cout << ans;
    return 0;
}
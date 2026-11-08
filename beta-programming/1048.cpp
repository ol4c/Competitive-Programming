#include <bits/stdc++.h>
using namespace std;

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    int k,n;
    cin >> k >> n;
    int ans = 0;
    while (n >= 1) {
        ans += n;
        n/= 2;
    }
    cout << ans;
    return 0;
}
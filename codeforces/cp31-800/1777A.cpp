#include <bits/stdc++.h>
using namespace std;


int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    int q;
    cin >> q;
    while (q--) {
        int n;
        cin >> n;
        bool par;
        int cnt = 0;
        int ans = 0;
        // par = 0 even | par = 1 odd
        for (int i = 1;i <= n;i++) {
            int k;
            cin >> k;
            if (i == 1) {
                par = k % 2;
                cnt++;
            } else {
                if (par == k % 2) {
                    cnt++;
                } else {
                    par = k % 2;
                    ans += cnt-1;
                    cnt = 1;
                }
            }
        }
        ans += cnt-1;
        cout << ans << "\n";;
    }
    return 0;
}
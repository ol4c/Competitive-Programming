#include <bits/stdc++.h>
using namespace std;


int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        bool ch = 0;
        int mx = 0;
        int cnt = 0;
        for (int i = 1;i <= n;i++) {
            int k;
            cin >> k;
            if (!ch && k == 0) {
                ch = 1;
                cnt++;
            } else if (ch && k == 0) {
                cnt++;
            }
            else if (ch && k !=0) {
                ch = 0;
                mx = max(mx,cnt);
                cnt = 0;
            }
        }
        mx = max(mx,cnt);
        cout << mx << "\n";
    }

    return 0;
}
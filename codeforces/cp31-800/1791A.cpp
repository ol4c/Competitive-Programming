#include <bits/stdc++.h>
using namespace std;


int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int q;
    cin >> q;
    while (q--) {
        int n;
        string s;
        cin >> n >> s;
        int ans = n;

        for (int i = 0;i < n/2;i++) {
            if (s[i] != s[n-1-i]) {
                ans -= 2;
            } else break;
        }
        cout << ans << endl;
    }

    return 0;
}
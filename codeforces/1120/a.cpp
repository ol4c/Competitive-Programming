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
        int one = 0;
        int zero = 0;
        for (int i = 1;i <= n;i++) {
            int k;
            cin >> k;
            if (k == 1) one++;
            else zero++;
        }
        if (one >= zero) cout << "Bessie\n";
        else cout << "Elsie\n";
    }
}
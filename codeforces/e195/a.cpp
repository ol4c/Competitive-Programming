#include <bits/stdc++.h>
using namespace std;


int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int q;
    cin >> q;
    while (q--) {
        int a,b;
        cin >> a >> b;
        if (a <= b) {
            cout << -1 << '\n';
        } else {
            cout << min(b, a - b) << '\n';
        }
    }

    return 0;
}
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
        int target = n+1;
        for (int i = 1;i <= n;i++) {
            int k;
            cin >> k;
            cout << target - k << " ";
        }
        cout << "\n";
    }

    return 0;
}
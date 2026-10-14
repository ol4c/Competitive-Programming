#include <bits/stdc++.h>
using namespace std;


int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) {
        int even = 0;
        int odd = 0;
        int n;
        cin >> n;
        for (int i = 1;i <= n;i++) {
            int k;
            cin >> k;
            if (k%2 == 0) {
                even++;
            } else odd++;
        }
        even += odd / 2;
        odd = odd % 2;
        if (n == 2) {
            if (odd == 0) cout << "YES\n";
            else cout << "NO\n"; 
        } else {
            if (odd == 1) cout << "NO\n";
            else cout << "YES\n"; 
        }
    }

    return 0;
}
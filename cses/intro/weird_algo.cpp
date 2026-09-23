#include <bits/stdc++.h>
#define int long long
using namespace std;

signed main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;
    cout << n << " ";
    while (1) {
        if (n == 1) break;

        if (n % 2 == 0) {
            n /= 2;
        } else {
            n = n*3 + 1;
        }
        cout << n << " ";
    }
}
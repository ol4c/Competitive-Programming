#include <bits/stdc++.h>
#define int long long
using namespace std;

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;
    int sum = 0;
    int most = 0;
    for (int i = 1;i <= n;i++) {
        int k;
        cin >> k;

        sum += most;
        if (k > most) {
            most = k;
        }
    }
    cout << sum;
}

#include <bits/stdc++.h>
#define int long long
using namespace std;


int32_t main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int q;
    cin >> q;
    while (q--) {
        int a,b,c,d;
        cin >> a >> b >> c >> d;
        int cnt = 0;
        if (a == c && b == d) {
            cout << "0\n";
            continue;
        } else {
            if (b <= d) {
                cnt += d-b;
                a = a+cnt;
                b = b+cnt;
                if (a >= c) {
                    cnt += a-c;
                } else {
                    cout << "-1\n";
                    continue;
                }
            } else {
                cout << "-1\n";
                continue;
            }
        }
        cout << cnt << "\n";
    }

    return 0;
}
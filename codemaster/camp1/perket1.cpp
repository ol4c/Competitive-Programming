#include <bits/stdc++.h>
using namespace std;
int n, mn = 2e9;
int s[15];
int b[15];
int a[15];

void sol(int now) {
    if (now == n+1) {
        bool ch = 0;
        int relative = -67;
        int cs = 1;
        int cb = 0;
        for (int i = 1;i <= n;i++) {
            if (a[i] == 1) {
                cs *= s[i];
                cb += b[i];
                ch = 1;
            }
        }
        if (ch) {
            mn = min(mn,abs(cs-cb));
        }
        return;
    }

    for (int i = 0;i <= 1;i++) {
        a[now] = i;
        sol(now+1);
    }
}
int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> n;
    for (int i = 1;i <= n;i++) {
        int cs,cb;
        cin >> cs>>cb;
        s[i] = cs;
        b[i] = cb;
    }
    sol(1);
    cout << mn;
}

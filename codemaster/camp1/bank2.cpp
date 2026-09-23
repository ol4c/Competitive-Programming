#include <bits/stdc++.h>
using namespace std;

int n, use[6767], a[6767], b[6767];
string s[6767];
void sol2(int now) {
    if (now == n+1) {
        for (int i = 1;i <= n;i++) {
            cout << s[i][b[i]];
        }
        cout << "\n";
        return;
    }
    int sz = s[now].length();
    for (int i = 0;i < sz;i++) {
        b[now] = i;
        sol2(now+1);
    }
}

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> n;

    for (int i = 1;i <= n;i++) {
        cin >> s[i];
    }
    sol2(1);
}
#include <bits/stdc++.h>
using namespace std;
int n;
int a[105];
void sol(int num) {
    if (num > n) {
        return;
    }
    a[num] = 1;
    sol(num+6);
    sol(num+9);
    sol(num+20);
}
int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> n;
    sol(0);
    bool ch = 0;
    for (int i = 1;i<=n ;i++) {
        if (a[i]) {
            cout << i << "\n";
            ch = 1;
        }
    }
    if (!ch) cout << "no";
}
#include <bits/stdc++.h>
using namespace std;


int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;
    for (int i = 0;i <= (1 << n) - 1;i++) {
        int g = (i >> 1) ^ i;
        for (int j = n-1;j >= 0;j--) {
            cout << ((g >> j) & 1);
        }
        cout << "\n";
    }
}
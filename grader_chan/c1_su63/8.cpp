#include <bits/stdc++.h>
using namespace std;

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int remain = 0;
    while (1) {
        int k;
        cin >> k;
        if (k < 0) break;
        remain += k;
        int ans = 0;
        if (remain >= 500) {
            ans += remain / 800;
            remain %= 800;
            if (remain >= 500) {ans += 1;remain = 0;}
        }

        cout << ans << "\n";
    }
}
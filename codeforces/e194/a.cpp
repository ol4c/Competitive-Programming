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
        int first;
        int last;
        int zeros = 0;
        int ones = 0;
        int need = 0;
        for (int i =1;i <= n;i++) {
            int k;
            cin >> k;
            if (i == 1) {
                if (k == 1) {
                    first = 1;
                } else {
                    first = 0;
                }
            } else if (i==n) {
                if (i == n) {
                    if (k == 1) {
                        last = 1;
                    } else {
                        last = 0;
                    }
                }
            } else {
                if (k == 1) {
                    ones++;
                } else {
                    zeros++;
                }
            }
        }
        need = first + last;
        if (need <= zeros) cout << need << endl;
        else cout << -1 << endl;


    }
}
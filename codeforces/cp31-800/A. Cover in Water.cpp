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
        int total = 0;
        int space = 0;
        int mx_space = 0;
        bool ch = 0;
        for (int i = 1;i <= n;i++) {
            char c;
            cin >> c;
            if (c == '#') {
                if (space > 0) space = 0; 
            } else {
                space++; total++;
                mx_space = max(mx_space,space);
            }
        }
        if (mx_space >= 3) {
            cout << 2 << "\n";
        } else {
            cout << total << "\n";
        }
    }
    return 0;
}
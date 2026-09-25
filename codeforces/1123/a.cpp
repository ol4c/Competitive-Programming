#include <bits/stdc++.h>
using namespace std;

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    int q;
    cin >> q;
    while (q--) {
        int k;
        char c;
        cin >> k >> c;
        string s;
        cin >> s;
        if (k == 1) {cout << 0 << "\n";continue;}
        int en1, st2;
        if (k % 2 == 0) {
            en1 = k/2;
            st2 = k/2;
        } else {
            en1 = k/2;
            st2 = k/2 + 2;
        }
        int sum = 0;
        for (int i = 1;i <= en1;i++) {
            if (s[i-1] != s[k-i]) {
                if (s[i-1] != c) sum++;
                if (s[k-i] != c) sum++; 
            }

        }
        cout << sum << "\n";
    }
}
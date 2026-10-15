#include <bits/stdc++.h>
using namespace std;


int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int q;
    cin >> q;
    while (q--) {
        string s;
        cin >> s;
        int l = 0;
        int sh = 0;
        for (int i = 1;i < s.size() - 1;i++) {
            if (s[i-1] != s[i+1]) continue;
            if (s[i] == s[i-1]) l = 1;
            else sh = 1;
        }
        cout << l+sh+1 << "\n";
    }

    return 0;
}
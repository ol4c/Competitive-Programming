#include <bits/stdc++.h>
#define int long long
using namespace std;
signed main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int q;
    cin >> q;
    while (q--) {
        string s;
        cin >> s;
        int sz = s.size();
        string sj = "";
        int s1, s2, s3;
        for (int i = 0;i < sz;i++) {
            
            if (s[i] == '*') {
                s1 = stoll(sj);
                sj = "";
            } else if (s[i] == '=') {
                s2 = stoll(sj);
                sj = "";
            } else {
                sj += s[i];
                if (i == sz - 1) {
                    s3 = stoll(sj);
                }
                
            }
        }

        if (s1 * s2 == s3) cout << "True";
        else cout << "False";
        cout << "\n";
    }
}
#include <bits/stdc++.h>
using namespace std;


int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    int t;
    cin >> t;
    while (t--) {
        int n,m;
        cin >> n >> m;
        string s1,s2,og;
        cin >> og >> s2;
        s1 = og;
        if (s1.find(s2) != string::npos) {
            cout << "0\n";
            continue;
        }
        bool ch = 0;
        for (int i = 1;i <= 6;i++) {
            s1 = s1 + s1;
            if (s1.find(s2) != string::npos) {
                cout << i << "\n";
                ch = 1;
                break;
            }
        } 
        if (!ch) cout << "-1\n";
        continue;
    }
    return 0;
}
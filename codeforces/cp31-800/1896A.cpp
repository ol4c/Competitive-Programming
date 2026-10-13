#include <bits/stdc++.h>
using namespace std;


int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    int q;
    cin >> q;
    while (q--) {
        int k;
        cin >> k;
        vector<int> vec;
        for (int i = 1;i<=k;i++) {
            int l;
            cin >> l;
            vec.push_back(l);
        }
        if (vec[0] == 1) {
            cout << "YES\n";
        } else cout << "NO\n";
    }
    return 0;
}
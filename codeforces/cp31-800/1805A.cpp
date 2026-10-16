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
        vector<int> vec;
        for (int i = 1;i<= n;i++) {
            int k;
            cin >> k;
            vec.push_back(k);
        }
        bool ch = 0;
        for (int i = 0;i < 256;i++) {
            int hold = 0;
            for (int x : vec) {
                hold = hold ^ (x ^ i);
            }
            if (hold == 0) {
                cout << i << "\n";
                ch = 1;
                break;
            }
        }
        if (!ch) cout << "-1\n";
    }
    return 0;
}
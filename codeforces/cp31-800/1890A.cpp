#include <bits/stdc++.h>
using namespace std;


int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> vec;
        map<int,int> mp;
        for (int i=0;i<n;i++) {
            int k;
            cin >> k;
            vec.push_back(k);
        }
        if (n == 2 || n == 1) {
            cout << "YES\n";
        } else {
            for (auto &x : vec) {
                mp[x]++;
            }
            if (mp.size() > 2) cout << "NO\n";
            else if (mp.size() == 1) cout << "YES\n";
            else {
                int a = 0;
                int b = 0;
                int id = 0;
                for (auto &k : mp) {
                    if (id == 0) a = k.second;
                    else b = k.second;
                    id++;
                }
                if ((n % 2 == 1 && abs(a-b) == 1) || (n % 2 == 0 && abs(a-b) == 0)) {
                    cout << "YES\n";
                } else cout << "NO\n";
            }
        }
    }
    return 0;
}
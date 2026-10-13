#include <bits/stdc++.h>
using namespace std;


int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) {
        int n,k;
        cin >> n >> k;
        map<int,bool> mp;
        for (int i = 1;i <= n;i++) {
            int k;
            cin >> k;
            mp[k] = 1;
        }
        if (mp[k]) cout << "YES\n";
        else cout << "NO\n";
    }

    return 0;
}
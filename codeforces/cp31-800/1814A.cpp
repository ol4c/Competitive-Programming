#include <bits/stdc++.h>
#define int long long
using namespace std;


signed main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    int t;
    cin >> t;
    while (t--) {
        int a,b;
        cin >> a >> b;
        if (b % 2 == 0 && a % 2 != 0) cout << "NO\n";
        else cout << "YES\n";
    }
    return 0; 
}
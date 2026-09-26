#include <bits/stdc++.h>
#define int long long
using namespace std;

signed main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    int q;
    cin >> q;
    while (q--) {
        int a,b;
        cin >> a >> b;
        if ((a + b) % 3 == 0 && (max(a,b)) <= 2*min(a,b)) cout << "YES";
        else cout << "NO";
        cout << "\n";
    }
}
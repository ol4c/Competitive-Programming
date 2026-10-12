#include <bits/stdc++.h>
using namespace std;


int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int q;
    cin >> q;
    while (q--) {
        int a,b;
        cin >> a >> b;
        if (((a+b) % 3 == 0) && (2*min(a,b) >= max(a,b))) cout << "YES\n";
        else cout << "NO\n";
    }   
}
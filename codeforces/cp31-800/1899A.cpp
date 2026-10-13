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
        if (k%3==0) {
            cout << "Second\n";
        } else cout << "First\n";
    }
    return 0;
}
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
        if (a % b != 0) {
            cout << "1\n" << a << "\n";
        } else {
            cout << "2\n" << a-1 << " 1\n"; 
        }
    }
    return 0;
}
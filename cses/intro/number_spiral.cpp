#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    int n;
    cin >> n;
    while (n--) {
        ll ri,rj;
        cin >> ri >> rj;
        ll j = max(ri,rj);
        ll cj = 1 + (j-1)*j;
        if (ri == j) {
            if (j % 2 == 0) cout << cj + j-rj;
            else cout << cj - j + rj;
        } else {
            if (j % 2 == 0) cout << cj - j+ri;
            else cout << cj + j - ri;
        }
        cout << "\n";
    }

}
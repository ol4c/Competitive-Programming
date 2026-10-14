#include <bits/stdc++.h>
using namespace std;


int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) {
        double a,b,c;
        cin >> a >> b >> c;
        if (a+ceil(c/2) > b+(c - ceil(c/2))) {
            cout << "First\n";
        } else cout << "Second\n";
    }

    return 0;
}
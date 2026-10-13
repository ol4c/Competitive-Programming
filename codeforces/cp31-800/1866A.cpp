#include <bits/stdc++.h>
using namespace std;


int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    int mn = 2e9;
    while (n--) {
        int k;
        cin >> k;
        mn = min(abs(k),mn);
    }
    cout << mn;

    return 0;
}
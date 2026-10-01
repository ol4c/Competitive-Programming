#include <bits/stdc++.h>
using namespace std;

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int sum = 0;

    for (int i = 10;i >= 2;i--) {
        int k;
        cin >> k;
        sum += i*k;
    }

    if (11 - (sum % 11) != 11) cout << 11 - (sum % 11);
    else cout << 0;
    
}
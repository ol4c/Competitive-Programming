#include <bits/stdc++.h>
using namespace std;
int mx = -1e9;
int sum;
int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    for (int i = 1;i <= n;i++) {
        int k;
        cin >> k;
        if (k > mx) {
            mx = k;
            sum += k;
        }
    }
    cout << sum;
}
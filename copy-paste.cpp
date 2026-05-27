#include <bits/stdc++.h>
#define int long long
using namespace std;

signed main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int k = pow(8,7);
    int prod = 1;
    for (int i = 1;i <= k;i++) {
        prod *= 19;
        cout << prod % 1000 << endl;
    }
    

}
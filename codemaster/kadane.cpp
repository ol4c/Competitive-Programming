#include <bits/stdc++.h>
using namespace std;

int mx = -2e9;
int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    int n;
    cin >> n;
    int val = 0;
    for (int i = 1;i <= n;i++) {
        int k;
        cin >> k;
        if (i == 1) val = k;
        else {
            val = max(val+k,k);
        }
        mx = max(mx,val);
    }
    cout << mx;
    return 0;
}
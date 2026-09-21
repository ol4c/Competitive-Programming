#include <bits/stdc++.h>
#define int long long
using namespace std;

int n;

signed main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> n;
    while (n--)
    {
        int a, b ,c;
        cin >> a >> b >> c;
        cout << max(abs(a+c-b),abs(a-b)) << "\n";
    }
    
    
}
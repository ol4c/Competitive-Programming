#include <bits/stdc++.h>
#define int long long
using namespace std;

int mygcd (int a, int b) {
    while (b) {
        int t = a % b;
        a = b;
        b = t;
    }
    return a;
}
int32_t main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    int n;
    cin >> n;
    int l = 1;
    while (n--) {
        int k;
        cin >> k;
        l = l * k / mygcd(l,k) ;
    }
    //cout << prod << " " << g << endl;
    cout << l;
    return 0;
}
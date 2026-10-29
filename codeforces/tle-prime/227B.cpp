#include <bits/stdc++.h>
#define int long long
using namespace std;
int arr[100005];

int32_t main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    int n,q;
    cin >> n;
    for (int i = 1;i <= n;i++) {
        int k;
        cin >> k;
        arr[k] = i;
    }
    cin >> q;
    int a = 0;
    int b = 0;
    while (q--) {
        int k;
        cin >> k;
        a+=arr[k];
        b+=(n-arr[k]+1);
    }
    cout << a << " " << b;
    return 0;
}
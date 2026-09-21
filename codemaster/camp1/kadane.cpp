#include <bits/stdc++.h>
#define int long long
using namespace std;

int n;
int arr[2000005];
signed main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> n;
    for (int i = 1;i <= n;i++) {
        cin >> arr[i];
    }
    int sum = 0;
    int mx = -1e18;
    for (int i = 1;i <= n;i++) {
        sum = max(arr[i],arr[i]+sum);
        mx = max(sum,mx);
    }
    cout << mx;
}
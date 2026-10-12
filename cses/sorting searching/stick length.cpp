#include <bits/stdc++.h>
#define int long long
using namespace std;

signed main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;
    vector<int> vec;
    for (int i=1;i <= n;i++) {
        int k;
        cin >> k;
        vec.push_back(k);
    }
    sort(vec.begin(),vec.end());

    int mid;
    if (n % 2 == 0) {
        mid = n/2;
    } else {
        mid = (n-1)/2;
    }
    int val_mid = vec[mid];
    int cnt = 0;
    for (auto &x : vec) {
        cnt += abs(val_mid - x);
    }
    cout << cnt;
} 
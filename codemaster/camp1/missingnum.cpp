#include <bits/stdc++.h>
#define int long long
using namespace std;
signed main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;
    int sum = 0;
    vector<int> vec;
    for (int i = 0;i < n-1;i++) {
        int k;
        cin >> k;
        vec.push_back(k);
    }
    sort(vec.begin(),vec.end());
    int pr = 0;
    for (int i = 0;i < n-1;i++) {
        if (vec[i] - pr != 1) {
            cout << vec[i] -1;
            break;
        } else {
            pr = vec[i];
            if (i == n-1-1) {
                cout << n;
            }
        }
    }
}
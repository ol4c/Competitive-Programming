#include <bits/stdc++.h>
#define int long long
using namespace std;

signed main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n;
    vector<int> vec;
    cin  >> n;
    for(int i = 1;i <= n;i++) {
        int k;
        cin >> k;
        vec.push_back(k);
    }
    sort(vec.begin(),vec.end());
    int target = vec[(n+1) / 2 - 1];
    int cnt = 0;
    for (auto x :vec) {
        cnt += abs(target-x);
    }
    cout << cnt;
    return 0;
}
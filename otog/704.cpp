#include <bits/stdc++.h>
#define int long long
using namespace std;

signed main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n,q;
    cin >> n >> q;
    vector<int> pf(n,0);
    vector<pair<int,int>> ord;
    for (int i = 0;i < n;i++) {
        int a;
        cin >> a;
        if (i == 0) pf[i] = a;
        else pf[i] = pf[i-1] + a;
        ord.push_back({pf[i],i});
    }
    sort(ord.begin(),ord.end());

    vector<int> min_idx(n);
    min_idx[n-1] = ord[n-1].second;

    for (int i = n-2;i >= 0;i--) {
        min_idx[i] = min(ord[i].second,min_idx[i+1]);
    }
    //cin >> q;
    while (q--) {
        int mn = INT_MAX;
        int x;
        cin >> x;
        auto it = lower_bound(ord.begin(),ord.end(),make_pair(x, LLONG_MIN));
        if (it != ord.end()) {
            int idx = it - ord.begin();
            cout << min_idx[idx] << "\n";
        } else cout << "-1\n";
        
    }

}
#include <bits/stdc++.h>
#define int long long
using namespace std;


signed main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n,q;
    cin >> n >> q;
    vector<int> og;
    vector<int> a;
    vector<int> a_idx;
    vector<int> back;
    og.push_back(0);
    for (int i =1;i <= n;i++) {
        int k;
        cin >> k;
        og.push_back(k);
    }
    og.push_back(0);
    for(int i = 1;i <= q;i++) {
        int k;
        cin >> k;
        back.push_back(k);
    }
    for (int i = 1;i < og.size() - 2;i++) {
        a.push_back(og[i] + og[i-1] + og[i+1]);
        a_idx.push_back(i);
    }

    for (auto x : back) {
        int idx = lower_bound(a.begin(),a.end(),x) - a.begin();
        cout << a_idx[idx] << "\n";
    }
}
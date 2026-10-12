#include <bits/stdc++.h>
using namespace std;


int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int q;
    cin >> q;
    vector<pair<int,int>> vec;
    while (q--) {
        int a,b;
        cin >> a >> b;
        vec.push_back({a,1});
        vec.push_back({b,-1});
    }
    sort(vec.begin(),vec.end());
    int cnt = 0;
    int mx = -2e9;
    for (auto &x : vec) {
        cnt += x.second;
        mx = max(mx,cnt);
    }

    cout << mx;
}
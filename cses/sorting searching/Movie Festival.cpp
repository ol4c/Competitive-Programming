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
        vec.push_back({a,b});
    }
    sort(vec.begin(),vec.end(),[](const auto &a, const auto &b) {
        if (a.second != b.second) return a.second < b.second;
        return a.first < b.first;
    });

    int cnt = 0;
    int fi = -67;
    for (auto &x : vec) {
        if (fi == -67) {
            fi = x.second;
            cnt++;
        } else {
            if (x.first >= fi) {
                fi = x.second;
                cnt++;
            }
        }
    }
    cout << cnt;
}
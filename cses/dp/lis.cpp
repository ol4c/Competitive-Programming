#include <bits/stdc++.h>
using namespace std;

vector<int> ans, vec;
int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    for (int i = 1;i <= n;i++) {
        int k;
        cin >> k;
        vec.push_back(k);
    }
    ans.push_back(0);
    for (auto &x : vec) {
        auto it = lower_bound(ans.begin(),ans.end(),x);
        if (it != ans.end()) {
            *it = x;
        } else {
            ans.push_back(x);
        }
    }
    cout << ans.size() - 1;

    return 0;
}
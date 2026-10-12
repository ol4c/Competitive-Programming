#include <bits/stdc++.h>
using namespace std;

map<int,vector<int>> mp;
int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n, sum;
    cin >> n >> sum;

    for (int i = 1;i <= n;i++) {
        int k;
        cin >> k;
        if (k >= sum) continue;
        mp[k].push_back(i);
    }

    for (auto &x : mp) {
        if (x.second.size() == 0) continue;
        if (mp[sum - x.first].size() != 0) {
            if ((sum - x.first) == x.first) {
                if (x.second.size() > 1) {
                    cout << x.second[0] << " " << mp[sum-x.first][1];
                    return 0;
                }
            } else {
                cout << x.second[0] << " " << mp[sum-x.first][0];
                return 0;
            }
        }
    }
    cout << "IMPOSSIBLE";
}
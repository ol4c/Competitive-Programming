#include <bits/stdc++.h>
#define int long long
using namespace std;
//triad,cnt idx
map<int,pair<int,set<int>>> mp;
signed main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) {
        int ans = 0;
        mp.clear();
        int n;
        cin >> n;
        vector<int> vec;
        for (int i= 1;i <= n;i++) {
            int k; cin >> k; vec.push_back(k);
        }
        for (int i = 0;i < n-4;i++) {
            int triad = vec[i] + vec[i+2] - vec[i+4];
            mp[triad].first++;
            mp[triad].second.insert(i);
        }
        for (auto i : mp) {
            //cout << i.first << " " << i.second << endl;
            //cout << "----" << i.second.first *(i.second.first - 1) / 2 << endl;;
            ans += i.second.first *(i.second.first - 1) / 2;
            /*for (auto &x : i.second.second) {
                cout << x << " ";
            } cout << endl;*/
            for (auto &x : i.second.second) {
                if (i.second.second.count(x - 2)) ans--;
                if (i.second.second.count(x - 4)) ans--;
            }
            
        }
        cout << ans <<"\n";
    }
}
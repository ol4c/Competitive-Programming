#include <bits/stdc++.h>
using namespace std;


int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) {
        int n;
        vector<int> vec;
        cin >> n;
        for (int i = 1;i <= n;i++) {
            int k;
            cin >> k;
            vec.push_back(k);
        }
        bool ch = 0;
        int idx;
        vector<int> ans;
        for (int i = 0;i < vec.size();i++) {
            ch = 1;
            int p = vec[i];
            vector<int> possible = {p};
            for (int j = 0;j < vec.size();j++) {
                if (i == j) continue;
                if (vec[j] == p) {
                    possible.push_back(p);
                    continue;
                }
                if (vec[j] % p == 0) {
                    ch = 0;
                    break;
                }
            }
            if(ch) {
                ans = possible;
                break;
            }
        }
        if (ans.size() == vec.size() || ans.size() == 0) {
            cout << "-1\n";
        } else {
            cout << vec.size() - ans.size() << " " << ans.size() << "\n";
            for (int i = 0;i < vec.size();i++) {
                if (vec[i] == ans[0]) continue;
                cout << vec[i] << " ";
            }
            cout << "\n";
            for (auto &x : ans){
                cout << x << " ";
            }
            cout << "\n";
        }
        
    }

    return 0;
}
#include <bits/stdc++.h>
using namespace std;
map<int,int,greater<int>> mp;
int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    int q;
    cin >> q;
    while (q--) {
        vector<int> vec;
        vector<int> ans;
        vector<int> kuy;
        
        int n;
        bool ch = 0;
        cin >> n;
        for (int i = 1;i <= n;i++) {
            int k;
            cin >> k;
            vec.push_back(k);
        }
        sort(vec.begin(),vec.end(),greater<int>());
        for (int i : vec) {
            if (ch == 0) {
                if (vec.empty()) ans.push_back(i);
                else if (i == vec.back()) {
                    ans.push_back(i);
                } else {
                    ch = 1;
                    mp[i]++;
                    kuy.push_back(i);
                }
            } else {
                if (mp[i] == 0) kuy.push_back(i);
                mp[i]++;
            }
        }
        sort(kuy.begin(),kuy.end(),greater<int>());
        while (1) {
            if (ans.size() == vec.size()) break;
            for (int i : kuy) {
                if (mp[i] > 0) {
                    ans.push_back(i);
                    mp[i]--;
                }
            }
            
        }
        

        for (int i : ans) {
            cout << i << " ";
        }
        cout << "\n";
        mp.clear();
    }
}
#include <bits/stdc++.h>
using namespace std;

map<char,int> mp;
map<char,bool> check;
int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int left = 7;
    while (1) {
        string s;
        cin >>s;
        if (s == "!") break;
        
        for (auto &c : s) {
            mp[c]++;
        }
        int mn = 2e9;
        int mn_freq = 0;
        int mn_c;
        for (char c = 'A';c != 'H';c++) {
            if (check[c]) continue;
            if (mp[c] < mn) {
                mn = mp[c];
                mn_freq = 1;
                mn_c = c;
            } else if (mp[c] == mn) {
                mn_freq++;
            }
        }
        if (left > 1) {
        if (mn_freq == 1) {
                    check[mn_c] = 1;
                    left--;
                }
        }
        
    }
    vector<pair<char,int>> vec;
    for (auto &x : mp) {
        if (check[x.first] == 0) {
            vec.push_back({x.first,x.second});
        }
    }
    sort(vec.begin(),vec.end(),[](const auto &a, const auto &b) {
        return a.second > b.second;
    });
    cout << vec.size() << "\n";
    for (auto &x : vec) {
        cout << x.first << " " << x.second << "\n";
    }
    return 0;
}
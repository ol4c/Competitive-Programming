#include <bits/stdc++.h>
#define int long long

using namespace std;
vector<string> cur;
vector<vector<string>> rule;
signed main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n,m;
    cin >> n >> m;
    for (int i = 1;i <= n;i++) {
        string s;
        cin >> s;
        cur.push_back(s);
    }
    for (int i = 1;i <= m;i++) {
        string s1,s2,s3;
        cin >> s1 >> s2 >> s3;
        rule.push_back({s1,s2,s3});
    }
    
    bool check = 0;
    if(n==1) {
        cout << cur[0];
        return 0;
    }
    while (!check) {
        check = 1;
        for (int i = 0;i < cur.size() - 1;i++) {
            string s1,s2;
            s1 = cur[i];
            s2 = cur[i+1];
            for (auto j : rule) {
                if (s1 == j[0] && s2 == j[1]) {
                    cur[i] = j[2];
                    cur.erase(cur.begin()+i+1);
                    check = 0;
                }
                if (!check) break;
            }
            if (!check) break;
        }
    }

    for (auto i : cur) cout << i << " ";
}
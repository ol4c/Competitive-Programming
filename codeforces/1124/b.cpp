#include <bits/stdc++.h>
#define int long long
using namespace std;
map<string,int> mp;

void sol(string s) {
    for (int i = 1;i <= 20;i++) {
        int sz = s.size();
        int sum = 0;
        for (int j = 0;j < sz;j++) {
            sum += pow(s[j] - '0',2);
        }
        s = to_string(sum);
    }
    mp[s]++;
    return;
}
signed main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) {
        mp.clear();
        int n;
        cin >> n;
        for (int i = 1;i <= n;i++) {
            string s;
            cin >> s;
            sol(s);
        }

        int sum = 0;
        for (auto i : mp) {
            //cout << "---" << i.first << " " << i.second << endl;;
            sum += (i.second * (i.second - 1)) / 2;
        }
        cout << sum << "\n";
    }
}
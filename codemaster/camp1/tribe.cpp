#include <bits/stdc++.h>
#define int long long 
using namespace std;
map<int,int> mp;
int mx = -1e18;
signed main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    for (int i = 1;i <= n;i++) {
        int k;
        cin >> k;
        string s = to_string(k);
        int sz = s.size();
        int sum = 0;
        for (int i = 0;i < sz;i++) {
            sum += s[i] - '0';
        }
        mp[sum] += k;
        mx = max(mp[sum],mx);
    }
    cout << mx;
}
#include <bits/stdc++.h>
using namespace std;
vector<int> mp(167,0);
int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n,k;
    cin >> n >> k;
    int mx_freq = 1;
    for (int i = 1;i<=n;i++) {
        int v;
        cin >> v;
        mp[v]++;
        mx_freq = max(mx_freq,mp[v]);
    }
    int ans = INT_MIN;
        for (int i = 0;i <= 100;i++) {
        if (mp[i] + k > mx_freq) {
            ans = max(ans,i);
        }
    }

    cout << ans;
}
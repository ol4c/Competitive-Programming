#include <bits/stdc++.h>
#define int long long
using namespace std;

map<double,int>mp;
set<double> st;
map<double,int>check;
signed main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    int n;
    cin >> n;
    for (int i = 1;i <= n;i++) {
        double p,q;
        cin >> p >> q;
        mp[p/q]+=q;
        st.insert(p/q);
    }
    int q;
    cin >> q;
    auto it = st.begin();
    while (q--) {
        int want;
        cin >> want;
        double price = 0;
        for (auto x = it;x != st.end();x++) {
            if (mp[*x] == 0) {
                it++;
                continue;
            }
            if (mp[*x] >= want) {
                mp[*x] = mp[*x] - want;
                price += *x*want;
                want = 0;
            } else {
                want -= mp[*x];
                price += *x*mp[*x];
                mp[*x] = 0;
            }
            if (want == 0) break;
        }
        cout << fixed << setprecision(3) << price << "\n";
    }
    return 0;
}
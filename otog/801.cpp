#include <bits/stdc++.h>
#define int long long
using namespace std;


signed main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n,q;
    cin >> n >> q;
    vector<int> og;
    vector<int> pf(n+1,0);
    og.push_back(0);
    for (int i =1;i <= n;i++) {
        int k;
        cin >> k;
        og.push_back(k);
    }
    sort(og.begin(),og.end());
    for (int i = 1;i <= n;i++) {
        pf[i] = pf[i-1] + og[i];
    }
    while (q--) {
        int as;
        cin >> as;
        cout << upper_bound(pf.begin(),pf.end(),as) - pf.begin() - 1 << "\n"; 
    }

}
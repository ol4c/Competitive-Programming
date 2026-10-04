#include <bits/stdc++.h>

using namespace std;
int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    vector<int> p;
    vector<int> h;
    int n,q;
    cin >> n >> q;
    for (int i = 1;i <= n;i++) {
        int k;
        cin >> k;
        p.push_back(k);
    }
    sort(p.begin(),p.end());
    for (int i = 1;i <= q;i++) {
        int k;
        cin >> k;
        int idx = lower_bound(p.begin(),p.end(),k) - p.begin();
        int ans;
        if (idx == p.size()) {
            ans = p[idx-1];
        }
        else if (idx > 0) {
            if (abs(k-p[idx]) < abs(k-p[idx-1])) ans = p[idx];
            else if (abs(k-p[idx]) > abs(k-p[idx-1])) ans = p[idx-1];
            else ans = min(p[idx],p[idx-1]);
        }
        else {
            ans = p[idx];
        }
        cout << ans << "\n";
    }
    

    
}
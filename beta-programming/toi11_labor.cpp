#include <bits/stdc++.h>
#define int long long
using namespace std;


signed main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    int n,m;
    cin >> n >> m;
    vector<int> labor;
    for (int i = 1;i <= n;i++) {
        int k;
        cin >> k;
        labor.push_back(k);
        
    }
    sort(labor.begin(),labor.end());
    int ans;
    int l = 1;
    int r = labor[0] * m;
    while (l <= r) {
        int mid = (l+r)/2;
        int amt = 0;
        for (auto &x: labor) {
            amt += mid / x;
            if (amt > m) {
                break;
            }
        }

        if (m <= amt) {
            ans = mid;
            r = mid-1;
        } else if(m > amt) {
            l = mid+1;
        }
        
    }
    cout << ans;
    return 0;
}
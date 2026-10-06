#include <bits/stdc++.h>
#define int long long
using namespace std;
vector<pair<int,int>> vec;
signed main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n,q;
    cin >> n >> q;
    int sum = 0;
    for (int i = 1;i <= n;i++) {
        int x,y;
        cin >> x >> y;
        vec.push_back({x,y});
    }
    for (int i =0;i < n;i++) {
        sum += vec[i].second*2;
        sum += vec[i].first + vec[i].first;
        if(n > 1) {
            if (i == 0 && n > 1) {
                sum -= min(vec[i].first,vec[i+1].first);
            }
            else if (i != 0 && i == n-1) {
                sum -= min(vec[i-1].first,vec[i].first);
            }
            else {
                sum -= min(vec[i].first,vec[i-1].first);
                sum -= min(vec[i].first,vec[i+1].first);
            }
        }
        
    }
    cout << sum << "\n";
    for (int i = 1;i <= q;i++) {
        int idx,x,y;
        cin >> idx >> x >> y;
        idx--;
        int temp = sum;
        if (n == 1) {
            cout << x*2 + y*2 << "\n";
        } else {
            if (idx == 0) {
                sum += min(vec[idx].first,vec[idx+1].first)*2;
            }
            else if (idx != 0 && idx == n-1) {
                sum += min(vec[idx-1].first,vec[idx].first)*2;
            }
            else {
                sum += min(vec[idx].first,vec[idx-1].first)*2;
                sum += min(vec[idx].first,vec[idx+1].first)*2;
            }

            sum -= vec[idx].first * 2 + vec[idx].second * 2;

            sum += x*2 + y*2;
            vec[idx] = {x,y};
            if (idx == 0) {
                sum -= min(vec[idx].first,vec[idx+1].first)*2;
            }
            else if (idx != 0 && idx == n-1) {
                sum -= min(vec[idx-1].first,vec[idx].first)*2;
            }
            else {
                sum -= min(vec[idx].first,vec[idx-1].first)*2;
                sum -= min(vec[idx].first,vec[idx+1].first)*2;
            }
            cout << sum << "\n";
        }
    }
}
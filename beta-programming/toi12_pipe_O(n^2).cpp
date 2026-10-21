#include <bits/stdc++.h>
#define int long long
using namespace std;

vector<pair<int,int>> vec;
int dist[15005], vs[15005];
signed main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    int n,k;
    cin >> n >> k;
    for (int i = 0;i < n;i++) {
        int x,y;
        cin >> x >> y;
        vec.push_back({x,y});
    }
    int com = n;
    for (int i = 0;i < n;i++) {
        dist[i] = 1e15;
    }
    dist[0] = 0;
    int total = 0;
    vector<int> v;
    int now = 0, mn = 1e9;
    for (int i = 1;i < n;i++) {
        vs[now] = 1; mn = 1e9;
        int nxt;
        for (int j = 0;j < n;j++) {
            if (vs[j]) continue;
            int val = abs(vec[now].first - vec[j].first) + abs(vec[now].second - vec[j].second);
            if (val < dist[j]) {
                dist[j] = val;
            }
            if (dist[j] < mn) {
                mn = dist[j];
                nxt = j;
            }
        }
        now = nxt;
        total += mn;
        v.push_back(mn);
    }
    sort(v.begin(),v.end(),greater<int>());
    for (int i = 1;i <= k-1;i++) {
        total -= v[i-1];
    }
    cout << total;
    return 0;
}
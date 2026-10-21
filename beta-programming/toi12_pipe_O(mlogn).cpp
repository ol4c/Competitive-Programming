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

    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
    pq.push({0,0});
    dist[0] = 0;
    int total = 0;
    vector<int> v;
    while (com > 0) {
        auto u = pq.top();
        pq.pop();

        if (vs[u.second]) continue;
        vs[u.second] = 1;
        total += u.first;
        v.push_back(u.first);
        com--;
        for (int i = 0;i < n;i++) {
            pair<int,int> p = {abs(vec[i].first - vec[u.second].first) + abs(vec[i].second - vec[u.second].second), i};
            if (p.first >= dist[p.second]) continue;
            if (vs[p.second]) continue;
            dist[p.second] = p.first;
            pq.push(p);
        }
    }
    sort(v.begin(),v.end(),greater<int>());
    for (int i = 1;i <= k-1;i++) {
        total -= v[i-1];
    }
    cout << total;
    return 0;
}
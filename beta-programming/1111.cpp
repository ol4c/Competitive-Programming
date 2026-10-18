#include <bits/stdc++.h>
#define int long long
using namespace std;
vector<pair<int,int>> adj[100005];
int dist[100005];
signed main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    int n;
    cin >> n;
    for (int i = 1;i < n ;i++) {
        int x,y,z;
        cin >> x >> y >> z;
        adj[x].push_back({y,z});
        adj[y].push_back({x,z});
        dist[x] = 1e15;
        dist[y] = 1e15;
    }

    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
    pq.push({0,1});
    dist[1] = 0;
    while (!pq.empty()) {
        auto u = pq.top();
        pq.pop();
        //cout << u.first << endl;
        if (u.first > dist[u.second]) continue;
        for (auto &x : adj[u.second]) {
            pair<int,int> p = {u.first+x.second,x.first};
            if (p.first >= dist[p.second]) continue;
            pq.push(p);
            dist[p.second] = p.first;
        }
    }
    int mx = -1e15;
    for (int i = 1;i <= n;i++) {
        mx = max(mx,dist[i]);
    }
    cout << mx;
    return 0;
}
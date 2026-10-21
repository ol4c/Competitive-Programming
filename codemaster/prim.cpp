#include <bits/stdc++.h>
#define int long long
using namespace std;

vector<pair<int,int>> adj[500005];
int dist[500005], vs[500005];
signed main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    int n,m;
    cin >> n >> m;
    for (int i = 1;i <= m;i++) {
        int u,v,w;
        cin >> u >> v >> w;
        adj[u].push_back({v,w});
        adj[v].push_back({u,w});
    }
    for (int i = 1;i <= n;i++) dist[i] = 9e18;

    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;

    pq.push({0,1});
    dist[1] = 0;
    int total = 0;
    while (!pq.empty()) {
        auto u = pq.top();
        pq.pop();

        if (vs[u.second]) continue;
        vs[u.second] = 1;
        total += u.first;
        for (auto &x : adj[u.second]) {
            pair<int,int> p = make_pair(x.second,x.first);
            if (vs[p.second]) continue;
            if (p.first >= dist[p.second]) continue;
            dist[p.second] = p.first;
            pq.push(p);
        }
    }
    cout << total;
    return 0;
}
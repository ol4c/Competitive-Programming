#include <bits/stdc++.h>
#define int long long
using namespace std;

vector<pair<int,int>> adj[100005];
int dist[100005];
int par[100005];
signed main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n,m,st,en;
    cin >> n >> m >> st >> en;
    for (int i = 1;i <= m;i++) {
        int x,y,z;
        cin >> x >> y >> z;
        adj[x].push_back({y,z});
        adj[y].push_back({x,z});
        dist[x] = 1e15;
        dist[y] = 1e15;
    }

    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
    dist[st] = 0;
    par[st] = -1;
    pq.push({0,st});
    while (!pq.empty()) {
        auto u = pq.top();
        pq.pop();
        if (u.first > dist[u.second]) continue;
        for (auto &x : adj[u.second]) {
            pair<int,int> p = {u.first+x.second,x.first};
            if (p.first >= dist[p.second]) continue;
            dist[p.second] = p.first;
            par[p.second] = u.second;
            pq.push(p);
        }
    }
    cout << dist[en] << "\n";
    vector<int> ans;
    int idx = en;
    ans.push_back(idx);
    while (1) {
        if (par[idx] != -1) {
            ans.push_back(par[idx]);
            idx = par[idx];
        } else break;
    }
    reverse(ans.begin(),ans.end());
    cout << ans.size() << "\n";
    for (auto &x : ans) cout << x << " ";
    return 0;
}
#include <bits/stdc++.h>
#define int long long
using namespace std;

vector<pair<int,int>> adj[100005];
int dist[100005];
signed main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    int n,m;
    cin >> n >> m;
    for (int i = 1;i <= m;i++) {
        int x,y,z;
        cin >> x >> y >> z;
        adj[x].push_back({y,z});
        dist[x] = 1e15;
        dist[y] = 1e15;
    }

    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
    pq.push({0,1});
    dist[1] = 0;
    while (!pq.empty()) {
        pair<int,int> u = pq.top();
        pq.pop();
        if (u.first > dist[u.second]) continue;
        for (auto &x : adj[u.second]) {
            pair<int,int> p = {u.first+x.second,x.first};
            if (p.first >= dist[p.second]) continue;
            dist[p.second] = p.first;
            pq.push(p);
        }
    }
    for (int i = 1;i <= n;i++) {
        cout << dist[i] << " ";
    }
    return 0;
}
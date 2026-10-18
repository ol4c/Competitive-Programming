#include <bits/stdc++.h>
#define int long long
using namespace std;

vector<pair<int,int>> adj[10005];
int dist[10005];
priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
int32_t main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    int n,m,st,en;
    cin >> n >> m >> st >> en;
    for (int i = 1;i <= m;i++){
        int x,y,z;
        cin >> x >> y >> z;
        // x,y = node | z = weight
        adj[x].push_back({y,z});
        adj[y].push_back({x,z});
        dist[x] = 1e15;
        dist[y] = 1e15;
    }
    dist[st] = 0;
    pq.push({0,st}); // .first = dist, .second = node
    while (!pq.empty()) {
        auto u = pq.top();
        pq.pop();

        if (u.first > dist[u.second]) continue; // check if pushed pair is actually the best option, if not do not continue
        for (auto &x : adj[u.second]) {
            pair<int,int> p = {u.first+x.second, x.first}; // create new pair
            if (p.first >= dist[p.second]) continue; // if calculated pair is worse then do not bother calculating
            dist[p.second] = p.first; 
            pq.push(p);
        }
    }
    cout << dist[en];
    

    return 0;
}
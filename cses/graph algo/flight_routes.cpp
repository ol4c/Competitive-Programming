#include <bits/stdc++.h>
#define int long long
using namespace std;

vector<pair<int,int>> adj[100005];
vector<multiset<int>> dist(100005);
signed main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    int n,m,k;
    cin >> n >> m >> k;
    for (int i = 1;i <= m;i++) {
        int u,v,w;
        cin >> u >> v >> w;
        adj[u].push_back({v,w});
    }

    priority_queue<pair<int,int> , vector<pair<int,int>>, greater<>> pq;
    pq.push({0,1});
    while (!pq.empty()) {
        auto u = pq.top();
        pq.pop();

        if (dist[u.second].size() == k && u.first > *dist[u.second].rbegin()) continue;
        for (auto &x :adj[u.second]) {
            int new_d = u.first + x.second;
            if (dist[x.first].size() < k) {
                dist[x.first].insert(new_d);
                pq.push({new_d,x.first});
            } else if (*dist[x.first].rbegin() > new_d) {
                dist[x.first].erase(prev(dist[x.first].end()));
                dist[x.first].insert(new_d);
                pq.push({new_d,x.first});
            }
        }
    }

    for (auto &x : dist[n]) cout << x << " ";
    return 0;
}
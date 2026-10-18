#include <bits/stdc++.h>
#define int long long
using namespace std;

vector<pair<int,int>> adj[30100];
vector<int> dist[55];
int idx[30100];
signed main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    int n,m,k,q;
    cin >> n >> m >> k >> q;
    for (int i = 1;i <= m;i++) {
        int x,y,z;
        cin >> x >> y >> z;
        adj[x].push_back({y,z});
        adj[y].push_back({x,z});
    }

    for (int i = 1;i <= k;i++) {
        int a;
        cin >> a;
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
        dist[i].assign(n+5,1e15);
        idx[a] = i;
        pq.push({0,a});
        dist[i][a] = 0;
        while (!pq.empty()) {
            auto u = pq.top();
            pq.pop();

            if (u.first > dist[i][u.second]) continue;
            for (auto &x : adj[u.second]){
                pair<int,int> p = {u.first+x.second,x.first};
                if (p.first >= dist[i][p.second]) continue;
                pq.push(p);
                dist[i][p.second] = p.first;
            }
        }
    }
    while (q--) {
        int x,y,z;
        cin >> x >> y >> z;
        cout << dist[idx[y]][x]+dist[idx[y]][z] << "\n";
    }
    return 0;
}
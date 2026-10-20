#include <bits/stdc++.h>
using namespace std;

struct Edge {
    int u,v,w;
};
vector<Edge> edges;
int dist[100005];
int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    int n,m,src;

    cin >> n >> m >> src;
    for (int i = 1;i <= m;i++) {
        Edge e;
        cin >> e.u >> e.v >> e.w;
        edges.push_back(e);
    }
    fill(dist, dist + 100005, 100000000);
    dist[src] = 0;
    for (int i = 1;i <= n-1;i++) {
        bool change = 0;
        for (auto &x : edges) {
            if (dist[x.u] != 1e8 && dist[x.u] + x.w < dist[x.v]) {
                dist[x.v] = dist[x.u] + x.w;
                change = 1;
            }
        }
        if (!change) break;
    }
    bool ch = 0;
    for (auto &x : edges) {
        if (dist[x.u] != 1e8 && dist[x.u] + x.w < dist[x.v]) {
            ch = 1;
            break;
        }
    }

    if (ch) cout << "Negative edge cycle detected";
    else {
        for (int i = 1;i <= n;i++) {
            cout << i << ": " << dist[i] << "\n";
        }
    }
    return 0;
}
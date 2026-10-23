#include <bits/stdc++.h>
using namespace std;

vector<int> adj[100005];
vector<int> indeg(100005);
int dist[100005];
int par[100005];

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    int n,m;
    cin >> n >> m;
    for (int i = 1;i <= m;i++) {
        int u,v;
        cin >> u >> v;
        adj[u].push_back(v);
        indeg[v]++;
    }
    for (int i = 1;i <= n;i++) {
        dist[i] = -1e9;
    }
    queue<int> q;
    par[1] = -1;
    dist[1] = 1;

    for (int i = 1;i<= n;i++) {
        if(indeg[i] == 0) q.push(i);
    }
    while (!q.empty()) {
        int u = q.front();
        q.pop();

        for (auto &x : adj[u]) {
            if (dist[u] + 1 > dist[x] && dist[u] > 0) {
                dist[x] = dist[u] + 1;
                par[x] = u;
            }

            indeg[x]--;
            if (indeg[x] == 0) q.push(x);
        }
    }

    if (dist[n] < 0) cout << "IMPOSSIBLE";
    else {
        cout << dist[n] << "\n";
        vector<int> ans;
        for (int i = n; i != -1;i = par[i]) {
            ans.push_back(i);
        }
        reverse(ans.begin(),ans.end());
        for (auto &x : ans) cout << x << " ";
        
    }
    return 0;
}
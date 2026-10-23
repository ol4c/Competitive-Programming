#include <bits/stdc++.h>
#define int long long
using namespace std;

vector<pair<int,pair<int,int>>> edges;
vector<int> adj1[2505];
vector<int> adj2[2505];
bool vs1[2505];
bool vsn[2505];
int dist[2505];
signed main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n,m;
    cin >> n >> m;

    for (int i = 1;i <= m;i++) {
        int u,v,w;
        cin >> u >> v >> w;
        adj1[u].push_back(v);
        adj2[v].push_back(u);
        edges.push_back({-w,{u,v}});
    }
    for (int i = 1;i <= n;i++) {
        dist[i] = 1e15;
    }
    
    queue<int> q;
    q.push(1);
    vs1[1] = 1;
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        for (auto &x : adj1[u]) {
            if(vs1[x]) continue;
            vs1[x] = 1;
            q.push(x);
        }
    }

    q.push(n);
    vsn[n] = 1;
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        for (auto &x : adj2[u]) {
            if(vsn[x]) continue;
            vsn[x] = 1;
            q.push(x);
        }
    }

    vector<pair<int,pair<int,int>>> good;
    for (auto &x : edges) {
        if (vs1[x.second.first] && vsn[x.second.first] && vs1[x.second.second] && vsn[x.second.second]) good.push_back(x);
    }

    dist[1] = 0;
    for (int i = 1;i <= n-1;i++) {
        for (auto &x : good) {
            if (dist[x.second.first] == 1e15) continue;
            if (dist[x.second.first] + x.first < dist[x.second.second]) {
                dist[x.second.second] = dist[x.second.first] + x.first;
            }
        }
    }
    bool ch=1;
    for (auto &x : good) {
        if (dist[x.second.first] == 1e15) continue;
        if (dist[x.second.first] + x.first < dist[x.second.second]) {
            ch = 0;
            break;
        }
    }

    if (!ch) cout << -1;
    else cout << -dist[n];
    return 0;
}
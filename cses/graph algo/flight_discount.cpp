#include <bits/stdc++.h>
#define int long long
using namespace std;

vector<pair<int,int>> adj1[100005];
vector<pair<int,int>> adjn[100005];
vector<pair<int,pair<int,int>>> edges;
int dist1[100005];
int distn[100005];
signed main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n,m;
    cin >> n >> m;
    for (int i = 1;i <= m;i++) {
        int u,v,w;
        cin >> u >> v >> w;
        adj1[u].push_back({v,w});
        adjn[v].push_back({u,w});
        edges.push_back({w,{u,v}});
    }
    for (int i = 1;i <= n;i++) {
        dist1[i] = 1e15;
        distn[i] = 1e15;
    }

    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
    pq.push({0,1});
    dist1[1] = 0;
    while (!pq.empty()) {
        auto u = pq.top();
        pq.pop();
        if (u.first > dist1[u.second]) continue;
        for (auto &x : adj1[u.second]) {
            pair<int,int> p = {u.first+x.second,x.first};
            if (p.first >= dist1[p.second]) continue;
            dist1[p.second] = p.first;
            pq.push(p);
        }
    }

    pq.push({0,n});
    distn[n] = 0;
    while (!pq.empty()) {
        auto u = pq.top();
        pq.pop();
        if (u.first > distn[u.second]) continue;
        for (auto &x : adjn[u.second]) {
            pair<int,int> p = {u.first+x.second,x.first};
            if (p.first >= distn[p.second]) continue;
            distn[p.second] = p.first;
            pq.push(p);
        }
    }
    int mn = 1e15;
    for (auto &x : edges) {
        mn = min(mn,dist1[x.second.first] + (x.first / 2) + distn[x.second.second]);
    }
    cout << mn;
    return 0;
}
#include <bits/stdc++.h>
#define int long long
using namespace std;

vector<pair<int,int>> adj1[100005];
vector<pair<int,int>> adj2[100005];
int dist1[100005];
int dist2[100005];
signed main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    int n,m,q,s,t;
    cin >> n >> m >> q >> s >> t;
    for (int i = 1;i <= m;i++) {
        int x,y,z;
        cin >> x >> y >> z;
        adj1[x].push_back({y,z});
        adj2[y].push_back({x,z});
        dist1[x] = 1e15;
        dist1[y] = 1e15;
        dist2[x] = 1e15;
        dist2[y] = 1e15;
    }

    // dijk from s
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
    dist1[s] = 0;
    pq.push({0,s});
    while (!pq.empty()) {
        auto u = pq.top();
        pq.pop();

        for (auto &x : adj1[u.second]) {
            pair<int,int> p = {u.first+x.second,x.first};
            if (p.first >= dist1[p.second]) continue;
            pq.push(p);
            dist1[p.second] = p.first;
        }
    }

    // dijk from t
    dist2[t] = 0;
    pq.push({0,t});
    while (!pq.empty()) {
        auto u = pq.top();
        pq.pop();

        for (auto &x : adj2[u.second]) {
            pair<int,int> p = {u.first+x.second,x.first};
            if (p.first >= dist2[p.second]) continue;
            pq.push(p);
            dist2[p.second] = p.first;
        }
    }

    while (q--) {
        int k;
        cin >> k;
        cout << dist1[k] + dist2[k] << "\n";
    }
    
    return 0;
}
#include <bits/stdc++.h>
#define int long long
using namespace std;

int MOD = 1e9+7;
vector<pair<int,int>> adj[100005];
int dist[100005];
int route[100005];
int mini[100005];
int maxi[100005];
signed main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    int n,m;
    cin >> n >> m;
    for (int i = 1;i <= m;i++) {
        int x,y,z;
        cin >> x >> y >> z;
        adj[x].push_back({y,z});
    }
    for (int i = 1;i <= n;i++) {
        dist[i] = 1e15;
;    }
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<>> pq;
    pq.push({0,1});
    dist[1] = 0;
    route[1] = 1;
    mini[1] = 0;
    maxi[1] = 0;
    while (!pq.empty()) {
        auto u = pq.top();
        pq.pop();
        //if (u.first > dist[u.second]) continue;
        for (auto &x : adj[u.second]) {
            pair<int,int> p = {u.first+x.second,x.first};

            if (p.first < dist[p.second]) {
                dist[p.second] = p.first;
                mini[p.second] = mini[u.second] + 1;
                maxi[p.second] = maxi[u.second] + 1;
                route[p.second] = route[u.second] % MOD;
                pq.push(p);
            }
            else if (p.first == dist[p.second]) {
                route[p.second] = (route[u.second]+route[p.second]) % MOD;
                mini[p.second] = min(mini[p.second],mini[u.second] + 1);
                maxi[p.second] = max(maxi[p.second],maxi[u.second] + 1);
            }
        }
    }
    cout << dist[n] << " " << route[n] << " " << mini[n] << " " << maxi[n];
    return 0;
}
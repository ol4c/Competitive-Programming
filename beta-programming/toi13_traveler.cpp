#include <bits/stdc++.h>
#define int long long
using namespace std;

vector<pair<int,int>> adj[10005];
int dist1[10005];
int dist2[10005];
signed main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n,m;
    cin >> n >> m;
    int st,en,b;
    cin >> st >> en >> b;
    for (int i = 1;i <= m;i++) {
        int x,y,z;
        cin >> x >> y >> z;
        adj[x].push_back({y,z});
        adj[y].push_back({x,z});
        dist1[x] = 1e15;
        dist1[y] = 1e15;
        dist2[x] = 1e15;
        dist2[y] = 1e15;
    }

    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
    pq.push({0,st});
    dist1[st] = 0;
    while (!pq.empty()) {
        auto u = pq.top();
        pq.pop();

        if (u.first > dist1[u.second]) continue;
        for (auto &x : adj[u.second]) {
            pair<int,int> p = {u.first+x.second,x.first};
            if (p.first >= dist1[p.second]) continue;
            dist1[p.second] = p.first;
            pq.push(p);
        }
    }

    if (dist1[en] <= b) {
        cout << en << " " << dist1[en] << " 0";
    } else {
        pq.push({0,en});
        dist2[en] = 0;
        while (!pq.empty()) {
            auto u = pq.top();
            pq.pop();

            if (u.first > dist2[u.second]) continue;
            for (auto &x : adj[u.second]) {
                pair<int,int> p = {u.first+x.second,x.first};
                if (p.first >= dist2[p.second]) continue;
                dist2[p.second] = p.first;
                pq.push(p);
            }
        }
        int bd = 1e15;
        int bn = 1e15;
        for (int i=0;i < n;i++) {
            if (dist1[i] <= b) {
                if (dist2[i] <= bd) {
                    if (dist2[i] == bd) {
                        bn = min(i,bn);
                    } else {
                        bd = dist2[i];
                        bn = i;
                    }
                }
            }
        }
        //cout <<dist1[4] << " " <<  dist2[4] << endl;
        cout << bn << " " << dist1[bn] << " " << bd;
    }

    

    return 0;
}
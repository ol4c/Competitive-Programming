#include <bits/stdc++.h>
using namespace std;

int head[3005], sz[3005];

int findhead(int i) {
    if (head[i] ==  i) return i;
    return head[i] = findhead(head[i]);
}

void unionhead(int u, int v) {
    u = findhead(u);
    v = findhead(v);

    if (u != v) {
        if (sz[u] > sz[v]) {
            head[v] = u;
            sz[u] += sz[v];
        } else {
            head[u] = v;
            sz[v] += sz[u];
        }
    }
}
int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    int n,m;
    cin >> n >> m;
    for (int i = 0;i < n;i++) {
        head[i] = i;
        sz[i]= 1; 
    }   
    vector<pair<int,pair<int,int>>> vec;
    for (int i = 1;i <= m;i++) {
        int u,v,w,x;
        cin >> u >> v >> w >> x;
        if (x) {
            unionhead(u,v);
        } else {
            vec.push_back({w,{u,v}});
        }
    }

    int q;
    cin >> q;
    vector<pair<int,int>> pr;
    while (q--) {
        int a,b;
        cin >> a >> b;
        pr.push_back({a,b});
    }
    sort(pr.begin(),pr.end(),[](const auto&a, const auto&b) {
        return a.second < b.second;
    });
    vector<pair<int,pair<int,int>>> real;
    for (auto &x : vec) {
        for (auto &y : pr) {
            if (x.first <= y.first) {
                real.push_back({y.second,{x.second.first,x.second.second}});
                break;
            }
        }
    }
    sort(real.begin(),real.end());
    int cost = 0;
    for (auto &x : real) {
        int u = findhead(x.second.first);
        int v = findhead(x.second.second);
        if (u != v) {
            cost += x.first;
            unionhead(u,v);
        }
    }
    cout << cost;
    return 0;
}
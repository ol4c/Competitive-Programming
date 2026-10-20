#include <bits/stdc++.h>
#define int long long
using namespace std;
struct Edge {
    int u,v,w;

    bool operator<(const auto &o) const {
        return w > o.w;
    }
};
vector<Edge> vec;
int head[500005], sz[500005];
int findhead(int i) {
    if (head[i] == i) return i;
    head[i] = findhead(head[i]);
    return head[i];
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
signed main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    int n,m;
    cin >> n >> m;

    for (int i = 1;i <= n;i++) {
        sz[i] = 1;
        head[i] = i;
    }
    for (int i = 1;i <= m;i++) {
        Edge e;
        cin >> e.u >> e.v >> e.w;
        vec.push_back(e);
    }
    sort(vec.begin(),vec.end());
    int total = 0;
    for (auto &x : vec) {
        int u = x.u;
        int v = x.v;

        u = findhead(u);
        v = findhead(v);
        if (u != v) {
            total += x.w - 1;
            unionhead(u,v);
        }
    }
    cout << total;
    return 0;
}
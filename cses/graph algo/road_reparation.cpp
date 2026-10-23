#include <bits/stdc++.h>
#define int long long
using namespace std;

vector<pair<int,pair<int,int>>> edges;
int head[100005], sz[100005];
int findhead(int i) {
    if (head[i] == i) return i;
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
int32_t main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    int n,m;
    cin >> n >> m;
    int compo = n;
    for (int i = 1;i <= m;i++) {
        int x,y,z;
        cin >> x >> y >> z;
        edges.push_back({z,{x,y}});
    }
    for (int i = 1;i <= n;i++) {
        head[i] = i;
        sz[i] = 1;
    }
    int total = 0;
    sort(edges.begin(),edges.end());
    for (auto &x : edges) {
        int u = findhead(x.second.first);
        int v = findhead(x.second.second);
        if (u != v) {
            total += x.first;
            compo--;
            unionhead(u,v);
        }
    }
    if (compo == 1) {
        cout << total;
    } else cout << "IMPOSSIBLE";
    
    return 0;
}
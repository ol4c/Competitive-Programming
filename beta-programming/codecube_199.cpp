#include <bits/stdc++.h>
#define int long long
using namespace std;
map<pair<int,pair<int,int>>,int> mp;
vector<pair<int,pair<int,int>>> edges;
int head[100005], sz[100005];
bool check[100005];
int findhead(int i) {
    if (head[i] == i) return i;
    return head[i] = findhead(head[i]);
}

void unionhead(int u,int v) {
    u = findhead(u);
    v = findhead(v);

    if (u != v) {
        if (sz[u] > sz[v]) {
            sz[u] += sz[v];
            head[v] = u; 
        } else {
            sz[v] += sz[u];
            head[u] = v; 
        }
    }
}
signed main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n,m;
    cin >> n >> m;
    for (int i = 1;i <= m;i++) {
        int u,v,w;
        cin >> u >> v >> w;
        edges.push_back({w,{u,v}});
        mp[{w,{u,v}}] = i;
    }
    int choice;
    cin >> choice;
    int compo = n;
    sort(edges.begin(),edges.end(),greater<pair<int,pair<int,int>>>());
    for (int i = 1;i <= n;i++) {
        sz[i] = 1;
        head[i] = i;
    }
    int total = 0;
    vector<int> ans;
    for (auto &x : edges) {
        int u = findhead(x.second.first);
        int v = findhead(x.second.second);
        if (u != v) {
            total += x.first;
            unionhead(u,v);
            compo--;
            ans.push_back(mp[x]);
            check[mp[x]] = 1;
        }
    }
    bool used = 0;
    for (auto &x : edges) {
        if (ans.size() == n) break;
        if (check[mp[x]] != 1) {
            used = 1;
            ans.push_back(mp[x]);
            total += x.first;
        }
    }

    if (!used) {
        cout << -1;
        return 0;
    }
    if (compo == 1) {
        cout << total << "\n";
        if (choice == 2) {
            for (auto &x : ans) cout << x << " ";
        }
    } else {
        cout << -1;
    }

    return 0;
}
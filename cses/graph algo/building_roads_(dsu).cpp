#include <bits/stdc++.h>
using namespace std;
int n,m;
int head[100005], sz[100005];
vector<pair<int,int>> vec;
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

void unionhead2(int u, int v) {
    u = findhead(u);
    v = findhead(v);
    if (u != v) {
        vec.push_back({u,v});
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
    cin >>n >> m;
    for (int i = 1;i <= n;i++) {
        head[i] = i;
        sz[i] = 1;
    }

    for (int i = 1;i <= m;i++) {
        int a,b;
        cin >> a >> b;
        unionhead(a,b);
    }

    for (int i = 2;i <= n;i++) {
        unionhead2(i,1);
    }

    cout << vec.size() << "\n";
    for (auto &x : vec) {
        cout << x.first << " " << x.second << "\n";
    }

    return 0;
}
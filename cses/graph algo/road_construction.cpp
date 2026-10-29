#include <bits/stdc++.h>
using namespace std;

int head[100005], sz[100005]; 
int mx = 1;
int findhead(int i) {
    if (head[i] == i) return i;
    return head[i] = findhead(head[i]);
}

void unionhead(int u, int v) {
    u = findhead(u);
    v = findhead(v);
    if (u != v) {
        if (sz[u] > sz[v]) {
            sz[u] += sz[v];
            head[v] = u;
            mx = max(sz[u],mx);
        } else {
            sz[v] += sz[u];
            head[u] = v;
            mx = max(sz[v],mx);
        }
    }
}
int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    int n,m;
    cin >> n >> m;
    for (int i = 1;i <= n;i++) {
        head[i] = i;
        sz[i] = 1;
    }
    int compo = n;
    
    for (int i = 1;i <= m;i++) {
        int u,v;
        cin >> u >> v;
        u = findhead(u);
        v = findhead(v);
        if (u != v) {
            compo--;
            unionhead(u,v);
            cout << compo << " " << mx << "\n";
        } else {
            cout << compo << " " << mx << "\n";
        }

    }
    return 0;
}
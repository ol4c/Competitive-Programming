#include <bits/stdc++.h>
using namespace std;
int n,m, comp;
int head[10005], sz[10005];
int findhead(int i) {
    if (head[i] == i) return i;
    head[i] = findhead(head[i]);
    return head[i];
}

void unionhead(int u, int v) {
    u = findhead(u);
    v = findhead(v);
    if (u != v) {
        comp--;
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
    cin >> n >> m;
    for (int i = 1;i <= n;i++) {
        head[i] = i;
        sz[i] = 1;
    }
    comp = n;
    for (int i = 1;i <= m;i++) {
        int a,b;
        cin >> a >> b;
        unionhead(a,b);
    }
    cout << comp;

    return 0;
}
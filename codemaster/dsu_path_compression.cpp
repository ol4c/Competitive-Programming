#include <bits/stdc++.h>
using namespace std;
int n,m, comp;
int head[10005];
int findhead(int i) {
    if (head[i] == i) return i;
    head[i] = findhead(head[i]);
    return head[i];
}

void unionhead(int u, int v) {
    u = findhead(u);
    v = findhead(v);
    if (u != v) {
        head[v] = u;
        comp--;
    }
}
int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> m;
    for (int i = 1;i <= n;i++) {
        head[i] = i;
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
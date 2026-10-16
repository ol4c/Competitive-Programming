#include <bits/stdc++.h>
using namespace std;
int vs[10005];
vector<int> adj[10005];
bool ch = 1;
void sol(int now) {
    if (!ch) return;
    for (auto &x : adj[now]) {
        if (vs[x] == 0) {
            if (vs[now] == 1) vs[x] = 2;
            else vs[x] = 1;
            sol(x);
        }

        if (vs[x] == vs[now]) {
            ch =0;
            break;
        }
    }
}
int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    int n,e;
    cin >> n >> e;
    
    for (int i = 1;i <= e;i++) {
        int x,y;
        cin >> x >> y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    vs[0] = 1;
    sol(0);
    cout << ch;
    return 0;
}
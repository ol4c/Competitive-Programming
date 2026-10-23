#include <bits/stdc++.h>
using namespace std;

vector<int> adj[100005];
int color[100005];
vector<int> ans;
int ch = 0;
void sol(int now) {
    if (ch) return;
    for (auto &x :adj[now]) {
        if (color[x] == 0) {
            color[x] = 1;
            sol(x);
            if (ch) return;
            ans.push_back(x);
        } else if (color[x] == 1) {
            ch = 1;
            break;
        }
    }
    color[now] = 2;
    
}
int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    int n,m;
    cin >> n >> m;
    for (int i = 1;i <= m;i++) {
        int u,v;
        cin >> u >> v;
        adj[u].push_back(v);
    }
    for (int i = 1;i <= n;i++) {
        if (color[i] == 0) {
            color[i] = 1;
            sol(i);
            ans.push_back(i);
        }
    }
    if (ch) cout << "IMPOSSIBLE";
    else {
        reverse(ans.begin(),ans.end());
        for (auto &x : ans) cout << x << " ";
    }
    
    return 0;
}
#include <bits/stdc++.h>
using namespace std;

vector<int> adj[100005];
int color[100005];
int par[100005];
bool check[100005];
bool ch = 0;
void sol(int now) {
    if (ch) return;
    for (auto x : adj[now]) {
        if (color[x] == 0) {
            par[x] = now;
            color[x] = 1;
            sol(x); 
            if (ch) return;
        }
        else if (color[x] == 1) {
            ch = 1;
            vector<int> ans;
            ans.push_back(x);
            for (int i = now;i != x && check[i] == 0;i = par[i]) {
                check[i]= 1;
                ans.push_back(i);
            }
            ans.push_back(x);
            reverse(ans.begin(),ans.end());
            cout << ans.size() << "\n";
            for (auto &k : ans) {
                cout << k << " ";
            }
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
            par[i] = -1;
            sol(i);
        }
        if (ch) break;
    }
    if (!ch) {
        cout << "IMPOSSIBLE";
    }
    return 0;
}
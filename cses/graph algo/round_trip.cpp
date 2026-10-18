#include <bits/stdc++.h>
using namespace std;

vector<int> adj[100005];
int color[100005];
int par[100005];
bool ch = 0;
void sol(int now, int p) {
    if (ch) return;
    for (auto &x : adj[now]) {
        if (color[x] == 0) {
            color[x] = 1;
            par[x] = now;
            sol(x,now);
        }
        else if (color[x] == 1 && p != x) {
            ch = 1;
            vector<int> ans;
            ans.push_back(x);
            int idx = now;
            while (1) {
                if (idx == x) break;
                ans.push_back(idx);
                idx = par[idx];
            }
            ans.push_back(x);
            cout << ans.size() << "\n";
            for (auto &x :ans) {
                cout << x << " ";
            }
            return;
        }
        if (ch) return;
    }
    color[now] = 2;
}
int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    int n,e;
    cin >> n >> e;
    for (int i = 1;i <= e;i++) {
        int a,b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    for (int i = 1;i <= n;i++) {
        if (color[i]== 0) {
            color[i] = 1;
            par[i] = -1;
            sol(i,-1);
            if (ch) return 0;
        }     
    }
    if (!ch) cout << "IMPOSSIBLE";
    return 0;
}
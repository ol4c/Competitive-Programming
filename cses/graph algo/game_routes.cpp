#include <bits/stdc++.h>

#define int long long
using namespace std;
const int MOD = 1e9+7;
vector<int> adj[100005];
int indeg[100005];
int dp[100005];
signed main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n,m;
    cin >> n >> m;
    for (int i = 1;i <= m;i++) {
        int u,v;
        cin >> u >> v;
        adj[u].push_back(v);
        indeg[v]++;
    }

    queue<int> q;
    dp[1]= 1;
    for (int i = 1;i <= n;i++) {
        if (indeg[i] == 0) q.push(i);
    }
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        for (int &x : adj[u]) {
            dp[x] = (dp[u] + dp[x]) % MOD;
            indeg[x]--;
            if (indeg[x] == 0) q.push(x); 
        }
    }
    cout << dp[n];

    return 0;
}
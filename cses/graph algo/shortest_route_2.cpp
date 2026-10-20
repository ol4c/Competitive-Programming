#include <bits/stdc++.h>
#define int long long
using namespace std;

int dist[505][505];
signed main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n,m,q;
    cin >> n >> m >> q;
    for (int i=1;i <= n;i++) {
        for (int j =1;j <= n;j++) {
            if (i == j) {
                dist[i][j] = 0;
                continue;
            }
            dist[i][j] = 9e18;
        }
    }

    for (int i = 1;i <= m;i++) {
        int u,v,w;
        cin >> u >> v >> w;
        dist[u][v] = min(w,dist[u][v]);
        dist[v][u] = min(w,dist[v][u]);
    }
    for (int k = 1;k <= n;k++) {
        for (int i=1;i <= n;i++) {
            for (int j =1;j <= n;j++) {
                if (dist[i][k] == 9e18 || dist[k][j] == 9e18) continue;

                dist[i][j] = min(dist[i][j],dist[i][k] + dist[k][j]); 
            }
        }
    }

    while (q--) {
        int a,b;
        cin >>a>>b;
        if(dist[a][b] == 9e18) cout << "-1\n";
        else cout << dist[a][b] << "\n";
    }

    return 0;
}
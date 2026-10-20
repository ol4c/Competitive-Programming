#include <bits/stdc++.h>
using namespace std;

int dist[1005][1005];
int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    int n,m;
    cin >> n >> m;
    for (int i = 1;i <= m;i++) {
        int u,v,w;
        cin >> u >> v >> w;
        dist[u][v] = w;
    }
    for (int i = 1;i <= n;i++) {
        for (int j = 1;j <= n;j++) {
            if (i==j) continue;
            if (dist[i][j] == 0) dist[i][j] = 1e9;
        }
    }

    for (int k = 1;k <= n;k++) {
        for (int i = 1;i <= n;i++) {
            for (int j = 1;j <= n;j++) {
                if (dist[i][k] == 1e9 || dist[k][j] == 1e9) continue;
                dist[i][j] = min(dist[i][j],dist[i][k] + dist[k][j]);
            }
        }
    }

    for (int i = 1;i <= n;i++) {
        for (int j = 1;j <= n;j++) {
            if (dist[i][j] == 1e9) cout << "-1 ";
            else cout << dist[i][j] << " ";
        }
        cout << "\n";
    }
    return 0;
}
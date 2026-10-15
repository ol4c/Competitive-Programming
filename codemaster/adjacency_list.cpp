#include <bits/stdc++.h>
using namespace std;
vector<int> adj[1005];
// 1-n
int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n,m;
    cin >> n >> m;
    for (int i = 1;i <= m;i++) {
        int x,y;
        cin >> x >> y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    for (int i = 1;i <= n;i++) {
        cout << i << "\n";
        for (int j = 0;j < adj[i].size();j++) {
            cout << adj[i][j] << " ";
        }
        cout << "\n";
    }

    return 0;
}
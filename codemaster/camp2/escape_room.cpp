#include <bits/stdc++.h>
using namespace std;

vector<int> adj[200005];
bool arr[200005];
int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    int n;
    cin >> n;
    for (int i = 0;i < n;i++) {
        int m;
        cin >> m;
        for (int j = 0;j < m;j++) {
            int k;
            cin >> k;
            adj[i].push_back(k);
        }
    }

    queue<int> q;
    q.push(0);
    arr[0] = 1;
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        for (auto &x : adj[u]) {
            if (arr[x]) continue;
            arr[x] = 1;
            q.push(x);
        }
    }
    for (int i = 0;i < n;i++) {
        if (arr[i]) cout << "Yes\n";
        else cout << "No\n";
    }
    return 0;
}
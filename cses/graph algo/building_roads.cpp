#include <bits/stdc++.h>
using namespace std;

vector<int> adj[100005];
bool vs[100005];
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
    vector<int> st;
    vector<int> en;
    int cnt = 0;
    for (int i = 1;i<=n;i++) {
        if (!vs[i]) {
            // bfs
            queue<int> q;
            q.push(i);
            vs[i]=1;
            st.push_back(i);
            en.push_back(i-1);
            cnt++;
            while (!q.empty()) {
                auto u = q.front();
                q.pop();

                for (auto &x : adj[u]) {
                    if (vs[x]) continue;
                    vs[x] = 1;
                    q.push(x);
                }
            }
        }
    }
    cout << cnt - 1 << "\n";
    for (int i = 0;i < st.size();i++) {
        if (st[i] != 0 && en[i] != 0) {
            cout << st[i] << " " << en[i] << "\n";
        }
    }

    return 0;
}
#include <bits/stdc++.h>
#define int long long
using namespace std;

vector<pair<int,pair<int,int>>> edges;
int dist[2505];
int par[2505];
signed main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n,m;
    cin >> n >> m;
    for (int i = 1;i <= m;i++) {
        int u,v,w;
        cin >> u >> v >> w;
        edges.push_back({w,{u,v}});
    }
    for (int i = 1;i <= n-1;i++) {
        for (auto &x : edges) {
            if (dist[x.second.first] + x.first < dist[x.second.second]) {
                dist[x.second.second] = dist[x.second.first] + x.first;
                par[x.second.second] = x.second.first;
            }
        }
    }
    bool ch = 1;
    int last;
    for (auto &x : edges) {
        if (dist[x.second.first] + x.first < dist[x.second.second]) {
            dist[x.second.second] = dist[x.second.first] + x.first;
            par[x.second.second] = x.second.first;
            last = x.second.second;
            ch = 0;
        }
    }

    if (!ch) {
        cout << "YES\n";
        
        for (int i = 1;i <= n;i++) last = par[last];
        vector<int> ans;
        ans.push_back(last);
        for (int i = par[last];i != last;i = par[i]) {
            //cout << i << endl;
            ans.push_back(i);
        }
        ans.push_back(last);

        reverse(ans.begin(),ans.end());

        for (auto &x : ans) {
            cout << x << " ";
        }
    } else cout << "NO";

    return 0;
}
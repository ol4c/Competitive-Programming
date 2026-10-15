#include <bits/stdc++.h>
using namespace std;

vector<int> vec[100005];
vector<int> dist(100005,1e9);
int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n,m;
    cin >> n >> m;
    
    for (int i = 1;i <= m;i++) {
        int a,b;
        cin >> a >> b;
        vec[a].push_back(b);
        vec[b].push_back(a);
    }

    queue<pair<int,int>> q;
    dist[1] = 0;
    q.push({1,0});
    while (!q.empty()) {
        auto u = q.front();
        q.pop();

        for (int i = 0;i < vec[u.first].size();i++) {
            auto p = make_pair(vec[u.first][i],u.second+1);
            if (p.second < dist[p.first]) {
                dist[p.first] = p.second;
                q.push(p);
            }
        }
    }
    if (dist[n] != 1e9) {
        
        int idx = n;
        int hold = dist[n];
        vector<int> ans;
        ans.push_back(n);
        while (1) {
            for (auto &x : vec[idx]) {
                if (dist[x] == hold-1) {
                    hold = hold - 1;
                    idx = x;
                    ans.push_back(x);
                    break;
                }
            }
            if (idx == 1) break;
        }
        cout << ans.size() << "\n";
        for (int i = ans.size() - 1;i >= 0;i--) cout << ans[i] << " ";
        cout << "\n";
    } else {
        cout << "IMPOSSIBLE";
    }

    return 0;
}
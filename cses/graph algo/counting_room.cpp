#include <bits/stdc++.h>
using namespace std;

bool vs[1005][1005];
int dx[] = {0,0,1,-1};
int dy[] = {1,-1,0,0};
int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n,m;
    cin >> n >> m;
    vector<pair<int,int>> vec;
    for (int i = 1;i <= n;i++) {
        for (int j = 1;j <= m;j++) {
            char c;
            cin >> c;
            if(c == '.') {
                vec.push_back({i,j});
            } else {
                vs[i][j] = 1;
            }
        }
    }
    int cnt = 0;
    for (auto &x : vec) {
        queue<pair<int,int>> q;
        if (!vs[x.first][x.second]) {
            cnt++;
            q.push(x);
            vs[x.first][x.second] = 1;
            while (!q.empty()) {
                auto u = q.front();
                q.pop();

                for (int i = 0;i < 4;i++) {
                    auto p = make_pair(u.first+dx[i],u.second+dy[i]);
                    if (p.first < 1 || p.first > n || p.second < 1 || p.second > m) continue;
                    if (vs[p.first][p.second]) continue;
                    vs[p.first][p.second] = 1;
                    q.push(p);
                }
            }
        }   
    }
    cout << cnt;

    return 0;
}
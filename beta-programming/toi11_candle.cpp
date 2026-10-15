#include <bits/stdc++.h>
using namespace std;

bool vs[2005][2005];
int dx[] = {0,0,1,-1,1,1,-1,-1};
int dy[] = {1,-1,0,0,1,-1,1,-1};
int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n,m;
    vector<pair<int,int>> vec;
    cin >> n >> m;
    for (int i = 1;i <= n;i++) {
        for (int j = 1;j <= m;j++) {
            char k;
            cin >> k;
            if (k=='1') {
                vec.push_back({i,j});
            } else {
                vs[i][j] = 1;
            }
        }
    }
    int cnt = 0;
    for (auto &s : vec) {
        //cout << s.first << " " << s.second << endl;
        if(!vs[s.first][s.second]) {
            cnt++;
            
            queue<pair<int,int>> q;
            vs[s.first][s.second] = 1;
            q.push({s.first,s.second});
            while (!q.empty()) {
                auto u = q.front();
                q.pop();
                for (int i = 0;i < 8;i++) {
                    pair<int,int> p = {u.first+dx[i],u.second+dy[i]};
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
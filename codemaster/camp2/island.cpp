#include <bits/stdc++.h>
using namespace std;

bool table[2005][2005];
int dx[] = {0,0,1,-1,-1,-1,1,1};
int dy[] = {1,-1,0,0,1,-1,1,-1};
int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    int n,m;
    cin >> n >> m;
    for (int i = 1;i <= n;i++) {
        for (int j= 1;j <= m;j++) {
            char c;
            cin >> c;
            if (c == '.') table[i][j] = 1;
        }
    }
    int best = 0;
    for (int i = 1;i <= n;i++) {
        for (int j= 1;j <= m;j++) {
            if (!table[i][j]) {
                int cnt = 0;
                queue<pair<int,int>> q;
                q.push({i,j});
                table[i][j] = 1;
                while (!q.empty()) {
                    auto u = q.front();
                    q.pop();
                    cnt++;
                    for (int i = 0;i < 8;i++) {
                        pair<int,int> p = {u.first+dx[i],u.second+dy[i]};
                        if (p.first < 1 || p.first > n || p.second < 1 || p.second > m) continue;
                        if (table[p.first][p.second]) continue;
                        table[p.first][p.second] = 1;
                        q.push(p);
                    }
                }
                best = max(cnt,best);
            }
        }
    }
    cout << best;
    return 0;
}
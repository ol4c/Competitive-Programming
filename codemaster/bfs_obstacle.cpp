#include <bits/stdc++.h>
using namespace std;

bool vs[1005][1005];
int dist[1005][1005];

int dx[] = {0,0,-1,1};
int dy[] = {-1,1,0,0};
int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    memset(dist,-1,sizeof(dist));
    int n,m;
    cin >> n >> m;
    int sti,stj,eni,enj;
    for (int i = 1;i <= n;i++) {
        for (int j = 1;j <= m;j++) {
            char c;
            cin >> c;
            if(c == '#') {
                vs[i][j] = 1;
            }
        }
    }
    cin >> sti >> stj >> eni >> enj;
    queue<pair<int,int>> q;
    q.push({sti,stj});
    vs[sti][stj] = 1;
    dist[sti][stj] = 0;
    while (!q.empty()) {
        auto u = q.front();
        q.pop();
        
        if (u.first == eni && u.second == enj) break;
        
        for (int i = 0;i < 4;i++) {
            auto p = make_pair(u.first+dx[i],u.second+dy[i]);
            //cout << u.first << " " << u.second << "\n";
            if (p.first < 1 || p.first > n || p.second < 1 || p.second > m) continue;
            if (vs[p.first][p.second]) continue;;
            vs[p.first][p.second] = 1;
            dist[p.first][p.second] = dist[u.first][u.second] + 1;
            
            q.push(p);
        }
    }
    cout << dist[eni][enj];
    return 0;
}
#include <bits/stdc++.h>
using namespace std;

bool table[1005][1005];
int dist[1005][1005];
int dx[] = {0,0,1,-1};
int dy[] = {1,-1,0,0};
// r,l,d,u
int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    int n,m,sti,stj,eni,enj;
    cin >> n >> m;
    for (int i = 1;i <= n;i++) {
        for (int j = 1;j <= m;j++) {
            char c;
            cin >> c;
            if (c=='#') {
                table[i][j] = 1;
            } else {
                if (c == 'A') {
                    sti = i; stj = j;
                } else if (c=='B') {
                    eni = i; enj = j;
                }
            }
            dist[i][j] = 1e9;
        }
    }

    //bfs
    queue<pair<int,int>> q;
    dist[sti][stj] = 0;
    table[sti][stj] = 1;
    q.push({sti,stj});
    while (!q.empty()) {
        auto u = q.front();
        q.pop();

        for (int i = 0;i < 4;i++) {
            pair<int,int> p = {u.first+dx[i],u.second+dy[i]};
            if (p.first < 1 || p.first > n || p.second < 1 || p.second > m) continue;
            if (table[p.first][p.second]) continue;
            table[p.first][p.second] = 1;
            dist[p.first][p.second] = dist[u.first][u.second] + 1;
            q.push(p);
        }
    }

    if (dist[eni][enj] == 1e9) {
        cout << "NO\n";
    } else {
        int ii = eni;
        int jj = enj;
        string ans;
        while (1) {
            if (ii == sti && jj == stj) break;
            for (int i = 0;i < 4;i++) {
                int ni = ii+dx[i];
                int nj = jj + dy[i];
                if (ni < 1 || ni > n || nj < 1 || nj > m) continue;
                if(dist[ii][jj] - 1 == dist[ni][nj]) {
                    ii = ni;
                    jj = nj;
                    if (i == 0) {
                        ans += 'L';
                    } else if (i == 1) {
                        ans += 'R';
                    } else if (i == 3) {
                        ans += 'D';
                    } else {
                        ans += 'U';
                    }
                    break;
                }
            }
        }
        reverse(ans.begin(),ans.end());
        cout << "YES\n" << ans.size() << "\n" << ans;
    }
    return 0;
}
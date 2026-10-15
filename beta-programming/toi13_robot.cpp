#include <bits/stdc++.h>
#define int long long
using namespace std;

bool vs[2005][2005];
int dist[2005][2005];

int dx[] = {0,0,-1,1};
int dy[] = {1,-1,0,0};
int32_t main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    vector<pair<int,int>> obj;
    vector<pair<int,int>> st;
    int n,m;
    cin >> n >> m;
    for (int i =1;i <= n;i++) {
        for (int j = 1;j <= m;j++) {
            char c;
            cin >> c;
            if (c == 'A') {
                obj.push_back({i,j});
            } else if(c=='X') {
                st.push_back({i,j});
            } else if(c=='W') {
                vs[i][j] = 1;
            }
            dist[i][j] = 1e9;
        }
    }

    queue<pair<int,int>> q;
    for (auto &x : st) {
        q.push({x.first,x.second});
        dist[x.first][x.second] = 0;
    }
    while (!q.empty()) {
        auto u = q.front();
        q.pop();

        for (int i = 0;i < 4;i++) {
            pair<int,int> p = {u.first+dx[i],u.second+dy[i]};
            if (p.first < 1 || p.first > n || p.second < 1 || p.second > m) continue;
            if (vs[p.first][p.second]) continue;
            vs[p.first][p.second] = 1;
            dist[p.first][p.second] = min(dist[u.first][u.second] + 1,dist[p.first][p.second]);
            q.push(p);
        }
    }
    int sum = 0;
    int cnt = 0;
    for (auto &x : obj) {
        if (dist[x.first][x.second] == 1e9) continue;
        cnt++;
        sum += dist[x.first][x.second];
        //cout << dist[x.first][x.second] << endl;
    }
    cout << cnt << " " << sum*2;
    

    return 0;
}
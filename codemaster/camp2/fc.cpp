#include <bits/stdc++.h>
using namespace std;
int table[2005][2005];
bool vs[2005][2005];

int dx[] = {0,0,1,-1};
int dy[] = {1,-1,0,0};
int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n,m,q;
    cin >> n >> m >> q;
    vector<pair<int,int>> st;
    for (int i = 0;i < n;i++) {
        for (int j = 0;j < m;j++) {
            char c;
            cin >> c;
            if (c == 'F') {
                st.push_back({i,j});
                table[i][j] = 0;
            } else if (c == '#') {
                vs[i][j] = 1;
                table[i][j] = -1;
            } else table[i][j] = -1;
        }
    }

    queue<pair<int,int>> qu;
    for (auto &x : st) {
        qu.push(make_pair(x.first,x.second));
        vs[x.first][x.second] = 1;
    }
    while (!qu.empty()) {
        auto u= qu.front();
        qu.pop();

        for (int i = 0;i < 4;i++) {
            pair<int,int> p = {u.first+dx[i],u.second+dy[i]};
            if (p.first < 0 || p.first >= n || p.second < 0 || p.second >= m) continue;
            if (vs[p.first][p.second]) continue;
            vs[p.first][p.second] = 1;
            table[p.first][p.second] = table[u.first][u.second] + 1;
            qu.push(p);
        }
    }
    while (q--) {
        int x,y;
        cin >> x >> y;
        cout << table[x][y] << "\n";
    }

    return 0;
}
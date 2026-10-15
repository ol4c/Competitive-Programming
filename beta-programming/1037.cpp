#include <bits/stdc++.h>
using namespace std;

int flood[105][105];
int dist[105][105];
int dx[] = {0,0,-1,1};
int dy[] = {-1,1,0,0};
int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    int n,m;
    cin >> n >> m;
    vector<pair<int,int>> water; pair<int,int> hedge; pair<int,int> beaver;
    
    
    for (int i = 1;i <= n;i++) {
        for (int j = 1;j <= m;j++) {
            char c;
            cin >> c;
            dist[i][j] = 1e9;
            flood[i][j] = 1e9;
            if (c == '*') {
                water.push_back({i,j});
            } else if(c=='S') {
                hedge.first = i;
                hedge.second = j;
            } else if (c=='D') {
                beaver.first = i;
                beaver.second = j;
            } else if(c=='X') {
                dist[i][j] = -1;
                flood[i][j] = -1;
            }
            
        }
    }
    flood[beaver.first][beaver.second] = -67;
    //simulate water
    queue<pair<int,int>> q;
    for (auto &x : water) {
        flood[x.first][x.second] = 0;
        q.push({x.first,x.second}); 
    }
    while (!q.empty()) {
        auto u = q.front();
        q.pop();
        if (u.first == beaver.first && u.second == beaver.second) continue;
        for (int i = 0;i<4;i++) {
            pair<int,int> p = make_pair(u.first+dx[i],u.second+dy[i]);
            if (p.first < 1 || p.first > n || p.second < 1 || p.second > m) continue;
            if (flood[p.first][p.second] == 1e9) {
                flood[p.first][p.second] = flood[u.first][u.second] + 1;
                q.push(p);
            }
        }
    }
    //  find shortest path
    queue<pair<pair<int,int>,int>> qu;
    qu.push({{hedge.first,hedge.second},0});
    dist[hedge.first][hedge.second] = 0;
    while (!qu.empty()) {
        auto u = qu.front();
        qu.pop();


        for (int i =0;i < 4;i++) {
            pair<pair<int,int>,int> p = make_pair(make_pair(u.first.first+dx[i],u.first.second+dy[i]),u.second+1);
            if (p.first.first < 1 || p.first.second < 1 || p.first.first > n || p.first.second > m) continue;
            if (p.second >= flood[p.first.first][p.first.second] && flood[p.first.first][p.first.second] != -67) continue;
            if (flood[p.first.first][p.first.second] == -1) continue;
            if (dist[p.first.first][p.first.second] == 1e9) {
                dist[p.first.first][p.first.second] = p.second;
                qu.push(p);
            }
        }
    }
    if (dist[beaver.first][beaver.second] != 1e9) {
        cout << dist[beaver.first][beaver.second];
    } else cout << "KAKTUS";
    return 0;
}
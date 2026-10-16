#include <bits/stdc++.h>
using namespace std;

int table[105][50];
int dist[105][50];
int dx[] = {1,1,1};
int dy[] = {-1,1,0};
int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int m,n,t;
    cin >> m >> n >> t;
    for (int i =1;i <= t;i++) {
        for (int j =1;j <= m;j++) {
            cin >> table[i][j];
            dist[i][j] = 1e9;
        }
    }
    for (int j = 1;j <= m;j++) {
        dist[0][j] = 1e9;
    }
    

    queue<pair<int,int>> q;
    pair<int,int> en;
    dist[0][n] = 0;
    q.push({0,n});
    while (!q.empty()) {
        auto u = q.front();
        q.pop();
        if (u.first == t) {
            //cout << t << endl;
            en.first = u.first;
            en.second = u.second;
            break;
        }
        for (int i = 0;i < 3;i++) {
            pair<int,int> p = {u.first+dx[i],u.second+dy[i]};
            if (p.first < 1 || p.second < 1 || p.first > t || p.second > m) continue;
            if (dist[p.first][p.second] == 1e9 && table[p.first][p.second] == 0) {
                dist[p.first][p.second] = dist[u.first][u.second] + 1;
                q.push(p);
            }
        }
    }
    vector<pair<int,int>> ans_node;
    ans_node.push_back({en.first,en.second});

    while (1) {
        for (int i = 0;i < 3;i++) {
            pair<int,int> p = {ans_node.back().first+(-1*dx[i]),ans_node.back().second+dy[i]};
            if (p.first < 1 || p.first > t || p.second < 1 || p.second > m) continue;
            if (dist[p.first][p.second] == 1e9) continue;
            if (dist[p.first][p.second] == dist[ans_node.back().first][ans_node.back().second] - 1) {
                ans_node.push_back(p);
                break;
            }
        }
        if (ans_node.back().first == 1) break;
    }
    reverse(ans_node.begin(),ans_node.end());
    int old_i = 0;
    int old_j = n;
    for (auto &x : ans_node) {
            if (old_j-1 == x.second) cout << "1\n";
            else if (old_j == x.second) cout << "3\n";
            else if (old_j+1 == x.second) cout << "2\n";
            old_i++;
            old_j = x.second;
        //cout << x.first << " " << x.second << "\n";
    }
    return 0;
}
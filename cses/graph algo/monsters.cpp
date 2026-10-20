#include <bits/stdc++.h>
using namespace std;

int table[1005][1005];
int table2[1005][1005];
pair<int,int> par[1005][1005];
bool vs[1005][1005];
bool vs2[1005][1005];

int dx[] = {0,0,1,-1};
int dy[] = {1,-1,0,0};
// R L D U
int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    int n,m;
    cin >>n >> m;
    vector<pair<int,int>> monsters;
    pair<int,int> st;
    for (int i = 1;i <= n;i++) {
        for (int j = 1;j <= m;j++) {
            char c;
            cin >> c;
            if (c == '#') {
                table[i][j] = 1e9;
                table2[i][j] = 1e9;
                vs[i][j] = 1;
                vs2[i][j] = 1;
            } else if (c == 'M') {
                monsters.push_back({i,j});
            } else if (c == 'A') {
                st.first = i;
                st.second = j;
            }
        }
    }
    for (int i = 0; i <= n+1; i++) {
        for (int j = 0; j <= m+1; j++) {
            table[i][j] = 1e9;
        }
    }
    
    queue<pair<int,int>> q;
    for (auto &x : monsters) {
        q.push(x);
        table[x.first][x.second]= 0;;
        vs[x.first][x.second] = 1;
    }
    while (!q.empty()) {
        auto u = q.front();
        q.pop();

        for (int i = 0;i<4;i++) {
            pair<int,int> p = {u.first+dx[i],u.second+dy[i]};
            if (p.first < 1 || p.first > n || p.second < 1 || p.second > m) continue;
            if (vs[p.first][p.second]) continue;
            table[p.first][p.second] = table[u.first][u.second] + 1;
            vs[p.first][p.second] = 1;
            q.push(p);
        }
    }

    // for (int i = 1;i <= n;i++) {
    //     for (int j = 1;j <= m;j++) {
    //         if (table[i][j] == 1e9) {
    //             cout << "-1 ";
    //             continue;
    //         }
    //         cout << table[i][j]<< " ";
    //     }
    //     cout << endl;
    // }

    q.push(st);
    bool ch = 0;
    vs2[st.first][st.second] = 1;
    par[st.first][st.second] = {-1,-1};
    pair<int,int> en;
    while (!q.empty()) {
        auto u = q.front();
        q.pop();
        if (u.first == n || u.first == 1 || u.second == 1 || u.second == m) {
            ch = 1;
            en.first = u.first;
            en.second = u.second;
            break;
        }
        for (int i = 0;i<4;i++) {
            pair<int,int> p = {u.first+dx[i],u.second+dy[i]};
            if (p.first < 1 || p.first > n || p.second < 1 || p.second > m) continue;
            if (vs2[p.first][p.second]) continue;
            if (table2[u.first][u.second] + 1 >= table[p.first][p.second]) continue;
            table2[p.first][p.second] = table2[u.first][u.second] + 1;
            par[p.first][p.second] = u;
            vs2[p.first][p.second] = 1;
            q.push(p);
        }
    }


    if (!ch) {
        cout << "NO\n";
    } else {
        vector<pair<int,int>> ans;
        
        for (pair<int,int> i = en;i != make_pair(-1,-1);i = par[i.first][i.second]) {
            ans.push_back(i);
        }
        reverse(ans.begin(),ans.end());
        string yo;
        for (int i = 0;i <= (int) ans.size() - 2;i++) {
            auto a = ans[i];
            auto b = ans[i+1];
            for (int j = 0; j< 4;j++) {
                if (a.first+dx[j] == b.first && a.second+dy[j] == b.second) {
                    if (j == 0) {
                        yo += 'R';
                    } else if( j == 1) yo+='L';
                    else if (j ==2) yo+= 'D';
                    else yo+='U';

                }
            }
        }
        cout << "YES\n" << yo.size() << "\n" << yo;
    }
    return 0;
}
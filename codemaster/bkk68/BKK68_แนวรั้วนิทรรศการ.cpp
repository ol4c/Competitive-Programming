#include <bits/stdc++.h>
using namespace std;

bool table[15][15];
bool vs[15][15];

int dx[] = {0,0,1,-1,-1,-1,1,1};
int dy[] = {1,-1,0,0,1,-1,1,-1};
int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    string s;
    cin >> s;
    string ns1, ns2;
    bool ch = 0;
    for (int i = 0;i < s.size();i++) {
        if (s[i] == 'x') {
            ch = 1;
            continue;
        }
        if(!ch) {
            ns1+=s[i];
        } else {
            ns2+=s[i];
        }
    }
    int n1 = stoi(ns1);
    int n2 = stoi(ns2);
    ch = 0;
    int f_sti = -67;
    int f_stj = -67;
    int sum_1 = 0;
    for (int i = 1;i <= n2;i++) {
        for (int j = 1;j <= n1;j++) {
            char c;
            cin >> c;
            table[i][j] = c - '0';
            if (c == '1' && ch == 0) {
                ch = 1;
                f_sti = i;
                f_stj = j;
            }

            if (c == '1') sum_1++;
        }
    }

    if(!ch) {
        cout << "0";
        return 0;
    }
    queue<pair<int,int>> q;
    q.push({f_sti,f_stj});
    int ss = 0;
    int border = 0;
    vs[f_sti][f_stj] = 1;
    while (!q.empty()) {
        auto u = q.front();
        q.pop();
        border += 4 - (table[u.first-1][u.second] + table[u.first+1][u.second] + table[u.first][u.second + 1] + table[u.first][u.second -1]);
        ss++;
        for (int i = 0;i < 8;i++) {
            pair<int,int> p = make_pair(u.first+dx[i],u.second+dy[i]);
            if (p.first < 1 || p.first > n2 || p.second < 1 || p.second > n1) continue;
            if (vs[p.first][p.second]) continue;
            if (table[p.first][p.second] == 0) continue;
            //cout << p.first << " " << p.second << "\n";
            vs[p.first][p.second] = 1;
            
            q.push(p);
        }
    }
    //cout << sum_1 << " " <<ss <<endl;
    if (ss != sum_1) cout << "0\n";
    else {
        
        cout << border;
    }
    return 0;
}
#include <bits/stdc++.h>
using namespace std;

int table[105][105];
map<int,int> mp;
vector<char> vec[1005];
vector<pair<int,int>> pos = {};
bool crash_check(int sti,int stj,int p) {
    for (int i = 1;i <= 4;i++) {
        if (i == p) continue;
        if (sti == pos[i].first && stj == pos[i].second) return 1;
    }
    return 0;
}
int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n,k;
    cin >> n >> k;
    for (int l = 1;l <= 4;l++) {
        for (int i = 1;i <= k;i++) {
            char c;
            cin >> c;
            vec[i].push_back(c);
        }
    }
    table[1][1] = 4;
    table[1][n] = 1;
    table[n][1] = 3;
    table[n][n] = 2;
    for (int i = 1;i <= 4;i++) mp[i] = 1;
    pos = {{0,0},{1,n},{n,n},{n,1},{1,1}};
    for (int i = 1;i <= k;i++) {
        for (int j = 1;j <= 4;j++) {
            char c = vec[i][j-1];
            if (c == 'S') {
                if (pos[j].first + 1 < 1 || pos[j].first + 1 > n || pos[j].second < 1 || pos[j].second > n) continue;
                if (crash_check(pos[j].first + 1,pos[j].second,j) == 0) {
                    if (table[pos[j].first + 1][pos[j].second] != j) {
                        mp[table[pos[j].first + 1][pos[j].second]]--;
                        table[pos[j].first + 1][pos[j].second] = j;
                        mp[j]++;
                    } 
                    pos[j].first = pos[j].first + 1;
                    pos[j].second = pos[j].second;
                    
                }
            } else if (c == 'E') {
                if (pos[j].first < 1 || pos[j].first > n || pos[j].second + 1 < 1 || pos[j].second + 1> n) continue;
                if (crash_check(pos[j].first,pos[j].second+1,j) == 0) {
                    if (table[pos[j].first][pos[j].second+1] != j) {
                        mp[table[pos[j].first][pos[j].second+1]]--;
                        table[pos[j].first][pos[j].second+1] = j;
                        mp[j]++;
                    }
                    table[pos[j].first][pos[j].second+1] = j;
                    pos[j].first = pos[j].first;
                    pos[j].second = pos[j].second + 1;
                  
                }
            } else if (c == 'N') {
                if (pos[j].first - 1 < 1 || pos[j].first - 1 > n || pos[j].second  < 1 || pos[j].second > n) continue;
                if (crash_check(pos[j].first - 1,pos[j].second,j)== 0) {
                    if (table[pos[j].first - 1][pos[j].second] != j) {
                        mp[table[pos[j].first -1][pos[j].second]]--;
                        table[pos[j].first - 1][pos[j].second] = j;
                        mp[j]++;
                    } 
                    table[pos[j].first-1][pos[j].second] = j;
                    pos[j].first = pos[j].first-1;
                    pos[j].second = pos[j].second;
                  
                }
            } else {
                if (pos[j].first < 1 || pos[j].first > n || pos[j].second - 1 < 1 || pos[j].second - 1 > n) continue;
                if (crash_check(pos[j].first,pos[j].second-1,j) == 0) {
                    if (table[pos[j].first][pos[j].second-1] != j) {
                        mp[table[pos[j].first][pos[j].second-1]]--;
                        table[pos[j].first][pos[j].second-1] = j;
                        mp[j]++;
                    } 
                    table[pos[j].first][pos[j].second - 1] = j;
                    pos[j].first = pos[j].first;
                    pos[j].second = pos[j].second - 1;
                    
                }
            }
        }
    }
    int mx = -2e9; vector<int> ans;
    if (mp[1]+mp[2]+mp[3]+mp[4] < n*n) cout <<"No\n";
    else {
        
        for (int i = 1;i <= 4;i++) {
            
            if (mp[i] > mx) {
                ans.clear();
                mx = mp[i];
                ans.push_back(i);
            } else if (mp[i] == mx) {
                ans.push_back(i);
            }
        }
        cout << ans.size() << " " << mx << "\n";
        for (auto &i : ans)cout << i << "\n";
    }
    
    
    return 0;
}
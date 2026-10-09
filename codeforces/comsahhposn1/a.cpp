#include <bits/stdc++.h>
using namespace std;

bool table[505][505];
vector<string> ans;
void jim_0(int i, int j) {
    vector<pair<int,int>> vec = {{i,j},{i,j+1},{i+1,j},{i+1,j+1}};
    string s;
    for (auto x : vec) {
        if (table[x.first][x.second] == 0) {
            for (auto y : vec) {
                if (y != x) {
                    s += to_string(y.first) + " " + to_string(y.second) + " ";
                    table[y.first][y.second] = !table[y.first][y.second];
                }
            }
            break;
        }
    }
    //sort(s.begin(),s.end());
    ans.push_back(s);
}

void jim_1(int i, int j) {
    vector<pair<int,int>> vec = {{i,j},{i+1,j},{i,j+1},{i+1,j+1}};
    string s;
    for (auto x : vec) {
        if (table[x.first][x.second]) {
            for (auto y : vec) {
                if (y != x) {
                    s += to_string(y.first) + " " + to_string(y.second) + " ";
                    table[y.first][y.second] = !table[y.first][y.second];
                }
            }
            break;
        }
    }
    //sort(s.begin(),s.end());
    ans.push_back(s);
}
int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    int n;
    cin >> n;
    for (int i = 1;i<= n;i++) {
        for (int j = 1;j <= n;j++) {
            char c;
            cin >> c;
            table[i][j] = c - '0';
        }
    }
    if (n % 2 == 0) {
        // cal normally
        int limit = n-1;
        if (n == 2) limit = 1;
        for (int i = 1;i <= limit;i+=2) {
            for (int j = 1;j <= limit;j+=2) {
                // cal with in the square
                // ---- cal amount of 1 in square
                
                vector<pair<int,int>> vec = {{i,j},{i+1,j},{i,j+1},{i+1,j+1}};
                int cnt = 0;
                for (auto x : vec) {
                    cnt += table[x.first][x.second];
                    //cout << cnt << endl;;
                }
                if (cnt == 0) continue;
                if (cnt == 1) {
                    jim_0(i,j);
                    jim_1(i,j);
                    jim_0(i,j);
                }
                if (cnt == 2) {
                    jim_1(i,j);
                    jim_0(i,j);
                }
                if (cnt == 3) {
                    jim_0(i,j);
                }
                if(cnt == 4) {
                    jim_1(i,j);
                    jim_0(i,j);
                    jim_1(i,j);
                    jim_0(i,j);
                }
            }
        }
    } else {
        int limit = n-2;
        for (int i = 1;i <= limit;i+=2) {
            for (int j = 1;j <= limit;j+=2) {
                // cal with in the square
                // ---- cal amount of 1 in square
                
                vector<pair<int,int>> vec = {{i,j},{i+1,j},{i,j+1},{i+1,j+1}};
                int cnt = 0;
                for (auto x : vec) {
                    cnt += table[x.first][x.second];
                    //cout << cnt << endl;;
                }
                if (cnt == 0) continue;
                if (cnt == 1) {
                    jim_0(i,j);
                    jim_1(i,j);
                    jim_0(i,j);
                }
                if (cnt == 2) {
                    jim_1(i,j);
                    jim_0(i,j);
                }
                if (cnt == 3) {
                    jim_0(i,j);
                }
                if(cnt == 4) {
                    jim_1(i,j);
                    jim_0(i,j);
                    jim_1(i,j);
                    jim_0(i,j);
                }
            }
        }
        // cal ขอบ

        // khob sai lanf -> khwa lang
        for (int j=1;j <= n-1;j+=2) {
            vector<pair<int,int>> vec = {{n-1,j},{n-1,j+1},{n,j},{n,j+1}};
            int cnt = 0;
            for (auto x : vec) {
                cnt += table[x.first][x.second];
                //cout << cnt << endl;;
            }
            if (cnt == 0) continue;
            if (cnt == 1) {
                jim_0(n-1,j);
                jim_1(n-1,j);
                jim_0(n-1,j);
            }
            if (cnt == 2) {
                jim_1(n-1,j);
                jim_0(n-1,j);
            }
            if (cnt == 3) {
                jim_0(n-1,j);
            }
            if(cnt == 4) {
                jim_1(n-1,j);
                jim_0(n-1,j);
                jim_1(n-1,j);
                jim_0(n-1,j);
            }
        }

        // bon long lang
        for (int i=1;i <= n-1;i+=2) {
            vector<pair<int,int>> vec = {{i,n-1},{i,n},{i+1,n-1},{i+1,n}};
            int cnt = 0;
            for (auto x : vec) {
                cnt += table[x.first][x.second];
                //cout << cnt << endl;;
            }
            if (cnt == 0) continue;
            if (cnt == 1) {
                jim_0(i,n-1);
                jim_1(i,n-1);
                jim_0(i,n-1);
            }
            if (cnt == 2) {
                jim_1(i,n-1);
                jim_0(i,n-1);
            }
            if (cnt == 3) {
                jim_0(i,n-1);
            }
            if(cnt == 4) {
                jim_1(i,n-1);
                jim_0(i,n-1);
                jim_1(i,n-1);
                jim_0(i,n-1);
            }
        }

        //bottom left
        vector<pair<int,int>> vec = {{n-1,n-1},{n-1,n},{n,n-1},{n,n}};
        int cnt = 0;
        for (auto x : vec) {
            cnt += table[x.first][x.second];
            //cout << cnt << endl;;
        }
    
        if (cnt == 1) {
            jim_0(n-1,n-1);
            jim_1(n-1,n-1);;
            jim_0(n-1,n-1);
        }
        if (cnt == 2) {
            jim_1(n-1,n-1);
            jim_0(n-1,n-1);
        }
        if (cnt == 3) {
            jim_0(n-1,n-1);
        }
        if(cnt == 4) {
            jim_1(n-1,n-1);
            jim_0(n-1,n-1);
            jim_1(n-1,n-1);;
            jim_0(n-1,n-1);
        }
    }
    cout << ans.size() << "\n";
    //sort(ans.begin(),ans.end());
    for (auto x : ans) cout << x << "\n";
    
}
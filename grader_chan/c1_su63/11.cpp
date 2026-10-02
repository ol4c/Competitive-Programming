#include <bits/stdc++.h>
using namespace std;
vector<pair<int,int>> vec;
int stx, sty;
char table[1000][1000];
int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    memset(table,'_',sizeof(table));
    int n;
    cin >> n;
    int q;
    cin >> q;
    while (q--) {
        int x,y;
        cin >> x >> y;
        if (x+1 < 1 || y+1 < 1 || x+1 > n || y+1 > n) {
            cout << "Out of range";
            return 0;
        }
        vec.push_back({x+1,y+1});
    }

    for (int i = 0;i < vec.size();i++) {
        if (i == 0) {
            stx = vec[i].first;
            sty = vec[i].second;
            table[stx][sty] = 'A';
        } else {
            int i1 = stx,j1 = sty,i2 = vec[i].first, j2 = vec[i].second;
            
            if (i1 == i2 && j1 == j2)  {
                table[i2][j2] = 'A' + i;
                stx = vec[i].first;
                sty = vec[i].second;
                continue;
            }
            if (i1 != i2) {
                char dc;
                if (j2 == j1) {
                    if (i2 < i1) {
                        dc = '^';
                        for (int i = i1-1;i > i2;i--) {
                            table[i][j2] = dc;
                        }
                    } else if (i2 > i1) {
                        dc = 'v';
                        for (int i = i1+1;i < i2;i++) {
                            table[i][j2] = dc;
                        }
                    }
                } else {
                    if (j2 < j1) {
                        dc = '<';
                        for (int j = j1-1;j >= j2;j--) {
                            table[i1][j] = dc;
                        }
                    } else if (j2 > j1) {
                        dc = '>';
                        for (int j = j1+1;j <= j2;j++) {
                            table[i1][j] = dc;
                        }
                    }

                    if (i2 < i1) {
                        dc = '^';
                        for (int i = i1;i > i2;i--) {
                            table[i][j2] = dc;
                        }
                    } else if (i2 > i1) {
                        dc = 'v';
                        for (int i = i1;i < i2;i++) {
                            table[i][j2] = dc;
                        }
                    }
                }
                
            } else {
                char dc;
                if (j2 < j1) {
                    dc = '<';
                    for (int j = j1-1;j >= j2;j--) {
                        table[i1][j] = dc;
                    }
                } else if (j2 > j1) {
                    dc = '>';
                    for (int j = j1+1;j <= j2;j++) {
                        table[i1][j] = dc;
                    }
                }
            }
            table[i2][j2] = 'A' + i;
            stx = vec[i].first;
            sty = vec[i].second;
        }
    }

    for (int i = 1;i <= n;i++) {
        for (int j = 1;j <= n;j++) {
            cout << table[i][j];
        }
        cout << endl;
    }
}
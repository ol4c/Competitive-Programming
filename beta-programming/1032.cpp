#include <bits/stdc++.h>
using namespace std;

int a[15][15];
int b[15][15];
bool ch1[15][15];
bool ch2[15][15];
// ch[row][num]
int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    int n;
    cin >> n;
    for (int i = 1;i <= 9;i++) {
        for (int j = 1;j <= 9;j++) {
            int k;
            cin >> k;
            a[i][j] = k;
        }
    }
    int d = 1;
    vector<int> ans;
    while (n--) {
        for (int i = 1;i <= 9;i++) {
            for (int j = 1;j <= 9;j++) {
                int k;
                cin >> k;
                b[i][j] = k;
            }
        }
        bool c = 0;
        for (int i = 1;i <= 9;i++) {
            for (int j = 1;j <= 9;j++) {
                if (a[i][j] == 0) {
                    if (ch1[i][b[i][j]] == 1) {
                        c=1;
                        break;
                    } else {
                        ch1[i][b[i][j]] = 1;
                    }

                    if (ch2[j][b[i][j]] == 1) {
                        c=1;
                        break;
                    } else {
                        ch2[j][b[i][j]] = 1;
                    }
                } else {
                    if (a[i][j] != b[i][j]) {
                        c = 1;
                        break;
                    } else {
                        ch1[i][b[i][j]] = 1;
                        ch2[j][b[i][j]] = 1;
                    }
                }
            }
            if (c) break;
        }
        if (!c) {
            ans.push_back(d);
        }
        d++;

        for (int i = 1;i <= 9;i++) {
            for (int j = 1;j<=9;j++) {
                ch1[i][j] = 0;
                ch2[i][j] = 0;
            }
        }
    }
    for (auto &x : ans) cout << x << "\n";
    cout << "END";
    return 0;
}
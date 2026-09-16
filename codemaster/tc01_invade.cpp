#include <bits/stdc++.h>
using namespace std;

struct ch {
    int val;
    int i;
    int j;
};
int arr[505][505];
int dx[] = {0,0,-1,1};
int dy[] = {1,-1,0,0};
vector<ch> change;
int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n,m,kuy;

    cin >> n >> m >> kuy;
    for (int i = 1;i <= n;i++) {
        for (int j = 1;j <= m;j++) {
            cin >> arr[i][j];
        }
    }

    for (int l = 1;l <= kuy;l++) {
        int f;
        cin >> f;
        
        for (int i = 1;i <= n;i++) {
            for (int j = 1;j <= m;j++) {
                if (arr[i][j] == f) {
                    for (int k = 0;k < 4;k++) {
                        if (i+dx[k] < 1 || i+dx[k] >  n || j + dy[k] < 1 || j + dy[k]  > m) {
                            continue;
                        } else {
                            ch cc;
                            cc.i = i+dx[k];
                            cc.j = j+dy[k];
                            cc.val = arr[i][j];
                            change.push_back(cc);
                        }
                    }
                }
            }
        }

        for (auto cc : change) {
            arr[cc.i][cc.j] = cc.val;
        }
        change.clear();

    }

    for (int i = 1;i <= n;i++) {
        for (int j = 1;j <= m;j++) {
            cout << arr[i][j] << " ";
        }
        cout << "\n";
    }


}
#include <bits/stdc++.h>
using namespace std;

bool vs[50];
int a[50];
//R - 1, U - 2, L - 3, D - 4
bool table[55][55];
int dx[] = {0,0,-1,0,1};
int dy[] = {0,1,0,-1,0};
int cnt = 0;
void sol(int now, int i, int j) {
    if (table[i][j]) return;
    if (i < 1 || i > 7 || j < 1 || j > 7) return;
    if (i == 7 && j == 1) {
        if (now == 49) cnt++;
        return;
    }
    if (now == 49) return; 

    if (!table[i-1][j] && !table[i+1][j] && table[i][j-1] && table[i][j+1]) return;
    if (table[i-1][j] && table[i+1][j] && !table[i][j-1] && !table[i][j+1]) return;

    table[i][j] = 1;
    if (vs[now]) {
        sol(now+1,i+dx[a[now]],j+dy[a[now]]);
    } else {
        for (int d = 1;d <= 4;d++) {
            sol(now+1,i+dx[d],j+dy[d]);
        }
    }
    table[i][j] = 0;
}
int main () {
    string s;
    cin >> s;
    for (int i = 1;i <= 48;i++) {
        if (s[i-1] != '?') {
            vs[i] = 1;
            if (s[i-1] == 'R') a[i] = 1;
            if (s[i-1] == 'U') a[i] = 2;
            if (s[i-1] == 'L') a[i] = 3;
            if (s[i-1] == 'D') a[i] = 4;
        }
    }
    for (int k = 0; k <= 8; k++)
        table[0][k] = table[8][k] = table[k][0] = table[k][8] = 1;
    sol(1,1,1);
    cout << cnt;
}
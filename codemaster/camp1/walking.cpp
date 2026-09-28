#include <bits/stdc++.h>
using namespace std;
bool table[10][10];
bool vs[10][10];
int dx[] = {1,0};
int dy[] = {0,1};
int n,m;
void sol(int sti, int stj, string s = "") {
    if (sti < 1 || stj < 1 || stj > m || sti > n) return;
    if (table[sti][stj]) return;
    if (vs[sti][stj]) return;
    if (sti == n && stj == m) {
        cout << s << "\n";
        return;
    }

    vs[sti][stj] = 1;
    sol(sti+dx[0],stj+dy[0],s+'D');
    sol(sti+dx[1],stj+dy[1],s+'R');
    vs[sti][stj] = 0;
}
int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    cin >> n >> m;
    for (int i = 1;i <= n;i++) {
        for (int j = 1;j <= m;j++) {
            char c;
            cin >> c;
            if (c == '#') {
                table[i][j] = 1;
            } else {
                table[i][j] = 0;
            }
        }
    }
    sol(1,1);

}
#include <bits/stdc++.h>
using namespace std;

int table[30][30];
bool vs[30][30];
int mx = -2e9;
int n;
int dx[] = {0,0,1,-1};
int dy[] = {1,-1,0,0};
void sol(int sti, int stj, int now_v) {
    mx = max(mx,now_v);
    vs[sti][stj] = 1;
    for (int i = 0;i < 4;i++) {
        int ni = sti + dx[i];
        int nj = stj + dy[i];
        if (ni < 1 || ni > n || nj < 1 || nj > n) continue;
        if(vs[ni][nj]) continue;
        if (table[ni][nj] <= now_v) continue;
        vs[ni][nj] = 1;
        sol(ni,nj,table[ni][nj]);
    }
}
int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    int sti,stj;
    cin >> n >> stj >> sti;
    for (int i = 1;i <= n;i++) {
        for (int j = 1;j <= n;j++) {
            int k;
            cin >> k;
            if (k == 100) {
                vs[i][j] = 1;
            } else {
                table[i][j] = k;
            }
        }
    }
    sol(sti,stj,table[sti][stj]);
    cout << mx;
    return 0;
}
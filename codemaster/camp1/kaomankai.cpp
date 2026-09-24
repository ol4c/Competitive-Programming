#include <bits/stdc++.h>
#define int long long
using namespace std;
char arr[45][45];
int dx[] = {-1,1,0,0};
int dy[] = {0,0,1,-1};
int mx = -1;
int n,m,k;
int visited[45][45];
void sol(int sti, int stj, int sum = 0,int mv = 0) {
    if (sti < 1 || stj < 1 || sti > n || stj > m || (mv >= k && arr[sti][stj] != 'T')) {
        return;
    }
    if (mv > k) return;

    if (arr[sti][stj] == 'T' && mv <= k) {
        mx = max(mx,sum);
        return;
    }
    bool picked = 0;
    if (!(arr[sti][stj] == 'S') && visited[sti][stj] == 0) {
        sum += arr[sti][stj] - '0';
        visited[sti][stj] = 1;
        picked = 1;
    }
    
    for (int i = 0;i < 4;i++) {
        
        sol(sti+dx[i],stj+dy[i],sum,mv+1);
        
    }
    
    if (picked) {
        visited[sti][stj] = 0;
    }
}
signed main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    cin >> n >> m >> k;
    int start_i, start_j;
    for (int i = 1;i <= n;i++) {
        for (int j = 1;j <= m;j++) {
            char l;
            cin >> l;
            arr[i][j] = l;
            if (l == 'S') {
                start_i = i;
                start_j = j;
            }
        }
    }
    sol(start_i,start_j);
    cout << mx;
}
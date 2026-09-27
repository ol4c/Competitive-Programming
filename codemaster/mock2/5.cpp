#include <bits/stdc++.h>
using namespace std;
int n,m;
char arr[1005][1005];
int sol(int sti, int stj) {
    for (int k = 1;k <= 1000;k++) {
        if (sti-k+1 < 1 || stj-k+1 < 1 || sti+k-1 < 1 || stj+k-1 < 1 || sti-k+1 > n || stj-k+1 > m || sti+k-1 > n || stj+k-1 > m) {
            return k-1;
        }
        if (!(arr[sti-k+1][stj-k+1] == arr[sti][stj])) return k-1;
        if (!(arr[sti-k+1][stj+k-1] == arr[sti][stj])) return k-1;
        if (!(arr[sti+k-1][stj-k+1] == arr[sti][stj])) return k-1;
        if (!(arr[sti+k-1][stj+k-1] == arr[sti][stj])) return k-1;

    }
    
    sol(sti,stj);
}
int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    cin >> n >> m;
    for (int i = 1;i <= n;i++) {
        for (int j = 1;j <= m;j++) {
            char c;
            cin >> c;
            arr[i][j] = c;
        }
    }
    int mx = 0;
    for (int i = 1;i <= n;i++) {
        for (int j = 1;j <= m;j++) {
            if (arr[i][j] != '.') {
                mx = max(mx,sol(i,j));
            }
        }
    }
    cout << mx;
}
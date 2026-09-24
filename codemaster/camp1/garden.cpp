#include <bits/stdc++.h>
#define ll long long
using namespace std;

int n,m,l;
string s;
ll mx = 0;
ll arr[505][505];
void sol(int sti, int stj, int s_idx,ll sum) {
    if (sti < 1 || stj < 1 || sti > n || stj > m) {
        mx = max(mx, sum);
        return;
    } 
       
    sum += arr[sti][stj];
    if (s_idx == l) {
        mx = max(mx, sum);
        return;
    }
    if (s[s_idx] == 'R') {
        sol(sti,stj+1,s_idx+1, sum);
    } else if (s[s_idx] == 'U') {
        sol(sti-1,stj,s_idx+1, sum);
    } else if (s[s_idx] == 'L') {
        sol(sti,stj-1,s_idx+1, sum);
    } else {
        sol(sti+1,stj,s_idx+1, sum);
    }
}

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    cin >> n >> m >> l;
    
    cin >> s;

    for (int i = 1;i <= n;i++) {
        for (int j = 1;j <= m;j++) {
            ll k;
            cin >> k;
            arr[i][j] = k;
        }
    }
    for (int i = 1;i <= n;i++) {
        for (int j = 1;j <= m;j++) {
            sol(i,j,0,0);
        }
    }
    cout << mx;
}
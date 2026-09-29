#include <bits/stdc++.h>
#define int long long
using namespace std;
int table[20][20];
int n,m;
int dx[] = {-1,0,1};
int mn = 9e18;
map<int,int> mp;
void sol(int sti, int stj, int sum = 0) {
    if (sti < 1 || stj < 1 || sti > n || stj > m) return;
    sum += table[sti][stj];
    if (stj == m) {
        mn = min(mn,sum);
        mp[sum]++;
    }
    for (int i = 0;i < 3;i++) {
        sol(sti+dx[i],stj+1,sum);
    }

}
signed main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    cin >> n >> m;
    for (int i = 1;i <= n;i++) {
        for (int j = 1;j <= m ;j++) {
            cin >> table[i][j];
        }
    }

    for (int i = 1;i <= n;i++) {
        sol(i,1);
    }
    cout << mn << " " << mp[mn];
}

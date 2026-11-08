#include <bits/stdc++.h>
using namespace std;

int table_x[5005];
int table_y[5005];
int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    int n,m,k;
    cin >> n >> m >> k;
    int mx = -2e9;
    for (int i = 1;i <= k;i++) {
        int x,y,r;
        cin >> x >> y >> r;
        int j = max(0,x-r);
        for (;j <= min(m,x+r);j++) {
            table_x[j]++;
            mx = max(table_x[j],mx);
        }
        j = max(0,y-r);
        for (;j <= min(n,y+r);j++) {
            table_y[j]++;
            mx = max(table_y[j],mx);
        }
    }
    cout << mx;
    return 0;
}
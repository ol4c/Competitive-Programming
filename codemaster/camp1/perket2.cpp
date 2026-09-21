#include <bits/stdc++.h>
using namespace std;
int n, mn = 2e9;
int s[15];
int b[15];
int a[15];

void sol(int totals, int totalb,int now,int pick) {
    if (now == n+1) {
        if (pick > 0) {
            mn = min(mn,abs(totals-totalb));
        }
        return;
    }
    sol(s[now]*totals,b[now]+totalb,now+1,pick+1);
    sol(totals,totalb,now+1,pick);
}
int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> n;
    for (int i = 1;i <= n;i++) {
        int cs,cb;
        cin >> cs>>cb;
        s[i] = cs;
        b[i] = cb;
    }
    sol(1,0,1,0);
    cout << mn;
}

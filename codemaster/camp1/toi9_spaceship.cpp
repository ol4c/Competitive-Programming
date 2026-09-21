#include <bits/stdc++.h>
using namespace std;
int n, stx,sty,stz,nshop;
int ax[505], ay[505], az[505], am[505], ak[505], ap[505], use[505], a[505];
int mn_dis = 2e9;
void sol(int now) {

    if (now == nshop+1) {
        int dis = 0;
        int m = 0, k = 0, p = 0;
        for (int i = 1;i <= nshop;i++) {
            if (dis > mn_dis) return;
            if (m >= n && k >= n && p >= n) {
                mn_dis = min(mn_dis, dis);
                break;
            }
            dis += pow(ax[a[i]]-ax[a[i-1]],2) + pow(ay[a[i]]-ay[a[i-1]],2) + pow(az[a[i]]-az[a[i-1]],2);
            m += am[a[i]];
            k += ak[a[i]];
            p += ap[a[i]];
            if (m == n && k == n && p == n) {
                mn_dis = min(mn_dis, dis);
                break;
            }
        }
        return;
    }
    for (int i = 1;i <= nshop;i++) {
        if (use[i]) continue;
        a[now] = i;
        use[i] = 1;
        sol(now+1);
        use[i] = 0;
    }
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    cin >> n >> stx >> sty >> stz >> nshop;
    ax[0] = stx;
    ay[0] = sty;
    az[0] = stz;
    for (int i = 1;i <= nshop;i++) {
        int x,y,z,m,k,p;
        cin >> x >> y >> z >> m >> k >> p;
        ax[i] = x;
        ay[i] = y;
        az[i] = z;
        am[i] = m;
        ak[i] = k;
        ap[i] = p;
    }
    sol(1);
    cout << mn_dis;
}
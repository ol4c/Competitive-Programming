#include <bits/stdc++.h>
#define int long long
using namespace std;
int mm[] = {0,31,28,31,30,31,30,31,31,30,31,30,31};
signed main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    int m,d;
    cin >> m >> d;

    int cd = 0;
    for (int i = 1;i < m ;i++) {
        cd += mm[i];
    }
    cd += 1;
    int dis = abs(224-cd);
    int md = dis % 7;

    if (cd > 224) {
        for (int i = 1;i <= md;i++) {
            if (d-1 >= 1) d -= 1;
            else d = 7;
        }
    } else {
        for (int i = 1;i <= md;i++) {
            if (d+1 <= 7) d += 1;
            else d = 1;
        }
    }
    
    cout << d;
}
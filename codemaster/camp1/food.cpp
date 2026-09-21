#include <bits/stdc++.h>
using namespace std;
int n,f, a[105], use[105], forbid[105];

void sol(int now) {
    if (now == n+1) {
        
        for (int i = 1;i <= n;i++) {
            cout << a[i] << " ";
        }
        cout << "\n";
        return;
    }
    
    for (int i = 1;i <= n;i++) {
        if(use[i])  continue;
        if (now == 1 && forbid[i]) continue;
        a[now] = i;
        use[i] = 1;
       
        sol(now+1);
        use[i] = 0;
    }
}
int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> f;
    for (int i = 1;i <= f;i++) {
        int k;
        cin >> k;
        forbid[k] = 1;
    }
    sol(1);
}
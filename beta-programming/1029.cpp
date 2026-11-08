#include <bits/stdc++.h>
using namespace std;


int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    int n,m,q;
    cin >> n >> m >> q;
    set<int> bd;
    for (int i = 1;i <= m;i++){
        int x,y;
        cin >> x >> y;
        for (int p : {x,x+y}) {
            if (bd.count(p)) bd.erase(p);
            else bd.insert(p);
        }
    }
    bd.insert(1);
    bd.insert(n+1);

    while (q--) {
        int x;
        cin >> x;
        int r = *bd.upper_bound(x);
        int l = *prev(bd.upper_bound(x));
        cout << r-l << "\n";
    }
    
    return 0;
}
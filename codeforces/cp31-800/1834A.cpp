#include <bits/stdc++.h>
using namespace std;


int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    int q;
    cin >> q;
    while (q--) {
        int n;
        cin >> n;
        int neg = 0, pos = 0;
        for (int i = 1;i <= n;i++) {
            int k;
            cin >> k;
            
            if (k == -1 ) {
                neg++;
            } else {
                pos++;
            }
        }
        int cnt = 0;
        int sum = -neg + pos;
            int prod;
            if (neg % 2 == 0) {
                prod=  1;
            } else prod = -1;
            if (sum >= 0 && prod == 1) {
                cout << "0\n";
            } else {
                // simulate
                while (!(sum >= 0 && prod == 1)) {
                    cnt++;
                    sum+=2;
                    prod = -prod;
                }
                cout << cnt << "\n";
            }
    }
    return 0;
}
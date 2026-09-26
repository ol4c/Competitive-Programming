#include <bits/stdc++.h>
#define int long long
using namespace std;
unordered_map<int,int> day_w;
signed main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) {
        day_w.clear();
        int n,k;
        cin >> n >> k;
        int sum = 0;
        if (k == 1) day_w[n] = 1;
        else {
            day_w[1]=1;
            int kuy = k-1;
            for (int i = n;i > 1;i--) {
                if (kuy > 0) {
                    day_w[i] = 1;
                    kuy--;
                } else break;
            }
            
            
        }
        int cur = 2;
            for (int i = 1;i <= n;i++) {
                if (day_w[i]) {
                    sum += cur;
                    cur = 2;
                } else {
                    cur *= 2;
                }
            }

        cout << sum << "\n"; 

    }
}
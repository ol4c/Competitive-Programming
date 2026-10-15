#include <bits/stdc++.h>
#define int long long
using namespace std;


signed main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int q;
    cin >> q;
    while (q--) {
        int cnt = 0;
        vector<int> vec;
        int a,b;
        cin >> a >> b;
        vec.push_back(0);
        for (int i = 1;i <= a;i++) {
            int k;
            cin >> k;
            if (i == 1) {
                vec.push_back(k);
            } else {
                vec.push_back(k+vec[i-1]);
            }
        }
        for (int k = b+1;k <= a;k++) {
            for (int i = k;i <= a;i++) {
                int sum = vec[i] - vec[i-k];
                if (sum % b == 0) cnt++;
            }
        }
        cout << cnt << "\n";

    }

    return 0;
}
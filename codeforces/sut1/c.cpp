#include <bits/stdc++.h>
#define int long long
using namespace std;

signed main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int q;
    cin >> q;
    while (q--) {
        int n;
        cin >> n;
        int cnt_odd = 0;
        int sum = 0;
        int sum_even = 0;
        int sum_odd =0;
        vector<int> odd;
        for (int i = 1;i <= n;i++) {
            int k;
            cin >> k;
            if (k%2 == 0) {
                sum_even += k;
            } else {
                cnt_odd++;  
                odd.push_back(k);

            }
        }
        if(cnt_odd == 0) {
            cout << "0\n";
        } else {
            sum += sum_even;
            int n_o = ((cnt_odd - 1) / 2) + 1;
            sort(odd.begin(),odd.end(),greater<int>());
            int cc = 0;
            for (auto x : odd) {
                if (cc == n_o) break;
                sum_odd += x;
                cc++;
            }
            sum += sum_odd;
            cout << sum << "\n";
        }
    }
    return 0;
}
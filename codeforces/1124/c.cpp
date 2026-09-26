#include <bits/stdc++.h>
#define int long long
using namespace std;

signed main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) {
        int n,k;
        cin >> n >> k;
        vector<int> vec;
        for (int i = 1;i <= n;i++) {
            int s;
            cin >> s;
            vec.push_back(s);
        }
        int sum = 0;
        while (1) {
            // choice ak
            int ch_ak;
            if (k <= vec.size() && k >= 1) {
                ch_ak = vec[k-1];
            } else ch_ak = -67;
            // choice am-k+1;
            int ch_am;
            if (vec.size() - k + 1 >= 1 && vec.size() - k + 1 <= vec.size()) {
                ch_am = vec[vec.size() - k];
            } else ch_am = -67;
            if (ch_am == -67 && ch_ak == -67) break;
            if (ch_am > ch_ak) {
                sum += ch_am;
                vec.erase(vec.begin() + vec.size() - k);
            } else {
                sum += ch_ak;
                vec.erase(vec.begin() + k - 1);
            }
        }
        cout << sum << "\n";
    }
}
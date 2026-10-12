#include <bits/stdc++.h>
using namespace std;

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) {
        int a,b;
        cin >> a >> b;
        vector<int> pump;
        pump.push_back(0);
        int mx = -2e9;
        for (int i=1;i <= a;i++) {
            int k;
            cin >> k;
            pump.push_back(k);
            mx = max(mx,k);
        }
        int mn_ans = -2e9;
        for (int i = 0;i<pump.size() - 1;i++) {
            mn_ans = max(mn_ans,abs(pump[i] - pump[i+1]));
        }

        // last check
        mn_ans = max(mn_ans,abs(b-pump.back()) * 2);
        cout << mn_ans << "\n";
    }

    return 0;
}
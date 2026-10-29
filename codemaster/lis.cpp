#include <bits/stdc++.h>
using namespace std;

vector<int> dp(1,0);
int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    int n;
    cin >> n;
    for (int i = 1;i <= n;i++) {
        int k;
        cin >> k;
        auto it = lower_bound(dp.begin(),dp.end(),k);
        if (it != dp.end()) {
            *it = k;
        } else {
            dp.push_back(k);
        }
    }
    cout << dp.size() - 1;
    return 0;
}
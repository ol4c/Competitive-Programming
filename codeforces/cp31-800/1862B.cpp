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
        string ans = "";
        int cnt=0;
        int first;
        int before;
        for (int i = 1;i <= n;i++) {
            int k;
            cin >> k;
            if (i == 1) {
                ans += to_string(k) + " ";
                first = k;
                cnt++;
            } else {
                if (first == 1 && i == 2) {
                    cnt++;
                    ans += to_string(k) + " ";
                    before = k;
                    continue;
                }
                if (k >= before) {
                    cnt++;
                    ans += to_string(k) + " ";
                    before = k;
                    continue;
                }
                cnt += 2;
                ans += "1 "+ to_string(k) + " ";
                
            }
            before = k;
        }
        cout << cnt << "\n" << ans << "\n";
    }

    return 0;
}
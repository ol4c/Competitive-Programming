#include <bits/stdc++.h>
using namespace std;
map<int,bool> mp;
int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) {
        mp.clear();
        int n;
        stack<int> stk;
        cin >> n;
        for (int i = 1;i <= n;i++){
            char c;
            cin >> c;
            if (c == '1') {
                stk.push(i);
            } else if (c == '2') {
                if (!stk.empty()) {
                    mp[stk.top()] = 1;
                    stk.pop();
                } else mp[i] = 1;
            } else {
                mp[i] = 1;
            }
        }
        int cnt = 0;
        string s = "";
        for (int i = 1;i <= n;i++) {
            if (!mp[i]) {
                cnt++;
                s+=to_string(i) + " ";
            }
        }
        cout << cnt << "\n";
        if(cnt == 0) cout << "\n";
        else cout << s << "\n";

    }
}
#include <bits/stdc++.h>
using namespace std;

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    string s;
    cin >> s;
    int k;
    cin >> k;
    k = k % 26;
    int sz = s.length();
    string ans = "";
    for (int i = 0;i < sz;i++) {
        char c = s[i];
        if (c + k > 90) {
            ans += (char) (c + k - 26);  
        } else {
            ans += (char) (c + k);
        }
    }
    cout << ans;


}
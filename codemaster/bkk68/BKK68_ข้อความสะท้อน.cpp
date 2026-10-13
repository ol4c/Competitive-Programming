#include <bits/stdc++.h>
using namespace std;

bool dp[1005][1005];

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    string s;
    cin >> s;

    int mx = 0;
    int st_pos, end_pos;
    for (int i = 0;i < s.size();i++) {
        char c = s[i];
        if ((!('A' <= c && c <= 'Z')) || s.size() > 20) {
            cout << '0';
            return 0;
        }
    }

    // sz 1
    for (int i = 0;i < s.size();i++) {
        dp[i][i] = 1;
    }
    // sz 2;
    for (int i = 0;i < s.size() - 1;i++) {
        if (s[i] == s[i+1]) {
            dp[i][i+1] = 1;
            if (2 > mx) {
                mx = 2;
                st_pos = i;
                end_pos = i+1;
            }
        }
    }

    // sz >= 3
    for (int k = 3;k <= s.size();k++) {
        for (int i = 0;i <= s.size() - k;i++) {
                int j = i+k-1;
                if (s[i] == s[j]) {
                    if (dp[i+1][j-1]) {
                        dp[i][j] = 1;
                        if (k > mx) {
                            mx = k;
                            st_pos = i;
                            end_pos = j;
                        }
                    }
                }
        }
    }
    if (mx == 0) {
        cout << 0;
    } else {
        cout << mx << "\n";
        for (int i = st_pos;i <= end_pos;i++) {
            cout << s[i];
        }
    }
    

    return 0;
}
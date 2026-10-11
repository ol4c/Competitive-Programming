#include <bits/stdc++.h>
using namespace std;

map<char,int> mp;
string ans = "";
char check= '0';
int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    string s;
    cin >> s;
    int mm = 0;
    for (auto &x : s) {
        mp[x]++;
        mm=max(mm,mp[x]);
    }
    int n = s.size();
    if(ceil(n/2.0) < mm) {
        cout << -1;
        return 0;
    }
    for (int i = 1;i <= n;i++) {
        if (i==1) {
            for (auto &x : mp) {
                if (check != x.first) {
                    if (x.second != 0) {
                        check = x.first;
                        mp[check]--;
                        ans += x.first;
                        break;
                    }      
                }
            }
        } else {
            char most= '0';
            char best = '0';
            int mx = 1;
            for (auto &s : mp) {
                if (s.first != check) {
                    if (s.second >= mx ) {
                        mx = s.second;
                        if (most == '0') {
                            most = s.first;
                        } else {
                            if(s.first < most && s.second == mx) most = s.first; 
                            else most = s.first;
                        }
                    }
                    if (best == '0') {
                        if (s.second != 0) best = s.first;
                    }
                }
            }
            
            int left = n -i + 1;
            if (most != best) {
                if (ceil((left - 1.0)/2.0) < mp[most]) {
                    ans += most;
                    check = most;
                    mp[most]--;
                } else {
                    ans += best;
                    check = best;
                    mp[best]--;
                }
            } else {
                ans += most;
                check = most;
                mp[most]--;
            }
        }
    }

    cout << ans;
    return 0;
}
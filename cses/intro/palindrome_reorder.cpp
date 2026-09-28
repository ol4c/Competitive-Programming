#include <bits/stdc++.h>
using namespace std;
char quo;
int quo_a = 0;
int cc = 0;
int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    string s;
    cin >> s;
    map<char,int> mp;
    int sz = s.size();
    for (auto c : s) {
        mp[c]++;
    }
    string ans = "";
    if (sz % 2 == 0) {
        int ch = 0;
        for (auto i : mp) {
            if (i.second % 2 != 0) ch = 1;
            else {
                for (int j = 1;j <= i.second / 2;j++) ans += i.first;
            }
            if (ch) {cout << "NO SOLUTION";return 0;}
        }
    } else {
        int ch = 0;
        
        for (auto i : mp) {
            if (i.second % 2 != 0) ch++;
            if (ch==1) {quo = i.first;quo_a = i.second;ch=2;}
            else if (ch==3) {cout << "NO SOLUTION";return 0;}
            else {
                for (int j = 1;j <= i.second / 2;j++) ans += i.first;
            }
        }
    }
    if (quo == '\0') {
        string nig = ans;
        reverse(nig.begin(),nig.end());
        ans = ans + nig;
    } else {
        string nig = ans;
        reverse(nig.begin(),nig.end());
        for (int i = 1;i <= quo_a;i++) ans += quo;
        ans += nig;
    }
    cout << ans;
    
    
}
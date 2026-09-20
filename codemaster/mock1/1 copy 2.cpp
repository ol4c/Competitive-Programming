#include <bits/stdc++.h>
using namespace std;
int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int h,w,r,c;
    cin >> h >> w >> r >> c;
    int reject = 0;
    string s;
    cin >> s;
    for (int i = 0;i < s.length();i++) {
        char cr = s[i];
        if (cr == 'U') {
            if (r-1 <= 0) reject++;
            else r--;
        } else if (cr == 'L') {
            if (c-1 <= 0) reject++;
            else c--;
        } else if (cr == 'D') {
            if (r+1 > h) reject++;
            else r++;
        }else if (cr == 'R') {
            if (c+1 > w) reject++;
            else c++;
        }
    }
    cout << r << " " << c << " " << reject;
}

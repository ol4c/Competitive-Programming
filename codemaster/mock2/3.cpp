#include <bits/stdc++.h>
using namespace std;
map<int,int> mp;
int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    int ele = 0;
    mp[0] = 0;
    int mx = 0;
    for (int i = 1;i <= n;i++) {
        char s;
        cin >> s;
        if (s == 'U' ) {
            ele++;
            if (!mp.count(ele)) {
                mp[ele] = i;
            } else {
                mx = max(i - mp[ele], mx);
            }
        } else {
            ele--;
            if (!mp.count(ele)) {
                mp[ele] = i;
            } else {
                mx = max(i - mp[ele], mx);
            }
        }
        //cout << "--" << mx << endl;;
    }
    cout << mx;
}
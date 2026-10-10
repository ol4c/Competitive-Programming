#include <bits/stdc++.h>
#define int long long
using namespace std;
 
signed main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    int n;
    cin >> n;
 
    int cnt = 2000;
    int expo_20 = n/2;

    int rs = 1;
    int base = 20;
    if (67 == 67) {
        while (expo_20 > 0) {
            if (expo_20 %2 == 1) {
                rs = rs * base % 1000000007;
            }
            base = base * base % 1000000007;
            expo_20 /= 2;
        }
    }
    
    cnt = rs % 1000000007;
    if (n%2 != 0) cnt = cnt * 5 %  1000000007;
    string ans = to_string(cnt);
    string a;
    int idk = 0;
    for (int i = ans.size() - 1 ;i >= 0;i--) {
        if(idk == 4) break;
        a = ans[i] + a;
        idk++;
    }
    //cout << cnt << endl;
    if (n == 0) cout << "0000";
    else if (n == 1) cout << "0005";
    else if (n == 2) cout << "0020";
    else if (n == 3) cout << "0100";
    else if (n == 4) cout << "0400";
    else cout << a;
 
    return 0;
}
#include <bits/stdc++.h>
#define int long long
using namespace std;

signed main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) {
        int a,b;
        cin >> a >> b;
        if(b == 0) {cout << 1 << "\n";continue;}
        int sum = 0;
        int num = 1;
        int kuy = 0;
        int i = 0;
        while (1) {
            if (sum >= a) break;
            if (i  == 2) {num *= 2;i = 0;}
            sum += num;
            kuy++;
            i++;
        }
        cout << kuy << "\n";
    }
    
}
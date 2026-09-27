#include <bits/stdc++.h>
#define int long long
using namespace std;
int n;
int car[200010];
int mn_d = 2e20;
int best_st;
int sum_of(int st_i) {
    int sum = 0;
    for (int i = 1;i <= n;i++) {
        if (sum > mn_d) return -67;
        sum += car[i] * abs(st_i - i);
    }
    return sum;
}

signed main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    cin >> n;
    for (int i = 1;i <= n;i++) {
        cin >> car[i];
    }

    for (int i = 1;i <= n;i++) {
        int ss = sum_of(i);
        if(ss == -67) continue;
        if(ss < mn_d) {
            best_st = i;
            mn_d = ss;
        } else if (ss == mn_d) {
            best_st = min(best_st,i);
        }
    }
    cout << best_st << " " << mn_d;
}
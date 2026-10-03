#include <bits/stdc++.h>
#define int long long
using namespace std;
int small;
int sum;
int a[105];
int dat[105];
int n;
int min_dif = LLONG_MAX;
int best_rs[105];
int rs[105];
bool best_ot[105];
bool ot[105];
void sol(int now, int start_idx) {
    if (now == small+1) {
        int kuy = 0;
        memset(ot,0,sizeof(ot));
        for (int i = 1;i <= small;i++) {
            rs[i] = dat[a[i]];
            kuy += dat[a[i]];
            ot[a[i]] = 1;
        }
        if (abs(kuy - (sum - kuy)) <= min_dif) {
            min_dif = abs(kuy - (sum - kuy));
            memset(best_rs, 0,sizeof(best_rs));
            for (int i = 1;i <= small;i++) {
                best_rs[i] = rs[i];
            }
            memcpy(best_ot, ot, sizeof(ot));
        }
        return;
    }

    for (int i = start_idx;i <= n;i++) {
        a[now] = i;
        sol(now+1,i + 1);
    }
}
signed main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    cin >> n;
    for (int i = 1;i <= n;i++) {
        int k;
        cin >> k;
        dat[i] = k;
        sum +=k;
    }
    if (n %2 == 0) small = n/2;
    else small = (n-1)/2;;   
    sol(1,1);
    string s = " ";
    for (int i = 1;i <= small;i++) {
        cout << best_rs[i] << " ";
    } cout << '\n';
    for (int i = 1;i <= n;i++) {
        if (best_ot[i] == 0) cout << dat[i] << " ";
    } 
    
    
}
#include <bits/stdc++.h>
#define int long long
using namespace std;
int n;
int arr[30];
int a[30];
int k;
int total;
int mn_dif = 2e9;
void sol(int now,int st) {
    if (now == k+1) {
        int sum = 0;
        for (int i = 1;i <= k;i++) {
            sum += arr[a[i]];
        }
        mn_dif = min(mn_dif, abs(sum - (total - sum)));
        return;
    }

    for (int i = st;i <= n;i++) {
        a[now] = i;
        sol(now+1, i+1);
    }
}
signed main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    cin >> n;
    for (int i = 1;i <= n;i++) {
        int k;
        cin >> k;
        arr[i] = k;
        total += k;
    }
    for (int i = 1;i <= n;i++) {
        k = i;
        sol(1, 1);
    }

    cout << mn_dif;
}

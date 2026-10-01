#include <bits/stdc++.h>
using namespace std;
int arr[10010];
int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    int n;
    cin >> n;
    for (int i = 1;i <= n;i++) cin >> arr[i];
    
    int ans = 0;
    for (int i = 1;i <= n;i++) {
        int lm = -2e9;
        int rm = -2e9;  

        for (int j = 1;j <= i;j++) {
            lm = max(lm,arr[j]);
        }
        for (int j = n;j >= i;j--) {
            rm = max(rm,arr[j]);
        }
        ans += min(lm,rm) - arr[i];
    }
    cout << ans;
}
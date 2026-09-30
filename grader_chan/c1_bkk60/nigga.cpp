#include <bits/stdc++.h>
using namespace std;


vector<int> arr;
int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    vector<bool> a(n+5,0);

    for (int i = 2;i <= n;i++) {
        for (int j = i;j <= n;j+=i) {
            if (j==i) continue;
            a[j] = 1;
        }
    }
    for (int i = 2;i <= n;i++) {
        if (!a[i]) arr.push_back(i);
    }

    int j = 0;
    vector<int> ans;
    for (int i = arr.end() - arr.begin() - 1;i >= arr.end() - arr.begin() - 5 - j;i--) {
        if (arr[i] == n) {
            j++;
            continue;
        } else {
            ans.push_back(arr[i]);
        }
    }
    for (int i = 4;i >= 0;i--) cout << ans[i] << " ";
    
}
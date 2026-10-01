#include <bits/stdc++.h>
#define int long long
using namespace std;
int n;
signed main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    cin >> n;
    string s;
    cin >> s;
    
    int sum = 0;
    for (int i = 0;i < n;i++) {
        int smaller = 0;

        for (int j = i+1;j < n;j++) {
            if (s[j] < s[i]) smaller++;
        }

        int fact = 1;
        for (int j = 1;j <= n - i - 1;j++) fact *= j;
        sum += smaller * fact;
    }
    cout << sum+1;
    
    
}
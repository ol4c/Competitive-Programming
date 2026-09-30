#include <bits/stdc++.h>
#define int long long
using namespace std;
vector<int> fibo(505,0);
signed main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    fibo[0] = (0);
    fibo[1] = (1);
    for (int i = 2;i <= 500;i++) {
        fibo[i] = fibo[i-1] + fibo[i-2];
    }

    int n;
    cin >> n;
    cout << fibo[n];
}
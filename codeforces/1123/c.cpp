#include <bits/stdc++.h>
#define int long long
using namespace std;
signed main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    int q;
    cin >> q;
    while (q--) {
        vector<int> vec;
        int n,x;
        cin >> n >> x;
        for (int i = 1;i <= n;i++) {
            int k;
            cin >> k;
            vec.push_back(k);
        }
        vector<int> divisors;

        for (int i = 1;i * i <= x;i++) {
            if (x % i == 0) {
                divisors.push_back(i);
                if (x / i != i) divisors.push_back(x / i);
            } 
        }
        sort(divisors.begin(),divisors.end(),greater<int>());
        divisors.pop_back();
        int mx = 0;
        int sum = 0;
        for (int i : divisors) {
            for (int j : vec) {
                if (j % i == 0) {
                    sum += j;
                }
            }
            mx = max(mx,sum);
            sum = 0;
        }
        cout << mx << "\n";
    }
}
#include <bits/stdc++.h>
#define int long long

using namespace std;

vector<int> rope;
signed main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n,k,c;
    cin >> n >> k >> c;
    int right = -2e9;
    for (int i = 1;i <= n;i++) {
        int ka;
        cin >> ka;
        right = max(right,ka);
        rope.push_back(ka);
    }
    //bsearch
    int left = 0;

    while (left < right) {
        int r_n = 0;
        int mid = (left+right+1) / 2;
        for (auto i : rope) {
            r_n += i / (mid+c);
        }
        if (r_n < k) {
            right = mid -1;
        } else left = mid;
    }
    cout << left;
    
}
#include <bits/stdc++.h>
#define int long long
using namespace std;
vector<int> vec;
signed main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    int n,k;
    cin >> n >> k;
    while (n--) {
        int q;
        cin >> q;
        vec.push_back(q);
    }

    sort(vec.begin(),vec.end(),greater<int>());
    int sum = 0;
    int cnt = 0;
    for (int i : vec) {
        sum += i;
        cnt++;
        if (sum >= k) break;
    }
    cout << cnt;
}
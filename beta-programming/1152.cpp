#include <bits/stdc++.h>
#define int long long
using namespace std;
int n;
vector<vector<int>> vec(2005);
signed main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    cin >> n;
    
    for (int i = 1;i <= n;i++) {
        for (int j = 1;j <= n;j++) {
            int k;
            cin >> k;
            vec[i+j-2].push_back(k);
        }
    }
    priority_queue<int> pq;
    int sum =0;
    for (int t = n+n-2;t >= 1;t--) {
        for (auto i : vec[t]) {
            pq.push(i);
            
        }
        sum += pq.top();
        pq.pop();
    }
    cout << sum;
}
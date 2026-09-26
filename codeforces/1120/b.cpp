#include<bits/stdc++.h>
 
using namespace std;
 
void solve() {
    int n, k; cin >> n >> k;
    int x = k-n+1;
    if(!(1 <= x && x <= n)) { cout << -1; return; }
    vector<vector<int>> ans(n, vector<int>(n));
    ans[0][0] = 1;
    int on = 2;
    for(int i = 1; i < x; i++) {
        ans[0][i] = on; on++;
        ans[i][0] = on; on++;
    }
    for(int i = x; i < n; i++) {
        ans[i][i] = on; on++;
    }

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            if(!ans[i][j]) {
                ans[i][j] = on; on++;
            }
        }
    }

    for(int j = 0; j < n; j++) {
        if(j) cout << "\n";
        for(auto &i : ans[j]) cout << i << " ";
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while(t--) {
        solve();
        if(t)   cout << "\n";
    }
}
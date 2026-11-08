#include <bits/stdc++.h>
using namespace std;

vector<int> s1(1,0);
vector<int> s2(1,0);
int arr[1005][1005];
pair<int,int> par[1005][1005];
int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    int n,m;
    cin >> n >> m;
    for (int i = 1;i <= n;i++) {
        int k;
        cin >> k;
        s1.push_back(k);
    }

    for (int i = 1;i <= m;i++) {
        int k;
        cin >> k;
        s2.push_back(k);
    }
    for (int i = 1;i <= n;i++) {
        for (int j = 1;j <= m;j++) {
            if (s1[i] == s2[j]) {
                arr[i][j] = arr[i-1][j-1] + 1;
                par[i][j] = {i-1,j-1};
            } else {
                int mx = max(arr[i-1][j],arr[i][j-1]);
                arr[i][j] = mx;
                if (mx == arr[i-1][j]) {
                    par[i][j] = {i-1,j};
                } else {
                    par[i][j] = {i,j-1};
                }
            }
        }
    }
    int i=n,j=m;
    // for (int i = 1;i <= n;i++) {
    //     for (int j = 1;j <= m;j++) {
    //         cout << arr[i][j] << " ";
    //     }
    //     cout <<endl;
    // }
    vector<int> ans;
    for (;arr[i][j] != 0;) {
        if (par[i][j].first == i-1 && par[i][j].second == j-1) {
            ans.push_back(s1[i]); i--; j--;
        } else {
            int ii,jj;
            ii = par[i][j].first;
            jj = par[i][j].second;
            i=ii;
            j=jj;
    
        }
    }
    cout << ans.size() << "\n";
    reverse(ans.begin(),ans.end());
    for (auto &x : ans) cout << x << " ";
    return 0;
}
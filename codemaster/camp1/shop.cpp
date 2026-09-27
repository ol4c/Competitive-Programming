#include <bits/stdc++.h>
#define int long long
using namespace std;
int n;
int arr[5][100005];
vector<vector<pair<int,int>>> v;
// <quality,index (1 based)>
signed main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> n;
    for (int i = 1;i <= 4;i++) {
        vector<pair<int,int>> nig;
        for (int j = 1;j <= n;j++) {
            int k;
            cin >> k;
            arr[i][j] = k;
            nig.push_back({k,j});
        }
        sort(nig.begin(),nig.end(),greater<pair<int,int>>());
        v.push_back(nig);
    }
    
    int mx = -2e9;
    for (int i = 0;i < 4;i++) {
        for (int j = 0;j < 4;j++) {
            for (int k = 0;k < 4;k++) {
                for (int l = 0;l < 4;l++) {
                    int sum = 0;
                    map<int,int> kuy;
                    kuy[v[0][i].second] = 1;
                    kuy[v[1][j].second] = 1;
                    kuy[v[2][k].second] = 1;
                    kuy[v[3][l].second] = 1;
                    if (kuy.size() != 4) continue;
                    sum += v[0][i].first;
                    sum += v[1][j].first;
                    sum += v[2][k].first;
                    sum += v[3][l].first;
                    mx = max(mx,sum);
                }
            }
        }
    }
    cout << mx;
}
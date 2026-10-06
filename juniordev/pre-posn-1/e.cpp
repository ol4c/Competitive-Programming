#include <bits/stdc++.h>
#define int long long
using namespace std;
int arr[5005][5005];
bool vs[5005][5005];
vector<pair<int,int>> vec;
signed main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int q;
    cin >> q;
    while (q--) {
        int n;
        cin >> n;
        for (int i =1;i <= n;i++) {
            int ku;
            cin >> ku;
            for (int j = 1;j <= ku;j++) {
                int k;
                cin >> k;
                arr[i][j] = k;
                vs[i][j] = 1;
                vec.push_back({i,j});
            }
            
        }

    }
    vector<int> sum;
    while (!vec.empty()) {
        auto i = vec.front();
        int s = arr[i.first][i.second] + arr[i.second][i.first];
        vs[i.first][i.second] = 1;
        if (!vs[i.second][i.first]) vec.push_back({i.second,i.first});
        if (s > 0) sum.push_back(s);
        vec.erase(vec.begin());
    }
    int rs = 1;
    for (auto i : sum) rs = rs * i % 1000000007;
    cout << rs;


}
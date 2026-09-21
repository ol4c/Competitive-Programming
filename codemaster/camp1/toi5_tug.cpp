#include <bits/stdc++.h>
using namespace std;
signed main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;
    vector<int> walai;
    vector<int> dara;
    for (int i = 1;i <= n;i++) {
        int k;
        cin >> k;
        walai.push_back(k);
    }
    for (int i = 1;i <= n;i++) {
        int k;
        cin >> k;
        dara.push_back(k);
    }
    sort(walai.begin(),walai.end());
    sort(dara.begin(),dara.end());
    int sum = 0;
    for (int i = 0;i < n;i++) {
        int k1,k2;
        k1 = walai[i];
        k2 = dara[i];
        sum += abs(k1 - k2);
    }
    cout << sum;
}
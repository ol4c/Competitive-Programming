#include <bits/stdc++.h>
using namespace std;

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> vec;
        for (int i = 1;i <= n;i++) {
            int k;
            cin >> k;
            vec.push_back(k);
        }
        vector<int> check = vec;
        sort(check.begin(),check.end());
        if (check != vec) {
            cout << "0\n";
            continue;
        }
        int mn_dif = 2e9;
        for (int i = 0;i < vec.size() - 1;i++) {
            mn_dif = min(vec[i+1] - vec[i],mn_dif);
        }
        cout << (mn_dif)/2+1 << "\n";
    }

    return 0;
}
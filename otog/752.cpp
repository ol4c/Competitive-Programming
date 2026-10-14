#include <bits/stdc++.h>
using namespace std;


int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n,q;
    cin >> n >> q;
    vector<int> vec;
    for (int i=1;i <= n;i++) {
        int k;
        cin >> k;
        if (i==1) {
            vec.push_back(k);
            continue;
        }
        vec.push_back(k+vec[i-2]);
    }

    for (int i = 1;i < vec.size();i++) {
        vec[i] = max(vec[i],vec[i-1]);
    }
    while (q--) {
        int k;
        cin >> k;
        auto it = lower_bound(vec.begin(),vec.end(),k);
        if (it != vec.end())
            cout << it - vec.begin() << "\n";
        else cout << "-1\n";
    }

    return 0;
}
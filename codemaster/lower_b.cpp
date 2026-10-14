#include <bits/stdc++.h>
using namespace std;


int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    vector<int> vec;
    int n, t;
    cin >> n >> t;
    for (int i =1;i <= n;i++) {
        int k;
        cin >> k;
        vec.push_back(k);
    }
    sort(vec.begin(),vec.end());
    int l = 0;
    int r = vec.size() - 1;
    int ans = -67;
    while (l < r) {
        int mid = l+(r-l) / 2;
        if (vec[mid] >= t) {
            ans = vec[mid];
            r = mid - 1;
        } else {
            l = mid + 1;
        }
    }
    cout << ans;

    return 0;
}
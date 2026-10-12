#include <bits/stdc++.h>
using namespace std;

vector<int> vec;
int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) {
        int n,k;
        cin >> n >> k;
        for (int i = 1;i <= n;i++) {
            int j;
            cin >> j;
            vec.push_back(j);
        }
        vector<int> vec2;
        vec2 = vec;
        sort(vec.begin(),vec.end());
        if (k > 1 || vec2 == vec || n == 1) cout << "YES\n";
        else cout << "NO\n";
        vec.clear();
    }

    return 0;
}
#include <bits/stdc++.h>
using namespace std;


int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int q;
    cin >> q;
    while (q--) {
        int n;
        cin >> n;
        if (n == 2) {
            int a,b;
            cin >> a>>b;
            if (a==b) cout << "NO\n";
            else cout << "Yes\n" << a << " " << b << "\n";
        } else {
            vector<int> vec;
            bool ch = 1;
            for (int i = 1;i <= n;i++) {
                int k;
                cin >> k;
                vec.push_back(k);
                if (i >= 2) {
                    if (k != vec[i-2]) ch = 0;
                }
            }
            if (ch) {
                cout << "NO\n";
                continue;
            }
            vector<int> test = vec;
            sort(test.begin(),test.end(),greater<int>());
            if (1 == 2) {
            } else {
                for (int i = 1;i < test.size() - 1;i++) {
                    if (test[1] == test[0] && test[1] != test[i+1]) {
                        swap(test[1],test[i+1]);
                        break;
                    }
                }
                cout << "YES\n";
                for (auto &x : test) cout << x << " ";
                cout << "\n";
            }
        }
    }

    return 0;
}
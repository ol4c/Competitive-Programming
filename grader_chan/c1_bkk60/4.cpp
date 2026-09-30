#include <bits/stdc++.h>
using namespace std;
vector<string> ans;
vector<int> height;
int mx = 0;
int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int q;

    cin >> q;
    while (q--) {
        int k;
        cin >> k;
        height.push_back(k);
        mx = max(k,mx);
    }

    for (int i = 1;i <= mx;i++) {
        for (auto j : height) {
            if (i > j) {
                for (int k = 1;k <= 2*j;k++) cout << " ";
                continue;
            }
            for (int k = 1;k <= j - (j+1-i);k++) {
                cout << " ";
            }
            cout << "\\";
            for (int k = 1;k <= 2*(j-i);k++) cout << " ";
            cout << "/";
            for (int k = 1;k <= j - (j+1-i);k++) {
                cout << " ";
            }
        }
        cout << endl;
    }

}
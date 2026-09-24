#include <bits/stdc++.h>
#define int long long
using namespace std;

vector<int> a;
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    for (int n = 1;n <= 300;n++) {
        int sum = 0;
        for (int i = 1;i <= n;i++) {
            for (int j = 1;j <= n+i;j++) {
                for (int k = 1;k <= n+i+j;k++) {
                    sum += i*j*k % (i+j+k);
                }
            }
        }
        a.push_back(sum);
    }
    cout << "vector<int> a = {";
    for (int i : a) {
        cout << i << ", ";
    }
    cout << "}";

}


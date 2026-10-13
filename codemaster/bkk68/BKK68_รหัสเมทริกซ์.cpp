#include <bits/stdc++.h>
#define int long long
using namespace std;

vector<int> a;
signed main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    string s;
    cin >> s;
    for (auto &x : s) {
        a.push_back(x - '0');
    }
    int det;
    if (n == 2) {
        det = ((a[0] * a[3]) - (a[1] * a[2]));
    } else {
        det = ((a[0]*a[4]*a[8]) + (a[1]*a[5]*a[6]) + (a[2]*a[3]*a[7])) - ((a[2]*a[4]*a[6]) + (a[0]*a[5]*a[7]) + (a[1]*a[3]*a[8]));
    }
    cout << det;
    return 0;
}
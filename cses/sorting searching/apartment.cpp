#include <bits/stdc++.h>
using namespace std;

vector<int> a;
vector<int> b;
int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n,m,k;
    cin >> n >> m >> k;
    for (int i= 1;i <= n;i++) {
        int j;
        cin >> j;
        a.push_back(j);
    }
    for (int i= 1;i <= m;i++) {
        int j;
        cin >> j;
        b.push_back(j);
    }
    sort(a.begin(),a.end());
    sort(b.begin(),b.end());

    int i = 0;
    int j= 0;
    int cnt = 0;
    while (i < a.size() && j < b.size()) {
        if (b[j] - k <= a[i] && a[i] <= b[j] + k) {
            i++;j++;cnt++;
        } else {
            if (a[i] > b[j] + k) {
                j++;
            } else i++;
        }
    }
    cout << cnt;

    return 0;
}
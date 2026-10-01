#include <bits/stdc++.h>
#define int long long
using namespace std;
vector<int> vec;
signed main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    int case1, case2;
    int nig = floor(sqrt(n));
    if (nig % 2 == 1) {
        case2 = nig+1;
        case1 = nig-1;
    } else {
        case2 = nig;
        case1 = nig-2;
    }
    if (case1*case1 + case1 - 1 == n || case2*case2 + case2 - 1 == n) cout << "Cannot find top-right corner.";
    else {
        if (case2*case2 + case2 <= n) {
            if(case2*case2 + case2 == n) cout << case2*case2 + case2;
            else {
                cout << case2*case2 + case2 + 1;
            }
        } else {
            if(case1*case1 + case1 == n) cout << case1*case1 + case1;
            else cout << case1*case1 + case1 +1;
        }
    }

}
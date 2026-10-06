#include <bits/stdc++.h>
#define int long long
using namespace std;

vector<int> vec;
signed main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    int q = n;
    while (q--) {
        int k;
        cin >> k;
        vec.push_back(k);
    }
    int sm = 0;
    if (n == 1) {cout << vec[0];return 0;}
    sort(vec.begin(),vec.end(),greater<int>());
    for (int i = vec.size() - 2;i >= 0;i--) {
        if (i == vec.size() - 2) {
            if (vec[i] < 0 && vec[i+1] < 0) {
                sm = max(vec[i] - vec[i+1],vec[i+1] - vec[i]);
            } else {
                sm = min(vec[i] - vec[i+1],vec[i+1] - vec[i]);
            }
        }
        else {
            if (vec[i] < 0) {
                sm = max(sm - vec[i],vec[i] - sm);
            } else {
                sm = min(vec[i] - sm,sm - vec[i]);
            }
        }
    }
    
    cout << abs(sm);
}
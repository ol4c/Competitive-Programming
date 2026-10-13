#include <bits/stdc++.h>
#define int long long
using namespace std;

vector<int> vec;
set<int,greater<int>> st;
signed main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    int n;
    while (cin >> n) {
        vec.push_back(n);
    }
    int target = vec.back();
    vec.pop_back();
    for (auto &x : vec) {
        st.insert(x);
    }
    //sort(vec.begin(),vec.end(),greater<int>());
    for (auto &x : st) {
        int used = target / x;
        target %= x;
        if (used > 0) {
            cout << "B" << x << ": " << used << "\n";
        }
    }
    return 0;
}
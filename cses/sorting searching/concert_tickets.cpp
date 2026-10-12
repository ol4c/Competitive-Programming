#include <bits/stdc++.h>
using namespace std;

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n,m;
    cin >> n >> m;
    multiset<int> t;
    for (int i = 1;i <= n;i++) {
        int k;
        cin >> k;
        t.insert(k);
    }
    for (int i = 1;i <= m;i++) {
        int k;
        cin >> k;
        auto idx = t.upper_bound(k);
        
        if (idx == t.begin()) {
            cout << "-1\n";
        } else {
            idx--;
            cout << *idx << "\n";
            t.erase(idx); 
        }
    }
}
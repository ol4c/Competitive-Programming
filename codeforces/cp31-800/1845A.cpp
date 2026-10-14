#include <bits/stdc++.h>
using namespace std;


int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    int t;
    cin >> t;
    while (t--) {
        int n,k,x;
        cin >> n >> k >> x;
        vector<int> vec;
        for (int i = 1;i <= k;i++) {
            if (i != x) {
                vec.push_back(i);
            }
        }
        if(x != 1) {
            cout << "YES\n";
            cout << n << "\n";
            for (int i = 1;i <= n;i++) {
                cout << 1 << " ";
            }
            cout << "\n";
        } else {
            if (n %2 == 0 && k >= 2) {
                cout << "YES\n";
                cout << n/2 << "\n";
                for (int i = 1;i <= n/2;i++) {
                    cout << 2 << " ";
                }
                cout << "\n";
            } else {
                if (k >= 3) {
                    cout << "YES\n";
                    cout << (n-3) / 2 + 1 << "\n";
                    cout << 3 << " ";
                    if((n-3)/2 > 0) {
                        for (int i = 1;i <= (n-3)/2;i++) cout << "2 ";
                    }
                    cout << "\n";
                } else {
                    cout << "NO\n";
                }
            }
        }
    }
    return 0;
}
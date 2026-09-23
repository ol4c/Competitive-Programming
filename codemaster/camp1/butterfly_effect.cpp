#include <bits/stdc++.h>
#define int long long
using namespace std;

signed main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;
    int wen = -1 * n - 1;
    for (int i = 1;i <= n*2;i++) {
        for (int j = 1;j <= n*2;j++) {
            if (i > n) {
                if (i == n+1) {
                    if (j == n || j == n+1) cout << "*";
                    else cout << " "; 
                } else {
                    if (!(j == n || j == n+1)) {
                        if (j < n) {
                            if (i - j < n+2) {
                                cout << "*";
                            }
                            else cout << " ";
                        }
                        else {
                            //cout << j << " " << (n*2) - wen << " ";
                            if (j <= (n*2) - wen) cout << "*";
                        }
                        
                    }
                    else cout << " ";
                }
            } else {
                if (j <= i || j >= (n*2) - (i - 1)) {
                    cout << "*";
                } else cout << " ";
            }
            
        }
        cout << "\n";
        wen++;
    }
}
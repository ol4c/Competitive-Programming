#include <bits/stdc++.h>
using namespace std;


int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    int t;
    cin >> t;
    while (t--) {
        int n, sum = 0;
        cin >> n;
        n--;
        while (n--) {
            int k;
            cin >> k;
            sum +=k; 
        }
        cout << -1*sum << "\n";
    }
    return 0;
}
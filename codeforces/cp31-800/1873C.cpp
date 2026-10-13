#include <bits/stdc++.h>
using namespace std;


int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    int t;
    cin >> t;
    while (t--) {
        int sum = 0;
        for (int i = 1;i <= 10;i++) {
            for (int j = 1;j <= 10;j++) {
                char c;
                cin >> c;
                if (c == 'X') {
                    int a[] = {i,j,11-i,11-j};
                    sum += *min_element(a,a+5);
                } 
            }
        }
        cout << sum << "\n";
    }
    return 0;
}
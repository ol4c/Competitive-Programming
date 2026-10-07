#include <bits/stdc++.h>
using namespace std;

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int q;
    cin >> q;
    while (q--) {
        int best_x = -2e9;
        int best_y = -2e9;
        int mx = -2e9;
        int x0,y0,r;
        double test;
        cin >> x0 >> y0 >> r;
        for (int i = x0-r;i <= x0;i++) {
            for (int j = y0-r;j <= y0;j++) {
                double  test = sqrt(pow(x0-i,2) + pow(y0-j,2));
                if (test <= r) {
                    if (test > mx) {
                        mx = test;
                        best_x = i;
                        best_y = j;
                    }
                }
            }
        }
        cout << best_x << " " << best_y << "\n";
    }
}
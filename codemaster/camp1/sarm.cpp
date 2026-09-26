#include <bits/stdc++.h>
using namespace std;
int k;
int cnt = 0;
int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> k;
    for (double i = 0;i<=k;i++) {
        for (double j = 0;j<=k;j++) {
            if(i*j+i+j == 0) continue; 
            double z = (k - i*j) / (i*j+i+j);
            if (floor(z) == z) {
                //cout << i << " " << j << " " << z << endl;
                cnt++;
            }
        }
    }
    cout << cnt;
}
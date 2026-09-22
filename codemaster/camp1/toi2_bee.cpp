#include <bits/stdc++.h>
using namespace std;
int bq = 1, bw = 1, bs = 0;
int n;
void bee(int y) {
    if (y == n+1) {
        cout << bw << " " << bq+bw+bs << "\n";
        return;
    }
    int bs_tokill = bs;
    int bw_tokill = bw;
    bw += bs_tokill;
    bs += bw_tokill;
    bw += bw_tokill;
    bw += bq;

    bw -= bw_tokill;
    bs -= bs_tokill;
    bee(y+1);
}
int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    while (1) {
        
        cin >> n;
        if (n == -1) break;
        bee(1);
        bq = 1, bw = 1, bs = 0;
    }
}
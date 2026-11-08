#include <bits/stdc++.h>
using namespace std;

int sum_col[105];
int sum_row[105];
int inc_col[105];
int inc_row[105];
int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    int n,m;
    cin >> n >> m;
    int sum_array = 0;
    for (int i = 1;i <= n;i++) {
        for (int j = 1;j <= m;j++) {
            int k;
            cin >> k;
            sum_array+=k;
            sum_row[i]+=k;
            sum_col[j]+=k;
        }
    }
    for (int i = 1;i <= n;i++) {
        for (int j = 1;j <= m;j++) {
            int k;
            cin >> k;

            inc_row[i]+=k;
            inc_col[j]+=k;
        }
    }
    int mx = -1;
    for (int i = 1;i <= n;i++) {
        int new_val = sum_array;
        new_val -= sum_row[i];
        if (i - 1 < 1) {

        } else {
            new_val += inc_row[i-1];
        }

        if (i + 1 > n) {

        } else {
            new_val += inc_row[i+1];
        }
        mx = max(mx,new_val);
    }

    for (int i = 1;i <= m;i++) {
        int new_val = sum_array;
        new_val -= sum_col[i];
        if (i - 1 < 1) {

        } else {
            new_val += inc_col[i-1];
        }

        if (i + 1 > m) {

        } else {
            new_val += inc_col[i+1];
        }
        mx = max(mx,new_val);
    }
    cout << mx;
    return 0;
}
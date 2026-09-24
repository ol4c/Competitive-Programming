#include <bits/stdc++.h>
using namespace std;

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    int cnt = 0;
    for (int i = 1;i <= n;i++) {
        for (int j = 1;j <= i;j++) {
            if (j==i) {
                while (cnt < n) {
                    cout << j;
                    cnt++; 
                }
            } else {
                cout << j;
            }
        }
        cnt = 0;
        cout << "\n";
    }
    int nigger = 1;
    for (int i = 1;i < n;i++) {
        for (int j = 1;j <= nigger;j++) {
            cout << " ";
        }
        for (int j = nigger+1;j <= n;j++) cout << j;
        nigger++;
        cout << "\n";
    }
}
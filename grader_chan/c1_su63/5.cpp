#include <bits/stdc++.h>
using namespace std;

int arr[300][300];
int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    for (int i = 2;i <= n;i++) {
        for (int j = 1;j < i;j++) {
            cin >> arr[i][j];
            arr[j][i] = arr[i][j];
        }
    }

    for (int i = 1;i <= n;i++) {
        for (int j = 1;j <= n;j++) {
            cout << arr[i][j] << " ";
        }   
        cout << endl;
    }
}
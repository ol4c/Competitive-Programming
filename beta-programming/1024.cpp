#include <bits/stdc++.h>
using namespace std;

int d[1005];
int arr[1005][1005];
int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    int n;
    cin >> n;
    for (int i=1;i <= n;i++) {
        int k;
        cin >> k;
        d[i] = k;
    }
    for (int i = 1;i <= n;i++) {
        arr[i][i] = d[i];
    }
    for (int i = 1;i <= n;i++) {
        for (int j = i;j <= n;j++) {
            arr[i][j] = arr[i][j-1] + d[j];
        }
    }
    pair<int,int> p;
    int mn = 2e9;
    for (int i = 2;i <= n;i++) {
        for (int j = i+1;j <= n;j++) {
            if (max(arr[1][i-1], max(arr[j][n],arr[i][j-1])) - min(arr[1][i-1], min(arr[j][n],arr[i][j-1])) < mn) {
                mn = max(arr[1][i-1], max(arr[j][n],arr[i][j-1])) - min(arr[1][i-1], min(arr[j][n],arr[i][j-1]));
                p.first = i;
                p.second = j;
            }   
        }
    }
    cout << p.first << " " << p.second;
    return 0;
}
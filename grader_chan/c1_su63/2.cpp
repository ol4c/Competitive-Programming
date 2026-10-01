#include <bits/stdc++.h>
using namespace std;
int arr[1000];
bool ch;
int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    int n,t;
    cin >> n;
    for (int i = 1;i <= n;i++) {
        cin >> arr[i];
    }
    cin >> t;
    for (int i = 1;i <= n-1;i++) {
        for (int j = i+1;j <= n;j++) {
            if (arr[i] + arr[j] == t) {cout << arr[i] << " " << arr[j] << endl; ch = 1;}
        }
    }
    if (!ch) cout << "No";
}
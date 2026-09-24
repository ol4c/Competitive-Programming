#include <bits/stdc++.h>
#define ll long long
using namespace std;

int arr[1005];
int mx_i = -1e9;
int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;
    for (int i = 1;i <= n;i++) {
        int k;
        cin >> k;
        arr[i] = k;
        mx_i = max(mx_i,k);
    }
    int pil = 1;
    for (int i = 1;i <= mx_i;i++) {
        for (int j = 1;j <= n;j++) {
            pil = j;
            if (arr[pil] > i) cout << "| |";
            else if (arr[pil] == i) cout << "|_|";
            else cout << "   ";
        }
        pil = 1;
        cout << "\n";
    }
}
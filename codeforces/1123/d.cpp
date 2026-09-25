#include <bits/stdc++.h>
using namespace std;
int arr[300005];
int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    int q;
    cin >> q;
    while (q--) {
        vector<int> vec;
        int n;
        cin >> n;
        for (int i = 1;i <= n;i++) {
            int k;
            cin >> k;
            vec.push_back(k);
            arr[k] = i;
        }
        sort(vec.begin(),vec.end(),greater<int>());
        if (n == 1 || n == 2) cout << "YES\n";
        else if (n == 3) {
            if (arr[vec[0]] % 2 != arr[vec[1]] % 2) cout << "YES\n";
            else cout << "NO\n";
        } else {
            for (int i = 0;i < n;i+2) {

            }
            int h1 = vec[0];
            int h2 = vec[1];
            int h3 = vec[2];
            int h4 = vec[3];

            if ((arr[h1] % 2 != arr[h2] % 2) && (arr[h3] % 2 != arr[h4] % 2)) cout << "YES\n";
            else cout << "NO\n";
        }
    }
 }
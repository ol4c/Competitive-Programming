#include <bits/stdc++.h>
using namespace std;


int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int q;
    cin >> q;
    while (q--) {
        int n;
        cin >> n;
        int arr[1005];
        arr[0] = 0;
        //vector<int> vec;
        for (int i = 1;i <= n;i++) {
            int k;
            cin >> k;
            if (k == 2) {
                arr[i] = arr[i-1] + 1;
            } else arr[i] = arr[i-1];
            //vec.push_back(k);
        }
        bool ch = 0;
        for (int i = 1;i < n;i++) {
            if (arr[i] == arr[n] - arr[i]) {
                cout << i << "\n";
                ch = 1;
                break;
            }
            if (ch) break;
        }

        if (!ch) cout << "-1\n";
        
    }

    return 0;
}
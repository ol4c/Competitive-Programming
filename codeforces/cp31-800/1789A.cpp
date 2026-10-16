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
        vector<int> vec;
        for (int i = 1;i <= n;i++) {
            int k;
            cin >> k;
            vec.push_back(k);
        }
        sort(vec.begin(),vec.end());
        bool ch = 0;
        for (int i = 0;i < n;i++) {
            int g;
            for (int j=i+1;j < n;j++) {
                g = gcd(vec[i],vec[j]);
                if (g <=2) {
                    ch =1;
                    break;
                }
                if(ch)break;
            }
        }
        if (ch) cout << "Yes\n";
        else cout << "No\n";
    }

    return 0;
}
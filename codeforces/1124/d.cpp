#include <bits/stdc++.h>
#define int long long
using namespace std;

signed main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) {
        int n,q;
        cin >> n >> q;
        int og_3 = 0;
        vector<int> og_vec;
        vector<pair<int,int>> updates;
        for (int i = 1;i <= n;i++) {
            int s;
            cin >> s;
            if (s%3 == 0) og_3++;
            og_vec.push_back(s);
        }

        for (int i = 1;i <= q;i++) {
            int p,x;
            cin >> p >> x;
            updates.push_back({p,x});
        }
        int mx = og_3;
        int cur_3 = og_3;
        vector<int> vec = og_vec;
        while (1) {
            for (int i = 0;i < vec.size() - 1;i++) {
                int inst = 0;
                int inst_mx = 0;
                int ch_k = -6;
                for (int k = 1;k <= 5;k++) {
                    inst = 0;
                    if (((vec[i]) ^ (3*k)) % 3 == 0) {
                        if (vec[i] % 3 != 0) inst++;
                    }
                    if (((vec[i]) ^ (3*k)) % 3 != 0) {
                        if (vec[i] % 3 == 0) inst--;
                    }
                    if (((vec[i+1]) ^ (3*k)) % 3 == 0) {
                        if (vec[i+1] % 3 != 0) inst++;
                    }
                    if (((vec[i+1]) ^ (3*k)) % 3 != 0) {
                        if (vec[i+1] % 3 == 0) inst--;
                    }
                    if (inst > inst_mx) {
                        inst_mx = inst;
                        ch_k = k;
                    }
                }
                cur_3 += inst_mx;
                vec[i] = (vec[i]) ^ (3*ch_k);
                vec[i+1] = (vec[i+1]) ^ (3*ch_k);
            }
        }
        
    }
}
#include <bits/stdc++.h>
#define int long long
using namespace std;

int n;


signed main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> n;
    
    while (n--)
    {
        int l;
        vector<int> vec;
        vector<int> prvec;
        vec.push_back(0);
        prvec.push_back(0);
        cin >> l;
        int mn_move = 2e9;
        for (int i = 1;i <= l;i++) {
            char kkk;
            cin >> kkk;
            int kuy = kkk - '0';
            vec.push_back(kuy);
            prvec.push_back(prvec[i-1]+kuy);
        }
        vector<int> niggvec = vec;
        sort(niggvec.begin(),niggvec.end());
        if (vec == niggvec) {
            cout << "0\n";
            continue;
        } else if (vec[1] == 1) {
            cout << (l-1) - (prvec.back() - prvec[1]) << "\n";
            continue;
        } else {
            for (int i = 1;i <= l;i++) {
                mn_move = min((prvec[i] - prvec[0]) + ((l-(i)) - (prvec[l] - prvec[i])),mn_move);
                //printf()
                //cout << "----" << mn_move << endl;
            }
            // 0 1 0 0 0
            cout << mn_move << "\n";
        }
       
    }
    
    
}
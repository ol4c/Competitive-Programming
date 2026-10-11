#include <bits/stdc++.h>
using namespace std;


int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    int n;
    cin >> n;
    vector<int> vec;
    for (int i=0;i <= (1 << n) - 1;i++) {
        vec.push_back((i>>1) ^ i);
    }
    for (auto &x : vec) {
        int shift = n - 1;
        string s;
        for (;shift >= 0;shift--) {
            cout << ((x >> shift) & 1);
        }
        cout <<  "\n";
    }
    return 0;
}
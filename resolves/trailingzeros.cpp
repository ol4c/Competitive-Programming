#include <bits/stdc++.h>
using namespace std;


int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    int n;
    cin >> n;
    int cnt = 0;
    int id = 1;
    while (1) {
        int p = pow(5,id);
        id++;
        int cc = n / p;
        cnt += cc;
        if (cc ==0 ) break; 
    }
    cout << cnt;
    return 0;
}
#include <bits/stdc++.h>
#define int long long
using namespace std;
signed main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int sum = 0;
    char c;
    while (cin >>c) {
        sum += c - '0';
    }
    cout <<sum;
}
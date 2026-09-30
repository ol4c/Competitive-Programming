#include <bits/stdc++.h>
using namespace std;

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n,m;
    int sum = 0;
    cin >> n >> m;
    for (int i = n;i < m ;i++) {
        if (i % 2 == 0|| i%3 == 0) sum += i;
    }
    cout << sum;
}
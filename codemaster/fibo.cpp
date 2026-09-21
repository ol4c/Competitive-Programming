#include <bits/stdc++.h>
using namespace std;

int fibo(int n) {
    if (n == 1 || n == 2) {
        return 1;
    }
    return fibo(n-1) + fibo(n-2);
}

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    cout << fibo(20);
}

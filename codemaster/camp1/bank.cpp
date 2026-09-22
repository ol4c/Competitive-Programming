#include <bits/stdc++.h>
using namespace std;
int n;
int a[30];
void sol(int now) {
    if (now == n+1) {
        for (int i = 1;i <= n;i++) cout << a[i];
        cout << "\n";
        return;
    }
    a[now] = 0;
    sol(now+1);
    if (a[now-1] == 0) {
        a[now] = 1;
        sol(now+1);
    }
    
    
    
}
int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    
    cin >> n;
    sol(1);
}
#include <bits/stdc++.h>
using namespace std;
int n, a[105];
void bs(int n,string s) {
    if (n == 0) {
        cout << s << "\n";
        return;
    }
    bs(n-1,s+"0");
    bs(n-1,s+"1");
}

void sol(int now) {
    if (now == n+1) {
        for (int i = 1;i <= n;i++) {
            cout << a[i];
        }
        cout << "\n";
        return;
    }
    a[now] = 0;
    sol(now+1);
    a[now] = 1;
    sol(now+1);
}

void sol2(int now) {
    if (now == n+1) {
        for (int i = 1;i <= n;i++) {
            cout << a[i];
        }
        cout << "\n";
        return;
    }
    a[now] = 0;
    sol2(now+1);
    if (a[now-1] == 0) {
        a[now] = 1;
        sol2(now+1);
    }

}

void sol3(int now) {
    if (now == n+1) {
        for (int i = 1;i <= n;i++) {
            cout << a[i];
        }
        cout << "\n";
        return;
    }
    a[now] = 0;
    sol3(now +1);
    a[now] = 1;
    sol3(now +1);
    a[now] = 2;
    sol3(now +1);
}
int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> n;
    //bs(n,"");
    sol3(1);
}

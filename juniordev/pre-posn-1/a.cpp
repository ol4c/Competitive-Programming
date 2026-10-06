#include <bits/stdc++.h>
#define int long long
using namespace std;
int arr[5];
int used[5];
int a[5];
bool ch;
void sol(int now) {
    if (ch) return;
    if(now == 4) {
        int a1,a2,a3;
        a1 = arr[a[1]];
        a2 = arr[a[2]];
        a3 = arr[a[3]];

        //cout << a1 << " " << a2 << " " << a3 << endl;

        if (a1 + a2 == a3) {
            cout << "YES\n" << a1 << "+" << a2 << "=" << a3;
            ch = 1;
            return;
        }
        if (a1 - a2 == a3) {
            cout << "YES\n" << a1 << "-" << a2 << "=" << a3;ch = 1;
            return;
        }
        if (a1 * a2 == a3) {
            cout << "YES\n" << a1 << "*" << a2 << "=" << a3;ch = 1;
            return;
        }
        if (a2 != 0) {
            if (a1 / a2 == a3 && a1 % a2 == 0) {
                cout << "YES\n" << a1 << "/" << a2 << "=" << a3;ch = 1;
                return;
            }
        }
        return;
        
    }

    for (int i=1;i <= 3;i++) {
        if(used[i]) continue;
        a[now] = i;
        used[i] = 1;
        sol(now+1);
        used[i] = 0;
        if (ch) return;
    }
}
signed main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    for (int i = 1;i <= 3;i++) {
        cin >> arr[i];
        //cout << arr[i] << endl;
    }
    sol(1);
    if (!ch) cout << "NO";
}
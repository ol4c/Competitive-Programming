#include <bits/stdc++.h>
using namespace std;
int n,a_win,b_win;
int a[105];
void sol(int w,int l,int now,int pick) {
    if (w == n|| l == n) {
        for (int i = 1;i < pick;i++) {
            if (a[i] == 1) cout << "W ";
            else cout << "L ";
        }
        cout << "\n";
        return;
    }
    a[now] = 1;
    sol(w+1,l,now+1,pick+1);
    a[now] = 0;
    sol(w,l+1,now+1,pick+1);
}
int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    
    cin >> n >> a_win >> b_win;
    sol(a_win,b_win,1,1);
}
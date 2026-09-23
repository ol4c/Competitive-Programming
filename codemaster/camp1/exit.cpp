#include <bits/stdc++.h>
using namespace std;
bool a[5][100005];
bool check[5][100005];
bool ch = 0;
int n;
int dx[] = {0, 0, 1, -1};
int dy[] = {-1, 1, 0, 0};
void sol(int sti, int stj) {
    if (ch) return;
    if (sti > 2 || sti < 1 || stj < 1 || stj > n) return;
    if (a[sti][stj] == 1 || check[sti][stj]) return;
    check[sti][stj] = 1;
    if (stj == n) {
        ch = 1;
        return;
    }

    for (int i = 0;i < 4;i++) {
        
        sol(sti+dx[i],stj+dy[i]);
        
        //check[sti][stj] = 0;
    }
}
int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    
    cin >> n;
    for (int i = 1;i <= 2;i++) {
        for (int j = 1;j <= n;j++) {
            char k;
            cin >> k;
            if (k == '#') {
                a[i][j] = 1;
            } else {
                a[i][j] = 0;
            }
        }   
    }
    sol(1,1);
    sol(2,1);

    if (ch) cout << "Yes";
    else cout << "No";

}
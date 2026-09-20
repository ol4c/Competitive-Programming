#include <bits/stdc++.h>
using namespace std;
bool table[1005][1005];
bool e[1005][1005];
void sol(int i, int j) {
    if (!table[i][j]) return;
    e[i][j]=1;
    table[i][j]=0;
    
    //cout << i << " " << j << endl;
    if (table[i][j+1] == 1) {
        
        if (table[i][j+1+1] == 1) table[i+1][j+1] = 0;
        sol(i,j+1);
    } else if (table[i+1][j]) {
        if (table[i+1+1][j] == 1) table[i+1][j-1] = 0;
        sol(i+1,j);
    } else if (table[i][j-1]) {
        //table[i-1][j-1] = 0;
        if (table[i][j-1-1] == 1) table[i-1][j-1] = 0;
        sol(i,j-1);
    } else if (table[i-1][j]) {
        if (table[i-1-1][j] == 1) table[i-1][j+1] = 0;
        //table[i-1][j+1] = 0;
        sol(i-1,j);
    }
}
int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n,m;
    cin >> n >> m;
    for (int i = 1;i <= n;i++) {
        for (int j = 1;j <= m;j++) {
            table[i][j] = 1;
        }
    }
    if (m != 1) table[2][1] = 0;
    
    sol(1,1);
    for (int i = 1;i <= n;i++) {
        for (int j = 1;j <= m;j++) {
            if (e[i][j]) {
                cout << "#";
            } else {
                cout << ".";
            }
        }
        cout << "\n";
    }

}
#include <bits/stdc++.h>
#define int long long
using namespace std;

int table[1005][1005];
int hold[1005][1005];
int dx[] = {0,0,1,-1};
int dy[] = {1,-1,0,0};
signed main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n,m;
    cin >> n>> m;
    for (int i = 1;i <= n;i++) {
        for (int j = 1;j <= m;j++) {
            cin >> table[i][j];
        }
    }
    int d;
    cin >> d;
    for (int k = 1;k <= d;k++) {
        int x,y,b,p;
       
        cin >> x >> y >> b >> p;
        x++;
        y++;
        // shadow
        if (k != 1) {
            for (int i = 1;i <= n;i++) {
                for (int j = 1;j <= m;j++) {
                    if (table[i][j] > 0) hold[i][j] = table[i][j] + 1;
                    else hold[i][j] = (table[i-1][j] > 0 || table[i+1][j] > 0 ||
                                    table[i][j-1] > 0 || table[i][j+1] > 0);
                }
            }
            for (int i = 1;i <= n;i++)
                for (int j = 1;j <= m;j++)
                    table[i][j] = hold[i][j];
        }

        if (b == 1) {
            int jr_1 =  max((long long) 1,y-(p-1));
            int jr_2 =  min((long long) m,y+(p-1));

            int ir_1 =  max((long long) 1,x-(p-1));
            int ir_2 =  min((long long) n,x+(p-1));
            
            for (int j = jr_1;j <= jr_2;j++) {
                if (x-(p-1) < 1 || x-(p-1) > n) break;
                table[x-(p-1)][j] = 0;
            }
            for (int j = jr_1;j <= jr_2;j++) {
                if (x+(p-1) < 1 || x+(p-1) > n) break;
                table[x+(p-1)][j] = 0;
            }
            for (int j = ir_1;j <= ir_2;j++) {
                if (y-(p-1) < 1 || y-(p-1) > m) break;
                table[j][y-(p-1)] = 0;
            }
            for (int j = ir_1;j <= ir_2;j++) {
                if (y+(p-1) < 1 || y+(p-1) > m) break;
                table[j][y+(p-1)] = 0;
            }
        } else if (b == 2) {
            int up_x = max((long long) 1, x-(p-1));
            int down_x = min((long long) n, x+(p-1));
            int jj = y - (p-1);
            int jj2 = y + (p - 1);
            for (int i = x;i >= up_x;i--) {
                if (!(jj < 1 || jj > m || i < 1 || i > n)) {
                    table[i][jj] = 0;
                }
                
                if (!(jj2 < 1 || jj2 > m || i < 1 || i > n)) {
                    table[i][jj2] = 0;
                }
    
                jj++;
                jj2--;
            }
             jj = y - (p-1);
             jj2 = y + (p - 1);
            for (int i = x;i <= down_x;i++) {
                if (!(jj < 1 || jj > m || i < 1 || i > n)) {
                    table[i][jj] = 0;
                }
                
                if (!(jj2 < 1 || jj2 > m || i < 1 || i > n)) {
                    table[i][jj2] = 0;
                }
                jj++;
                jj2--;
            }
        } else {
            int up_x = max((long long) 1, x-(p-1));
            int down_x = min((long long) n, x+(p-1));

            int left_x = max((long long) 1, y-(p-1));
            int right_x = min((long long) m, y+(p-1));

            int jj = y;
            int jj2 = y;
            for (int i = up_x;i <= down_x;i++) {
                if (y < 1 || y > m) break;
                table[i][y] = 0;
            }

            for (int i = left_x;i <= right_x;i++) {
                if (x < 1 || x > n) break;
                table[x][i] = 0;
            }

            for (int i = x;i >= up_x;i--) {
                if (!(jj < 1 || jj > m)) table[i][jj] = 0;
                if (!(jj2 > m || jj2 < 1)) table[i][jj2] = 0;
                
                jj--;
                jj2++;
            }
            jj = y;
            jj2 = y;
            for (int i = x;i <= down_x;i++) {
                if (!(jj < 1 || jj > m)) table[i][jj] = 0;
                if (!(jj2 > m || jj2 < 1)) table[i][jj2] = 0;
                
                jj--;
                jj2++;
            }
        }

    }
    int total = 0;
    for (int i = 1;i <= n;i++) {
        for (int j = 1;j <= m;j++) {
            total = (total%1000000007 + table[i][j]%1000000007) %1000000007;
        }
    }
    cout<< total;
}
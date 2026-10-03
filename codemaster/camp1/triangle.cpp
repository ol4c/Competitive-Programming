#include <bits/stdc++.h>
using namespace std;
int arr[5][100005];
bool ch = 0;
void sol(int sti,int stj) {
    int x = arr[sti][stj];
    if (arr[sti+1][stj-1] == x+1 && arr[sti+1][stj] == x+2 && arr[sti+1][stj+1] == x+3
    && arr[sti+2][stj-2] == x+4 && arr[sti+2][stj-1] == x+5 && arr[sti+2][stj] == x+6 &&
    arr[sti+2][stj+1] == x+7 && arr[sti+2][stj+2] == x+8) {
        ch = 1;
    }
    if(ch) {
        printf("    %d\n",x);
        printf("  %d %d %d\n",x+1,x+2,x+3);
        printf("%d %d %d %d %d",x+4,x+5,x+6,x+7,x+8);
    }
    
    return;
}

void sol2(int sti,int stj) {
    int x = arr[sti][stj];
    if (arr[sti-1][stj-1] == x+3 && arr[sti-1][stj] == x+2 && arr[sti-1][stj+1] == x+1
    && arr[sti-2][stj+2] == x+4 && arr[sti-2][stj+1] == x+5 && arr[sti-2][stj] == x+6 &&
    arr[sti-2][stj-1] == x+7 && arr[sti-2][stj-2] == x+8) {
        ch = 1;
    }
    if (ch) {
        printf("%d %d %d %d %d\n",x+8,x+7,x+6,x+5,x+4);
        printf("  %d %d %d\n",x+3,x+2,x+1);
        printf("    %d\n",x);
    }
    
    return;
}
int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    for (int i = 1;i <= 3;i++) {
        for (int j = 1;j <= n;j++) {
            cin >> arr[i][j];
        }
    }
    for (int i = 3;i <= n-2;i++) {
        sol(1,i);
        if (ch) break;
        sol2(3,i);
        if (ch) break;
    }
}
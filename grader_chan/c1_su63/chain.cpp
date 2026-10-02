#include <bits/stdc++.h>
using namespace std;
char a[100][50000];
int h;
char c;
void t_d(int sti, int stj) {
    int i = sti;
    int j1 = stj;
    int j2 = stj;
    while (i <= h + 1) {
        a[i][j1] = c;
        a[i][j2] = c;
        i++;
        j1--;
        j2++;
    }
    return;
}
void d_t(int sti, int stj) {
    int i = sti;
    int j1 = stj;
    int j2 = stj;
    while (i > h + 1) {
        a[i][j1] = c;
        a[i][j2] = c;
        i--;
        j1--;
        j2++;
    }
    return;
}
int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    string s;
    cin >> s;
    
    cin >> h;
    for (int i = 0;i < s.size();i++) {
        c = s[i];
        t_d(1,(h+1)+i*(2*h-1));
        d_t(2*h+1,(h+1)+i*(2*h-1));
    }
    for (int i = 1;i <=2*h+1;i++) {
        for (int j = 1;j <= 2*s.size()*h - s.size() + 2;j++) {
            if (a[i][j] == '\0') cout << ".";
            else cout << a[i][j];
        }
        cout << endl;
    }
    
}
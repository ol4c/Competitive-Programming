#include <bits/stdc++.h>
using namespace std;
int vert1[100005];
int vert2[100005];
int vert3[100005];
int vert4[100005];
int hor1[100005];
int hor2[100005];
int hor3[100005];
int hor4[100005];
int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n,m;
    cin >> n >> m;
    for (int i = 1;i <= n;i++) {
        int k;
        cin >> k;
        vert1[i] = k;
        if(i == 1) hor1[1] = k;
    }
    for (int i = 2;i <= m;i++) {
        int k;
        cin >> k;
        hor1[i] = k;
    }

    // permu hor2
    hor2[1] = vert1[2];
    for (int i = 2;i <= m;i++) {
        if (i == 2) {
            if (hor1[i] == 1 && vert1[i] == 1) hor2[i] = 0;
            else hor2[i] = 1;
        } else {
            if (hor1[i] == 1 && hor2[i-1] == 1) hor2[i] = 0;
            else hor2[i] = 1;
        }
    }
    // permu vert2
    vert2[1] = hor1[2];
    for (int i = 2;i <= n;i++) {
        if (i == 2) {
            if (hor1[i] == 1 && vert1[i] == 1) vert2[i] = 0;
            else vert2[i] = 1;
        } else {
            if (vert1[i] == 1 && vert2[i-1] == 1) vert2[i] = 0;
            else vert2[i] = 1;
        }
    }
    // permu hor3
    hor3[1] = vert1[3];
    hor3[2] = vert2[3];
    for (int i = 3;i <= m;i++) {
        if (i == 3) {
            if (hor2[i] == 1 && vert2[i] == 1) hor3[i] = 0;
            else hor3[i] = 1;
        } else {
            if (hor2[i] == 1 && hor3[i-1] == 1) hor3[i] = 0;
            else hor3[i] = 1;
        }
    }
    // permu vert3
    vert3[1] = hor1[3];
    vert3[2] = hor2[3];
    for (int i = 3;i <= n;i++) {
        if (i == 3) {
            if (hor2[i] == 1 && vert2[i] == 1) vert3[i] = 0;
            else vert3[i] = 1;
        } else {
            if (vert2[i] == 1 && vert3[i-1] == 1) vert3[i] = 0;
            else vert3[i] = 1;
        }
    }

    // permu vert 4 (ans)
    vert4[1] = hor1[4];
    vert4[2] = hor2[4];
    vert4[3] = hor3[4];
    for (int i = 4;i <= n;i++) {
        if (i == 4) {
            if (hor3[i] == 1 && vert3[i] == 1) vert4[i] = 0;
            else vert4[i] = 1;
        } else {
            if (vert3[i] == 1 && vert4[i-1] == 1) vert4[i] = 0;
            else vert4[i] = 1;
        }
    }
    //permu hor4(ans)
    hor4[1] = vert1[4];
    hor4[2] = vert2[4];
    hor4[3] = vert3[4];
    for (int i = 4;i <= m;i++) {
        if (i == 4) {
            if (hor3[i] == 1 && vert3[i] == 1) hor4[i] = 0;
            else hor4[i] = 1;
        } else {
            if (hor3[i] == 1 && hor4[i-1] == 1) hor4[i] = 0;
            else hor4[i] = 1;
        }
    }
    int q;
    cin >> q;
    while (q--) {
        int x,y;
        cin >> x >> y;
        if (x <= 4) {
            if (x == 1) cout << hor1[y] << "\n";
            else if (x == 2) cout << hor2[y] << "\n";
            else if (x == 3) cout << hor3[y] << "\n";
            else if (x == 4) cout << hor4[y] << "\n";
        } else if (y <= 4) {
            if (y == 1) cout << vert1[x] << "\n";
            else if (y == 2) cout << vert2[x] << "\n";
            else if (y == 3) cout << vert3[x] << "\n";
            else if (y == 4) cout << vert4[x] << "\n";
        } else {
            int d_x = x - (min(x,y) - 4);
            int d_y = y - (min(x,y) - 4);
            if (d_x == 4) {
                cout << hor4[d_y] << "\n";
            } else {
                cout << vert4[d_x] << "\n";
            }
        }
    }
}
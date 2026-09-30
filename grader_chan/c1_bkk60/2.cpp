#include <bits/stdc++.h>
using namespace std;
char arr[500][500];
int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;
    char c = 'A' + n - 1;
    for (int i = 1;i <= (2*n - 1) / 2;i++) {
        for (int j = 1;j <= 2*n - 1;j++) {
            if (j == i || j == 2*n - 1 - (i - 1)) {
                //cout << i << " " << j << endl;
                arr[i][j] = c;
            }
        }   
        c--;
    }
    

    for (int i = 1;i <= (2*n - 1) / 2;i++) {
        for (int j = 1;j <= 2*n - 1;j++) {
            if (j == i || j == 2*n - 1 - (i - 1)) {
                cout << arr[i][j] << "";
            } else cout << " ";
        }   
        cout << " ";
        for (int j = 1;j <= 2*n - 1;j++) {
            if (j == i || j == 2*n - 1 - (i - 1)) {
                cout <<  "*";
            } else cout << " ";
        }  
        cout << endl;
    }

    for (int i = 1;i <= (2*n - 1);i++) {
        if (i == n) cout << "A";
        else cout << " ";
        
        
    }
    cout << " ";
        for (int j = 1;j <= (2*n - 1);j++) {
            if (j == n) cout << "*";
            else cout << " ";

        }
    cout << endl;
    
    for (int i = (2*n - 1) / 2;i >= 1;i--) {
        for (int j = 1;j <= 2*n - 1;j++) {
            if (j == i || j == 2*n - 1 - (i - 1)) {
                cout << arr[i][j] << "";
            } else cout << " ";
        }   
        cout << " ";
        for (int j = 1;j <= 2*n - 1;j++) {
            if (j == i || j == 2*n - 1 - (i - 1)) {
                cout <<  "*";
            } else cout << " ";
        }
        cout << endl;
    }
}
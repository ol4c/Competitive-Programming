#include <bits/stdc++.h>
using namespace std;
char arr[5000][5000];
char temp[5000][5000];

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int r,c;
    cin >> r >> c;
    for (int i = 1;i <= r;i++) {
        for (int j = 1;j <= c;j++) {
            char cr;
            cin >> cr;
            arr[i][j] = cr;
        }
    }
    int ra = r,ca = c;
    short q;
    cin >> q;
    while (q--) {
        char cr;
        cin >> cr;
        if (cr == 'R') {
            for (int i = 1;i <= ra;i++) {
                for (int j = 1;j <= ca;j++) {
                    temp[j][ra+1-i] = arr[i][j];
                }   
            }
            swap(ra,ca);
            memset(arr,'\0',sizeof(arr));
            for (int i = 1;i <= ra;i++) {
                for (int j = 1;j <= ca;j++) {
                    arr[i][j] = temp[i][j];
                }   
            }
            memset(temp,'\0',sizeof(temp));

        } else if (cr == 'H') {
            for (int i = 1;i <= ra;i++) {
                for (int j = 1;j <= ca;j++) {
                    temp[i][ca+1-j] = arr[i][j];
                }   
            }
            memset(arr,'\0',sizeof(arr));
            for (int i = 1;i <= ra;i++) {
                for (int j = 1;j <= ca;j++) {
                    arr[i][j] = temp[i][j];
                }   
            }
            memset(temp,'\0',sizeof(temp));
        } else if (cr == 'V') {
            for (int i = 1;i <= ra;i++) {
                for (int j = 1;j <= ca;j++) {
                    temp[ra+1-i][j] = arr[i][j];
                }   
            }
            memset(arr,'\0',sizeof(arr));
            for (int i = 1;i <= ra;i++) {
                for (int j = 1;j <= ca;j++) {
                    arr[i][j] = temp[i][j];
                }   
            }
            memset(temp,'\0',sizeof(temp));
        }
    }
    cout << ra << " " << ca << "\n";
    for (int i = 1;i <= ra;i++) {
        for (int j = 1;j <= ca;j++) {
            cout << arr[i][j];
        }   
        cout << "\n";
    }
}

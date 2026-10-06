#include <bits/stdc++.h>
using namespace std;
char table[1005][1005];
int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    string s;
    cin >> s;
    int k;
    cin >> k;
    string first = "";
    string last = "";
    for (auto c : s) {
        if (c == toupper(c)) {
            if (last == "") last += c;
            else last += tolower(c); 
        } else {
            if (first == "") first += toupper(c);
            else first += c;
        }
    }
    
    string full = first + last;
    int sz = full.length();
    int dimension;
    if (floor(sqrt(sz)) * floor(sqrt(sz)) == sz ) {
        dimension = floor(sqrt(sz));
    } else dimension = ceil(sqrt(sz));

    for (int j = 2*dimension;j >= 2*dimension - (dimension-1);j--) {
        for (int i = 2*dimension + 1 -j;i <= dimension;i++) {
            table[i][j] = '#';
        }
    }
    for (int j = dimension+1;j <= 2*dimension;j++) {
        for (int i = 3*dimension + (j - (dimension+1))*-1;i > 2*dimension;i--) {
            table[i][j] = '#';
        }
    }

    for (int j = dimension;j >= 1;j--) {
        for (int i = dimension + 1;i <= 2*dimension + (j - dimension);i++) {
            table[i][j] = '#';
        }
    }

    for (int j = 2*dimension + 1;j <= 3*dimension;j++) {
        for (int i = dimension + 1 + (j-(2*dimension+1));i <= 2*dimension;i++) {
            //cout << j << " " << i <<endl;
            table[i][j] = '#';
        }
    }
    for (int i = dimension+1;i <= dimension+dimension;i++) {
        for (int j = dimension+1;j <= dimension+dimension;j++) {
            int idx = (i - (dimension+1))*dimension + (j - dimension+1);
            if (idx <= sz+1) {
                table[i][j] = full[idx-2];
            } else table[i][j] = '=';
            
        }
    }

    if (k == 1) {
        for (int i = 1;i <= dimension * 3;i++) {
            for (int j = 1;j <= dimension * 3;j++) {
                if (table[i][j] == '\0') cout << ".";
                else cout << table[i][j] << "";
                
            }
            cout << "\n";
        }
    } else {
        cout << full;
    }
}
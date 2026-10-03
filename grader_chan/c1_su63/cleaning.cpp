#include <bits/stdc++.h>
using namespace std;
int table[505][505];
int sum = 0;
int n;
int dx[] = {0,0,1,-1};
int dy[] = {1,-1,0,0};
void sol(int sti, int stj) {
    if (sti < 1 || stj < 1 || sti > n || stj > n) {
        return;
    }

    int s = (table[sti][stj] * 4) + 2*min(1,table[sti][stj]);
    for (int i = 0;i < 4;i++) {
        if (sti+dx[i] < 1 || sti+dx[i] > n || stj+dy[i] < 1 || stj+dy[i] > n) {
            continue;
        }
        s -= min(table[sti+dx[i]][stj+dy[i]],table[sti][stj]);
    }

    sum += s;
}
int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    cin >> n;

    string s;
    cin >> s;
    
    int ii = 1;
    int jj = 1;

    string temp_num = "";
    bool check_num = 0;

    for (int i = 1;i < s.size() - 1;i++) {
        if (!(s[i] == '[' || s[i] == ']' || s[i] == ',')) {
            if (check_num == 0) {
                check_num = 1;
                temp_num += s[i];
            } else {
                temp_num += s[i];
            }
        } else {
            if (check_num == 1) {
                table[ii][jj] = stoi(temp_num);
                jj++;
                if (jj > n) {
                    jj = 1;
                    ii++;
                }
                temp_num = " ";
                check_num = 0;
            }
        }
    }

    for (int i = 1;i <= n;i++) {
        for (int j = 1;j <= n;j++) {
            //cout << table[i][j] << " ";
            sol(i,j);
        }
        //cout << endl;
    }
    cout << sum;
}
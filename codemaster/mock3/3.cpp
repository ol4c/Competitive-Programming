#include <bits/stdc++.h>
#define int long long

using namespace std;

vector<string> table;
signed main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int r,c,q;
    int cnt_clear = 0;
    
    cin >> r >> c >> q;
    int cnt_suc = q;
    for (int i = 1;i <= r;i++) {
        string s = "";
        for (int j = 1;j <= c;j++) {
            s+="0";
        }
        table.push_back(s);
    }
    while (q--) {
        int si,li;
        cin >> si >> li;
        si--;
        li--;
        bool check = 0;
        int r_place = r-1;
        for (int i = 0;i < r;i++) {
            for (int j = si;j <= li+si;j++) {
                if (table[i][j] == '1') {
                    check = 1;
                    r_place = i-1;
                }
                if (check) break;
            }
            if (check) break;
        }

        if (r_place >= 0) {
            for (int j = si;j <= li+si;j++) {
                table[r_place][j] = '1';
            }
            
           
                bool check2 = 1;
                for (int i = 0;i < c;i++) {
                    
                    if (table[r_place][i] == '0') {check2 = 0;break;}
                    //if (check2) break;
                }
                if (check2) {
                    table.erase(table.begin() + r_place);
                    string s = "";
                    for (int j = 1;j <= c;j++) {
                        s+="0";
                    }
                    table.insert(table.begin(),s);
                    cnt_clear++;
                }
                //for (auto i : table) cout << i << "\n";
                //cout << endl;

            
        } else {
            cnt_suc--;
            continue;
        }
    }
    cout << cnt_suc << " " << cnt_clear << "\n";
    for (auto i : table) cout << i << "\n";
}
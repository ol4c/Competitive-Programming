#include <bits/stdc++.h>
using namespace std;

int table[105][105];
int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    int n;
    cin >> n;
    int gay = 0;
    int sti, stj;
    bool ch = 0;
    for (int i = 1;i <=10;i++) {
        for (int j = 1;j <= 10;j++) {
            gay++;
            if (n == gay) {
                sti = i;
                stj = j;
                ch = 1;
                break;
            }
        }
        if (ch) break;
    }

    string s;
    cin >> s;

    ch = 1;
    vector<string> moves;
    string ss;
    for (auto &x : s) {
        if (x != '4') {
            ss += x;
        } else if (x == '4') {
            moves.push_back(ss);
            ss = "";
        }
    }
    moves.push_back(ss);
    
    for (auto &x : moves) {
        int ni = sti;
        int nj = stj;
        if (x == "T") {
            ni += -1;
        } else if (x == "U") {
            ni += 1;
        } else if (x == "L") {
            nj += -1;
        } else if (x == "R") {
            nj += 1;
        } else if (x == "LT") {
            ni += -1;
            nj += -1;
        } else if (x == "RT") {
            ni += -1;
            nj += 1;
        } else if (x == "LU") {
            ni += 1;
            nj += -1;
        } else if (x == "RU") {
            ni += 1;
            nj += 1;
        }
        if (ni < 1 || ni > 10 || nj < 1 || nj > 10) continue;
        sti = ni;
        stj = nj;
    }

    int fin = ((sti-1)*10) + stj;
    cout << fin;
    return 0;
}
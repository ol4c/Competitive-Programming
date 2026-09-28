#include <bits/stdc++.h>
using namespace std;
vector<string> rs;
int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    int n,k;
    cin >> n >> k;
    for (int i = 1;i <= k;i++) {
        for (int j = 1;j <= n+1;j++) {
            string s = "";
            if (j == 1) {
                for (int k = 1;k <= 2*n +1;k++) {
                    if (k == 2*n +1) s+="*";
                    else s+="* ";
                }
            } else {
                for (int k = 1;k <= 2*n;k++) {
                    if (k == 2) s+="* ";
                    else if (k == 2*n) s+="*";
                    else s+="  ";
                }
            }
            rs.push_back(s);
        }
    }
    for (string s : rs) cout << s << "\n";
}
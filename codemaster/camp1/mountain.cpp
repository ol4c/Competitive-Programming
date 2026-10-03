#include <bits/stdc++.h>
using namespace std;
deque<string> vec;
int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    for (int i = 1;i <= n;i++) {
        string s = "";
        for (int k = 1;k <= n;k++) {
            
            if (k == 1) for (int j = 1;j <= i-1;j++) s+= " ";
            if (!(i == 1 && k > 1)) s+=  "*";
            
            for (int j = 1;j <= 2*(n-i) - 1;j++) s+= " ";
            
            if(i <= n) {
                //=
                if(i != n) s+= "*";
                for (int j = 1;j <= 2*i-3;j++) s+= " ";
            }
            
        }
        vec.push_front(s);
        
    }

    for (auto s : vec) cout << s << "\n";
}
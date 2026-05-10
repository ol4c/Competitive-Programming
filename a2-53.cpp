#include <bits/stdc++.h>
using namespace std;

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    string s;
    cin >> s;

    int sz = s.length();
    
    for (int i = 0;i < sz ;i++) {
        char ch = s[sz];

        int asc = ch + 'a';
        cout << asc << endl;
    }
}
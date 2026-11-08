#include <bits/stdc++.h>
using namespace std;
map<string,int> mp;

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    while (1) {
        string a;
        cin >> a;
        if (a == "!") {
            cout << "!\n";
            break;
        }
        if (a == "=") {
            string b,c;
            cin >> b >> c;
            mp[b] = stoi(c);
        } else if (a == "#") {
            string b;
            cin >> b;
            cout << mp[b] << "\n";
        } else if (a == "+") {
            string b,c;
            cin >> b >> c;
            mp[b] += mp[c];
        } else if (a == "-") {
            string b,c;
            cin >> b >> c;
            mp[b] -= mp[c];
        } else if (a == "*") {
            string b,c;
            cin >> b >> c;
            mp[b] *= mp[c];
        } else if (a == "/") {
            string b,c;
            cin >> b >> c;
            mp[b] /= mp[c];
        }
    }
    return 0;
}
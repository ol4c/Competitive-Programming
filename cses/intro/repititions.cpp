#include <bits/stdc++.h>;
using namespace std;

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    string s;
    cin >> s;
    int sum = 1;
    int mx = 1;
    char prev;
    for (int i = 0;i < s.length();i++) {
        if (i == 0) {
            prev = s[i];
        }
        else {
            if (s[i] == prev) {
                sum++;
            } else {
                sum = 1;
                prev = s[i];
            }
        }

        mx = max(mx,sum);
    }
    cout << mx;
}
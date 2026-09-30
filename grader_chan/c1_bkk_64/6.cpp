#include <bits/stdc++.h>
using namespace std;

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    string s;
    cin >> s;
    int ch_digit = s[12] - '0';
    int s1 = 0; int s2 = 0;
    for(int i = 12;i >= 0;i--) {
        if(i%2 == 1) s1+= s[i] - '0';
        else s2 += s[i] - '0';
    }
    s1 *= 3;
    s2-= ch_digit;
    //cout << s1 << " " << s2 << " " << ch_digit << endl;
    if((s1+s2+ch_digit)%10 == 0) cout << "YES";
    else cout << "NO";
}
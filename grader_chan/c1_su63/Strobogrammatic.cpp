#include <bits/stdc++.h>
#define int long long
using namespace std;
string a,b;
int cnt;
vector<pair<string,string>> vec = {{"0","0"},{"1","1"},{"8","8"},{"6","9"},{"9","6"}};
void sol(string s, int len) {
    if (s.length() == len) {
        if (len > 1 && s[0] == '0') return;
        int sum = stoll(s);
        if (sum >= stoll(a) && sum <= stoll(b)) cnt++;
        return;
    } 

    if (s.length() == 0 && len % 2 != 0) {
        sol("1",len);
        sol("0",len);
        sol("8",len);
        return;
    }

    for (auto a : vec) {
        sol(a.first + s + a.second,len);
    }
}
signed main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> a >> b;
    int small_len = a.length();
    int large_len = b.length();

    for (int i = small_len;i <= large_len;i++) {
        sol("",i);
    }
    cout << cnt;
}
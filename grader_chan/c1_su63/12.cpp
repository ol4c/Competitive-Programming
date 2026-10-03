#include <bits/stdc++.h>
using namespace std;

int n;
int nig[10];
int a[10];
int used[10];
int mx = -2e9;
string base2(int ni) {
    string s = "";
    while (ni > 0) {
        s = to_string(ni % 2) + s;
        ni /= 2;
    }
    //cout  << " " << s << endl;
    return s;
}

int base10 (string s) {
    int sz = s.length();
    int sum = 0;
    for (int i = sz-1;i >= 0;i--) {
        sum += pow(2,i) * (s[sz-i-1] - '0');
    }
    return sum;
}

void solve(int now) {
    if (now == n+1) {
        vector<string> s;
        for (int i = 1;i <= n;i++) {

            s.push_back(to_string(nig[a[i]]));

        }
        string bin = "";
        for (auto c : s) {
            bin += base2(stoi(c));
            //cout << c << " " << base2(c - '0') << endl;
        }
        //cout << bin << endl;
        //cout << stoi(s) << " ";
        mx = max(mx,(base10(bin)));
        return;
    } 

    for (int i = 1;i <= n;i++) {
        if (used[i]) continue;
        a[now] = i;
        used[i] = 1;
        solve(now+1);
        used[i] = 0;
    }
}
int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    cin >> n;
    int nigga = n;
    string ans = "";
    int i = 1;
    while (nigga--) {
        int k;
        cin >> k;
        nig[i] = k;
        i++;
    }
    solve(1);
    cout << mx;
    
}


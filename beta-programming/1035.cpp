#include <bits/stdc++.h>
#define int long long
using namespace std;

int prime[10000005];
vector<int> p;
vector<int> ans;
signed main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    for (int i = 3;i <= n;i+=2) {
        if (prime[i] == 0) {
            for (int j = i;j <= n;j+=i) {
                if (j == i) continue;
                prime[j] = 1;
            }
        }   
    }

    for (int i = 2;i <= n;i++) {
        if (i == 2) {
            p.push_back(i);
            continue;
        } else {
            if (prime[i] == 0 && i %2 != 0) {
                p.push_back(i);
            }
        }
    }
    for (auto &x : p) {
        string s = to_string(x);
        if (s.size() == 1) {
            ans.push_back(x);
        } else {
            string s2 = s;
            reverse(s.begin(),s.end());
            if (s2 == s) {
                ans.push_back(x);
            }
        }
    }
    cout << "vector<int> ans = {";
    for (auto &x : ans) cout << x << ", ";
    cout << "};";
    return 0;
}
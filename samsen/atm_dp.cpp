#include <bits/stdc++.h>
using namespace std;

map<int,int,greater<int>> mp;
int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    string s;
    int sum;
    cin >> s;
    cin >> sum;
    vector<int> coins;
    vector<int> dp(sum+1,2e9);
    vector<int> coin_used(sum+1,2e9);
    bool ch = 0;
    string a;
    for (auto &x : s) {
        if (x != '0' && ch) {
            coins.push_back(stoi(a));
            a = "";
            a += x;
            continue;
        }
        if (x == '0' && !ch) {
            a += x;
            ch = 1;
        } else {
            a+=x;
        } 
    }
    coins.push_back(stoi(a));
    dp[0] = 0;
    for (int i = 1;i <= sum;i++) {
        for (auto c : coins) {
            if (i - c >= 0) {
                if (dp[i-c] + 1 <= dp[i]) {
                    dp[i] = dp[i-c] + 1;
                    coin_used[i] = c;
                }
            }
        }
    }
    int p = sum;
    while (p > 0) {
        mp[coin_used[p]]++;
        p = p-coin_used[p];
    }
    for (auto &x : mp) {
        cout << "B" << x.first << ":\t" << x.second << "\n";
    }
}
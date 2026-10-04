#include <bits/stdc++.h>
#define int long long

using namespace std;

stack<int> stk;
signed main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    for (int i = 1;i <= n;i++) {
        char c;
        cin >> c;
        if (stk.empty()) stk.push(c);
        else if (stk.top() == c) stk.pop();
        else stk.push(c);
    }
    if (stk.empty()) cout << "EMPTY";
    else {
        string s = "";
        while (!stk.empty()) {
            char kuy = stk.top();
            s = kuy + s;
            stk.pop();
        }
        cout << s;
    }
}
#include <bits/stdc++.h>
#define int long long
using namespace std;

string opr[30];
bool ch;
int target;

void sol(int now) {
    if (ch) return;
    if (now == 14) {
        stack<string> stk;
        for (int i = 1;i <= 13;i++) {
            
            string k = opr[i];
            
            if (k == "+" || k == "/" || k == "*" || k == "-") {
                double rs;
                double s2 = stoi(stk.top());
                stk.pop();
                double s1 = stoi(stk.top());
                stk.pop();
                if (k == "+") rs = s1 + s2;
                if (k == "-") rs = s1 - s2;
                if (k == "*") rs = s1 * s2;
                stk.push(to_string((int) rs));
            } else {
                stk.push(k);
            }
        }
        if (stoi(stk.top()) == target) ch = 1;
        return;
    }

    opr[now] = "+";
    sol(now+1);
    opr[now] = "-";
    sol(now+1);
    opr[now] = "*";
    sol(now+1);
}
signed main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    for (int i = 1;i <= 7;i++) {
        cin >> opr[i];
    }

    cin >> target;
    sol(8);
    if (ch) cout << "Yes";
    else cout << "No";
}
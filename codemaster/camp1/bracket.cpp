#include <bits/stdc++.h>
using namespace std;
struct nigger {
    char p;
    int idx;
};
stack<nigger> stk;
long long sum = 0;
int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;
    for (int i = 1;i <= n;i++) {
        nigger k;
        cin >> k.p;
        k.idx = i;

        if (stk.empty()) {
            stk.push(k);
        } else {
            if (stk.top().p == '(' && k.p == ')') {
                sum += i - stk.top().idx;
                stk.pop();
            } else {
                stk.push(k);
            }
        }
    }

    cout << sum;
}
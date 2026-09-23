#include <bits/stdc++.h>
using namespace std;

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    if (n < 4) {
        if (n == 1) cout << 1;
        else cout << "NO SOLUTION";
    }
    else {
        deque<int> dq;
        dq.push_back(3); dq.push_back(1); dq.push_back(4); dq.push_back(2);
        for (int i = 5;i <= n;i++) {
            if (i % 2 == 1) dq.push_front(i);
            else dq.push_back(i);
        }
        for (int i : dq) {
            cout << i << " ";
        }
    }
}
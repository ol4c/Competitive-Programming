#include <bits/stdc++.h>
using namespace std;

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    priority_queue<int> pq;
    int q;
    cin >> q;
    while (q--) {
        char c; int n;
        cin >> c;
        if (c == 'P') {
            cin >> n;
            pq.push(n);
        }
        else {
            if (!pq.empty()) {
                cout << pq.top() << "\n";

                pq.pop();
            } else cout << "-1\n";
        }
    }
}
#include <bits/stdc++.h>
using namespace std;
deque<string> dq;
vector<string> ord;

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    int n,k;
    cin >> n >> k;
    while (n--) {
        int opr;
        cin >> opr;
        if (opr == 1) {
            if (!dq.empty()) {
                ord.push_back(dq.front());
                dq.pop_front();
            }
        } else {
            string s;
            cin >> s;
            if (dq.size() != k) dq.push_back(s);
        }
    }

    for (string s : ord) cout << s << " ";
}
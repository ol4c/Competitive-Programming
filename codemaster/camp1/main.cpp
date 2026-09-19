#include <bits/stdc++.h>
using namespace std;

queue<int> q;
int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    while (n--) {
        string s;
        cin >> s;
        if (s == "push") {
            int ik;
            cin >> ik;
            q.push(ik);
        } else {
            if (q.empty()) cout << "null\n";
            else {
                cout << q.front() <<endl;
                q.pop();
            }
        }
    }
}
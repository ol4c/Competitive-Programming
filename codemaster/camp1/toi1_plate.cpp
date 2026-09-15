#include <bits/stdc++.h>
using namespace std;

int idx[10005];
vector<int> q;

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int c,s;
    cin >> c >> s;

    for (int i = 0;i < s;i++) {
        int ci,id;
        cin >> ci >> id;
        idx[id] = ci;
    }

    while (1) {
        char opr;
        cin >> opr;
        if (opr == 'X') {
            cout << "0\n";
            break;
        } else if (opr == 'E') {
            int id ;
            cin >> id;
            if (q.empty()) {
                q.push_back(id);
            } else {
                bool ch = 0;
                for (int i = q.size()-1;i >= 0;i--) {
                    if (idx[q[i]] == idx[id]) {
                        if (i == q.size()-1) q.push_back(id);
                        else {
                            q.insert(q.begin()+i+1,id);
                        }
                        ch = 1;
                        break;
                    }
                }
                if (!ch) q.push_back(id);
            }
        } else {
            if (q.empty()) cout << "empty\n";
            else {
                cout << q[0] << "\n";
                q.erase(q.begin());
            }
        } 
    }
}
#include <bits/stdc++.h>
using namespace std;
vector<set<int>> vec(1005);

void uni(int a, int b) {
    set<int> temp;
    for (auto i : vec[a]) {
        temp.insert(i);
    }
    for (auto i : vec[b]) {
        temp.insert(i);
    }
    if (temp.empty()) cout << "Empty\n";
    else {
        for (auto i : temp) cout << i << " ";
        cout << "\n";
    }
}

void inter(int a,int b) {
    set<int> temp;
    for (auto i : vec[a]) {
        if (vec[b].find(i) != vec[b].end()) {
            temp.insert(i);
        }
    }
    if (temp.empty()) cout << "Empty\n";
    else {
        for (auto i : temp) cout << i << " ";
        cout << "\n";
    }
}

void sub(int a, int b) {
    set<int> temp;
    for (auto i : vec[a]) {
        if (vec[b].find(i) == vec[b].end()) {
            temp.insert(i);
        }
    }
    if (temp.empty()) cout << "Empty\n";
    else {
        for (auto i : temp) cout << i << " ";
        cout << "\n";
    }

}
int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n,q;
    cin >> n >> q;
    for (int i =1;i <= n;i++) {
        int m;
        cin >> m;
        while (m--) {
            int k;
            cin >> k;
            vec[i].insert(k);
        }
    }
    while (q--) {
        string se;
        cin >> se;
        string f,s;
        char opr;
        bool ch = 0;
        for (auto c : se) {
            if (isdigit(c)) {
                if (ch == 0) f+=c;
                else s+=c;
            } else {
                opr = c;
                ch = 1;
            }
        }
        if (opr == 'U') {
            uni(stoi(f),stoi(s));
        } else if (opr == '|') inter(stoi(f),stoi(s));
        else sub(stoi(f),stoi(s));
    }
}
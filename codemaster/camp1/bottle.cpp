#include <bits/stdc++.h>
using namespace std;
int n;
deque<int> stk;

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> n;

    for (int i = 1;i <= n;i++) {
        int k;
        cin >> k;
        if (stk.empty()) stk.push_back(k);
        else {
            if (stk.back() % 2 == k % 2) {
                stk.push_back(k);
            } else {
                stk.pop_back();
            }
        }        
    }

    int sz = stk.size();
    for (int i = 1;i <= sz;i++) {
        cout << stk.front() << " ";
        stk.pop_front();
    }
    

}
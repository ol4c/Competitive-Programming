#include <bits/stdc++.h>
using namespace std;
int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    stack<pair<int,int>> stk;
    int n;
    cin >> n;
    stk.push({0,0});
    while (n--) {
        string s;
        cin >> s;
        if (s == "U") {
            stk.push({stk.top().first,stk.top().second+1});
        } else if (s == "L") {
            stk.push({stk.top().first-1,stk.top().second});
        } else if (s == "R") {
            stk.push({stk.top().first+1,stk.top().second});
        } else if (s == "D") {
            stk.push({stk.top().first,stk.top().second-1});
        } else if (s == "UNDO") {
            if (stk.size() > 1) stk.pop();
            
        }
    }
    cout << stk.top().first << " " << stk.top().second;
}

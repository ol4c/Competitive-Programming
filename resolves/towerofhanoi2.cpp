#include <bits/stdc++.h>
using namespace std;

vector<pair<int,int>> vec;
void sol(int n,int st,int des, int mid) {
    if (n == 1) {
        vec.push_back({st,des});
        return;
    }
    sol(n-1,st,mid,des);
    vec.push_back({st,des});
    sol(n-1,mid,des,st);
    return;
}
int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;
    //st 1, mid 2, final 3
    sol(n,1,3,2);
    cout << vec.size() << "\n";
    for (auto &x : vec) {
        cout << x.first << " " << x.second << "\n";
    }
}
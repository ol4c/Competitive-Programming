#include <bits/stdc++.h>
using namespace std;

struct A{
    int id;
    int speed;
    int lane;
    bool operator<(const A &o) const {
        if (o.speed != speed) return speed > o.speed;
        return lane < o.lane;
    }
};
int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    int n,m;
    cin >> n >> m;
    vector<queue<int>> vec(m+1);
    vector<vector<A>> v(n+5);
    for (int i = 1;i <= n;i++) {
        int a,b,c;
        cin >> a >> b >> c;
        A aa;
        aa.id = a;
        aa.speed = c;
        aa.lane = b;
        v[vec[b].size() + 1].push_back(aa);
        vec[b].push(a);
    }
    for (int i = 1;;i++) {
        if (v[i].size() == 0) break;
        sort(v[i].begin(),v[i].end());
        cout << v[i][0].id << "\n";
    }
    return 0;
}
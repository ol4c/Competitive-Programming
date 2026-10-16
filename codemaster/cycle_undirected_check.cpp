#include <bits/stdc++.h>
using namespace std;
vector<int> adj[100005];
vector<int> color(100005);
bool ch = 0;
void sol(int now,int p) {
    if(ch)return;
    for (auto &x : adj[now]) {
        if (color[x] == 0) {
            color[x] = 1;
            sol(x,now);
        }
        if (color[x] == 1 && p != x) {
            ch = 1;
            break;
        }
    }
    color[now] = 2;
}
int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n,e;
    cin >> n >> e;
    for (int i = 1;i <= e;i++) {
        int a,b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    for (int i = 0;i < n;i++) {
        if(color[i] == 0) {
            color[i] = 1;
            sol(i,-1);
        }
    }
    
    cout << ch;
    return 0;
}
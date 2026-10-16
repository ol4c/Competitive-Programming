#include <bits/stdc++.h>
using namespace std;
vector<int> adj[100005];
int ch = 1;
int color[100005];
void sol(int now) {
    if (!ch) return;

    for (auto &x : adj[now]) {
        if (color[x] == 0) {
            color[x] = color[now] % 2 + 1;
            sol(x);
        }

        if (color[x] == color[now]) {
            ch =0;
            break;
        }
    }
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
        if (!ch) break;
        if (color[i] != 0) continue;
        color[i] = 1;
        sol(i);
    }
    
    if (ch) cout << "Gay not found!";
    else cout << "Gay found!";


    return 0;
}
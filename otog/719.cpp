#include <bits/stdc++.h>
using namespace std;

vector<pair<int,int>> vec;
int dist[100005], vs[100005];
int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    for (int i = 0;i < n;i++) {
        int x,y;
        cin >> x >> y;
        vec.push_back({x,y});
        dist[i] = -1e9;
    }
    priority_queue<pair<int,int>> pq;
    dist[0] = 0;
    pq.push({0,0});
    int total = 0;
    while (!pq.empty()) {
        auto u = pq.top();
        pq.pop();

        if (vs[u.second]) continue;
        vs[u.second] = 1;
        total += u.first;
        for (int i = 0;i < n;i++) {
            pair<int,int> p = {max(abs(vec[i].first - vec[u.second].first),abs(vec[i].second - vec[u.second].second)),i};
            if (vs[p.second]) continue;
            if (p.first <= dist[p.second]) continue;
            dist[p.second] = p.first;
            pq.push(p);
        }
    }
    cout << total;
    return 0;
}
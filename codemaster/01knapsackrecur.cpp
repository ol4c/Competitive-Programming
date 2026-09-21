#include <bits/stdc++.h>
using namespace std;

vector<pair<int,int>> dat;

int n, max_w, max_v = INT_MIN;
int a[105];
void sol(int now) {
    if (now == n+1) {
        int sum = 0;
        int we = 0;
        for (int i = 1;i <= n;i++) {
            if(a[i] == 1) {
                sum += dat[i].second;
                we += dat[i].first;
            } 
        }

        if (we <= max_w) max_v = max(max_v,sum);
        
        return;
    }
    a[now] = 0;
    sol(now+1);
    a[now] = 1;
    sol(now+1);
}
int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    dat.push_back({-67,-67});
    cin >> n >> max_w;

    for (int i = 1;i <= n;i++) {
        int w,v;
        cin >> w >> v;
        dat.push_back(make_pair(w,v));
    }
    sol(1);
    cout << max_v;
}

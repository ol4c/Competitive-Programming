#include <bits/stdc++.h>
using namespace std;

deque<int> vec;
int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n,m;
    cin >> n >> m;
    for (int i = 1;i <= n;i++) {
        int k;
        cin >> k;
        vec.push_back(k);
    }
    sort(vec.begin(),vec.end(),greater<int>());
    int cnt = 0;
    while (vec.size() >= 1) {
        int a,b;
        if (vec.size() == 1) {
            cnt++;
            break;
        }
        a = vec.front();
        b = vec.back();
        if (a+b <= m) {
            cnt++;
            vec.pop_front();
            vec.pop_back();
        } else {
            cnt++;
            vec.pop_front();
        }
    }
    cout << cnt;

    return 0;
}
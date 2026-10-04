#include <bits/stdc++.h>
using namespace std;
map<int,int> mp_R;
map<int,int> mp_B;

int cnt;

signed main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    while (n--) {
        int k;
        char c;
        cin >> k >> c;
        if (c == 'R') {
            mp_R[k]++;
            //mp_B[k] = 0;
        } else {
            mp_B[k]++;
            //mp_R[k] = 0;
        }
    }

    for (auto &i : mp_R) {
        int diff = min(i.second,mp_B[i.first]);
        //cout << i.first << ' ' << i.second << " " << mp_B[i.first]  << endl;
        i.second -= diff;
        mp_B[i.first] -= diff;
        cnt += diff;
    }
    int left = 0;
    for (auto &i : mp_R) {
        left += i.second;
    }

    for (auto &i : mp_B) {
        left += i.second;
    }

    cout << cnt << " " << left;
}
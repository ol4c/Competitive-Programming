#include <bits/stdc++.h>
#define int long long
using namespace std;

struct S{
    int t;
    int b;
    int h;
    int i;
    bool operator<(const S&o) {
        if (t != o.t) return t < o.t;
        if (b != o.b) return b > o.b;
        return i < o.i ;
    }
};

struct Group {
    int h;
    int c;
};
signed main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    int q = n;
    int idx = 1;
    vector<S> stu;
    while (q--) {
        S s;
        cin >> s.t >> s.b >> s.h;
        s.i = idx;
        idx++;
        stu.push_back(s);
    }
    sort(stu.begin(),stu.end());
    vector<Group> st;
    int cnt = 0;
    for (int i = 0; i < n; i++) {
        int h = stu[i].h;
        while (!st.empty() && st.back().h < h) {
            cnt += st.back().c;
            st.pop_back();
        }
        if (st.empty()) {
            st.push_back({h, 1});
        }
        else if (st.back().h == h) {
            int sesame = st.back().c;
            cnt += sesame;
            st.pop_back();
            if (!st.empty()) {
                cnt++;
            }
            st.push_back({h, sesame + 1});
        }
        else {
            cnt++;
            st.push_back({h, 1});
        }
    }
    cout << cnt << "\n";
}
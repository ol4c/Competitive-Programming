#include <bits/stdc++.h>
using namespace std;
int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    for (int ii = 1;ii <= 5;ii++) {
        int n;
        cin >> n;
        vector<pair<int,int>> vec1;
        vector<pair<int,int>> vec2;
        for (int i = 1;i <= (n-1);i++) {
            int a,b;
            cin >> a >> b;
            if (a < b) swap(a,b);
            vec1.push_back({a,b});
        }
        for (int i = 1;i <= (n-1);i++) {
            int a,b;
            cin >> a >> b;
            if (a < b) swap(a,b);
            vec2.push_back({a,b});
        }
        sort(vec1.begin(),vec1.end());
        sort(vec2.begin(),vec2.end());
        if (vec1 == vec2) cout << "Y";
        else cout << "N";
    }

    return 0;
}
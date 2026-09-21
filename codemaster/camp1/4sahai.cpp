#include <bits/stdc++.h>
using namespace std;
int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;
    vector<int> vec;
    for (int i = 0;i < n;i++) {
        int k;
        cin >> k;
        vec.push_back(k);
    }
    sort(vec.begin(),vec.end(),greater<int>());
    int price = 0;
    int cnt = 0;
    while (vec.empty() != 1) {
        int sz = vec.size();
        if (cnt == 3) {
            vec.erase(vec.begin());
            cnt = 0;
        }
        else if (cnt == 2) {
            price += vec[0];
            vec.erase(vec.begin());
            cnt++;
        } else {
            price += vec[sz-1];
            vec.pop_back();
            cnt++;
        }
    }
    cout << price;
}
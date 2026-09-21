#include <bits/stdc++.h>
using namespace std;
int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;
    vector<string> vec;
    for (int i = 0;i < n;i++) {
        string k;
        cin >> k;
        vec.push_back(k);
    }

    sort(vec.begin(),vec.end(),less<string>());
    for (string i : vec) cout << i << " ";
}
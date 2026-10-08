#include <bits/stdc++.h>
using namespace std;
struct runner {
    int id;
    string name;
    int minute;
    int second;

    bool operator<(const runner& o) {
        if (minute != o.minute) return minute < o.minute;
        return second < o.second;
    }
};
int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int q;
    cin >>q;
    vector<runner> vec;
    while (q--) {
        runner R;
        cin >> R.id >> R.name >> R.minute >> R.second;
        vec.push_back(R);
    }   
    sort(vec.begin(),vec.end());
    for (auto x : vec) {
        cout << x.id << " " << x.name << " " << x.minute << " " << x.second << "\n";
    }
}
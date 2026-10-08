#include <bits/stdc++.h>
using namespace std;
struct competitor {
    int id;
    int score;
    int time;

    bool operator<(const competitor& o) {
        if(score != o.score) return score > o.score;
        return time < o.time;
    }
};
int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int q;
    cin >> q;
    vector<competitor> vec;
    while (q--) {
        competitor C;
        cin >> C.id >> C.score >> C.time;
        vec.push_back(C);
    }
    sort(vec.begin(),vec.end());
    cout << "Winner is ID " << vec[0].id << " with " << vec[0].score << " points and " << vec[0].time << " seconds";
}
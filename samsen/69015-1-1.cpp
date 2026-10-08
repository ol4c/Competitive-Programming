#include <bits/stdc++.h>
using namespace std;
struct date{
    int dd;
    int mm;
    int yy;
};
struct student {
    int std_id;
    char name[50];
    struct date birth;
    struct date checkin;
    int level;

    bool operator<(const student& other) {
        if (birth.yy != other.birth.yy) return birth.yy > other.birth.yy;
        if (birth.mm != other.birth.mm) return birth.mm > other.birth.mm;
        return birth.dd > other.birth.dd;
    }
};
int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    vector<student> vec;
    while (n--) {
        student A;
        cin >> A.std_id >> A.name;
        cin >> A.birth.dd >> A.birth.mm >> A.birth.yy >> A.checkin.dd >>A.checkin.mm >> A.checkin.yy >> A.level;
        vec.push_back(A);
    }
    sort(vec.begin(),vec.end());
    student ans = vec[0];
    cout << ans.std_id << "\n" << ans.name;
}
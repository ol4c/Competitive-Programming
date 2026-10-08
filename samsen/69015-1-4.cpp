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
        if (checkin.yy != other.checkin.yy) return checkin.yy > other.checkin.yy;
        if (checkin.mm != other.checkin.mm) return checkin.mm > other.checkin.mm;
        return checkin.dd > other.checkin.dd;
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
    int rq;
    cin >> rq;
    for (auto a : vec) {
        if (a.birth.mm == rq) {
            cout << a.name << "\n";
        }
    }
}
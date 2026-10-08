#include <bits/stdc++.h>
using namespace std;

struct date{
    int day;
    int month;
    int year;
};
int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    date d;
    //cin.ignore();
    string sd, sm, sy;
    getline(cin,sd,'/');
    getline(cin,sm,'/');
    getline(cin,sy);
    d.day = stoi(sd);
    d.month = stoi(sm);
    d.year = stoi(sy);
    if (d.year % 4 == 0) {
        if (d.year % 100 == 0) {
            if (d.year % 400 == 0) cout << "February " <<d.year << " has 29 days";
            else cout << "February " <<d.year << " has 28 days";
        } else cout << "February " <<d.year << " has 29 days";
    } else cout << "February " <<d.year << " has 28 days";

}
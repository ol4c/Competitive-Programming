#include <bits/stdc++.h>
using namespace std;

struct date{
    int day;
    int month;
    int year;
};

int md[] = {-67,31,28,31,30,31,30,31,31,30,31,30,31};
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
            if (d.year % 400 == 0) md[2] = 29;
            else md[2] = 28;;
        } else md[2] = 29;
    } else md[2] = 28;
    d.day++;
    if(d.day > md[d.month]) {
        d.day = 1;
        d.month++;
    }
    if (d.month > 12) {
        d.month = 1;
        d.year++;
    }
    printf("%d/%d/%d",d.day,d.month,d.year);


}
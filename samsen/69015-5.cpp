#include <bits/stdc++.h>
using namespace std;

struct time{
    int hour;
    int min;
    int sec;
};

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    struct time d;
    //cin.ignore();
    string sd, sm, sy;
    getline(cin,sd,':');
    getline(cin,sm,':');
    getline(cin,sy);
    d.hour = stoi(sd);
    d.min = stoi(sm);
    d.sec = stoi(sy);
    
    d.sec--;
    if (d.sec == -1) {
        d.sec = 59;
        d.min--;
    }
    if (d.min == -1) {
        d.min = 59;
        d.hour--;
    }
    if (d.hour == -1) d.hour = 23;
    printf("%d:%d:%d",d.hour,d.min,d.sec);

}
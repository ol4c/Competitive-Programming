#include <bits/stdc++.h>
using namespace std;

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    string n1,n2;
    bool sex,married;
    int age;
    string title = "";
    cin >> n1 >> n2 >> sex >> age >> married;
    if (sex == 1) {
        if (age < 15)  title = "Master ";
        else title = "Mr. ";
    } else {
        if (age < 15 || !married) title = "Miss ";
        else if (married) title = "Mrs. ";
    }
    cout << title << n1 << " " << n2;
}
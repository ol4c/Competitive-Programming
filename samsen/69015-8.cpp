#include <bits/stdc++.h>
using namespace std;
struct Earthquake {
    double epicenter_x;
    double epicenter_y;
    double magnitude;
    double depth;
};
struct City {
    string name;
    double city_x;
    double city_y;
};
int best_idx;
double mn = 2e9;
int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    Earthquake eq;
    cin >> eq.epicenter_x >> eq.epicenter_y >> eq.magnitude >> eq.depth;
    int n;
    cin >> n; vector<City> vec;
    int idx =0;
    while (n--) {
        City c;
        cin >> c.name >> c.city_x >> c.city_y;
        vec.push_back(c);
        double dif = sqrt(pow(c.city_x - eq.epicenter_x,2) + pow(c.city_y - eq.epicenter_y,2));
        if (dif < mn) {
            mn= dif;
            best_idx = idx;
        }
        idx++;
    }
    cout <<"Closest City: "<< vec[best_idx].name << "\n";
    cout <<fixed << setprecision(2) << "Distance: " << mn << "\n";
    cout << fixed << setprecision(1) << "Magnitude: " << eq.magnitude;
}
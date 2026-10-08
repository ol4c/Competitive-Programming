#include <bits/stdc++.h>
using namespace std;
struct experiment {
    int id;
    double temp;
    double pressure;
    double humidity;
};

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int q;
    cin >> q;
    vector<experiment> vec;
    int best_mx_id = 2e9;
    int best_min_id = 2e9;
    int mx = -2e9, mn = 2e9;
    int idx = 0;
    int best_mx_idx;
    int best_min_idx;
    while (q--) {
        experiment e;
        cin >> e.id >> e.temp >> e.pressure >> e.humidity;
        if (e.temp >= mx) {
            if (e.temp == mx && e.id < best_mx_id) {best_mx_id = e.id;best_mx_idx = idx;}
            if (e.temp > mx) best_mx_idx = idx;
            mx = e.temp;
        }

        if (e.temp <= mn) {
            if (e.temp == mn && e.id < best_min_id) {best_min_id = e.id;best_min_idx = idx;}
            if (e.temp < mn) best_min_idx = idx;
            mn = e.temp;
        }
        vec.push_back(e);
        idx++;
    }
    printf("Max Temp: ID %d, Temp %.1llf, Pressure %.1llf, Humidity %.1llf\n",vec[best_mx_idx].id,vec[best_mx_idx].temp,vec[best_mx_idx].pressure,vec[best_mx_idx].humidity);
    printf("Min Temp: ID %d, Temp %.1llf, Pressure %.1llf, Humidity %.1llf",vec[best_min_idx].id,vec[best_min_idx].temp,vec[best_min_idx].pressure,vec[best_min_idx].humidity);

}
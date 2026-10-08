#include <bits/stdc++.h>
using namespace std;
typedef struct {
    int x,y;
}point;
typedef struct {
    point pt1;
    point pt2;
    point pt3;
} triangle;
int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    triangle tr;
    cin >> tr.pt1.x >> tr.pt1.y >> tr.pt2.x >> tr.pt2.y >> tr.pt3.x >> tr.pt3.y;
    double d = sqrt(pow((tr.pt1.x - tr.pt2.x),2) + pow((tr.pt1.y - tr.pt2.y),2)) 
    +  sqrt(pow((tr.pt1.x - tr.pt3.x),2) + pow((tr.pt1.y - tr.pt3.y),2)) 
    +  sqrt(pow((tr.pt3.x - tr.pt2.x),2) + pow((tr.pt3.y - tr.pt2.y),2)) ; 
    cout << fixed << setprecision(2) << d;
}
#include <bits/stdc++.h>
using namespace std;

int n;

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> n;
    while (n--)
    {
        int na;
        int a1,a2,a3;
        cin >> na >> a1 >> a2 >> a3;
        int mn = min(a1,min(a2,a3));
        cout << na - mn << "\n";
    }
    
    
}
#include <bits/stdc++.h>
using namespace std;
map<char,int> mp;
int a,b;
int arr[10];
int mx = -2e9;
void sol(int now) {
    if (now == 5) {
        map<char,int> mp2 = mp;
        int pts = 0;
        int sum = 0;
        for (int i = 1;i <= 4;i++) {
            if (i == 1) mp2['k'] += arr[i];
            if (i == 2) mp2['r'] += arr[i];
            if (i == 3) mp2['o'] += arr[i];
            if (i == 4) mp2['d'] += arr[i];
            sum += arr[i];
        }
        if (sum != b) return;
        int krod_n = min(mp2['k'] / 2,min(mp2['r'],min(mp2['o'] / 2,mp2['d'])));
        pts += krod_n * 7;
        pts += mp2['k']*mp2['k'];
        pts += mp2['r']*mp2['r'];
        pts += mp2['o']*mp2['o'];
        pts += mp2['d']*mp2['d'];
        mx = max(pts,mx);
        return;
    }

    for (int i = 0;i <= b;i++) {
        arr[now] = i;
        sol(now+1);
    }
}
int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    cin >> a >> b;
    for (int i = 1;i <= a;i++) {
        char c;
        cin >> c;
        mp[c]++;
    }
    sol(1);
    cout << mx;
    //for krokod you need k:2 r:1 o:2 d:1 
}
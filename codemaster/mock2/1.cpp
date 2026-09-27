#include <bits/stdc++.h>
#define int long long
using namespace std;
int n,l;
int arr[15000];
vector<int> pos;
vector<int> radi;
signed main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    cin >> n >> l;
    for (int i = 1;i <= n;i++) {
        int x_i, r_i;
        cin >> x_i >> r_i;
        if (arr[x_i] != 0) {
            arr[x_i] = max(arr[x_i],r_i);
        } else {arr[x_i] = r_i;pos.push_back(x_i);}
        
        
    }
    sort(pos.begin(),pos.end());
    int le = 1;
    int r = 10000;
    while (le < r) {
        int mid = (le+r)/2;
        if (pos[0] - mid * arr[pos[0]] > 0) {
                le = mid + 1;
                break;
            }
            if (pos.back() + mid * arr[pos.back()] < l) {
                le = mid + 1;
                break;
            }
        for (int i = 0;i < pos.size();i++) {
            int p = pos[i];
            if (i == pos.size() - 1) {
                if (pos.size() == 1) {
                    r = mid;
                    break;
                }
                if (pos.back() - mid * arr[pos.back()] <= radi.back()) {
                    r = mid;
                    break;
                } else {
                    le = mid + 1;
                    break;
                }
            }
            if (i == 0) {
                radi.push_back(pos[0] + mid * arr[pos[0]]);
            } else {
                if (p - mid * arr[p] > radi.back()) {
                    le = mid + 1;
                    break;
                } else {
                    if(p + mid * arr[p] > radi.back()) {
                        radi.push_back(p + mid * arr[p]);
                    }
                }
            }
        }
        radi.clear();
    }
    cout << r;

}
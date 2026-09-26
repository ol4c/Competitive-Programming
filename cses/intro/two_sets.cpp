#include <bits/stdc++.h>
#define int long long
using namespace std;

vector<int> first;
vector<int> second;
unordered_map<int,int> nigga;
signed main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    int n;
    cin >> n;
    int sum = n*(n+1)/2;
    int half = sum / 2;
    if (sum % 2 != 0) cout << "NO";
    else {
        cout << "YES\n";
        int s = 0;
        for (int i = n;i >= 1;i--) {
            if (s+i <= half) {
                s += i;
                first.push_back(i);
                nigga[i] = 1;
            } else {
                if (half - s == 0) break;
                first.push_back(half - s);
                nigga[first.back()] = 1;
                break;
            }
        }
        for (int i = 1;i <= n;i++) {
            if (nigga[i] != 1) {
                second.push_back(i);
            }
        }
        cout << first.size() << "\n";
        for (int i : first) cout <<  i << " ";
        cout << "\n";
        sort(second.begin(),second.end(),greater<int>());
        cout << second.size() << "\n";
        for (int i : second) cout <<  i << " ";
    }
    
    
}
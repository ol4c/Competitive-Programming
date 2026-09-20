#include <bits/stdc++.h>
using namespace std;
int arr[200005];
int dp[200005];
stack<pair<int,int>> kuyyai;
int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    for (int i = 1;i <=n;i++) {
        int kuy;
        cin >> kuy;
        arr[i] = kuy; 
        if (kuyyai.empty()) {
            kuyyai.push({i,kuy});
        } else {
            while (1) {
                if (kuyyai.size() == 0)  {
                    kuyyai.push({i,kuy});
                    break;
                }
                if (kuyyai.top().second < kuy) {
                    dp[kuyyai.top().first] = i - kuyyai.top().first;
                    kuyyai.pop();
                } else {
                    kuyyai.push({i,kuy});
                    break;
                }
            }
            
        }
    }

    for (int i = 1;i <= n;i++) {
        cout << dp[i] << " ";
    }
}

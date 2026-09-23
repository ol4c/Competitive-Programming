#include <bits/stdc++.h>
using namespace std;

deque<int> nigga;
int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    for (int i = 1;i <= n;i++) {
        int k;
        cin >> k;
        if (k > 0) {
            nigga.push_back(k);
        } else {
            int f = abs(k);
            while (!nigga.empty()) {
                if (nigga.front() - f <= 0) {
                    f = abs(nigga.front() - f);
                    nigga.pop_front();
                } else {
                    nigga.front() = nigga.front() - f;
                    break;
                }
                
            }
        }
    }
    for (int k : nigga) cout << k << " ";
}

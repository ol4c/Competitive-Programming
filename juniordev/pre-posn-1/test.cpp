#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--) {
        long long n;
        int b;
        cin >> n >> b;

        if (b == 0) {
            cout << 1 << '\n';
            continue;
        }

        long long x = n + 1;

        long long p = 1;
        int m = 0;

        while (p * 2 <= x) {
            p *= 2;
            ++m;
        }

        long long answer;

        if (2 * x < 3 * p) {
            answer = 2LL * m - 1;
        } else {
            answer = 2LL * m;
        }

        cout << n << " " << answer << '\n';
    }

    return 0;
}

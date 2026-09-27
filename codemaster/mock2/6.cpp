#include <bits/stdc++.h>
using namespace std;
int n;
vector<int> height;
deque<string> level;
int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    cin >> n;
    int mx = 1;
    int sum = 0;
    for (int i = 1;i <= n;i++) {
        int k;
        cin >> k;
        mx = max(mx,k);
        sum += k;
        height.push_back(k);
    }
    for (int i = 1;i <= mx;i++) {
        // level i
        string s = "";
        for (int j = 0;j < height.size();j++) {
            int h = height[j];
            if (h >= i) {
                //print spaces before
                for (int k = 1;k <= i-1;k++) s += " ";
                s+= "/";
                // PRINT spaces middle
                for (int k = 1;k <= (h - i) * 2;k++) s += " ";
                s+= "\\";
                //print spaces after
                for (int k = 1;k <= i-1;k++) s += " ";
                
            } else {
                s += string(2 * h, ' ');
            }
            if (j < height.size() - 1) s += ' ';
        }
        level.push_front(s);
    }

    for (string s : level) {
        while (!s.empty() && s.back() == ' ') s.pop_back();
        
        cout << s << "\n";
    }
}
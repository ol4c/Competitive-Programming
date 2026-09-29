#include <bits/stdc++.h>
#define int long long
using namespace std;
vector<int> vec;
int a[100000009];


signed main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    for (int i=2;i <= 200000;i++) {
        if (a[i] == 0) {
            for (int j = i;j <= 200000;j+= i) {
                if (j != i) a[j] = 1;

            }
        }
    }
    string s = "";
    s+="int arr[100010] = {";
    for (int i=2;i <= 200000;i++) {
        for (int j=i;j <= 200000;j++) {
            if (a[i] == 0 && a[j] == 0 && i != j) {

                //s+= to_string(i*j) + ", ";
                //cout << i << " " << j << " = " <<i * j << endl;
                if (i*j <= 500000) vec.push_back(i*j);

            }
        }
    }
    sort(vec.begin(),vec.end());
    for (int i : vec) s+= to_string(i) + ", ";
    s+= "};";
    cout << vec.size();
    ofstream outputFile("example.txt");
    outputFile << s << std::endl;
    outputFile.close();
}

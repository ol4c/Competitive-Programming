#include <bits/stdc++.h>
using namespace std;

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    char a,b,c;
    cin >> a >> b >> c;
    if (a - '0' > 6 || a - '0' < 1 || b - '0' > 6 || b - '0' < 1 || c - '0' > 6 || c - '0' < 1 ) {
        cout << "ERROR";
        return 0;
    }
    char nigg[3] = {a,b,c};
    string s1 = "";
    string s2 = "";
    string s3 = "";
    for (int i = 0;i < 3;i++) {
        if (nigg[i] == '1') {
            s1 += "   ";
            s2+= " * ";
            s3+= "   ";
        } else if (nigg[i] == '2') {
            s1 += "   ";
            s2+= "* *";
            s3+= "   ";
        } else if (nigg[i] == '3') {
            s1 += " * ";
            s2+= " * ";
            s3+= " * ";
        } else if (nigg[i] == '4') {
            s1 += "* *";
            s2+= "   ";
            s3+= "* *";
        } else if (nigg[i] == '5') {
            s1 += "* *";
            s2+= " * ";
            s3+= "* *";
        } else if (nigg[i] == '6') {
            s1 += "* *";
            s2+= "* *";
            s3+= "* *";
        } 
        if (i != 2) {
            s1+="|";
            s2+="|";
            s3+="|";
        }
        
    }

    cout << s1 << "\n" << s2 << "\n" << s3;

}
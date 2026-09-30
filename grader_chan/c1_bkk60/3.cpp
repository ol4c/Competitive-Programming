#include <bits/stdc++.h>
using namespace std;

vector<string> v_1;
vector<string> v_2;
deque<string> v_ans;
int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int base;
    string n1,n2;
    string ans = "";
    cin >> base >> n1 >> n2;

    if (n1.size() != n2.size()) {
        if (n1.size() > n2.size()) {
            while (n1.size() > n2.size()) n2 = " " + n2;
        } else {
            while (n1.size() < n2.size()) n1 = " " + n1;
        }
    }
    for (int i = 0;i < n1.size();i++) v_1.push_back(string(1,n1[i]));
    for (int i = 0;i < n2.size();i++) v_2.push_back(string(1,n2[i]));
    vector<string> tod(v_1.size(), "0");
    tod[v_1.size() - 1] = "0";
    for (int i = n1.size() - 1;i >= 0;i--) {
        string waw_v1,waw_v2;
        if (v_1[i] != " ") {
            if (v_1[i] == "A") waw_v1 = "10";
            else if (v_1[i] == "B") waw_v1 = "11";
            else if (v_1[i] == "C") waw_v1 = "12";
            else if (v_1[i] == "D") waw_v1 = "13";
            else if (v_1[i] == "E") waw_v1 = "14";
            else if (v_1[i] == "F") waw_v1 = "15";
            else waw_v1 = v_1[i];
        } else {
            waw_v1 = " ";
        }

        if (v_2[i] != " ") {
            if (v_2[i] == "A") waw_v2 = "10";
            else if (v_2[i] == "B") waw_v2 = "11";
            else if (v_2[i] == "C") waw_v2 = "12";
            else if (v_2[i] == "D") waw_v2 = "13";
            else if (v_2[i] == "E") waw_v2 = "14";
            else if (v_2[i] == "F") waw_v2 = "15";
            else waw_v2 = v_2[i];
        } else {
            waw_v2 = " ";
        }

        string waw_ans;
        if (waw_v1 == " " || waw_v2 == " ") {
            if ((waw_v1 == " " && waw_v2 == " ")) waw_ans = "0";
            else if (waw_v1 == " ") waw_ans = to_string(stoi(tod[i]) + stoi(waw_v2));
            else if (waw_v2 == " ") waw_ans = to_string(stoi(tod[i]) + stoi(waw_v1));
             
        } else {
            waw_ans = to_string(stoi(waw_v1) + stoi(waw_v2) + stoi(tod[i]));
        }
        
        int sum = stoi(waw_ans);

        v_ans.push_front(to_string(sum % base));

        if (i > 0) {
            tod[i - 1] = to_string(sum / base);
        } else if (sum / base > 0) {
            v_ans.push_front(to_string(sum / base));
        }

        
    }

    for (auto i : v_ans) {
        if (i == "10") cout << "A";
        else if (i == "11") cout << "B";
        else if (i == "12") cout << "C";
        else if (i == "13") cout << "D";
        else if (i == "14") cout << "E";
        else if (i == "15") cout << "F";
        else cout << i;
    }
}
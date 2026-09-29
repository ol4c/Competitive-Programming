#include <bits/stdc++.h>
using namespace std;

int og[10];
string a[10];
string yo[] = {"+","-","*","/"};
int mx = 0;
/*
(a b) (c d)
((a b) c) d
(a (b c)) d
a ((b c) d)
a (b (c d))
*/
vector<vector<string>> paren = {
    {"","(","","",")","(","","",")"},
    {"","((","","",")","",")","",""},
    {"","(","","(","","","))","",""},
    {"","","","((","","",")","",")"},
    {"","","","(","","(","","","))"},

};
void solve(int now) {
    if (now > 6) {
        for (int p = 0;p < 5;p++) {
            stack<string> stk;
            stack<int> stk2;
            vector<string> postfix;
            for (int i = 1;i <= 8;i++) {
                if (paren[p][i] == "((" || paren[p][i] == "(") {
                    if (paren[p][i] == "((") {stk.push("(");stk.push("(");}
                    else {
                        stk.push("(");
                    }
                } else if (paren[p][i] == "))" || paren[p][i] == ")") {
                    if (paren[p][i] == "))") {
                        while (stk.top() !="(") {
                            postfix.push_back(stk.top());
                            stk.pop();
                        }
                        stk.pop();
                        while (stk.top() !="(") {
                            postfix.push_back(stk.top());
                            stk.pop();
                        }
                        stk.pop();
                    }
                    else {
                        while (stk.top() !="(") {
                            postfix.push_back(stk.top());
                            stk.pop();
                        }
                        stk.pop();
                    }
                }
                if (i != 8) {
                    if (i % 2 == 1) {
                        postfix.push_back(a[i]);
                    } else {
                        if (stk.empty()) {
                            stk.push(a[i]);
                        } else {
                            if (a[i] == "*" || a[i] == "/") {
                                while (!stk.empty()) {
                                    if (stk.top() == "*" || stk.top() == "/") {
                                        postfix.push_back(stk.top());
                                        stk.pop();
                                    } else break;
                                }
                                
                                stk.push(a[i]);
                            } else {
                                while (!stk.empty()) {
                                    if (stk.top() == "(") break;
                                    postfix.push_back(stk.top());
                                    stk.pop();
                                }
                                
                                stk.push(a[i]);
                            }
                        }
                    }
                } 
                
            }
            while (!stk.empty()) {
                postfix.push_back(stk.top());
                stk.pop();
            }


            int prod = 0;
            bool chch = 0;
            for (int i = 0;i < postfix.size();i++) {
                if (postfix[i] != "+" && postfix[i] != "-" && postfix[i] != "*" && postfix[i] != "/") {
                    stk2.push(stoi(postfix[i]));
                } else {
                    int a2 = stk2.top();
                    stk2.pop();
                    int a1 = stk2.top();
                    stk2.pop();
                    if (postfix[i] == "+") stk2.push(a1+a2);
                    if (postfix[i] == "-") stk2.push(a1-a2);
                    if (postfix[i] == "*") stk2.push(a1*a2);
                    if (postfix[i] == "/") {
                        if (a2 == 0) chch = 1;
                         if(chch) break;
                        if (a1 % a2 != 0) chch = 1;
                        if(chch) break;
                        stk2.push(a1/a2);
                    }
                }
            }
            if (chch) continue;
            prod = stk2.top();
            if (prod <= 24) {
                mx = max(prod,mx);
            }
            


        }
        

        
        return;
    }
    
    for (int i = 0;i < 4;i++) {
        a[now] = yo[i];
        solve(now+2);
    }
}

int pe[7];
int used[7];
vector<vector<int>> vec;
void permu(int now) {
    if (now == 5) {
        vector<int> minivec;
        for (int i = 1;i <=4 ;i++) {
            minivec.push_back(pe[i]);
        }
        vec.push_back(minivec);
        return;
    }

    for (int i = 1;i <= 4;i++) {
        if (used[i]) continue;
        pe[now] = i;
        used[i] = 1;
        permu(now + 1);
        used[i] = 0;
    }
}
int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int q;
    cin >> q;
    while (q--) {
        mx = INT_MIN;
        for (int i =1;i<=4;i++) {
            int k;
            cin >> k;
            og[i] = k;
        }
        permu(1);
        for (auto x : vec) {
            a[1] = to_string(og[x[0]]);
            a[3] = to_string(og[x[1]]);
            a[5] = to_string(og[x[2]]);
            a[7] = to_string(og[x[3]]);
            solve(2);
        }
        

        
        cout << mx << "\n";
        
    }

}
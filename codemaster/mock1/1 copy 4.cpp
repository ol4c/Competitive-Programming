#include <bits/stdc++.h>
using namespace std;
int checker = 0;
int n,t;
int arr[25];
void sol(int num,int sum,int idx) {
    if (sum == t) {
        checker = 1; 
    }
    if (checker) return;
    if (sum > t || idx > n) return;
    
    sol(arr[idx+1],sum+arr[idx+1],idx+1);

    sol(arr[idx+1],sum,idx+1);
    
}

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    cin >> n >> t;
    for (int i = 1;i <= n;i++) {
        cin >> arr[i];
    }
    sol(arr[1],arr[1],1);
    sol(arr[1],0,1);
    
    if (checker) cout << "YES";
    else cout << "NO";

}

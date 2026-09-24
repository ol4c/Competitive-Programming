#include <bits/stdc++.h>
using namespace std;

int main () {
    int n;
    int nigga = 4;
    scanf("%d",&n);
    if (n <= 2) printf("%.6f",2.0);
    else if (n ==3) {
        printf("%.6f", 2 + (sqrt(3)));
    }
    else if (n == 5) printf("%.6f", 2 + (2*sqrt(3)));
    else if (n >= 7 && n % 2 == 1) printf("%.6f", (n - 7+4) + (2*sqrt(3)));
    else printf("%.6f",n*1.0);
}
#include <bits/stdc++.h>
using namespace std;

struct Book{
    string author;
    string name;
    int sales;
    int year;

    bool operator<(const Book&o) {
        if (o.sales != sales) return sales > o.sales;
        return year > o.year;
    }
};
int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int q;
    cin >> q;
    vector<Book> v;
    while (q--) {
        Book b;
        cin >> b.author >> b.name >> b.sales >> b.year;
        v.push_back(b);
    }
    sort(v.begin(),v.end());
    cout << v[0].name;
}
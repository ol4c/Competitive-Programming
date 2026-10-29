#include <bits/stdc++.h>
using namespace std;
struct node {
    int key;
    node *lchild;
    node *rchild;
};

node* searchp(node* now, int want) {
    if (now == NULL || now->key == want) return now;
    node *pos = searchp(now->lchild,want);
    if (pos == NULL) {
        return searchp(now->rchild,want); 
    } else {
        return pos;
    }
}
node *root;
void add(int par, int ch) {
    node *pos = searchp(root,par);
    node *newn = new node;
    newn->key = ch;
    newn->lchild = NULL;
    newn->rchild = NULL;
    if (par == 1) {
        root = newn;
        return;
    }

    if (pos->lchild == NULL) {
        pos->lchild = newn;
    } else {
        pos->rchild = newn;
    }
}
int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    int n,m;
    cin >> n >> m;

    for (int i = 1;i <= m;i++) {
        int x,y;
        cin >> x >> y;
        add(x,y);
    }

    return 0;
}
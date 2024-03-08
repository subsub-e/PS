#include <iostream>
#include <stack>
#include <algorithm>
#include <vector>
using namespace std;

int n;
int lc[30];
int rc[30];

void preorder(int now){
    cout << char(now + 'A' - 1);
    if(lc[now] != 0){
        preorder(lc[now]);
    }
    if(rc[now] != 0){
        preorder(rc[now]);
    }
}

void inorder(int now){
    if(lc[now] != 0){
        inorder(lc[now]);
    }
    cout << char(now + 'A' - 1);
    if(rc[now] != 0){
        inorder(rc[now]);
    }
}

void postorder(int now){
    if(lc[now] != 0){
        postorder(lc[now]);
    }
    if(rc[now] != 0){
        postorder(rc[now]);
    }
    cout << char(now + 'A' - 1);
}


int main(){
    cin.tie(0);
    ios_base::sync_with_stdio(false);

    cin >> n;
    for(int i = 0; i < n; i++){
        char c, l, r;
        cin >> c >> l >> r;
        if(l != '.'){
            lc[c - 'A' + 1] = l - 'A' + 1;
        }
        if(r != '.'){
            rc[c - 'A' + 1] = r - 'A' + 1;
        }
    }

    preorder(1);
    cout << '\n';
    inorder(1);
    cout << '\n';
    postorder(1);
    return 0;
    return 0;
}
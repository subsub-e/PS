#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n;
int inorder[100001];
int postorder[100001];
int ind[100001];



void preorder(int inorderStart, int inorderEnd, int postorderStart, int postorderEnd){

    //cout << inorderStart << ' ' << inorderEnd << ' ' << postorderStart << ' ' << postorderEnd << '\n';
    if(inorderStart > inorderEnd || postorderStart > postorderEnd){
        return;
    }


    int root = postorder[postorderEnd];
    int rootind = ind[root];
    int leftSize = rootind - inorderStart;
    int rightSize = inorderEnd - rootind;
    cout << root << ' ';

    preorder(inorderStart, rootind - 1, postorderStart, postorderStart + leftSize - 1);
    preorder(rootind + 1, inorderEnd, postorderStart + leftSize, postorderEnd -1);
}


int main(){
    cin >> n;
    for(int i = 1; i <= n; i++){
        cin >> inorder[i];
        ind[inorder[i]] = i;
    }
    for(int i = 1; i <= n; i++){
        cin >> postorder[i];
    }

    preorder(1, n, 1, n);
}
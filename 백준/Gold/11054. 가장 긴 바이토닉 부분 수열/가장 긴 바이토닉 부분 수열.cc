#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n;
vector<int> v;
int arr1[1001][2];
int arr2[1001][2];

int main(){
    cin >> n;

    for(int i = 0; i < n; i++){
        int x; cin >> x;
        v.push_back(x);
    }

    arr1[0][0] = 0;
    arr1[0][1] = 1;
    arr2[n-1][0] = 0;
    arr2[n-1][1] = 1;

    for(int i = 1; i < n; i++){
        arr1[i][0] = max(arr1[i-1][0], arr1[i-1][1]);
        int temp = 0;
        for(int j = 0; j < i; j++){
            if(v[i] > v[j]){
                temp = max(temp, arr1[j][1]);
            }
        }
        arr1[i][1] = temp + 1;
    }

    for(int i = n-1; i >= 0; i--){
        arr2[i][0] = max(arr2[i+1][0], arr2[i+1][1]);
        int temp = 0;
        for(int j = n-1; j > i; j--){
            if(v[i] > v[j]){
                temp = max(temp, arr2[j][1]);
            }
        }
        arr2[i][1] = temp + 1;
    }

    int maxans = 0;

    for(int i = 0; i < n; i++){
        maxans = max(maxans, arr1[i][1] + arr2[i][1] - 1);
    }
    
    cout<< maxans;
}
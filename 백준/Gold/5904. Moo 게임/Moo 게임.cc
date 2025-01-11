#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int n;
int arr[100001];

void func(int temp, int siz, int target){
    //cout << temp << ' ' << siz << ' ' << target << '\n';
    if(temp == 3){
        if(target == 1){
            cout << 'm';
            exit(0);
        }
        else{
            cout << 'o';
            exit(0);
        }
    }
    if(target <= arr[siz - 1]){
        func(arr[siz - 1], siz - 1, target);
    }
    else if(target > arr[siz - 1] + 3 + siz){
        func(arr[siz - 1], siz - 1, target - arr[siz - 1] - 3 - siz);
    }
    else{
        if(target == arr[siz - 1] + 1){
            cout << 'm';
            exit(0);
        }   
        else{
            cout << 'o';
            exit(0);
        }
    }
}


int main(){
    cin >> n;
    int m = 0;
    int temp = 3;
    arr[0] = 3;
    while(temp < n){
        m++;
        temp = 2 * temp + 1 + m + 2;
        arr[m] = temp;
    }
    func(temp, m, n);
}
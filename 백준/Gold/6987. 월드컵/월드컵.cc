#include <iostream>
#include <algorithm>
#include <cmath>
#include <string>
#include <vector>
#include <climits>
#include <cstring>
#include <tuple>
#include <queue>

using namespace std;

int arr[6][3];
int flag;

bool check(){
    for(int i = 0; i < 6; i++){
        for(int j = 0; j < 3; j++){
            if(arr[i][j] != 0){
                return false;
            }
        }
    }
    return true;
}

void func(int index, int next, int depth){
    if(index == 5 && depth == 15){
        if(check()){
            flag = 1;
        }
        return;
    }

    if(arr[index][0] > 0 && arr[next][2] > 0){
        arr[index][0]--;
        arr[next][2]--;
        func(index, next + 1, depth + 1);
        arr[index][0]++;
        arr[next][2]++;
    }

    if(arr[index][1] > 0 && arr[next][1] > 0){
        arr[index][1]--;
        arr[next][1]--;
        func(index, next + 1, depth + 1);
        arr[index][1]++;
        arr[next][1]++;
    }

    if(arr[index][2] > 0 && arr[next][0] > 0){
        arr[index][2]--;
        arr[next][0]--;
        func(index, next + 1, depth + 1);
        arr[index][2]++;
        arr[next][0]++;
    }

    if(index < 5) {
        func(index + 1, index + 2, depth);
    }
}


int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

    int t = 4;
    while(t--){
        for(int i = 0; i < 6; i++){
            for(int j = 0; j < 3; j++){
                cin >> arr[i][j];
            }
        }

        func(0, 1, 0);

        if(flag == 0){
            cout << 0 << '\n';
        }
        else{
            cout << 1 << '\n';
        }
        flag = 0;
    }

    




	return 0;
}
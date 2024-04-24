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

int arr[9][9];
vector<pair<int, int> > v;
int flag;

bool check(int x, int y, int val){
    for(int i = 0; i < 9; i++){
        if(arr[i][y] == val){
            return false;
        }
        if(arr[x][i] == val){
            return false;
        } 
    }

    int grid_x = x / 3;
    int grid_y = y / 3;
    grid_x *= 3;
    grid_y *= 3;
    for(int i = grid_x; i < grid_x + 3; i++){
        for(int j = grid_y; j < grid_y + 3; j++){
            if(arr[i][j] == val){
                return false;
            }
        }
    }
    return true;
}

void func(int cnt){
    if(flag == 1){
        return;
    }
    if(cnt == v.size()){
        for(int i = 0; i < 9; i++){
            for(int j = 0; j < 9; j++){
                cout << arr[i][j];
            }
            cout << '\n';
        }
        flag = 1;
        return;
    }
    else{
        int x = v[cnt].first;
        int y = v[cnt].second;
        for(int i = 1; i <= 9; i++){
            if(check(x, y, i)){
                arr[x][y] = i;
                func(cnt + 1);
                arr[x][y] = 0;
            }
        }
    }
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

    for(int i = 0; i < 9; i++){
        for(int j = 0; j < 9; j++){
            char c; cin >> c;
            arr[i][j] = (int)c - '0';
            if(arr[i][j] == 0){
                v.push_back(make_pair(i, j));
            }
        }
    }

    func(0);

	return 0;
}
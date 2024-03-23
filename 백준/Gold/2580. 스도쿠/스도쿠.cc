#include <iostream>
#include <string>
#include <cmath>
#include <set>
#include <map>
#include <stack>
#include <queue>
#include <deque>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

int arr[9][9];
vector<pair<int, int> > v;
int flag = 0;

bool check(int x, int y, int value){
    for(int i = 0; i < 9; i++){
        if(arr[x][i] == value){
            return false;
        }
        if(arr[i][y] == value){
            return false;
        }
    }

    int part_x = x / 3;
    int part_y = y / 3;
    part_x *= 3;
    part_y *= 3;

    for (int i = part_x; i < part_x + 3; i++) {
		for (int j = part_y; j < part_y + 3; j++) {
			if (arr[i][j] == value) return false;
		}
	}
	return true;
}

void func(int cnt){
    if(flag == 1){
        return;
    }
    if(cnt == v.size()){
        flag = 1;
        for(int i = 0; i < 9; i++){
            for(int j = 0; j < 9; j++){
                cout << arr[i][j] << ' ';
            }
            cout << '\n';
        }
        return;
    }
    else{
        int x = v[cnt].first;
        int y = v[cnt].second;
        for(int j = 1; j <= 9; j++){
            if(check(x, y, j)){
                arr[x][y] = j;
                func(cnt + 1);
                arr[x][y] = 0; 
            }
        }
    }
}

int main() {
	
    for(int i = 0; i < 9; i++){
        for(int j = 0; j < 9; j++){
            cin >> arr[i][j];
            if(arr[i][j] == 0){
                v.push_back(make_pair(i, j));
            }
        }
    }

    func(0);
	return 0;
}
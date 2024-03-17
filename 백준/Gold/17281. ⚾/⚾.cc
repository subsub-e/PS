#include <iostream>
#include <algorithm>
#include <cmath>
#include <string>
#include <vector>
#include <climits>
using namespace std;

int n;
int arr[51][9];
bool visited[9];
vector<int> v;
int maxans = 0;

void game(){
    int temp[n][9];
    for(int i = 0; i < n; i++){
        for(int j = 0; j < 9; j++){
            temp[i][v[j]] = arr[i][j];
        }
    }

    int cnt = 0;
    int out = 0;
    int index = 0;
    int ans = 0;
    int base[3] = {};
    while(cnt < n){
        if(out == 3){
            out = 0;
            cnt++;
            base[0] = 0;
            base[1] = 0;
            base[2] = 0;
            continue;
        }
        if(temp[cnt][index % 9] == 0){
            out++;
            index++;
        }
        else if(temp[cnt][index % 9] == 1){
            index++;
            if(base[2] == 1){
                ans++;
            }
            base[2] = base[1];
            base[1] = base[0];
            base[0] = 1;
        }
        else if(temp[cnt][index % 9] == 2){
            index++;
            if(base[2] == 1){
                ans++;
            }
            if(base[1] == 1){
                ans++;
            }
            base[2] = base[0];
            base[1] = 1;
            base[0] = 0;
        }
        else if(temp[cnt][index % 9] == 3){
            index++;
            if(base[2] == 1){
                ans++;
            }
            if(base[1] == 1){
                ans++;
            }
            if(base[0] == 1){
                ans++;
            }
            base[2] = 1;
            base[1] = 0;
            base[0] = 0;
        }
        else if(temp[cnt][index % 9] == 4){
            index++;
            if(base[2] == 1){
                ans++;
            }
            if(base[1] == 1){
                ans++;
            }
            if(base[0] == 1){
                ans++;
            }
            base[2] = 0;
            base[1] = 0;
            base[0] = 0;
            ans++;
        }
    }
    maxans = max(maxans, ans);
}

void func(int x){
    if(x == 8){
        game();
        return;
    }

    for(int i = 0; i < 9; i++){
        if(!visited[i]){
            visited[i] = 1;
            v.push_back(i);
            func(x + 1);
            visited[i] = 0;
            v.pop_back();
        }
    }
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
    
	cin >> n;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < 9; j++){
            cin >> arr[i][j];
        }
    }
    v.push_back(3);
    visited[3] = 1;
    func(0);
    cout << maxans;
	return 0;
}
#include <iostream>
#include <algorithm>
#include <cmath>
#include <string>
#include <vector>
#include <climits>
using namespace std;

int n;
int arr[17][17];
int dx[3] = {0, 1, 1};
int dy[3] = {1, 1, 0};
int cnt = 0;

void dfs(int x, int y, int dir){
	if(x == n - 1 && y == n - 1){
		cnt++;
		return;
	}

	for(int i = 0; i < 3; i++){
		int nx = x + dx[i];
		int ny = y + dy[i];

		if((dir == 0 && i == 2) || (dir == 2 && i == 0)){
			continue;
		}

		if(i != 1){
			if(0 <= nx && nx < n && 0 <= ny && ny < n && arr[nx][ny] != 1){
				dfs(nx, ny, i);
			}
		}
		else{
			if(0 <= nx && nx < n && 0 <= ny && ny < n && arr[x + 1][y] != 1 && arr[x][y + 1] != 1 && arr[nx][ny] != 1){
				dfs(nx, ny, i);
			}
		}
	}
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
    
	cin >> n;
	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++){
			cin >> arr[i][j];
		}
	}

	dfs(0, 1, 0);
	cout << cnt;
	return 0;
}
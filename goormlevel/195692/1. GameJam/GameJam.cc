#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <cstring>
using namespace std;

int n, x1, x2, y1, y2;
string arr[201][201];
int cnt1, cnt2;
bool visited[201][201];

void game(int x, int y, int cnt, int flag){
	int index;
	string temp = arr[x][y];
	for(int i = 0; i < temp.length(); i++){
		if(!isdigit(temp[i])){
			index = i;
			break;
		}
	}
	int temp_cnt = 0;
	string distance_temp = temp.substr(0, index);
	int distance;
	if(distance_temp.length() == 1){
		distance = (int) distance_temp[0] - 48;
	}
	else{
		distance = stoi(distance_temp);
	}
	if(temp[index] == 'L'){
		int ny = y;
		for(int i = 0; i < distance; i++){
			ny--;
			temp_cnt++;
			if(ny < 0){
				ny = n - 1;
			}
			if(visited[x][ny]){
				if(flag == 0){
					cnt1 = cnt + temp_cnt;
				}
				else{
					cnt2 = cnt + temp_cnt;
				}
				return;
			}
			visited[x][ny] = 1;
		}
		game(x, ny, cnt + temp_cnt, flag);
	}
	else if(temp[index] == 'D'){
		int nx = x;
		for(int i = 0; i < distance; i++){
			nx++;
			temp_cnt++;
			if(nx == n){
				nx = 0;
			}
			if(visited[nx][y]){
				if(flag == 0){
					cnt1 = cnt + temp_cnt;
				}
				else{
					cnt2 = cnt + temp_cnt;
				}
				return;
			}
			visited[nx][y] = 1;
		}
		game(nx, y, cnt + temp_cnt, flag);
	}
	else if(temp[index] == 'U'){
		int nx = x;
		for(int i = 0; i < distance; i++){
			nx--;
			temp_cnt++;
			if(nx < 0){
				nx = n-1;
			}
			if(visited[nx][y]){
				if(flag == 0){
					cnt1 = cnt + temp_cnt;
				}
				else{
					cnt2 = cnt + temp_cnt;
				}
				return;
			}
			visited[nx][y] = 1;
		}
		game(nx, y, cnt + temp_cnt, flag);
	}
	else{
		int ny = y;
		for(int i = 0; i < distance; i++){
			ny++;
			temp_cnt++;
			if(ny == n){
				ny = 0;
			}
			if(visited[x][ny]){
				if(flag == 0){
					cnt1 = cnt + temp_cnt;
				}
				else{
					cnt2 = cnt + temp_cnt;
				}
				return;
			}
			visited[x][ny] = 1;
		}
		game(x, ny, cnt + temp_cnt, flag);
	}
}

int main() {
	cin >> n >> x1 >> x2 >> y1 >> y2;
	x1--;
	x2--;
	y1--;
	y2--;
	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++){
			string str; cin >> str;
			arr[i][j] = str;
		}
	}
	visited[x1][x2] = 1;
	game(x1, x2, 0, 0);
	memset(visited, 0, sizeof(visited));
	visited[y1][y2] = 1;
	game(y1, y2, 0, 1);
	
	if(cnt1 > cnt2){
		cout << "goorm" << ' ' << cnt1;
	}
	else{
		cout << "player" << ' ' << cnt2;
	}
	return 0;
}
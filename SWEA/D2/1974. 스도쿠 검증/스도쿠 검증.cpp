#include<iostream>
#include <cstring>
using namespace std;


bool visited[10];
int arr[9][9];

bool func(int x){
    memset(visited, 0, sizeof(visited));
    for(int i = 0; i < 9; i++){
    	if(visited[arr[i][x]]){
            return false;
        }
        visited[arr[i][x]] = 1;
    }
    return true;
}

bool func1(int x){
    memset(visited, 0, sizeof(visited));
    for(int i = 0; i < 9; i++){
    	if(visited[arr[x][i]]){
            return false;
        }
        visited[arr[x][i]] = 1;
    }
    return true;
}

bool func2(int x, int y){
    memset(visited, 0, sizeof(visited));
    for(int i = x; i < x + 3; i++){
        for(int j = y; j < y + 3; j++){
            if(visited[arr[i][j]]){
                return false;
            }
            visited[arr[i][j]] = 1;
        }
    }
    return true;
}

int main(int argc, char** argv)
{
	int test_case;
	int T;
	
	cin>>T;
	/*
	   여러 개의 테스트 케이스가 주어지므로, 각각을 처리합니다.
	*/
	for(test_case = 1; test_case <= T; ++test_case)
	{
		for(int i = 0; i < 9; i++){
            for(int j = 0; j < 9; j++){
                cin >> arr[i][j];
            }
        }
        
        cout << '#' << test_case << ' ';
        int flag = 0;
        for(int i = 0; i < 9; i++){
        	if(!func(i)){
                flag = 1;
                break;
            }
            if(!func1(i)){
                flag = 1;
                break;
            }
        }
        
        if(!func2(0, 0)){
            flag = 1;
        }
        if(!func2(0, 3)){
            flag = 1;
        }
        if(!func2(0, 6)){
            flag = 1;
        }
        if(!func2(3, 0)){
            flag = 1;
        }
        if(!func2(3, 3)){
            flag = 1;
        }
        if(!func2(3, 6)){
            flag = 1;
        }
        if(!func2(6, 0)){
            flag = 1;
        }
        if(!func2(6, 3)){
            flag = 1;
        }
        if(!func2(6, 6)){
            flag = 1;
        }
        
        if(flag == 0){
            cout << 1 << '\n';
        }
        else{
            cout << 0 << '\n';
        }

	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}
#include<iostream>
#include <cstring>
using namespace std;

int arr[11][11];
int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};

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
		int n; cin >> n;
        for(int i = 0; i < n; i++){
        	fill(arr[i], arr[i] + n, 0);
        }
        int num = 1;
        int index = 0;
        int x = 0;
        int y = 0;
        while(num <= n * n){
        	arr[x][y] = num;
            num++;
            int nx = x + dx[index % 4];
            int ny = y + dy[index % 4];
            if(0 <= nx && nx < n && 0 <= ny && ny < n && arr[nx][ny] == 0){
            	x = nx;
                y = ny;
            }
            else{
                index++;
                x += dx[index % 4];
                y += dy[index % 4];
            }
        }
        
        cout << '#' << test_case << '\n';
        for(int i = 0; i < n; i++){
        	for(int j = 0; j < n ; j++){
            	cout << arr[i][j] << ' ';
            }
            cout << '\n';
        }
	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}
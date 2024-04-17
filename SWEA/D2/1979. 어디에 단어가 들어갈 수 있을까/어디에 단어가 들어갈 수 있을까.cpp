#include<iostream>
#include <cstring>
using namespace std;
int arr[20][20];
bool visited[20][20];
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
		int n, m;
        cin >> n >> m;
        for(int i = 0; i < 20; i++){
        	fill(arr[i], arr[i] + 20, -1);
        }
        for(int i = 0; i < 20; i++){
        	fill(visited[i], visited[i] + 20, 0);
        }
        int ans = 0;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                cin >> arr[i][j];
            }
        }
        
       	for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                if(arr[i][j] == 1){
                	int temp = j;
                    int cnt = 0;
                    while(arr[i][temp] == 1 && !visited[i][temp]){
                        visited[i][temp] = 1;
                        temp++;
                        cnt++;
                    }
                    if(cnt == m){
                        //cout << i << ' ' << j << '\n';
                    	ans++;
                    }
                }
            }
        }
        
        for(int i = 0; i < 20; i++){
        	fill(visited[i], visited[i] + 20, 0);
        }
        
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                if(arr[i][j] == 1){
                	int temp = i;
                    int cnt = 0;
                    while(arr[temp][j] == 1 && !visited[temp][j]){
                        visited[temp][j] = 1;
                        temp++;
                        cnt++;
                    }
                    if(cnt == m){
                        //cout << i << ' ' << j << '\n';
                    	ans++;
                    }
                }
            }
        }
        cout << '#' << test_case << ' ' << ans << '\n';
	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}
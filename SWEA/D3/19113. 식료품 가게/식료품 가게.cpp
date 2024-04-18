#include<iostream>
#include <vector>
#include <cstring>
using namespace std;

int arr[203];
bool visited[203];
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
        for(int i = 0; i < n * 2; i++){
        	cin >> arr[i];
        }
        memset(visited, 0, sizeof(visited));
        
        vector<int> v;
        v.push_back(arr[0]);
        visited[0] = 1;
        int temp = arr[0] / 3 * 4;
        for(int i = 0; i < n * 2; i++){
            if(arr[i] == temp){
                visited[i] = 1;
                break;
            }
        }
        
        for(int i = 1; i < n * 2; i++){
        	if(visited[i]){
            	continue;
            }
            v.push_back(arr[i]);
            visited[i] = 1;
            int temp = arr[i] / 3 * 4;
            for(int i = 0; i < n * 2; i++){
                if(arr[i] == temp && !visited[i]){
                    visited[i] = 1;
                    break;
                }
            }
        }
		cout << '#' << test_case << ' ';
        for(int i = 0; i < v.size(); i++){
        	cout << v[i] << ' ';
        }
        cout << '\n';
	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}
#include<iostream>

using namespace std;

int arr[3];

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
		for(int i = 0; i < 3; i++){
            cin >> arr[i];
        }
        
        cout << '#' << test_case << ' ';
        if(arr[1] < 2){
            cout << -1 << '\n';
            continue;
        }
        if(arr[2] < 3){
            cout << -1 << '\n';
            continue;
        }
        
        int sum = 0;
        if(arr[1] >= arr[2]){
        	sum = arr[1] - (arr[2] - 1);
            arr[1] = arr[2] - 1;
        }
        if(arr[0] >= arr[1]){
        	sum += arr[0] - (arr[1] - 1);
            
        }
        //cout << arr[0] << ' ' << arr[1] << ' ' << arr[2] << ' ';
		cout << sum << '\n';
	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}
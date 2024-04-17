/////////////////////////////////////////////////////////////////////////////////////////////
// 기본 제공코드는 임의 수정해도 관계 없습니다. 단, 입출력 포맷 주의

#include<iostream>

using namespace std;

int arr[8];
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
        int cnt = 0;
        while(n - 50000 >= 0){
            n -= 50000;
            cnt++;
        }
        arr[0] = cnt;
        cnt = 0;
        while(n - 10000 >= 0){
            n -= 10000;
            cnt++;
        }
        arr[1] = cnt;
        cnt = 0;
        while(n - 5000 >= 0){
            n -= 5000;
            cnt++;
        }
        arr[2] = cnt;
        cnt = 0;
        while(n - 1000 >= 0){
            n -= 1000;
            cnt++;
        }
        arr[3] = cnt;
        cnt = 0;
        while(n - 500 >= 0){
            n -= 500;
            cnt++;
        }
        arr[4] = cnt;
        cnt = 0;
        while(n - 100 >= 0){
            n -= 100;
            cnt++;
        }
        arr[5] = cnt;
        cnt = 0;
        while(n - 50 >= 0){
            n -= 50;
            cnt++;
        }
        arr[6] = cnt;
        cnt = 0;
        while(n - 10 >= 0){
            n -= 10;
            cnt++;
        }
        arr[7] = cnt;
        cnt = 0;
        
        cout << '#' << test_case << '\n';
        for(int i = 0; i < 8; i++){
        	cout << arr[i] << ' ';
        }
        cout << '\n';

	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}
#include <cstring>
#include<iostream>

using namespace std;
int arr[6];
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
        fill(arr, arr + 5, 0);
        
        while(1){
            if(n == 1 || (n % 2 != 0 && n % 3 != 0 && n % 5 != 0 && n % 7 != 0 && n % 11 != 0)){
                break;
            }
            if(n % 2 == 0){
            	arr[0]++;
                n /= 2;
            }
            else if(n % 3 == 0){
            	arr[1]++;
                n /= 3;
            }
            else if(n % 5 == 0){
            	arr[2]++;
                n /= 5;
            }
            else if(n % 7 == 0){
            	arr[3]++;
                n /= 7;
            }
            else if(n % 11 == 0){
            	arr[4]++;
                n /= 11;
            }
               
        }
        cout << '#' << test_case << ' ';
        for(int i = 0; i < 5; i++){
        	cout << arr[i] << ' ';
        }
        cout << '\n';
	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}
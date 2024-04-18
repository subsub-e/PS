#include <algorithm>
#include <cstring>
#include <iostream>
using namespace std;

int arr[101];
int main(void)
{
	int test_case;
	int T;
	
	cin >> test_case;
	/*
	여러 개의 테스트 케이스를 처리하기 위한 부분입니다.
	*/
	for (test_case = 1; test_case <= T; ++test_case)
	{
		int n; cin >> n;
        memset(arr, 0, sizeof(arr));
        int maxans = 0;
        for(int i = 0; i < 1000; i++){
        	int x; cin >> x;
            arr[x]++;
            maxans = max(maxans, arr[x]);
        }
        
        for(int i = 100; i >= 0; i--){
        	if(maxans == arr[i]){
                cout << '#' << n << ' ' << i << '\n';
                    break;
            }
        }
	}
	return 0; //정상종료시 반드시 0을 리턴해야 합니다.
}
#include <algorithm>
#include<iostream>

using namespace std;

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
		long long x1, x2;
        cin >> x1 >> x2;
         cout << '#' << test_case << ' ';
        if(x1 > x2){
        	cout << -1 << '\n';
            continue;
        }
        if(x1 == x2){
        	cout << 0 << '\n';
            continue;
        }
        long long temp = x2 - x1;
    
        if(temp == 1){
            cout << -1 << '\n';
        }
        else{
            cout << temp / 2 << '\n';
        }
	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}
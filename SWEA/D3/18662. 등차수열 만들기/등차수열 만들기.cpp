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
		double x1, x2, x3;
        cin >> x1 >> x2 >> x3;
        cout << '#' << test_case << ' ';
        
        double temp1 = x2 - x1;
        double temp2 = x3 - x2;
        cout << fixed;
        cout.precision(1);
        cout << abs(temp2 - temp1) / 2 << '\n';
	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}
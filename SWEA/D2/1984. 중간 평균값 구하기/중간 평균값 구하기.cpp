#include <vector>
#include <algorithm>
#include<iostream>
#include <cmath>
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
		int sum = 0;
        vector<int> v;
		for(int i = 0; i < 10; i++){
        	int x; cin >> x;
            v.push_back(x);
            sum += x;
        }
        
        sort(v.begin(), v.end());
        sum -= v[0];
        sum -= v[9];
        
        cout << '#' << test_case << ' ' << round((double) sum / 8) << '\n';

	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}
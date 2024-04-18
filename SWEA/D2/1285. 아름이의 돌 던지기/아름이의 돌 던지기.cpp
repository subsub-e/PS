#include <algorithm>
#include <cmath>
#include <vector>
#include<iostream>
#include <climits>
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
		int n; cin >> n;
        vector<int> v;
        for(int i = 0; i < n; i++){
        	int x; cin >> x;
            v.push_back(x);
        }
        
        int cnt = 1;
        int minans = INT_MAX;

		for(int i = 0; i < n; i++){
        	int temp = abs(0 - v[i]);
            if(minans == temp){
            	cnt++;
            }
            if(minans > temp){
            	minans = temp;
                cnt = 1;
            }
        }
        
        cout << '#' << test_case << ' ' << minans << ' ' << cnt << '\n';
	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}
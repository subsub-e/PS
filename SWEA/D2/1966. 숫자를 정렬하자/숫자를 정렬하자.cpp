#include <vector>
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

		vector<int> v;
        int n; cin >> n;
        for(int i = 0; i < n; i++){
        	int x; cin >> x;
            v.push_back(x);
        }
        sort(v.begin(), v.end());
        cout << '#' << test_case << ' ';
        for(int i = 0; i < n; i++){
        	cout << v[i] << ' ';
        }
        cout << '\n';

	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}
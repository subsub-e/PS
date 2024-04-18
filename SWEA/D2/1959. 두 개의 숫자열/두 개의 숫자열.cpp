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
		int n, m; cin >> n >> m;
        vector<int> v1;
        vector<int> v2;
        for(int i = 0; i < n; i++){
        	int x; cin >> x;
            v1.push_back(x);
        }
        
         for(int i = 0; i < m; i++){
        	int x; cin >> x;
            v2.push_back(x);
        }
        
        long long maxans = 0;
       	if(n < m){
            for(int i = 0; i < m - n + 1; i++){
            	long long sum = 0;
                for(int j = 0; j < n; j++){
                	sum += v1[j] * v2[i + j];
                }
                maxans = max(maxans , sum);
            }
        }
        else{
            for(int i = 0; i < n - m + 1; i++){
            	long long sum = 0;
                for(int j = 0; j < m; j++){
                	sum += v2[j] * v1[i + j];
                }
                maxans = max(maxans , sum);
            }
        }
        
        cout << '#' << test_case << ' ' << maxans << '\n';

	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}
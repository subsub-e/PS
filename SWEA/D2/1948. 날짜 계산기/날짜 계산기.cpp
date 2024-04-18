#include<iostream>
#include <unordered_map>
using namespace std;

unordered_map<int, int> m;
int main(int argc, char** argv)
{
	int test_case;
	int T;
	m[1] = 31;
    m[2] = 28;
    m[3] = 31;
    m[4] = 30;
    m[5] = 31;
    m[6] = 30;
    m[7] = 31;
    m[8] = 31;
    m[9] = 30;
    m[10] = 31;
    m[11] = 30;
    m[12] = 31;
	cin>>T;
	/*
	   여러 개의 테스트 케이스가 주어지므로, 각각을 처리합니다.
	*/
	for(test_case = 1; test_case <= T; ++test_case)
	{
		int m1, d1, m2, d2;
        cin >> m1 >> d1 >> m2 >> d2;
        
        if(m1 == m2){
        	cout << '#' << test_case << ' ' << d2 - d1 + 1 << '\n';
            continue;
        }
        int sum = 0;
        for(int i = m1 + 1; i < m2; i++){
        	sum += m[i];
        }
        sum += m[m1] - d1;
        sum += d2;
        cout << '#' << test_case << ' ' << sum + 1 << '\n';
        
	
	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}
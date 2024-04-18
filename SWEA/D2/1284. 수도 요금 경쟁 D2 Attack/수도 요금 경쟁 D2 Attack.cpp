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
		int p, q, r, s, w;
        cin >> p >> q >> r >> s >> w;
        int temp1 = p * w;
        int temp2;
        if(r >= w){
        	temp2 = q;
        }
        else{
            temp2 = q + (w - r) * s;
        }
        
        cout << '#' << test_case << ' ' << min(temp1, temp2) << '\n';
    
	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}

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

		int sum = 0;
        int now = 0;
        int n; cin >> n;
        while(n--){
        	int x; cin >> x;
            if(x == 0){
                sum += now;
            }
            else{
                int y; cin >> y;
                if(x == 1){
                	now += y;
                    sum += now;
                }
                else{
                    now -= y;
                    if(now < 0){
                    	now = 0;
                    }
                    sum += now;
                }
            }
        }
		cout << '#' << test_case << ' ' << sum << '\n';
	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}
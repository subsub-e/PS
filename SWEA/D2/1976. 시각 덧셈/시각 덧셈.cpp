/////////////////////////////////////////////////////////////////////////////////////////////
// 기본 제공코드는 임의 수정해도 관계 없습니다. 단, 입출력 포맷 주의
// 아래 표준 입출력 예제 필요시 참고하세요.

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
		
        int h1, m1, h2, m2;
        cin >> h1 >> m1 >> h2 >> m2;
        int temp1 = h1 + h2;
        int temp2 = m1 + m2;
        if(temp2 > 59){
            temp2 -= 60;
            temp1++;
        }
        if(temp1 >= 12){
            temp1 -= 12;
        }
        cout << '#' << test_case << ' ' << temp1 << ' ' << temp2 << '\n';


	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}
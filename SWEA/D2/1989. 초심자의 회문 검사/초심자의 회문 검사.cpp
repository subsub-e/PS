#include <string>
#include<iostream>

using namespace std;

int main(int argc, char** argv)
{
	int test_case;
	int T;
	
	cin>>T;
	for(test_case = 1; test_case <= T; ++test_case)
	{
		string str; cin >> str;
        int flag = 0;
        for(int i = 0; i < str.length() / 2; i++){
        	if(str[i] != str[str.length() - i - 1]){
            	flag = 1;
                break;
            }
        }
		if(flag == 1){
        	cout << '#' << test_case << ' ' << 0 << '\n';
        }
        else{
            cout << '#' << test_case << ' ' << 1 << '\n';
        }
	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}
#include <string>
#include<iostream>
#include <cstring>
using namespace std;

bool visited[10];
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
		memset(visited, 0, sizeof(visited));
        
        long long n; cin >> n;
        int index = 1;
        while(1){
        	
            long long temp = n * index;
            string str = to_string(temp);
            //cout << str << '\n';
            for(int i = 0; i < str.length(); i++){
            	visited[(int) str[i] - 48] = 1;
            }
            int flag = 0;
            for(int i = 0; i < 10; i++){
            	if(!visited[i]){
                	flag = 1;
                    break;
                }
            }
            if(flag == 0){
            	cout << '#' << test_case << ' ' << n * index << '\n';
                break;
            }
            index++;
        }
        
	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}
#include <vector>
#include <string>
#include<iostream>
#include <cstring>
using namespace std;


int main(int argc, char** argv)
{
	int test_case;
	int T;
	
	cin>>T;
	for(test_case = 1; test_case <= T; ++test_case)
	{

        int n; cin >> n;
        int sum = 0;
        int cnt = 0;
        for(int i = 1; i < n; i++){
            for(int j = 1; j < n; j++){
                if(i * i + j * j <= n * n){
                    cnt++;
                }
            }
        }

        cnt += n;

        cout << '#' << test_case << ' ' << cnt * 4 + 1 << '\n';

	}
	return 0;
}
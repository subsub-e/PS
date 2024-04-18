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
        string str;
        cin >> str;
        int flag = 0;
        if(n % 2 == 1){
            cout << '#' << test_case << ' ' << "No" << '\n';
            continue;
        }
        for(int i = 0; i < n/2; i++){
            if(str[i] != str[i + n/2]){
                flag = 1;
                break;
            }
        }
        if(flag == 0){
            cout << '#' << test_case << ' ' << "Yes" << '\n';
        }
        else{
            cout << '#' << test_case << ' ' << "No" << '\n';
        }

	}
	return 0;
}
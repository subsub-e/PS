#include <vector>
#include <string>
#include<iostream>
#include <cstring>
#include <cmath>
using namespace std;


int main(int argc, char** argv)
{
	int test_case;
	int T;
	
	cin>>T;
	for(test_case = 1; test_case <= T; ++test_case)
	{

        long long n; cin >> n;
        long long maxans = 0;
        for(int i = sqrt(n); i > 0; i--){
            if(n % i == 0){
                maxans = i;
                break;
            }
        }

        long long temp = n / maxans;
        cout << '#' << test_case << ' ' << maxans + temp - 2 << '\n';

	}
	return 0;
}
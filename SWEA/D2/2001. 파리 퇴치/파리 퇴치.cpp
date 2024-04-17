#include<iostream>
#include <algorithm>
using namespace std;

int arr[16][16];

int main(int argc, char** argv)
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
	int test_case;
	int T;
	cin>>T;
	for(test_case = 1; test_case <= T; ++test_case)
	{
		//cout << '#' << test_case << '\n';
        int n, m;
        cin >> n >> m;
        
        for(int i = 0; i < n; i++){
        	for(int j = 0; j < n; j++){
            	cin >> arr[i][j];
            }
        }
        
        int maxans = 0;
        
        for(int i = 0; i < n - m + 1; i++){
        	for(int j = 0; j < n - m + 1; j++){
            	int sum = 0;
                for(int k = i; k < i + m; k++){
                	for(int p = j; p < j + m; p++){
                    	sum += arr[k][p];
                    }
                }
                maxans = max(maxans, sum);
            }
        }
        
        cout << '#' << test_case << ' ' << maxans << '\n';
	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}

#include<iostream>

using namespace std;

int arr[8][8];
int arr1[8][8];
int arr2[8][8];
int arr3[8][8];
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
		int n; cin >> n;
        for(int i = 0; i < n; i++){
        	for(int j = 0; j < n ; j++){
            	cin >> arr[i][j];
            }
        }
        
        for(int i = 0; i < n; i++){
        	for(int j = 0; j < n ; j++){
            	arr1[i][j] = arr[n-j-1][i];
            }
        }
        
        for(int i = 0; i < n; i++){
        	for(int j = 0; j < n ; j++){
            	arr2[i][j] = arr1[n-j-1][i];
            }
        }
        
        for(int i = 0; i < n; i++){
        	for(int j = 0; j < n ; j++){
            	arr3[i][j] = arr2[n-j-1][i];
            }
        }
        
        cout << '#' << test_case << '\n';
        for(int i = 0; i < n; i++){
        	for(int j = 0; j < n ; j++){
            	cout << arr1[i][j];
            }
            cout << ' ' ;
            
            for(int j = 0; j < n ; j++){
            	cout << arr2[i][j];
            }
            cout << ' ' ;
            
            for(int j = 0; j < n ; j++){
            	cout << arr3[i][j];
            }
            cout << '\n';
        }
        
	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}
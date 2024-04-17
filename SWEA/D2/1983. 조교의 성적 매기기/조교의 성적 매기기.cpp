#include<iostream>
#include <algorithm>
using namespace std;

pair<int, int> arr[101];
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

		int n, m;
        cin >> n >> m;
        int p = n / 10;
        for(int i = 1; i <= n; i++){
        	int x1, x2, x3;
            cin >> x1 >> x2 >> x3;
            arr[i] = make_pair(x1 * 35 + x2 * 45 + x3 * 20, i);
        }
		sort(arr + 1, arr + 1 + n);
        //for(int i = 1; i <= n; i++){
        	//cout << arr[i].first << ' ' << arr[i].second << '\n';
        //}
        for(int i = 1; i <= n; i++){
        	if(arr[i].second == m){
                if((n - i) / p + 1 == 1){
                    cout << '#' << test_case << ' ' << "A+" << '\n';
                }
                else if((n - i) / p + 1 == 2){
                    cout << '#' << test_case << ' ' << "A0" << '\n';
                }
                else if((n - i) / p + 1 == 3){
                    cout << '#' << test_case << ' ' << "A-" << '\n';
                }
                else if((n - i) / p + 1 == 4){
                    cout << '#' << test_case << ' ' << "B+" << '\n';
                }
                else if((n - i) / p + 1 == 5){
                    cout << '#' << test_case << ' ' << "B0" << '\n';
                }
                else if((n - i) / p + 1 == 6){
                    cout << '#' << test_case << ' ' << "B-" << '\n';
                }else if((n - i) / p + 1 == 7){
                    cout << '#' << test_case << ' ' << "C+" << '\n';
                }
                else if((n - i) / p + 1 == 8){
                    cout << '#' << test_case << ' ' << "C0" << '\n';
                }
                else if((n - i) / p + 1 == 9){
                    cout << '#' << test_case << ' ' << "C-" << '\n';
                }
                else{
                    cout << '#' << test_case << ' ' << "D0" << '\n';
                }
            }
        }
	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}
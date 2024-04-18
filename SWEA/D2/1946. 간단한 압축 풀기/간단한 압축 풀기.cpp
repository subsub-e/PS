#include <vector>
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
		vector<pair<char, int> > v;
        int n; cin >> n;
        for(int i = 0; i < n; i++){
        	char c;
            int t;
            cin >> c >> t;
            v.push_back(make_pair(c, t));
        }
        
        cout << '#' << test_case << '\n';
        int index = 0;
        for(int i = 0; i < v.size(); i++){
        	for(int j = 0; j < v[i].second; j++){
            	index++;
                cout << v[i].first;
                if(index >= 10){
                    index = 0;
                	cout << '\n';
                }
            }
        }
        if(index != 0){
        	cout << '\n';
        }
	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}
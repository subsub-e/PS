#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>
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
		int n, m;
        cin >> n >> m;
        vector<string> v1;
        vector<string> v2;
        for(int i = 0; i < n; i++){
        	string str; cin >> str;
            v1.push_back(str);
        }
        for(int i = 0; i < m; i++){
        	string str; cin >> str;
            v2.push_back(str);
        }
        
        int gcdnum = __gcd(n, m);
        int gcdnum1 = gcdnum * (n / gcdnum) * (m / gcdnum);
        //cout << gcdnum1 << '\n';
        unordered_map<int, string> ma;
        int index1 = 0;
        int index2 = 0;
        for(int i = 0; i < gcdnum1; i++){
            string temp = v1[index1 % n] + v2[index2 % m];
            ma[i] = temp;
            index1++;
            index2++;
        }
        
        int k; cin >> k;
        cout << '#' << test_case << ' ';
        while(k--){
        	int pq;
            cin >> pq;
            pq--;
            cout << ma[pq % gcdnum1] << ' ';
        }
        cout << '\n';
	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}
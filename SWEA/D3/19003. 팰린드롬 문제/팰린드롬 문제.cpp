#include <vector>
#include <string>
#include<iostream>
#include <cstring>
using namespace std;

bool visited[101];

bool func(string s){
    int left = 0;
    int right = s.length() - 1;
    while(left < right){
        if(s[left] != s[right]){
            return false;
        }
        left++;
        right--;
    }
    return true;
}
int main(int argc, char** argv)
{
	int test_case;
	int T;
	
	cin>>T;
	for(test_case = 1; test_case <= T; ++test_case)
	{

        int n, m;
        cin >> n >> m;
        vector<string> v;
        memset(visited, 0, sizeof(visited));
        for(int i = 0; i < n; i++){
            string str; cin >> str;
            v.push_back(str);
        }

        int sum = 0;
        for(int i = 0; i < n; i++){
            if(func(v[i])){
                sum = m;
                break;
            }
        }
        
        int cnt = 0;
        for(int i = 0; i < n; i++){
            if(visited[i]){
                continue;
            }
            for(int j = i + 1; j < n; j++){
                string temp1 = v[i];
                string temp2 = v[j];
                int flag = 0;
                for(int k = 0; k < m; k++){
                    if(temp1[k] != temp2[m - k - 1]){
                        flag = 1;
                        break;
                    }
                }
                if(flag == 0){
                    visited[i] = 1;
                    visited[j] = 1;
                    sum += m * 2;
                }
            }
        }

        

        v.clear();
        cout << '#' << test_case << ' ' << sum << '\n';



	}
	return 0;
}
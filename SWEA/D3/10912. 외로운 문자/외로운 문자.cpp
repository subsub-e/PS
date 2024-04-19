#include <vector>
#include <string>
#include<iostream>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <climits>
#include <map>
#include <tuple>
using namespace std;
  
 


int main(int argc, char** argv)
{   
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int test_case;
    int T;

    
    cin>>T;
    for(test_case = 1; test_case <= T; ++test_case)
    {
        map<char, int> m;
        string str;
        cin >> str;
        for(int i = 0; i < str.length(); i++){
            m[str[i]]++;
        }

        int flag = 0;
        cout << '#' << test_case << ' ';
        for(auto iter : m){
            if(iter.second % 2 == 1){
                flag = 1;
                cout << iter.first;
            }
        }
        if(flag == 0){
            cout << "Good" << '\n';
        }
        else{
            cout << '\n';
        }
    }
    return 0;
}
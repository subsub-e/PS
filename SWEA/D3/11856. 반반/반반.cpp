#include <vector>
#include <string>
#include<iostream>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <climits>
using namespace std;
 
int visited[26];

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
        string str;
        cin >> str;
        memset(visited, 0, sizeof(visited));
        for(int i = 0; i < 4; i++){
            visited[(int)str[i] - 65]++;
        }

        int cnt = 0;
        for(int i = 0; i < 27; i++){
            if(visited[i] == 2){
                cnt++;
            }
        }

        if(cnt == 2){
            cout << '#' << test_case << ' ' << "Yes" << '\n';
        }
        else{
            cout << '#' << test_case << ' ' << "No" << '\n';
        }

    }
    return 0;
}
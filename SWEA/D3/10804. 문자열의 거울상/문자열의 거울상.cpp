#include <vector>
#include <string>
#include<iostream>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <climits>
#include <unordered_map>
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
        string str; cin >> str;
        cout << '#' << test_case << ' ';
        for(int i = str.length() - 1; i >= 0; i--){
            if(str[i] == 'b'){
                cout << 'd';
            }
            else if(str[i] == 'd'){
                cout << 'b';
            }
            else if(str[i] == 'p'){
                cout << 'q';
            }
            else if(str[i] == 'q'){
                cout << 'p';
            }
        }
        cout << '\n';
    }
    return 0;
}
#include <vector>
#include <string>
#include<iostream>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <climits>
#include <unordered_map>
#include <tuple>
#include <unordered_set>
using namespace std;

int arr[10001];

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
        int a = stoi(str.substr(0, 2));
        int b = stoi(str.substr(2));

        int flag = 0;
        int flag1 = 0;
        if(0 < a && a <= 12){
            flag = 1;
        }
        if(0 < b && b <= 12){
            flag1 = 1;
        }

        if(flag == 1 && flag1 == 1){
            cout << '#' << test_case << ' ' << "AMBIGUOUS" << '\n';
        }
        else if(flag == 0 && flag1 == 1){
            cout << '#' << test_case << ' ' << "YYMM" << '\n';
        }
        else if(flag == 1 && flag1 == 0){
            cout << '#' << test_case << ' ' << "MMYY" << '\n';
        }
        else{
            cout << '#' << test_case << ' ' << "NA" << '\n';
        }


    }
    return 0;
}
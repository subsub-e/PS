#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

string solution(int n) {
    string ans = "";
    vector<int> v;
    while(n != 0){
        int temp = n % 3;
        if(temp == 0){
            v.push_back(4);
            n--;
        }
        else{
            v.push_back(temp);
        }
        n /= 3;
    }
    
    reverse(v.begin(), v.end());
    for(int i = 0; i < v.size(); i++){
        //cout << to_string(v[i]) << '\n';
        ans += to_string(v[i]);
    }
    return ans;
}
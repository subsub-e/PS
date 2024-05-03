#include <string>
#include <vector>
#include <algorithm>
#include <climits>
#include <iostream>

using namespace std;

string solution(string s) {
    string answer = "";
    int minans = INT_MAX;
    int maxans = INT_MIN;
    string temp = "";
    for(int i = 0; i < s.length(); i++){
        if(s[i] == ' '){
            //cout << temp << '\n';
//             if(temp.length() == 1){
//                 int temp 
//             }
//             if(temp.length() == 2 && temp[0] == '-'){
                
//             }
            int now = stoi(temp);
            maxans = max(maxans, now);
            minans = min(minans, now);
            temp = "";
        }
        else{
            temp += s[i];
        }
    }
    
    if(temp != ""){
        int now = stoi(temp);
        maxans = max(maxans, now);
        minans = min(minans, now);
        temp = "";
    }
    
    cout << minans << ' ' << maxans;
    
    answer += to_string(minans);
    answer += ' ';
    answer += to_string(maxans);
    
    
    return answer;
}
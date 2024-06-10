#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

int cnt, turn;

void func(string str, int x, int y){
    string temp = "";
    int temp_cnt = 0;
    for(int i = 0; i < str.length(); i++){
        if(str[i] == '1'){
            temp.push_back('1');
        }
        else{
            temp_cnt++;
        }
    }
    
    if(temp == "1"){
        turn = x + 1;
        cnt = y + temp_cnt;
        return;
    }
    
    int t = temp.length();
    string str_temp = "";
    while(t > 0){
        if(t % 2 == 0){
            str_temp.push_back('0');
        }
        else{
            str_temp.push_back('1');
        }
        t /= 2;
    }
    cout << str_temp << '\n';
    reverse(str_temp.begin(), str_temp.end());
    func(str_temp, x + 1, y + temp_cnt);
}

vector<int> solution(string s) {
    vector<int> answer;
    func(s, 0, 0);
    answer.push_back(turn);
    answer.push_back(cnt);
    return answer;
}
#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

vector<vector<int> > v;
vector<int> answer;
vector<int> e;
vector<int> temp;

void game(){
    int sum = 0;
    int cnt = 0;
    for(int i = 0; i < v.size(); i++){
        int a = v[i][0];
        int b = v[i][1];
        int temp_sum = 0;
        for(int j = 0; j < temp.size(); j++){
            if(temp[j] * 10 < a){
                continue;
            }
            temp_sum += (e[j] - ((e[j] * (temp[j] * 10)) / 100));
        }
        if(temp_sum >= b){
            cnt++;
        }
        else{
            sum += temp_sum;
        }
    }
    if(answer.empty()){
        answer.push_back(cnt);
        answer.push_back(sum);
    }
    else{
        if(answer[0] < cnt){
            answer.clear();
            answer.push_back(cnt);
            answer.push_back(sum);
        }
        else if(answer[0] == cnt){
            if(answer[1] < sum){
                answer.clear();
                answer.push_back(cnt);
                answer.push_back(sum);
            }
        }
    }
}

void func(){
    if(temp.size() == e.size()){
        game();
        return;
    }
    
    for(int i = 0; i < 5; i++){
        temp.push_back(i);
        func();
        temp.pop_back();
    }
}

vector<int> solution(vector<vector<int>> users, vector<int> emoticons) {
    v = users;
    e = emoticons;
    func();
    return answer;
}
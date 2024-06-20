#include <string>
#include <vector>
#include <queue>
#include <algorithm>
#include <iostream>
using namespace std;

vector<int> solution(vector<string> operations) {
    vector<int> answer;
    int cnt = 0;
    int nowSize = 0;
    priority_queue<int> pq;
    for(int i = 0; i < operations.size(); i++){
        if(operations[i] == "D 1"){
            if(nowSize > 0){
                pq.pop();
                nowSize--;
            }
        }
        else if(operations[i] == "D -1"){
            if(nowSize > 0){
                cnt++;
                nowSize--;
            }
        }
        else{
            string temp = operations[i].substr(2);
            pq.push(stoi(temp));
            nowSize++;
        }
    }
    
    if(pq.size() <= cnt){
        answer.push_back(0);
        answer.push_back(0);
        return answer;
    }
    answer.push_back(pq.top());
    while(pq.size() > cnt + 1){
        //cout << pq.top() << ' ';
        pq.pop();
    }
    answer.push_back(pq.top());
    return answer;
}
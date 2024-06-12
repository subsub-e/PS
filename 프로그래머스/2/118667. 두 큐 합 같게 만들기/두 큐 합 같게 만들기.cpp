#include <string>
#include <vector>
#include <queue>
#include <iostream>
#include <algorithm>
using namespace std;

int answer = -1;
long long sum, sum1, sum2;
queue<long long> q1;
queue<long long> q2;

void func(long long x, long long y, long long cnt){
    if(x == sum && y == sum){
        answer = cnt;
        return;
    }
    if(x == sum || y == sum || (cnt > (q1.size() + q2.size() + 1))){
        return;
    }
    
    if(y - sum > 0){
        if(q2.empty()){
            return;
        }
        long long temp = q2.front();
        q2.pop();
        q1.push(temp);
        //cout << temp << '\n';
        func(x+temp, y - temp, cnt + 1);
    }
    else{
        if(q1.empty()){
            return;
        }
        long long temp = q1.front();
        q1.pop();
        q2.push(temp);
        //cout << temp << '\n';
        func(x-temp, y + temp, cnt + 1);
    }
}

int solution(vector<int> queue1, vector<int> queue2) {
    for(int i = 0; i < queue1.size(); i++){
        q1.push(queue1[i]);
        sum += queue1[i];
        sum1 += queue1[i];
    }
    for(int i = 0; i < queue2.size(); i++){
        q2.push(queue2[i]);
        sum += queue2[i];
        sum2 += queue2[i];
    }
    if(sum % 2 == 1){
        return answer;
    }
    else{
        sum /= 2;
        func(sum1, sum2, 0);
        return answer;
    }
}
#include <string>
#include <vector>
#include <queue>
#include <iostream>
#include <algorithm>
using namespace std;

int solution(vector<int> scoville, int K) {
    int answer = 0;
    priority_queue<int, vector<int>, greater<int> > pq;
    for(int i = 0; i < scoville.size(); i++){
        pq.push(scoville[i]);
    }
    //cout << pq.top();
    while(pq.top() < K){
        if(pq.size() < 2){
            return -1;
        }
        int temp = pq.top();
        pq.pop();
        temp += pq.top() * 2;
        pq.pop();
        pq.push(temp);
        answer++;
    }
    return answer;
}
#include <string>
#include <vector>
#include <queue>
#include <algorithm>
#include <iostream>
using namespace std;

priority_queue<pair<int, int>, vector<pair<int, int> >, greater<pair<int, int> > > pq;

int solution(vector<vector<int>> jobs) {
    int answer = 0;
    sort(jobs.begin(), jobs.end());
    
    int curTime = 0;
    int i = 0;
    
    while(true){
        
        if(i >= jobs.size() && pq.empty()){
            break;
        }
        
        while(i < jobs.size() && curTime >= jobs[i][0]){
            pq.push({jobs[i][1], jobs[i][0]});
            i++;
        }
        
        if(!pq.empty()){
            answer += (curTime - pq.top().second + pq.top().first);
            curTime += pq.top().first;
            pq.pop();
        }
        else{
            curTime = jobs[i][0];
        }
        //cout << answer << '\n';
    }
    return answer / jobs.size();
}
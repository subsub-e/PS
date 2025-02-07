#include <string>
#include <vector>
#include <queue>
#include <algorithm>
#include <iostream>

using namespace std;

int d[100001];
vector<pair<int, int> > v[100001];
priority_queue<pair<int, int>, vector<pair<int, int> >, greater<pair<int, int> > > pq;

const int INF = 1e9 + 10;

vector<int> solution(int n, vector<vector<int>> roads, vector<int> sources, int destination) {
    vector<int> answer;
    
    fill(d, d + n + 1, INF);
    
    for(int i = 0; i < roads.size(); i++){
        int st = roads[i][0];
        int en = roads[i][1];
        v[st].push_back({1, en});
        v[en].push_back({1, st});
    }
    
    d[destination] = 0;
    pq.push({d[destination], destination});
    
    while(!pq.empty()){
        int now = pq.top().second;
        int cost = pq.top().first;
        pq.pop();
        
        for(auto next : v[now]){
            if(d[next.second] > next.first + cost){
                d[next.second] = next.first + cost;
                pq.push({d[next.second], next.second});
            }
        }
    }
    
    for(int i = 0; i < sources.size(); i++){
        if(d[sources[i]] == INF){
            answer.push_back(-1);
        }
        else{
            answer.push_back(d[sources[i]]);
        }
    }
    
    return answer;
}
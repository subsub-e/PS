#include <string>
#include <vector>
#include <algorithm>
#include <tuple>
#include <unordered_set>
#include <iostream>
#include <queue>

using namespace std;

int d[50002];
priority_queue<pair<int, int>, vector<pair<int, int> >, greater<pair<int, int> > > pq;
const int INF = 1e9 + 10;
vector<pair<int, int> > v[50001];
bool summit[50001];

vector<int> solution(int n, vector<vector<int>> paths, vector<int> gates, vector<int> summits) {
    vector<int> answer;
    
    for(int i = 0; i < summits.size(); i++){
        summit[summits[i]] = 1;
    }
    
    for(int i = 0; i < paths.size(); i++){
        int st = paths[i][0];
        int en = paths[i][1];
        int cost = paths[i][2];
        v[st].push_back({cost, en});
        v[en].push_back({cost, st});
    }
    
    fill(d, d + n + 1, INF);
    
    for(int i = 0; i < gates.size(); i++){
        d[gates[i]] = 0;
        pq.push({d[gates[i]], gates[i]});
    }
    
    while(!pq.empty()){
        int cost_now = pq.top().first;
        int now = pq.top().second;
        pq.pop();
        
        for(auto next : v[now]){
            if(d[next.second] > max(next.first, d[now])){
                d[next.second] = max(next.first, d[now]);
                if(!summit[next.second]){
                    pq.push({d[next.second], next.second});
                }
            }
        }
    }
    
    int ans = summits[0];
    
    for(int i = 1; i < summits.size(); i++){
        if(d[summits[i]] < d[ans]){
            ans = summits[i];
        }
        else if(d[summits[i]] == d[ans] && ans > summits[i]){
            ans = summits[i];
        }
    }
    answer.push_back(ans);
    answer.push_back(d[ans]);
    
    return answer;
}
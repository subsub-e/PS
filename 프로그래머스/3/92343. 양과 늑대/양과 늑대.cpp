#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

vector<int> v[18];
int maxans = 0;

void dfs(int cur, int wolf, int ani, vector<int> next, vector<int> info){
    if(info[cur] == 0){
        ani++;
    }
    else{
        wolf++;
    }
    
    if(wolf >= ani){
        return;
    }
    //cout << cur << '\n';
    maxans = max(maxans, ani);
    
    for(int i = 0; i < next.size(); i++){
        vector<int> nextNode = next;
        nextNode.erase(nextNode.begin() + i);
        for(auto n : v[next[i]]){
            nextNode.push_back(n);
        }
        dfs(next[i], wolf, ani, nextNode, info);
    }
}

int solution(vector<int> info, vector<vector<int>> edges) {
    
    for(int i = 0; i < edges.size(); i++){
        v[edges[i][0]].push_back(edges[i][1]);
    }
    
    vector<int> next;
    for(int i = 0; i < v[0].size(); i++){
        next.push_back(v[0][i]);
    }
    
    dfs(0, 0, 0, next, info);
    
    return maxans;
}
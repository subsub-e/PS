#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;

vector<long long > v[300001];
long long answer = 0;

void dfs(long long now, long long parent, vector<long long> &a){
    
    for(auto next : v[now]){
        if(next != parent){
            dfs(next, now, a);
        }
    }
    
    a[parent] += a[now];
    answer += abs(a[now]);
}

long long solution(vector<int> a, vector<vector<int>> edges) {
    
    vector<long long> sum(a.size());
    for(int i = 0; i < a.size(); i++){
        sum[i] = a[i];
    }
    
    for(auto e : edges){
        v[e[0]].push_back(e[1]);
        v[e[1]].push_back(e[0]);
    }
    
    dfs(0, 0, sum);
    
    if(sum[0] == 0){
        return answer;
    }
    return -1;
}
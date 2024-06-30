#include <string>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;


int solution(int n, vector<vector<int>> edge) {
    vector<vector<int> > v(n + 1);
    for(int i = 0; i < edge.size(); i++){
        v[edge[i][0]].push_back(edge[i][1]);
        v[edge[i][1]].push_back(edge[i][0]);
    }
    
    vector<int> dist(n + 1, -1);
    queue<int> q;
    dist[1] = 0;
    q.push(1);
    
    while(!q.empty()){
        int now = q.front();
        q.pop();
        
        for(auto next : v[now]){
            if(dist[next] == -1){
                dist[next] = dist[now] + 1;
                q.push(next);
            }
        }
    }
    
    int maxans = *max_element(dist.begin(), dist.end());
    int cnt = 0;
    for(int i = 0; i < dist.size(); i++){
        if(maxans == dist[i]){
            cnt++;
        }
    }
    return cnt;
}
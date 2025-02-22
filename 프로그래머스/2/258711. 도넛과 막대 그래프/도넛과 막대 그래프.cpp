#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

int arr[1000001][2];
vector<int> v[1000001];
int cnt[3];
queue<int> q;

void check(int start){
    q.push(start);
    bool visited = false;
    while(!q.empty()){
        int now = q.front();
        q.pop();
        if(start == now && visited){
            cnt[0]++;
            return;
        }
        if(arr[now][0] >= 2){
            cnt[2]++;
            return;
        }
        for(auto next : v[now]){
            q.push(next);
        }
        visited = true;
    }
    cnt[1]++;
    return;
}

vector<int> solution(vector<vector<int>> edges) {
    vector<int> answer;
    for(int i = 0; i < edges.size(); i++){
        v[edges[i][0]].push_back(edges[i][1]);
        arr[edges[i][0]][0]++;
        arr[edges[i][1]][1]++;
    }
    
    int root = -1;
    
    for(int i = 0; i < 1000001; i++){
        if(arr[i][0] >= 2 && arr[i][1] == 0){
            root = i;
            break;
        }
    }
    answer.push_back(root);
    for(auto next : v[root]){
        check(next);
    }
    for(int i = 0; i < 3; i++){
        answer.push_back(cnt[i]);
    }
    return answer;
}
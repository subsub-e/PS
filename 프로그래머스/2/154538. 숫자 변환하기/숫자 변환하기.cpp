#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <climits>
#include <queue>
#include <cstring>
using namespace std;

bool visited[3000001];
int cnt[3000001];
queue<int> q;


void bfs(int y, int n){
    while(!q.empty()){
        int x = q.front();
        q.pop();
        if(x > y){
            continue;
        }
        
        if(!visited[x * 3]){
            visited[x * 3] = 1;
            cnt[x * 3] = cnt[x] + 1;
            q.push(x * 3);
        }
        if(!visited[x * 2]){
            visited[x * 2] = 1;
            cnt[x * 2] = cnt[x] + 1;
            q.push(x * 2);
        }
        if(!visited[x + n]){
            visited[x + n] = 1;
            cnt[x + n] = cnt[x] + 1;
            q.push(x + n);
        }
    }
}

int solution(int x, int y, int n) {
    memset(cnt, INT_MAX, sizeof(cnt));
    visited[x] = 1;
    cnt[x] = 0;
    q.push(x);
    bfs(y, n);
    if(cnt[y] == INT_MAX){
        return -1;
    }
    return cnt[y];
}
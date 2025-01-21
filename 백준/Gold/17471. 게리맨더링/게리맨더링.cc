#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <cmath>
#include <cstring>

using namespace std;

int n;
int arr[11];
vector<int> v[11];
bool visited[11];
vector<int> v1;
vector<int> v2;
int minans = 1e9 + 10;
bool visited1[11];
bool visited2[11];


bool cangov1(){
    memset(visited1, 0, sizeof(visited1));
    int cnt = 1;
    queue<int> q;
    q.push(v1[0]);
    visited1[v1[0]] = 1;
    while(!q.empty()){
        int now = q.front();
        q.pop();
        
        for(auto next : v[now]){
            if(visited[next] && !visited1[next]){
                q.push(next);
                visited1[next] = 1;
                cnt++;
            }
        }
    }

    if(cnt == v1.size()){
        return true;
    }
    else{
        return false;
    }
}

bool cangov2(){
    memset(visited2, 0, sizeof(visited2));
    int cnt = 1;
    queue<int> q;
    q.push(v2[0]);
    visited2[v2[0]] = 1;
    while(!q.empty()){
        int now = q.front();
        q.pop();
        
        for(auto next : v[now]){
            if(!visited[next] && !visited2[next]){
                q.push(next);
                visited2[next] = 1;
                cnt++;
            }
        }
    }

    if(cnt == v2.size()){
        return true;
    }
    else{
        return false;
    }
}

void simulate(){
    int cnt1 = 0;
    int cnt2 = 0;
    for(int i = 0; i < v1.size(); i++){
        cnt1 += arr[v1[i]];
    }
    for(int i = 0; i < v2.size(); i++){
        cnt2 += arr[v2[i]];
    }

    minans = min(minans, abs(cnt1 - cnt2));
}

void dfs(int now, int cnt){
    if(v1.size() == cnt){
        for(int i = 1; i <= n; i++){
            if(!visited[i]){
                v2.push_back(i);
            }
        }

        if(cangov1() && cangov2()){
            simulate();
        }

        v2.clear();
        return;
    }


    for(int i = now; i <= n; i++){
        if(!visited[i]){
            visited[i] = 1;
            v1.push_back(i);
            dfs(i + 1, cnt);
            v1.pop_back();
            visited[i] = 0;
        }
    }
}


int main(){
    cin >> n;
    for(int i = 1; i <= n; i++){
        cin >> arr[i];
    }

    for(int i = 1; i <= n; i++){
        int t; cin >> t;
        while(t--){
            int x; cin >> x;
            v[i].push_back(x);
        }
    }

    for(int i = 1; i <= n / 2; i++){
        dfs(1, i);
    }

    if(minans == 1e9 + 10){
        cout << -1;
    }
    else{
        cout << minans;
    }
}
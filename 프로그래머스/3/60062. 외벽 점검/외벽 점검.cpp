#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

int m;
vector<int> fri;
vector<int> path;
vector<int> v;
vector<int> we;
int flag;
bool visited[16];


void dfs(int now, int siz){
    if(flag != 0){
        return;
    }
    
    if(v.size() == siz){
        for(int i = 0; i < m; i++){
            int start = path[i];
            int end = path[i + m - 1];
            
            for(int j = 0; j < siz; j++){
                start += v[j];
                
                if(start >= end){
                    flag = siz;
                    return;
                }
                for(int l = i + 1; l < i + m; l++){
                    if(path[l] > start){
                        start = path[l];
                        break;
                    }
                }
            }
            
            
        }
        return;
    }
    
    for(int i = 0; i < fri.size(); i++){
        if(!visited[i]){
            visited[i] = 1;
            v.push_back(fri[i]);
            dfs(now + 1, siz);
            v.pop_back();
            visited[i] = 0;
        }
    }
}

int solution(int n, vector<int> weak, vector<int> dist) {
    int answer = 0;
    path = weak;
    for(int i = 0; i < weak.size() - 1; i++){
        path.push_back(weak[i] + n);
    } 
    fri = dist;
    //sort(fri.rbegin(), fri.rend());
    m = weak.size();
    
    for(int i = 1; i <= dist.size(); i++){
        dfs(0, i);
        if(flag != 0){
            break;
        }
    }
    
    if(flag == 0){
        return -1;
    }
    return flag;
}
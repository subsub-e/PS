#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

bool visited[10];
int flag = 0;
vector<int> v;
int answer = 0;


void func(int cnt, int k, vector<vector<int>> dungeons){
    
    if(flag == 1){
        return;
    }
    
    if(v.size() == cnt){
        int temp = k;
        // for(int i = 0; i < v.size(); i++){
        //     cout << v[i] << ' ';
        // }
        // cout << '\n';
        for(int i = 0; i < cnt; i++){
            if(temp < dungeons[v[i]][0]){
                 // cout << temp << '\n';
                return;
            }
            temp -= dungeons[v[i]][1];
        }
        
        if(temp < 0){
            return;
        }
        flag = 1;
    }
    
    for(int i = 0; i < dungeons.size(); i++){
        if(!visited[i]){
            visited[i] = 1;
            v.push_back(i);
            func(cnt, k, dungeons);
            v.pop_back();
            visited[i] = 0;
        }
    }
}

int solution(int k, vector<vector<int>> dungeons) {
    
    for(int i = dungeons.size(); i > 0; i--){
        func(i, k, dungeons);
        if(flag == 1){
            return i;
        }
    }
    
    
    return answer;
}
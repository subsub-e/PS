#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

int n;
int maxans;
vector<int> v;
vector<int> v2;
bool visited1[11][6];
bool visited2[11][6];
vector<int> map1;
vector<int> map2;
vector<vector<int>> d;
vector<int> answer;

void func1(int now, int tot){
    if(now == v.size()){
        map1.push_back(tot);
        return;
    }
    
    for(int i = 0; i < 6; i++){
        if(!visited1[now][i]){
            visited1[now][i] = 1;
            func1(now + 1, tot + d[v[now]][i]);
            visited1[now][i] = 0;
        }
    }
}

void func2(int now, int tot){
    if(now == v2.size()){
        map2.push_back(tot);
        return;
    }
    
    for(int i = 0; i < 6; i++){
        if(!visited2[now][i]){
            visited2[now][i] = 1;
            func2(now + 1, tot + d[v2[now]][i]);
            visited2[now][i] = 0;
        }
    }
}


void dfs(int now){
    if(v.size() == d.size() / 2){
        int index = 0;
        v2.clear();
        for(int i = 0; i < n; i++){
            if(index < v.size() && v[index] == i){
                index++;
                continue;
            }
            v2.push_back(i);
        }
        
        map1.clear();
        map2.clear();
        
        func1(0, 0);
        func2(0, 0);
        // for(int i = 0; i < map1.size(); i++){
        //     cout << map1[i] << ' ';
        // }
        // cout << '\n';
        
        int temp = 0;
        int temp1 = 0;
        int temp2 = 0;
        for(int i = 0; i < map1.size(); i++){
            
            for(int j = 0; j < map2.size(); j++){
                if(map1[i] > map2[j]){
                    temp++;
                }
                else if(map1[i] == map2[j]){
                    temp1++;
                }
                else{
                    temp2++;
                }
            }
        }
        //cout << temp << ' ' << temp1 << ' ' << temp2 << '\n';
        if(maxans < temp){
            maxans = temp;
            answer.clear();
            for(int i = 0; i < v.size(); i++){
                answer.push_back(v[i] + 1);
            }
        }
        
        
        return;
    }
    
    for(int i = now; i < d.size(); i++){
        v.push_back(i);
        dfs(i + 1);
        v.pop_back();
    }
}


vector<int> solution(vector<vector<int>> dice) {
    
    d = dice;
    n = dice.size();
    
    dfs(0);
    
    return answer;
}
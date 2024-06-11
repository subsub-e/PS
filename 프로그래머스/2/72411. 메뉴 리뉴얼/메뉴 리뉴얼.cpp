#include <string>
#include <vector>
#include <map>
#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

map<string, int> m;

bool visited[100];

void func(string str, int now, int len, string ans){
    if(str.length() == len){
        //sort(str.begin(), str.end());
        //cout << str << '\n';
        m[str]++;
        return;
    }
    
    for(int i = now; i < ans.length(); i++){
        if(!visited[i]){
            visited[i] = 1;
            func(str + ans[i], i + 1, len, ans);
            visited[i] = 0;
        }
    }
}

vector<string> solution(vector<string> orders, vector<int> course) {
    vector<string> answer;
    for(int i = 0; i < orders.size(); i++){
        string temp = orders[i];
        sort(temp.begin(), temp.end());
        for(int j = 2; j <= temp.length(); j++){
            memset(visited, 0, sizeof(visited));
            func("", 0, j, temp);
        }  
    }
    
    for(int i = 0; i < course.size(); i++){
        int maxans = 2;
        vector<string> v;
        for(auto it : m){
            if(it.first.length() == course[i]){
                if(it.second > maxans){
                    v.clear();
                    v.push_back(it.first);
                    maxans = it.second;
                }
                else if(it.second == maxans){
                    v.push_back(it.first);
                }
            }
        }
        for(int i = 0; i < v.size(); i++){
            answer.push_back(v[i]);
        }
    }
    sort(answer.begin(), answer.end());
    return answer;
}
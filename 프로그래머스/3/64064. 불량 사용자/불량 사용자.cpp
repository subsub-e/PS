#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <unordered_set>
using namespace std;

vector<string> v;
int cnt;
bool visited[10];
bool visited2[10];
unordered_set<string> s;

bool func(string str1, string str2){
    if(str1.length() != str2.length()){
        return false;
    }
    for(int i = 0; i < str1.length(); i++){
        if(str2[i] == '*'){
            continue;
        }
        if(str1[i] != str2[i]){
            return false;
        }
    }
    return true;
}

void dfs(int now, int goal, vector<string> user_id, vector<string> banned_id){
    if(now == goal){
        vector<string> ppp = v;
        sort(ppp.begin(), ppp.end());
        string temp = "";
        for(int i = 0; i < v.size(); i++){
            temp += ppp[i];
            //cout << v[i] << ' ';
        }
        //cout << '\n';
        //cout << temp << '\n';
        if(s.find(temp) == s.end()){
            s.insert(temp);
            cnt++;
        }
        return;
    }
    
    for(int i = 0; i < user_id.size(); i++){
        if(!visited[i] && func(user_id[i], banned_id[now])){
            visited[i] = 1;
            v.push_back(user_id[i]);
            dfs(now + 1, goal, user_id, banned_id);
            v.pop_back();
            visited[i] = 0;
        }
    }
}

int solution(vector<string> user_id, vector<string> banned_id) {
    dfs(0, banned_id.size(), user_id, banned_id);
    return cnt;
}
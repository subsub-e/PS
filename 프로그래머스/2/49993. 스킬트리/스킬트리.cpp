#include <string>
#include <vector>
#include <unordered_map>
#include <iostream>
#include <cstring>
using namespace std;

bool visited[27];

int solution(string skill, vector<string> skill_trees) {
    int answer = 0;
    unordered_map<char, int> m;
    for(int i = 0; i < skill.length(); i++){
        m[skill[i]] = i;
    }
    for(int i = 0; i < skill_trees.size(); i++){
        memset(visited, 0, sizeof(visited));
        int flag = 0;
        for(int j = 0; j < skill_trees[i].length(); j++){
            if(m.find(skill_trees[i][j]) != m.end()){
                int index = m[skill_trees[i][j]];
                //cout << index << ' ';
                for(int k = 0; k < index; k++){
                    if(!visited[k]){
                        flag = 1;
                        break;
                    }
                }
                if(flag == 0){
                    visited[index] = 1;
                }
                else{
                    break;
                }
            }
        }
        if(flag == 0){
            //cout << i << '\n';
            answer++;
        }
    }
    return answer;
}
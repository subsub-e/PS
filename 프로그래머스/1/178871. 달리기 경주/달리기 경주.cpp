#include <string>
#include <vector>
#include <map>
#include <iostream>
using namespace std;

vector<string> solution(vector<string> players, vector<string> callings) {
    vector<string> answer;
    map<int, string> m1;
    map<string, int> m2;
    for(int i = 0; i < players.size(); i++){
        m1[i] = players[i];
        m2[players[i]] = i;
    }
    
    for(int i = 0; i < callings.size(); i++){
        int index = m2[callings[i]];
        string temp = m1[index - 1];
        m1[index - 1] = callings[i];
        m1[index] = temp;
        m2[callings[i]] = index - 1;
        m2[temp] = index;
    }
    
    for(auto iter : m1){
        answer.push_back(iter.second);
    }
    
    return answer;
}
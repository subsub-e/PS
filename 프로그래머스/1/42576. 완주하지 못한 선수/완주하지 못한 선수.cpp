#include <string>
#include <vector>
#include <unordered_map>
#include <iostream>
using namespace std;

string solution(vector<string> participant, vector<string> completion) {
    string answer = "";
    unordered_map<string, int> m;
    
    for(int i = 0; i < participant.size(); i++){
        m[participant[i]]++;
    }
    
    for(int i = 0; i < completion.size(); i++){
        m[completion[i]]--;
    }
    
    for(auto it : m){
        //cout << it.first << ' ' << it.second << '\n';
        if(it.second > 0){
            return it.first;
        }
    }
    return answer;
}
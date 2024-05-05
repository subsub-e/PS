#include <string>
#include <vector>
#include <iostream>
#include <unordered_set>
using namespace std;

vector<int> solution(int n, vector<string> words) {
    vector<int> answer;
    unordered_set<string> s;
    
    for(int i = 0; i < words.size(); i++){
        if(s.empty()){
            s.insert(words[i]);
            continue;
        }
        if(s.find(words[i]) == s.end() && words[i-1][words[i-1].length() - 1] == words[i][0]){
            s.insert(words[i]);
        }
        else{
            //cout << words[i-1][words[i-1].length() - 1] << ' ' << words[i][0] << '\n';
            answer.push_back(i % n + 1);
            answer.push_back(i / n + 1);
            break;
        }
    }
    
    if(answer.empty()){
        answer.push_back(0);
        answer.push_back(0);
    }
    return answer;
}
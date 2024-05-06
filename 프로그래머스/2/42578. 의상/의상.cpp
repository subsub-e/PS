#include <string>
#include <vector>
#include <unordered_map>
#include <iostream>
using namespace std;

int solution(vector<vector<string>> clothes) {
    int answer = 1;
    unordered_map<string, int> m;
    for(int i = 0; i < clothes.size(); i++){
        //cout << clothes[i][1] << '\n';
        m[clothes[i][1]]++;
    }
    for(auto now : m){
        answer = answer * (now.second + 1);
        //cout << m[now.first] << '\n';
    }
    
    return answer - 1;
}
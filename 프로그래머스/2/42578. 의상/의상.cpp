#include <string>
#include <vector>
#include <unordered_map>
using namespace std;

int solution(vector<vector<string>> clothes) {
    int answer = 1;
    
    unordered_map<string, int> m;
    
    for(int i = 0; i < clothes.size(); i++){
        m[clothes[i][1]]++;
    }
    
    for(auto it : m){
        answer *= (it.second + 1);
    }
    answer--;
    return answer;
    
}
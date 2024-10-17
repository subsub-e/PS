#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

vector<int> solution(vector<int> answers) {
    vector<int> answer(3);
    int a[5] = {1, 2, 3, 4, 5};
    int b[8] = {2, 1, 2, 3, 2, 4, 2, 5};
    int c[10] = {3, 3, 1, 1, 2, 2, 4, 4, 5, 5};
    
    for(int i = 0; i < answers.size(); i++){
        if(a[i % 5] == answers[i]){
            answer[0]++;
        }
        if(b[i % 8] == answers[i]){
            answer[1]++;
        }
        if(c[i % 10] == answers[i]){
            answer[2]++;
        }
    }
    
    int maxans = 0;
    for(int i = 0; i < answer.size(); i++){
        maxans = max(maxans, answer[i]);
    }
    
    vector<int> ans;
    for(int i = 0; i < answer.size(); i++){
        if(maxans == answer[i]){
            ans.push_back(i + 1);
        }
    }
    
    sort(ans.begin(), ans.end());
    return ans;
}
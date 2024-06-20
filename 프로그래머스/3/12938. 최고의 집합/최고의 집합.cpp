#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

vector<int> solution(int n, int s) {
    vector<int> answer;
    if(s / n == 0){
        answer.push_back(-1);
        return answer;
    }
    
    int temp = s % n;
    for(int i = 0; i < n; i++){
        answer.push_back(s / n);
    }
    int index = answer.size() - 1;
    for(int i = 0; i < temp; i++){
        answer[index]++;
        index--;
    }
    return answer;
}
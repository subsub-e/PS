#include <string>
#include <vector>
#include <stack>
#include <algorithm>
using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
    vector<int> answer;
    vector<int> v;
    for(int i = 0; i < speeds.size(); i++){
        if((100 - progresses[i]) % speeds[i] != 0){
            v.push_back((100 - progresses[i]) / speeds[i] + 1);
        }
        else{
            v.push_back((100 - progresses[i]) / speeds[i]);
        }
    }
    
    int maxans = v[0];
    int temp = 1;
    for(int i = 1; i < speeds.size(); i++){
        if(maxans < v[i]){
            maxans = v[i];
            answer.push_back(temp);
            temp = 1;
        }
        else{
            temp++;
        }
    }
    
    answer.push_back(temp);
    return answer;
}
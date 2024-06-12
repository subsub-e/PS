#include <string>
#include <vector>
#include <stack>
using namespace std;

int solution(vector<int> order) {
    int answer = 0;
    stack<int> s;
    int index = 0;
    for(int i = 1; i <= order.size(); i++){
        if(i == order[index]){
            answer++;
            index++;
            while(!s.empty() && s.top() == order[index]){
                s.pop();
                index++;
                answer++;
            }
            continue;
        }
        if(!s.empty() && order[index] == s.top()){
            answer++;
            index++;
            s.pop();
            continue;
        }
        s.push(i);
    }
    while(!s.empty() && s.top() == order[index]){
        answer++;
        index++;
        s.pop();
    }
    return answer;
}
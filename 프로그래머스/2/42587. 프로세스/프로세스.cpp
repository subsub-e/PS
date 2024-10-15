#include <string>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

int solution(vector<int> priorities, int location) {
    int answer = 0;
    queue<pair<int, int> > q;
    
    for(int i = 0; i < priorities.size(); i++){
        q.push(make_pair(i, priorities[i]));
    }
    
    sort(priorities.rbegin(), priorities.rend());
    int index = 0;
    
    while(!q.empty()){
        if(q.front().second == priorities[index]){
            answer++;
            if(location == q.front().first){
                return answer;
            }
            else{
                q.pop();
                index++;
            }
        }
        else{
            q.push(q.front());
            q.pop();
        }
    }
    
    return answer;
}
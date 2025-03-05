#include <string>
#include <vector>
#include <queue>

using namespace std;

priority_queue<int, vector<int>, greater<int> > pq;

int solution(int n, int k, vector<int> enemy) {
    int answer = enemy.size();
    
    for(int i = 0; i < enemy.size(); i++){
        if(pq.size() == k){
            if(pq.top() < enemy[i]){
                if(n - pq.top() < 0){
                    answer = i;
                    break;
                }
                else{
                    n -= pq.top();
                    pq.pop();
                    pq.push(enemy[i]);
                }
            }
            else{
                if(n - enemy[i] < 0){
                    answer = i;
                    break;
                }
                else{
                    n -= enemy[i];
                }
            }
        }
        else{
            pq.push(enemy[i]);
        }
    }
    return answer;
}
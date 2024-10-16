#include <string>
#include <vector>
#include <set>
using namespace std;

vector<int> solution(vector<string> operations) {
    vector<int> answer;
    multiset<int> pq;
    
    
    for(int i = 0; i < operations.size(); i++){
        string temp = operations[i];
        if(temp[0] == 'I'){
            pq.insert(stoi(operations[i].substr(2)));
        }
        else{
            if(temp[2] == '-'){
                if(pq.size() > 0){
                    pq.erase(pq.begin());
                    
                }
            }
            else{
                if(pq.size() > 0){
                    pq.erase(--pq.end());
                }
            }
        }
    }
    
    if(pq.size() > 0){
        answer.push_back(*--pq.end());
        answer.push_back(*pq.begin());
        return answer;
    }
    
    answer.push_back(0);
    answer.push_back(0);
    return answer;
}
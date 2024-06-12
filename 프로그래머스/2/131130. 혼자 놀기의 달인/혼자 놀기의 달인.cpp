#include <string>
#include <vector>
#include <algorithm>
using namespace std;
vector<int> v;

bool visited[102];

void func(int x, int cnt, vector<int> cards){
    if(visited[x]){
        v.push_back(cnt);
        return;
    }
    visited[x] = 1;
    
    func(cards[x], cnt + 1, cards);
}

int solution(vector<int> cards) {
    int answer = 0;
    
    for(int i = 0; i < cards.size(); i++){
        cards[i]--;
    }
    
    while(1){
        int flag = 0;
        for(int i = 0; i < cards.size(); i++){
            if(!visited[i]){
                flag = 1;
            }
        }
        if(flag == 0){
            break;
        }
        
        for(int i = 0; i < cards.size(); i++){
            if(!visited[i]){
                func(i, 0, cards);
            }
        }
    }
    sort(v.begin(), v.end());
    answer = v[v.size() - 1] * v[v.size() - 2];
    return answer;
}
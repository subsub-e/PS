#include <string>
#include <vector>
#include <queue>
#include <iostream>
using namespace std;

int solution(vector<int> players, int m, int k) {
    int answer = 0;
    int now = 1;
    queue<pair<int, int> > s;
    
    for(int i = 0; i < players.size(); i++){
        
        if(!s.empty() && s.front().first + k == i){
            pair<int, int> temp = s.front();
            s.pop();
            now -= (temp.second);
            cout << i << ' ' << temp.second << ' ' << 'p' << '\n';
        }
        
        if(players[i] >= m * now){
            s.push({i, (players[i] / m + 1) - now});
            answer += ((players[i] / m + 1) - now);
            now = players[i] / m + 1;
            
            cout << i << ' ' << answer << '\n';
        }   
        
        
        
    }
    return answer;
}
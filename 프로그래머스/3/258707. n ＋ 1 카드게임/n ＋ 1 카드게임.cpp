#include <string>
#include <vector>
#include <iostream>
#include <unordered_set>
using namespace std;

bool visited[1001];
unordered_set<int> s;
unordered_set<int> bag;

int solution(int coin, vector<int> cards) {
    int answer = 1;
    
    int index = cards.size() / 3;
    int cnt = 0;
    int n = cards.size() + 1;
    
    for(int i = 0; i < index; i++){
        s.insert(cards[i]);
        visited[cards[i]] = 1;
        if(!s.empty() && s.find(n - cards[i]) != s.end()){
            cnt++;
        }
    }
    
    
    for(int i = index; i < cards.size(); i += 2){
        int firstCard = cards[i];
        int secondCard = cards[i + 1];
        bag.insert(firstCard);
        bag.insert(secondCard);
        if(coin > 0 && s.find(n - firstCard) != s.end()){
            coin--;
            cnt++;
            visited[firstCard] = 1;
        }
        if(coin > 0 && s.find(n - secondCard) != s.end()){
            coin--;
            cnt++;
            visited[secondCard] = 1;
        }
        
        if(cnt == 0){
            if(coin >= 2){
                int flag = 0;
                for(int j = cards.size() / 3; j <= i + 1; j++){
                    if(!visited[cards[j]] && bag.find(n - cards[j]) != bag.end()){
                        coin -= 2;
                        visited[cards[j]] = 1;
                        visited[n - cards[j]] = 1;
                        answer++;
                        flag = 1;
                        break;
                    }
                }
                if(flag == 0){
                    break;
                }
            }   
            else{
                break;
            }
        }
        else{
            cnt--;
            answer++;
        }
    }
    
    
    return answer;
}
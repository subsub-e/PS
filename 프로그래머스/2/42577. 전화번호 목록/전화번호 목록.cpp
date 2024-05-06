#include <string>
#include <vector>
#include <unordered_set>
#include <climits>
#include <algorithm>
#include <iostream>
using namespace std;

bool solution(vector<string> phone_book) {
    bool answer = true;
    unordered_set<string> s;
    
    for(int i = 0; i < phone_book.size(); i++){
        s.insert(phone_book[i]);
    }
    
    for(int i = 0; i < phone_book.size(); i++){
        string temp = "";
        for(int j = 0; j < phone_book[i].length(); j++){
            temp += phone_book[i][j];
            if(j == phone_book[i].length() - 1){
                break;
            }
            if(s.find(temp) != s.end()){
                answer = false;
            }
        }
    }
    
     return answer;
}
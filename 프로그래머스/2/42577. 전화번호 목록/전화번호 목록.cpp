#include <string>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <iostream>
#include <string>
#include <set>
using namespace std;


bool solution(vector<string> phone_book) {
    bool answer = true;
    set<string> s;
    unordered_map<int, string> m;
    
    for(int i = 0; i < phone_book.size(); i++){
        s.insert(phone_book[i]);
    }
    
    for(int i = 0; i < phone_book.size(); i++){
        for(int j = 1; j < phone_book[i].length(); j++){
            if(s.find(phone_book[i].substr(0, j)) != s.end()){
                // cout << phone_book[i].substr(0, j) << '\n';
                return false;
            }
        }
    }
    return answer;
}
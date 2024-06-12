#include <string>
#include <vector>
#include <unordered_map>
#include <iostream>
using namespace std;

unordered_map<int, int> s1;
unordered_map<int, int> s2;

int solution(vector<int> topping) {
    int answer = 0;
    s1[topping[0]]++;
    for(int i = 1; i < topping.size(); i++){
        s2[topping[i]]++;
    }
    if(s1.size() == s2.size()){
        
        answer++;
    }
    //cout << s1.size() << ' ' << s2.size() << '\n';
    for(int i = 1; i < topping.size() - 1; i++){
        s1[topping[i]]++;
        s2[topping[i]]--;
        if(s2[topping[i]] == 0){
            s2.erase(topping[i]);
        }
        //cout << s1.size() << ' ' << s2.size() << '\n';
        if(s1.size() == s2.size()){
            answer++;
        }
    }
    return answer;
}
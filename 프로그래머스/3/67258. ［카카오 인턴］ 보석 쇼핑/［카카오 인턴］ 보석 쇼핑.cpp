#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <iostream>
#include <unordered_set>
using namespace std;

vector<int> solution(vector<string> gems) {
    vector<int> answer;
    unordered_set<string> s(gems.begin(), gems.end());
    unordered_map<string, int> m;
    
    int st = 0;
    int en = 0;
    
    
    for(int i = 0; i < gems.size(); i++){
        m[gems[i]]++;
        if(m.size() == s.size()){
            break;
        }
        en++;
    }
    
    int minans = en - st;
    answer.push_back(st + 1);
    answer.push_back(en + 1);
    
    while(en < gems.size()){
        string key = gems[st];
        m[key]--;
        st++;
        if(m[key] == 0){
            en++;
            while(en < gems.size()){
                m[gems[en]]++;
                if(key == gems[en]){
                    break;
                }
                en++;
            }
            if(en == gems.size()){
                break;
            }
        }
        
        if(minans > en - st){
            minans = en - st;
            answer.clear();
            answer.push_back(st + 1);
            answer.push_back(en + 1);
        }
    }
    
    
    return answer;
}
#include <string>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <iostream>
using namespace std;

int solution(int cacheSize, vector<string> cities) {
    int answer = 0;
    unordered_map<int, string> m;
    vector<string> v;
    for(int i = 0; i < cities.size(); i++){
        transform(cities[i].begin(), cities[i].end(), cities[i].begin(), ::tolower);
    }
    
    if(cacheSize == 0){
        for(int i = 0; i < cities.size(); i++){
            answer += 5;
        }
        return answer;
    }
    
    for(int i = 0; i < cities.size(); i++){
        int flag = 0;
        int index;
        if(!v.empty()){
            for(int j = 0; j < v.size(); j++){
                if(cities[i] == v[j]){
                    flag = 1;
                    index = j;
                    break;
                }
            }
        }
        if(flag == 1){
            answer++;
            v.erase(v.begin() + index);
            v.push_back(cities[i]);
        }
        else{
            answer += 5;
            if(v.size() == cacheSize){
                v.erase(v.begin());
            }
            v.push_back(cities[i]);
        }
    }
    
    
    return answer;
}
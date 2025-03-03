#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

bool comp(vector<int> v1, vector<int> v2){
    if(v1[0] == v2[0]){
        return v1[1] > v2[1];
    }
    return v1[0] > v2[0];
}

int solution(vector<vector<int>> scores) {
    int answer = 1;
    int s1 = scores[0][0];
    int s2 = scores[0][1];
    int hap = scores[0][0] + scores[0][1];
    
    sort(scores.begin(), scores.end(), comp);
    vector<vector<int> > v;
    
    v.push_back(scores[0]);
    
    int prvMax = 0;
    int newMax = scores[0][1];
    
    for(int i = 1; i < scores.size(); i++){
        if(scores[i-1][0] > scores[i][0]){
            prvMax = newMax;
        }
        if(prvMax <= scores[i][1]){
            v.push_back(scores[i]);
            newMax = max(newMax, scores[i][1]);
        }
        
    }
    
    for(int i = 0; i < v.size(); i++){
        if(v[i][0] > s1 && v[i][1] > s2){
            return -1;
        }
        if(hap < v[i][0] + v[i][1]){
            answer++;
        }
    }
    
    return answer;
}
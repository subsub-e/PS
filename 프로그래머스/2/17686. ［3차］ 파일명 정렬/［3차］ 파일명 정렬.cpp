#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

vector<pair<string, pair<int, int> > > v;

bool comp(pair<string, pair<int, int> > a, pair<string, pair<int, int> > b){
    if(a.first == b.first){
        if(a.second.first == b.second.first){
            return a.second.second < b.second.second;
        }
        else{
            return a.second.first < b.second.first;
        }
    }
    else{
        return a.first < b.first;
    }
}

vector<string> solution(vector<string> files) {
    vector<string> answer;
    
    for(int i = 0; i < files.size(); i++){
        string head = "", num = "";
        
        for(int j = 1; j < files[i].size(); j++){
            if(isdigit(files[i][j]) && !isdigit(files[i][j-1])){
                head = files[i].substr(0, j);
            }
            else if(!isdigit(files[i][j]) && isdigit(files[i][j-1])){
                num = files[i].substr(head.size(), j - head.size());
                break;
            }
        }
        
        transform(head.begin(), head.end(), head.begin(), ::tolower);
        
        if(num == ""){
            num = files[i].substr(head.size(), files[i].size() - head.size());
        }
        
        v.push_back(make_pair(head, make_pair(stoi(num), i)));
    }
    
    stable_sort(v.begin(), v.end(), comp);
    
    for(int i = 0; i < files.size(); i++){
        answer.push_back(files[v[i].second.second]);
    }
    return answer;
}
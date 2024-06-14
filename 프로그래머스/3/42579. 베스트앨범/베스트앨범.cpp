#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <iostream>
#include <tuple>
using namespace std;

unordered_map<string, int> m;
vector<pair<string, int> > v;
vector<tuple<string, int, int> > temp;

bool comp(pair<string, int> p1, pair<string, int> p2){
    return p1.second > p2.second;
}

bool comp2(tuple<string, int, int> p1, tuple<string, int, int> p2){
    return get<1>(p1) > get<1>(p2);
}

vector<int> solution(vector<string> genres, vector<int> plays) {
    vector<int> answer;
    for(int i = 0; i < genres.size(); i++){
        m[genres[i]] += plays[i];
        temp.push_back(make_tuple(genres[i], plays[i], i));
    }
    
    for(auto it : m){
        v.push_back(make_pair(it.first, it.second));
    }
    
    sort(v.begin(), v.end(), comp);
    
    sort(temp.begin(), temp.end(), comp2);
    
    
    for(int i = 0; i < v.size(); i++){
        int cnt = 0;
        for(int j = 0; j < temp.size(); j++){
            if(get<0>(temp[j]) == v[i].first){
                cnt++;
                answer.push_back(get<2>(temp[j]));
            }
            if(cnt == 2){
                break;
            }
        }
    }
    
    return answer;
}
#include <string>
#include <vector>
#include <tuple>
#include <iostream>
#include <algorithm>
#include <unordered_map>
using namespace std;

bool comp(pair<string, int> a, pair<string, int> b){
    return a.second > b.second;
}

bool comp2(tuple<int, int, string> a, tuple<int, int, string> b){
    if(get<0>(a) == get<0>(b)){
        return get<1>(a) < get<1>(b);
    }
    return get<0>(a) > get<0>(b);
}

vector<int> solution(vector<string> genres, vector<int> plays) {
    vector<int> answer;
    unordered_map<string, int> m;
    vector<tuple<int, int, string> > v;
    
    for(int i = 0; i < genres.size(); i++){
        m[genres[i]] += plays[i];
        v.push_back(make_tuple(plays[i], i, genres[i]));
    }
    
    
    vector<pair<string, int> > table(m.begin(), m.end());
    
    sort(table.begin(), table.end(), comp);
    
    // for(int i = 0; i < table.size(); i++){
    //     cout << table[i].first << ' ' << table[i].second << '\n';
    // }
    
    sort(v.begin(), v.end(), comp2);
    
    // for(int i = 0; i < v.size(); i++){
    //     cout << get<0>(v[i]) << ' ' << get<1>(v[i]) << ' ' << get<2>(v[i]) << '\n';
    // }
    
    for(int i = 0; i < table.size(); i++){
        int cnt = 0;
        for(int j = 0; j < v.size(); j++){
            if(cnt >= 2){
                break;
            }
            string temp = get<2>(v[j]);
            // cout << table[i].first << ' ' << temp << ' ' << cnt << '\n';
            if(table[i].first == temp){
                cnt++;
                answer.push_back(get<1>(v[j]));
            }
        }
    }
    
    return answer;
}
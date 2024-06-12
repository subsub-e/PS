#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <map>
using namespace std;

map<string, int> m;
map<string, int> m1;

vector<int> solution(vector<int> fees, vector<string> records) {
    vector<int> answer;
    vector<pair<int, string> > v;
    
    for(int i = 0; i < records.size(); i++){
        int t = stoi(records[i].substr(0, 2)) * 60 + stoi(records[i].substr(3, 2));
        string num = records[i].substr(6, 4);
        string temp = records[i].substr(11);
        //cout << t << ' ' << num << ' ' << temp << '\n';
        if(temp == "IN"){
            v.push_back(make_pair(t, num));
        }
        else{
            int index;
            for(int i = 0; i < v.size(); i++){
                if(v[i].second == num){
                    index = i;
                    break;
                }
            }
            
            int fee = t - v[index].first;
            m1[num] += fee;
            v.erase(v.begin() + index);
        }
    }
    
    for(int i = 0; i < v.size(); i++){
        int ppp = 1439 - v[i].first;
        m1[v[i].second] += ppp;
    }
    for(auto it : m1){
        if(it.second <= fees[0]){
            m[it.first] = fees[1];
        }
        else{
            int te = it.second - fees[0];
            if(te % fees[2] == 0){
                m[it.first] = (fees[1] + (te / fees[2]) * fees[3]);
            }
            else{
                m[it.first] = (fees[1] + (te / fees[2] + 1) * fees[3]);
            }
        }
    }
    
    for(auto it : m){
        answer.push_back(it.second);
    }
    return answer;
}
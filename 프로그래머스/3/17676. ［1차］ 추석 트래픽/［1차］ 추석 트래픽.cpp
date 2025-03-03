#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <string>

using namespace std;

vector<pair<int, int> > v;

int timeToInt(string str){
    int hour = stoi(str.substr(0, 2)) * 3600 * 1000;
    int minute = stoi(str.substr(3, 2)) * 60 * 1000;
    int sec = stoi(str.substr(6, 2)) * 1000;
    int misec = stoi(str.substr(9));
    return hour + minute + sec + misec;
}

int func(int endT, string t){
    if(t.length() == 2){
        return endT - (((int) t[0] - 48) * 1000) + 1;
    }
    string temp = "";
    for(int i = 0; i < 6; i++){
        if(t.length() <= i){
            temp += "0";
            continue;
        }
        if(t[i] == '.' || t[i] == 's'){
            continue;
        }
        temp += t[i];
    }
    return endT - stoi(temp) + 1;
}

int solution(vector<string> lines) {
    
    for(int i = 0; i < lines.size(); i++){
        string end_time = lines[i].substr(11, 12);
        string t = lines[i].substr(24);
        int endT = timeToInt(end_time);
        int stT = func(endT, t);
        v.push_back({stT, endT});
    }
    
    int answer = 0;
    for(int i = 0; i < v.size(); i++){
        int stT = v[i].second;
        int enT = stT + 999;
        int cnt = 1;
        for(int j = i + 1; j < v.size(); j++){
            if(v[j].first <= enT){
                cnt++;
            }
        }
        answer = max(answer, cnt);
    }
    return answer;
}
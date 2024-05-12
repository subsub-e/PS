#include <string>
#include <vector>
#include <algorithm>
#include <unordered_set>
#include <map>
using namespace std;

bool comp(pair<int, int> a, pair<int, int> b){
    return a.second > b.second;
}

vector<int> solution(string s) {
    vector<int> answer;
    map<int, int> m;
    string temp = "";
    for(int i = 1; i < s.length() - 1; i++){
        if(isdigit(s[i])){
            temp += s[i];
        }
        if(s[i] == ','){
            m[stoi(temp)]++;
            //answer.push_back(stoi(temp));
            temp = "";
        }
    }
    if(temp != ""){
        m[stoi(temp)]++;
        //answer.push_back(stoi(temp));
    }
    
    vector<pair<int, int> > v(m.begin(), m.end());
    sort(v.begin(), v.end(), comp);
    
    for(int i = 0; i < v.size(); i++){
        answer.push_back(v[i].first);
    }
    
    return answer;
}
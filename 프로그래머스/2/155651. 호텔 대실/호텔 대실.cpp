#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <queue>
using namespace std;

int trans(string t){
    int hour = stoi(t.substr(0, 2));
    int minute = stoi(t.substr(3));
    return hour * 60 + minute;
}

int solution(vector<vector<string>> book_time) {
    vector<pair<int, int> > v;
    
    for(int i = 0; i < (int)book_time.size(); i++){
        int start_time, end_time;
        start_time = trans(book_time[i][0]);
        end_time = trans(book_time[i][1]) + 10;
        v.push_back(make_pair(start_time, end_time));
    }
    
    sort(v.begin(), v.end());
    
    priority_queue<int, vector<int>, greater<int> > q;
    
    for(int i = 0; i < (int) v.size(); i++){
        if(!q.empty() && q.top() <= v[i].first){
            q.pop();
            
        }
        q.push(v[i].second);
    }
    return q.size();
}
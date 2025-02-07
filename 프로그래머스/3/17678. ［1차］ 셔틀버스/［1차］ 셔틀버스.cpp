#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

string solution(int n, int t, int m, vector<string> timetable) {
    
    int st = 540;
    vector<int> v;
    for(int i = 0; i < timetable.size(); i++){
        int hour = stoi(timetable[i].substr(0, 2)) * 60;
        int minute = stoi(timetable[i].substr(3, 2));
        v.push_back(hour + minute);
    }
    
    sort(v.begin(), v.end());
    
    // for(int i = 0; i < v.size(); i++){
    //     cout << v[i] << '\n';
    // }
    
    int ans = v[0] - 1;
    
    int index = 0;
    
    for(int i = 0; i < n; i++){
        int cnt = 0;
        int temp = index;
        for(int j = 0; j < m; j++){
            if(temp == v.size()){
                break;
            }
            if(st >= v[temp]){
                cnt++;
                temp++;
            }
            else{
                break;
            }
        }
        if(cnt < m){
            ans = st;
        }
        else{
            int temp1 = index;
            for(int j = 0; j < m; j++){
                if(temp1 + 1 < v.size() && v[temp1] != v[temp1 + 1] && st >= v[temp1]){
                    ans = v[temp1];
                }
                if(j == m - 1){
                    ans = v[temp1] - 1;
                }
                temp1++;
            }
        }
        st += t;
        index = temp;
    }
    
    //cout << ans;
    
    string hour = to_string(ans / 60);
    if(hour.length() < 2){
        hour = "0" + hour;
    }
    string minute = to_string(ans % 60);
    if(minute.length() < 2){
        minute = "0" + minute;
    }
    
    string answer = hour + ":" + minute;
    
    return answer;
}
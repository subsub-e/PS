#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

int play, adv;
int dp[360001];

int timeToInt(string str){
    int hour = stoi(str.substr(0, 2));
    int minute = stoi(str.substr(3, 2));
    int sec = stoi(str.substr(6));
    
    return hour * 60 * 60 + minute * 60 + sec;
}

string intToTime(int x){
    int temp = x;
    string answer = "";
    if(temp / 3600 < 10){
        answer += ("0" + to_string(temp / 3600) + ":");
    }
    else{
        answer += (to_string(temp / 3600) + ":");
    }
    temp %= 3600;
    
    if(temp / 60 < 10){
        answer += ("0" + to_string(temp / 60) + ":");
    }
    else{
        answer += (to_string(temp / 60) + ":");
    }
    
    temp %= 60;
    
    if(temp < 10){
        answer += ("0" + to_string(temp));
    }
    else{
        answer += to_string(temp);
    }
    
    return answer;
}

string solution(string play_time, string adv_time, vector<string> logs) {
    play = timeToInt(play_time);
    adv = timeToInt(adv_time);
    for(string now : logs){
        string fir = now.substr(0, 8);
        string sec = now.substr(9);
        int st = timeToInt(fir);
        int en = timeToInt(sec);
        dp[st] += 1;
        dp[en] -= 1;
        //cout << dp[st] << ' ' << dp[en] << '\n';
    }
    
    for(int i = 1; i <= 360000; i++){
        dp[i] += dp[i - 1];
    }
    
    int minans = 1e9 + 10;
    long long maxcnt = 0;
    for(int i = 0; i <= play - adv; i++){
        long long temp_max = 0;
        for(int j = i; j < i + adv; j++){
            temp_max += dp[j];
        }
        if(temp_max > maxcnt){
            maxcnt = temp_max;
            minans = i;
            
            //cout << intToTime(i) << ' ' << temp_max << '\n';
        }
        else if(temp_max == maxcnt){
            minans = min(minans, i);
        }
    }
    
    string answer = intToTime(minans);
    // cout << play << ' ' << adv << '\n';
    return answer;
}


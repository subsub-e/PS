// #include <string>
// #include <vector>
// #include <algorithm>
// #include <iostream>

// using namespace std;

// int play, adv;
// int dp[360001];

// int timeToInt(string str){
//     int hour = stoi(str.substr(0, 2));
//     int minute = stoi(str.substr(3, 2));
//     int sec = stoi(str.substr(6));
    
//     return hour * 60 * 60 + minute * 60 + sec;
// }

// string intToTime(int x){
//     int temp = x;
//     string answer = "";
//     if(temp / 3600 < 10){
//         answer += ("0" + to_string(temp / 3600) + ":");
//     }
//     else{
//         answer += (to_string(temp / 3600) + ":");
//     }
//     temp %= 3600;
    
//     if(temp / 60 < 10){
//         answer += ("0" + to_string(temp / 60) + ":");
//     }
//     else{
//         answer += (to_string(temp / 60) + ":");
//     }
    
//     temp %= 60;
    
//     if(temp < 10){
//         answer += ("0" + to_string(temp));
//     }
//     else{
//         answer += to_string(temp);
//     }
    
//     return answer;
// }

// string solution(string play_time, string adv_time, vector<string> logs) {
//     play = timeToInt(play_time);
//     adv = timeToInt(adv_time);
//     for(string now : logs){
//         string fir = now.substr(0, 8);
//         string sec = now.substr(9);
//         int st = timeToInt(fir);
//         int en = timeToInt(sec);
//         dp[st] += 1;
//         dp[en] -= 1;
//         //cout << dp[st] << ' ' << dp[en] << '\n';
//     }
    
//     for(int i = 1; i <= 360000; i++){
//         dp[i] += dp[i - 1];
//     }
    
//     int minans = 1e9 + 10;
//     int maxcnt = 0;
//     for(int i = 0; i <= play - adv; i++){
//         int temp_max = 0;
//         for(int j = i; j <= i + adv; j++){
//             temp_max += dp[j];
//         }
//         if(temp_max > maxcnt){
//             maxcnt = temp_max;
//             minans = i;
            
//             //cout << intToTime(i) << ' ' << temp_max << '\n';
//         }
//         else if(temp_max == maxcnt){
//             minans = min(minans, i);
//         }
//     }
    
//     string answer = intToTime(minans);
//     // cout << play << ' ' << adv << '\n';
//     return answer;
// }

#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

int play, adv;
long long dp[360001];

int timeToInt(string str) {
    int hour = stoi(str.substr(0, 2));
    int minute = stoi(str.substr(3, 2));
    int sec = stoi(str.substr(6));
    
    return hour * 60 * 60 + minute * 60 + sec;
}

string intToTime(int x) {
    int h = x / 3600;
    x %= 3600;
    int m = x / 60;
    int s = x % 60;
    
    return (h < 10 ? "0" : "") + to_string(h) + ":" +
           (m < 10 ? "0" : "") + to_string(m) + ":" +
           (s < 10 ? "0" : "") + to_string(s);
}

string solution(string play_time, string adv_time, vector<string> logs) {
    play = timeToInt(play_time);
    adv = timeToInt(adv_time);

    // 시청자 변화량 기록
    for (string now : logs) {
        int st = timeToInt(now.substr(0, 8));
        int en = timeToInt(now.substr(9));
        dp[st] += 1;
        dp[en] -= 1;
    }

    // 누적 시청자 수 계산
    for (int i = 1; i <= play; i++) {
        dp[i] += dp[i - 1];
    }

    // 누적 시청 시간 계산
    for (int i = 1; i <= play; i++) {
        dp[i] += dp[i - 1];
    }

    // 최적의 광고 시작 시간 찾기 (슬라이딩 윈도우)
    long long maxView = dp[adv - 1];
    int minStartTime = 0;

    for (int i = adv; i <= play; i++) {
        long long currentView = dp[i] - dp[i - adv];
        if (currentView > maxView) {
            maxView = currentView;
            minStartTime = i - adv + 1;
        }
    }

    return intToTime(minStartTime);
}

#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

bool find(int target, vector<int> diffs, vector<int> times, long long limit){
    long long cnt = 0;
    for(int i = 0; i < diffs.size(); i++){
        if(diffs[i] - target > 0){
            cnt += ((times[i] + times[i-1]) * (diffs[i] - target) + times[i]);
        }
        else{
            cnt += times[i];
        }
    }
    
    if(cnt > limit){
        return true;
    }
    else{
        return false;
    }
}

int solution(vector<int> diffs, vector<int> times, long long limit) {
    int answer = 1;
    int left = 1;
    int right = 100000;
    while(left <= right){
        int mid = (left + right) / 2;
        if(find(mid, diffs, times, limit)){
            left = mid + 1;
            //cout << mid << '\n';
        }
        else{
            right = mid - 1;
            answer = mid;
        }
    }
    //cout << '\n';
    return left;
}
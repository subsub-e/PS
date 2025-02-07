#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

bool calculate(long long target, int n, vector<int> times){
    long long cnt = 0;
    for(int i = 0; i < times.size(); i++){
        cnt += (target / (long long) times[i]);
    }
    //cout << cnt << '\n';
    if(cnt >= n){
        return true;
    }
    else{
        return false;
    }
}

long long solution(int n, vector<int> times) {
    long long answer = 0;
    long long st = 1;
    long long en = 1000000000000000000;
    while(st < en){
        long long mid = (st + en) / 2;
        if(calculate(mid, n, times)){
            answer = mid;
            en = mid;
        }
        else{
            st = mid + 1;
        }
    }
    return answer;
}
#include <string>
#include <vector>

using namespace std;

bool check(int target, vector<int> stones, int k){
    int cnt = 0;
    for(int i = 0; i < stones.size(); i++){
        stones[i] -= (target - 1);
    }
    for(int i = 0; i < stones.size(); i++){
        if(stones[i] <= 0){
            cnt++;
            if(cnt == k){
                return false;
            }
        }
        else{
            cnt = 0;
        }
    }
    return true;
}

int solution(vector<int> stones, int k) {
    int answer = 0;
    int st = 0;
    int en = 200000000;
    while(st <= en){
        int mid = (st + en) / 2;
        if(check(mid, stones, k)){
            st = mid + 1;
        }
        else{
            en = mid - 1;
            answer = en;
        }
    }
    return answer;
}
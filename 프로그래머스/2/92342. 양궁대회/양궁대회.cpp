#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

vector<int> answer = {-1};
int maxans = 0;

void dfs(int cnt, int n, int idx, vector<int> info, vector<int> v){
    if(cnt == n){
        int score = 0;
        for(int i = 0; i < 11; i++){
            if(v[i] > info[i]){
                score += (10-i);
            }
            else if (info[i] > 0){
                score -= (10 - i);
            }
        }
        if(score > maxans && score){
            maxans = score;
            answer = v;
        }
        else if(score == maxans && score){
            for(int i = 10; i >= 0; i--){
                if(answer[i] > v[i]){
                    return;
                }
                else if(answer[i] < v[i]){
                    answer = v;
                    break;
                }
            }
        }
        return;
    }
    
    
    for(int i = idx; i <= 10; i++){
        int num = info[i] + 1;
        if(num > n - cnt){
            num = n - cnt;
        }
        v[i] = num;
        dfs(cnt + num, n, idx + 1, info, v);
        v[i] = 0;
    }
}

vector<int> solution(int n, vector<int> info) {
    vector<int> v(11, 0);
    dfs(0, n, 0, info, v);
    return answer;
}
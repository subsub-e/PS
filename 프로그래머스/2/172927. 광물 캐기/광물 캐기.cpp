#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <iostream>

using namespace std;

unordered_map<string, int> m;
int arr[3][3] = {{1, 1, 1}, {5, 1, 1}, {25, 5, 1}};
int answer = 1e9;

void dfs(vector<int>& picks, vector<string>& minerals, int now, int sum){
    if(now == minerals.size() || (picks[0] == 0 && picks[1] == 0 && picks[2] == 0)){
        answer = min(answer, sum);
        return;
    }
    
    for(int i = 0; i < 3; i++){
        if(picks[i] != 0){
            picks[i]--;
            
            int tmpInx;
            int tmpSum = sum;
            for(tmpInx = now; tmpInx < now + 5 && tmpInx < minerals.size(); tmpInx++){
                tmpSum += arr[i][m[minerals[tmpInx]]];
            }
            
            dfs(picks, minerals, tmpInx, tmpSum);
            picks[i]++;
        }
    }
}

int solution(vector<int> picks, vector<string> minerals) {
    
    m["diamond"] = 0;
    m["iron"] = 1;
    m["stone"] = 2;
    
    dfs(picks, minerals, 0, 0);
    return answer;
}
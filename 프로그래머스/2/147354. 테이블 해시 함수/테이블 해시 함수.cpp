#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;
int n;

bool comp(vector<int> v1, vector<int> v2){
    if(v1[n-1] == v2[n-1]){
        return v1[0] > v2[0];
    }
    return v1[n-1] < v2[n-1];
}

int solution(vector<vector<int>> data, int col, int row_begin, int row_end) {
    int ans = 0;
    n = col;
    sort(data.begin(), data.end(), comp);
    
    //vector<int> answer;
    
    for(int i = row_begin - 1; i < row_end; i++){
        int cnt = 0;
        for(int j = 0; j < data[i].size(); j++){
            cnt += (data[i][j] % (i + 1));
            //cout << data[i][j] (i + 1)<< '\n';
        }
        ans ^= cnt;
        //answer.push_back(cnt);
    }
    
    //cout << answer[0] << ' ' << answer[1];
    
    // ans = answer[0] ^ answer[1];
    // for(int i = 2; i < answer.size(); i++){
    //     ans = (ans ^ answer[2]);
    // }
    return ans;
}
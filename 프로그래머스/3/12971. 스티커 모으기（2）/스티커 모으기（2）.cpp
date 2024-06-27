#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int dp1[100001][2];
int dp2[100001][2];

int solution(vector<int> sticker)
{
    if(sticker.size() == 1){
        return sticker[0];
    }
    if(sticker.size() == 2){
        return max(sticker[0], sticker[1]);
    }
    
    dp1[0][1] = sticker[0];
    dp2[1][1] = sticker[1];
    
    for(int i = 2; i < sticker.size(); i++){
        if(i == sticker.size() - 1){
            dp2[i][0] = max(dp2[i-1][0], max(dp2[i-1][1], max(dp2[i-2][0], dp2[i-2][1])));
            dp2[i][1] = max(dp2[i-1][0], max(dp2[i-2][0], dp2[i-2][1])) + sticker[i];
        }
        else{
            dp1[i][0] = max(dp1[i-1][0], max(dp1[i-1][1], max(dp1[i-2][0], dp1[i-2][1])));
            dp2[i][0] = max(dp2[i-1][0], max(dp2[i-1][1], max(dp2[i-2][0], dp2[i-2][1])));
            dp1[i][1] = max(dp1[i-1][0], max(dp1[i-2][0], dp1[i-2][1])) + sticker[i];
            dp2[i][1] = max(dp2[i-1][0], max(dp2[i-2][0], dp2[i-2][1])) + sticker[i];
        }
    }
    
    
    return max(dp1[sticker.size()-2][0], max(dp1[sticker.size()-2][1], max(dp2[sticker.size() - 1][0], dp2[sticker.size() - 1][1])));
}
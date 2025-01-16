#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>

using namespace std;

vector<int> v;
int step[5][5];
int dp[100001][5][5];
const int INF = 1e9 + 10;

int solve(int idx, int left, int right){
    if(idx == (int)v.size()){
        return 0;
    }

    int &ret = dp[idx][left][right];
    if(ret != -1){
        return ret;
    }
    ret = INF;

    int leftMove = solve(idx + 1, v[idx], right) + step[left][v[idx]];
    int rightMove = solve(idx + 1, left, v[idx]) + step[right][v[idx]];

    ret = min(leftMove, rightMove);

    return ret;


}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    memset(dp, -1, sizeof(dp));

    while(1){
        int x; cin >> x;
        if(x == 0){
            break;
        }
        v.push_back(x);
    }

    for(int i = 0; i < 5; i++){
        step[i][i] = 1;
    }

    for(int i = 1; i < 5; i++){
        step[0][i] = 2;
    }

    step[1][2] = step[1][4] = step[2][1] = step[2][3] = step[3][2] = step[3][4] = step[4][1] = step[4][3] = 3;

    step[1][3] = step[2][4] = step[3][1] = step[4][2] = 4;

    cout << solve(0, 0, 0);

}
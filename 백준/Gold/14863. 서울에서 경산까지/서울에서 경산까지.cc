#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>

using namespace std;

vector<pair<int, int> > bike(101);
vector<pair<int, int> > walk(101);
int dp[101][100001];
int n, k;

int main(){
    cin >> n >> k;
    for(int i = 1; i <= n; i++){
        int a, b, c, d;
        cin >>a >> b >> c >> d;
        walk[i] = {a, b};
        bike[i] = {c, d};
    }

    dp[1][walk[1].first] = walk[1].second;
    dp[1][bike[1].first] = max(dp[1][bike[1].first],bike[1].second);

    for(int i = 1; i < n; i++){
        for(int j = 0; j <=k; j++){
            if(!dp[i][j]){
                continue;
            }
            if(j + walk[i + 1].first <= k){
                dp[i+ 1][j + walk[i + 1].first] = max(dp[i + 1][j + walk[i+1].first], dp[i][j] + walk[i+1].second);
            }
            if(j + bike[i+1].first <= k){
                dp[i+1][j + bike[i+1].first] = max(dp[i+1][j + bike[i+1].first], dp[i][j] + bike[i+1].second);
            } 
        }
    }

    int answer = 0;
    for(int i = 0; i <= k; i++){
        answer = max(answer, dp[n][i]);
    }
    cout << answer;
}
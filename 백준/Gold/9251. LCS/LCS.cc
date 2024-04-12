#include <iostream>
#include <algorithm>
#include <cmath>
#include <string>
#include <vector>
#include <climits>
#include <cstring>
#include <tuple>
#include <queue>
using namespace std;

string str1, str2;
int dp[1001][1001];

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

    cin >> str1 >> str2;
    for(int i = 1; i <= str1.length(); i++){
        for(int j = 1; j <= str2.length(); j++){
            if(str1[i - 1] == str2[j - 1]){
                dp[i][j] = dp[i - 1][j-1] + 1;
            }
            else{
                dp[i][j] = max(dp[i][j-1], dp[i-1][j]);
            }
        }
    }
    
    // for(int i = 1; i <= str1.length(); i++){
    //     for(int j = 1; j <= str2.length(); j++){
    //         cout << dp[i][j] << ' ';
    //     }
    //     cout << '\n';
    // }

    cout << dp[str1.length()][str2.length()];
    
	return 0;
}
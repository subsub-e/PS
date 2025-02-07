#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

int arr[201][201];
const int INF = 1e8 + 10;

int solution(int n, int s, int a, int b, vector<vector<int>> fares) {
    int answer = INF;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            arr[i][j] = INF;
        }
    }
    
    for(int i = 1; i <= n; i++){
        arr[i][i] = 0;
    }
    
    for(int i = 0; i < fares.size(); i++){
        arr[fares[i][0]][fares[i][1]] = fares[i][2];
        arr[fares[i][1]][fares[i][0]] = fares[i][2];
    }
    
    for(int k = 1; k <= n; k++){
        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= n; j++){
                arr[i][j] = min(arr[i][j], arr[i][k] + arr[k][j]);
            }
        }
    }
    
    // for(int i = 1; i <= n; i++){
    //     for(int j = 1; j <= n; j++){
    //         cout << arr[i][j] << ' ';
    //     }
    //     cout << '\n';
    // }
    
    answer = min(answer, arr[s][a] + arr[s][b]);
    //cout << answer << '\n';
    
    for(int i = 1; i <= n; i++){
        if(i == s){
            continue;
        }
        answer = min(answer, arr[s][i] + arr[i][a] + arr[i][b]);
    }
    
    return answer;
}
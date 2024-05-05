#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
using namespace std;

int arr[51][51];
const int INF = 0x3f3f3f3f;

int solution(int N, vector<vector<int> > road, int K) {
    int answer = 0;
    
    for(int i = 1; i <= N; i++){
        fill(arr[i], arr[i] + N + 1, INF);
    }
    
    for(int i = 1; i <= N; i++){
        arr[i][i] = 0;
    }
    
    for(int i = 0; i < road.size(); i++){
        int x = road[i][0];
        int y = road[i][1];
        int cost = road[i][2];
        arr[x][y] = min(arr[x][y], cost);
        arr[y][x] = min(arr[y][x], cost);
    }
    
    for(int k = 1; k <= N; k++){
        for(int i = 1; i <= N; i++){
            for(int j = 1; j <= N; j++){
                arr[i][j] = min(arr[i][j], arr[i][k] + arr[k][j]);
            }
        }
    }
    
    for(int i = 1; i <= N; i++){
        //cout << arr[1][i] << '\n';
        if(arr[1][i] <= K){
            answer++;
        }
    }
    
    

    return answer;
}
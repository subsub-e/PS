#include <string>
#include <vector>
#include <iostream>
using namespace std;

int arr[1001][1001];
int dx[3] = {1, 0, -1};
int dy[3] = {0, 1, 0};

vector<int> solution(int n) {
    vector<int> answer;
    
    int temp = n;
    int index = 0;
    int x = -1;
    int y = 0;
    int dir = 0;
    int count = 1;
    
    
    while(temp > 0){
        if(dir % 3 == 0){   
            y = index;
            index++;
        }
        for(int i = 0; i < temp; i++){
            x += dx[dir % 3];
            y += dy[dir % 3];
            arr[x][y] = count;
            count++;
        }
        dir++;
        temp--;
    }
    
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if(arr[i][j] == 0){
                continue;
            }
            answer.push_back(arr[i][j]);
        }
    }
    return answer;
}
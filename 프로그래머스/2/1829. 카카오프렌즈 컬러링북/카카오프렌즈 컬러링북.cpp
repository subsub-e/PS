#include <vector>
#include <queue>
#include <algorithm>
#include <iostream>
#include <cstring>
using namespace std;

int maxans;
queue<pair<int, int> > q;
bool visited[101][101];

void bfs(int val, int height, int weight, vector<vector<int>> arr){
    int cnt = 1;
    int dx[4] = {-1, 0, 1, 0};
    int dy[4] = {0, -1, 0, 1};
    
    while(!q.empty()){
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
        
        for(int i = 0; i < 4; i++){
            int nx = x + dx[i];
            int ny = y + dy[i];
            if(0 <= nx && nx < height && 0 <= ny && ny < weight && arr[nx][ny] == val && !visited[nx][ny]){
                visited[nx][ny] = 1;
                q.push(make_pair(nx, ny));
                cnt++;
            }
        }
    }
    
    maxans = max(maxans, cnt);
}

// 전역 변수를 정의할 경우 함수 내에 초기화 코드를 꼭 작성해주세요.
vector<int> solution(int m, int n, vector<vector<int>> picture) {
    int number_of_area = 0;
    int max_size_of_one_area = 0;
    int cnt = 0;
    maxans = 0;
    memset(visited, 0, sizeof(visited));
    for(int i = 0; i < m; i++){
        for(int j = 0; j < n; j++){
            if(picture[i][j] != 0 && !visited[i][j]){
                cnt++;
                q.push(make_pair(i, j));
                visited[i][j] = 1;
                //cout << i << ' ' << j << '\n';
                bfs(picture[i][j], m, n, picture);
            }
        }
    }
    
    
    vector<int> answer(2);
    answer[0] = cnt;
    answer[1] = maxans;
    return answer;
}
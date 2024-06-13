#include <string>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

bool visited[101][101];
int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, -1, 0, 1};
vector<int> answer;
queue<pair<int, int> > q;
vector<string> v;

void bfs(int temp){
    int sum = temp;
    while(!q.empty()){
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
        
        for(int i = 0; i < 4; i++){
            int nx = x + dx[i];
            int ny = y + dy[i];
            
            if(0 <= nx && nx < v.size() && 0 <= ny && ny < v[0].size() && !visited[nx][ny] && v[nx][ny] != 'X'){
                visited[nx][ny] = 1;
                q.push(make_pair(nx, ny));
                sum += (int) v[nx][ny] - 48;
            }
        }
    }
    answer.push_back(sum);
}

vector<int> solution(vector<string> maps) {
    v = maps;
    for(int i = 0; i < maps.size(); i++){
        for(int j = 0; j < maps[i].length(); j++){
            if(!visited[i][j] && maps[i][j] != 'X'){
                q.push(make_pair(i, j));
                visited[i][j] = 1;
                bfs((int) maps[i][j] - 48);
            }
        }
    }
    if(answer.empty()){
        answer.push_back(-1);
        return answer;
    }
    sort(answer.begin(), answer.end());
    return answer;
}
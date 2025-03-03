#include <string>
#include <vector>
#include <queue>
#include <algorithm>
#include <iostream>

using namespace std;

vector<vector<bool> > visited;
vector<vector<pair<int, int> > > puzzle;
vector<vector<pair<int, int> > > board;
int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, -1, 0, 1};

bool cango(vector<vector<int>> &table, int x, int y, int flag){
    return 0 <= x && x < table.size() && 0 <= y && y < table[0].size() && !visited[x][y] && table[x][y] == flag;
}

vector<pair<int, int> > bfs(vector<vector<int>> &table, int x, int y, int flag){
    queue<pair<int, int> > q;
    visited[x][y] = 1;
    q.push({x, y});
    vector<pair<int, int> > v;
    
    int minX = x;
    int minY = y;
    
    while(!q.empty()){
        int tempX = q.front().first;
        int tempY = q.front().second;
        q.pop();
        v.push_back({tempX, tempY});
        
        for(int i = 0; i < 4; i++){
            int nx = tempX + dx[i];
            int ny = tempY + dy[i];
            
            if(cango(table, nx, ny, flag)){
                q.push({nx, ny});
                visited[nx][ny] = 1;
                
                minX = min(minX, nx);
                minY = min(minY, ny);
            }
        }
    }
    
    for(auto& now : v){
        now.first -= minX;
        now.second -= minY;
    }
    
    return v;
}

void rotate(vector<pair<int, int> >& target){
    int maxY = -1;
    int minX = 1e5;
    int minY = 1e5;
    for(int i = 0; i < target.size(); i++){
        maxY = max(maxY, target[i].first);
    }
    
    for(auto& now : target){
        int temp = now.first;
        now.first = maxY - now.second;
        now.second = temp;
        
        minX = min(minX, now.second);
        minY = min(minY, now.first);
    }
    
    for(auto& now : target){
        now.first -= minY;
        now.second -= minX;
    }

}

bool match(vector<pair<int, int> >& now, vector<pair<int, int> >& empty){
    if(now.size() != empty.size()){
        return false;
    }
    
    for(int i = 0; i < 4; i++){
        int cnt = 0;
        for(auto& e : empty){
            for(auto& p : now){
                if(p == e){
                    cnt++;
                    break;
                }
            }
        }
        if(cnt == now.size()){
            return true;
        }
        rotate(now);
    }
    return false;
}

int solution(vector<vector<int>> game_board, vector<vector<int>> table) {
    int answer = 0;
    
    visited.resize(table.size(), vector<bool>(table[0].size(), false));
    for(int i = 0; i < table.size(); i++){
        for(int j = 0; j < table[i].size(); j++){
            if(!visited[i][j] && table[i][j] == 1){
                puzzle.push_back(bfs(table, i, j, 1));
            }
        }
    }
    
    visited.clear();
    visited.resize(game_board.size(), vector<bool>(game_board[0].size(), false));
    for(int i = 0; i < game_board.size(); i++){
        for(int j = 0; j < game_board[i].size(); j++){
            if(!visited[i][j] && game_board[i][j] == 0){
                board.push_back(bfs(game_board, i, j, 0));
            }
        }
    }
    
    vector<bool> used(puzzle.size(), false);
    
    for(auto& empty : board){
        for(int i = 0; i < puzzle.size(); i++){
            if(!used[i] && match(puzzle[i], empty)){
                used[i] = 1;
                answer += puzzle[i].size();
                break;
            }
        }
    }
    
    return answer;
}
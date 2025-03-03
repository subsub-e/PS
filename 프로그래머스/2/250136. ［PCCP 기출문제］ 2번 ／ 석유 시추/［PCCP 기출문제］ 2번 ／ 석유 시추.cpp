#include <string>
#include <vector>
#include <queue>
#include <iostream>
#include <stack>
#include <unordered_set> s;
using namespace std;

int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, -1, 0, 1};
bool visited[501][501];
pair<int, int> cnt[501][501];
queue<pair<int, int> > q;
stack<pair<int, int> > s;
int fin = 1;

void bfs(vector<vector<int>>& land){
    int now_cnt = 1;
    while(!q.empty()){
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
        
        for(int i = 0; i < 4; i++){
            int nx = x + dx[i];
            int ny = y + dy[i];
            if(0 <= nx && nx < land.size() && 0 <= ny && ny < land[0].size() && !visited[nx][ny] && land[nx][ny] == 1){
                q.push({nx, ny});
                s.push({nx, ny});
                now_cnt++;
                visited[nx][ny] = 1;
            }
        }
    }
    
    while(!s.empty()){
        int x = s.top().first;
        int y = s.top().second;
        s.pop();
        cnt[x][y] = make_pair(fin, now_cnt);
    }
    fin++;
}

int solution(vector<vector<int>> land) {
    int answer = 0;
    for(int i = 0; i < land.size(); i++){
        for(int j = 0; j < land[i].size(); j++){
            if(!visited[i][j] && land[i][j] == 1){
                visited[i][j] = 1;
                q.push({i, j});
                s.push({i, j});
                bfs(land);
            }
        }
    }
    
    for(int i = 0; i < land[0].size(); i++){
        int ans = 0;
        unordered_set<int> s;
        for(int j = 0; j < land.size(); j++){
            if(!s.empty() && cnt[j][i].second > 0 && s.find(cnt[j][i].first) == s.end()){
                s.insert(cnt[j][i].first);
                ans += cnt[j][i].second;
            }
            if(s.empty() && cnt[j][i].second > 0){
                s.insert(cnt[j][i].first);
                ans += cnt[j][i].second;
            }
        }
        answer = max(answer, ans);
    }
    return answer;
}